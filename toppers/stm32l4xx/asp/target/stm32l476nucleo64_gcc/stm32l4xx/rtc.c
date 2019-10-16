/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2008-2011 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2015-2017 by TOPPERS PROJECT Educational Working Group.
 * 
 *  上記著作権者は，以下の(1)〜(4)の条件を満たす場合に限り，本ソフトウェ
 *  ア（本ソフトウェアを改変したものを含む．以下同じ）を使用・複製・改
 *  変・再配布（以下，利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 *      また，本ソフトウェアのユーザまたはエンドユーザからのいかなる理
 *      由に基づく請求からも，上記著作権者およびTOPPERSプロジェクトを
 *      免責すること．
 * 
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，特定の使用目的
 *  に対する適合性も含めて，いかなる保証も行わない．また，本ソフトウェ
 *  アの利用により直接的または間接的に生じたいかなる損害に関しても，そ
 *  の責任を負わない．
 * 
 *  @(#) $Id: rtc.c 698 2017-07-27 17:15:29Z roi $
 */
/*
 *
 * RTC(L4XX)用デバイス操作関数群の定義
 *
 */
#include "kernel_impl.h"
#include <t_syslog.h>
#include <t_stdlib.h>
#include <sil.h>
#include <target_syssvc.h>
#include "kernel_cfg.h"
#include "device.h"
#include "rtc.h"

/*
 *  SIL関数のマクロ定義
 */
#define sil_orw_mem(a, b)		sil_wrw_mem((a), sil_rew_mem(a) | (b))
#define sil_andw_mem(a, b)		sil_wrw_mem((a), sil_rew_mem(a) & ~(b))
#define sil_modw_mem(a, b, c)	sil_wrw_mem((a), (sil_rew_mem(a) & (~b)) | (c))

#define byte2bcd(value) ((((value)/10)<<4) | ((value) % 10))
#define bcd2byte(value) ((((value)>>4) * 10) + ((value) & 0xF))

/*
 *  サービスコールのエラーのログ出力
 */
Inline void
svc_perror(const char *file, int_t line, const char *expr, ER ercd)
{
	if (ercd < 0) {
		t_perror(LOG_ERROR, file, line, expr, ercd);
	}
}

#define	SVC_PERROR(expr)	svc_perror(__FILE__, __LINE__, #expr, (expr))


#define RCC_RTCCLKSOURCE_LSE    RCC_BDCR_RTCSEL_0
#define RCC_RTCCLKSOURCE_LSI    RCC_BDCR_RTCSEL_1


#ifndef RTC_CLOCK_LSE
#define RCC_RTCCLKSOURCE_DEF    RCC_RTCCLKSOURCE_LSI
#else
#define RCC_RTCCLKSOURCE_DEF    RCC_RTCCLKSOURCE_LSE
#endif

#if RCC_RTCCLKSOURCE_DEF == RCC_RTCCLKSOURCE_LSI
#define RTC_ASYNCH_PREDIV       0x7C	/* LSI as RTC clock */
#define RTC_SYNCH_PREDIV        0x00F9	/* LSI as RTC clock */
#elif RCC_RTCCLKSOURCE_DEF == RCC_RTCCLKSOURCE_LSE
#define RTC_ASYNCH_PREDIV       0x7F	/* LSE as RTC clock */
#define RTC_SYNCH_PREDIV        0x00FF	/* LSE as RTC clock */
#else
#error "No clok select for RTC."
#endif


#define RTC_TR_RESERVED_MASK    (RTC_TR_SU | RTC_TR_ST | RTC_TR_MNU | RTC_TR_MNT | \
								 RTC_TR_HU | RTC_TR_HT | RTC_TR_PM)
#define RTC_DR_RESERVED_MASK    (RTC_DR_DU | RTC_DR_DT  | RTC_DR_MU | RTC_DR_MT | \
								 RTC_DR_WDU | RTC_DR_YU | RTC_DR_YT)
#define RTC_INIT_MASK           ((uint32_t)0xFFFFFFFF)  
#define RTC_RSF_MASK            ((uint32_t)0xFFFFFF5F)

#define RTC_TIMEOUT_VALUE       (1000*1000)
#define LSI_TIMEOUT_VALUE       (100*1000)
#define HSE_TIMEOUT_VALUE       (100*1000)
#define RCC_DBP_TIMEOUT_VALUE   (100*1000)
#define RCC_LSE_TIMEOUT_VALUE   (5000*1000)

uint32_t rtcerrorcode;

static void (*rtcalarmA_callback)(void);	/* RTC AlamA callback */
#if defined(TOFF_RTC_ALRMBR)
static void (*rtcalarmB_callback)(void);	/* RTC AlamB callback */
#endif

/*
 *  RTCエントリモード設定
 */
static ER
rtc_requestInitMode(void)
{
	uint32_t tick = 0;

	/*
	 * イニシャルモード判定
	 */
	if((sil_rew_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_ISR)) & RTC_ISR_INITF) == 0){
	    /*
		 *  イニシャルモード設定
		 */
		sil_wrw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_ISR), RTC_INIT_MASK);
	    while((sil_rew_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_ISR)) & RTC_ISR_INITF) == 0){
			if(tick > RTC_TIMEOUT_VALUE){
				return E_TMOUT;
			}
		}
		sil_dly_nse(1000);
		tick++;
	}
	return E_OK;
}

/*
 *  RTC用初期化
 */
void
rtc_init(intptr_t exinf)
{
	uint32_t tick = 0;
	bool_t   pwrclkchanged = false;
	volatile uint32_t tmp;

	rtcerrorcode = 0;

	if((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_APB1ENR1)) & RCC_APB1ENR1_PWREN) == 0){
		sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_APB1ENR1), RCC_APB1ENR1_PWREN);
		pwrclkchanged = true;
	}

#if RCC_RTCCLKSOURCE_DEF == RCC_RTCCLKSOURCE_LSI
	/*
	 *  LSE DISABLE
	 */
	if((sil_rew_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR1)) & PWR_CR1_DBP) == 0){
		sil_orw_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR1), PWR_CR1_DBP);
		while((sil_rew_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR1)) & PWR_CR1_DBP) == 0){
			if(tick > RCC_DBP_TIMEOUT_VALUE){
				syslog_0(LOG_ERROR, "rtc_init dbp timeout!");
				rtcerrorcode |= RTC_ERROR_RTC;
				return;
			}
			tick++;
			sil_dly_nse(1000);
		}
	}

	sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_BDCR), RCC_BDCR_LSEON);
	sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_BDCR), RCC_BDCR_LSEBYP);
	tick = 0;
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_BDCR)) & RCC_BDCR_LSERDY) != 0){
		if(tick > RCC_LSE_TIMEOUT_VALUE){
			syslog_0(LOG_ERROR, "rtc_init LSE timeout!");
			rtcerrorcode |= RTC_ERROR_LSE;
			return;
		}
		tick++;
		sil_dly_nse(1000);
    }

	/*
	 *  LSI ENABLE
	 */
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CSR), RCC_CSR_LSION);

	tick = 0;
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CSR)) & RCC_CSR_LSIRDY) == 0){
		if(tick > RCC_LSE_TIMEOUT_VALUE){
			syslog_0(LOG_ERROR, "rtc_init LSI timeout!");
			rtcerrorcode |= RTC_ERROR_LSI;
			return;
		}
		tick++;
		sil_dly_nse(1000);
	}

#elif RCC_RTCCLKSOURCE_DEF == RCC_RTCCLKSOURCE_LSE
	/*
	 *  LSI DISABLE
	 */
	sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CSR), RCC_CSR_LSION);

	tick = 0;
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CSR)) & RCC_CSR_LSIRDY) != 0){
		if(tick > RCC_LSE_TIMEOUT_VALUE){
			syslog_0(LOG_ERROR, "rtc_init LSI timeout!");
			rtcerrorcode |= RTC_ERROR_LSI;
			return;
		}
		tick++;
		sil_dly_nse(1000);
	}

	/*
	 *  LSE ENABLE
	 */
	if((sil_rew_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR1)) & PWR_CR1_DBP) == 0){
		sil_orw_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR1), PWR_CR1_DBP);
		while((sil_rew_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR1)) & PWR_CR1_DBP) == 0){
			if(tick > RCC_DBP_TIMEOUT_VALUE){
				syslog_0(LOG_ERROR, "rtc_init dbp timeout!");
				rtcerrorcode |= RTC_ERROR_RTC;
				return;
			}
			tick++;
			sil_dly_nse(1000);
		}
	}

	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_BDCR), RCC_BDCR_LSEON);
	tick = 0;
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_BDCR)) & RCC_BDCR_LSERDY) == 0){
		if(tick > RCC_LSE_TIMEOUT_VALUE){
			syslog_0(LOG_ERROR, "rtc_init LSE timeout!");
			rtcerrorcode |= RTC_ERROR_LSE;
			return;
		}
		tick++;
		sil_dly_nse(1000);
    }
#endif

    /*
	 *  クロックソースの選択
	 */
    tmp = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_BDCR)) & RCC_BDCR_RTCSEL;
    if(tmp != 0 && tmp != RCC_RTCCLKSOURCE_DEF){
		/*
		 *  クロックソースが違う場合、RTCリセット
		 */
		tmp = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_BDCR)) & ~RCC_BDCR_RTCSEL;
		sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_BDCR), RCC_BDCR_BDRST);
		sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_BDCR), RCC_BDCR_BDRST);
		/*
		 * クロックソースなしに設定
		 */
		sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_BDCR), tmp);
	}
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_BDCR), RCC_BDCR_RTCSEL, RCC_RTCCLKSOURCE_DEF);

	if(pwrclkchanged)
		sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_APB1ENR1), RCC_APB1ENR1_PWREN);

	/*
	 *  RTCのクロック設定
	 */
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_BDCR), RCC_BDCR_RTCEN);


	/* プロテクション解除 */
	sil_wrw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_WPR), 0xCA);
	sil_wrw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_WPR), 0x53);

	/*
	 *  RTC初期設定
	 */
	if(rtc_requestInitMode() != E_OK){
		rtcerrorcode |= RTC_ERROR_RTC;
	    /* プロテクション設定 */
		sil_wrw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_WPR), 0xFF);
		return;
	}
	else{
		sil_andw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_CR), (RTC_CR_FMT | RTC_CR_OSEL | RTC_CR_POL));

		sil_wrw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_PRER), RTC_SYNCH_PREDIV);
		sil_orw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_PRER), (RTC_ASYNCH_PREDIV << 16));

		sil_andw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_ISR), RTC_ISR_INIT);

	    /* プロテクション設定 */
		sil_wrw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_WPR), 0xFF);
		return;
	}
}


/*
 *  RTCの時刻設定関数
 *
 *  時刻の設定はPONIXのtm構造体を使用する
 *  PONIXのインクルードがない場合を考慮し、同一項目のtm2をドライバとして定義する。
 */
ER
rtc_set_time(struct tm2 *pt)
{
	uint32_t timetmp = 0;
	uint32_t datetmp = 0;

	if(pt == NULL)
		return E_PAR;
	if(rtcerrorcode != 0)
		return E_SYS;

	SVC_PERROR(wai_sem(RTCSEM));

	datetmp = (((uint32_t)byte2bcd(pt->tm_year - 30) << 16) |
				((uint32_t)byte2bcd(pt->tm_mon) << 8) |
				((uint32_t)byte2bcd(pt->tm_mday)) |
				((uint32_t)pt->tm_wday << 13));
    timetmp = (uint32_t)(((uint32_t)byte2bcd(pt->tm_hour) << 16) |
				((uint32_t)byte2bcd(pt->tm_min) << 8) |
				((uint32_t)byte2bcd(pt->tm_sec)));

	/* プロテクション解除 */
	sil_wrw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_WPR), 0xCA);
	sil_wrw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_WPR), 0x53);

	/*
	 *  初期化モード設定
	 */
	if(rtc_requestInitMode() != E_OK){
		/* プロテクション設定 */
		sil_wrw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_WPR), 0xFF);
		SVC_PERROR(sig_sem(RTCSEM));
		return E_TMOUT;
	}
	else{
		/*
		 *  日付、時刻設定
		 */
		sil_wrw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_DR), (datetmp & RTC_DR_RESERVED_MASK));
		sil_wrw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_TR), (timetmp & RTC_TR_RESERVED_MASK));

		/*  初期化モード終了 */
		sil_andw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_CR), RTC_CR_BCK);
		sil_andw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_ISR), RTC_ISR_INIT);

		/*
		 *  同期設定
		 */
		if((sil_rew_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_CR)) & RTC_CR_BYPSHAD) == 0){
			uint32_t tick = 0;

			sil_andw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_ISR), RTC_RSF_MASK);
    		while((sil_rew_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_ISR)) & RTC_ISR_RSF) == 0){
				if(tick > (RTC_TIMEOUT_VALUE/1000)){
					SVC_PERROR(sig_sem(RTCSEM));
					return E_TMOUT;
				}
				dly_tsk(1);
				tick++;
			}
		}

		/* プロテクション設定 */
		sil_wrw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_WPR), 0xFF);
	}
	SVC_PERROR(sig_sem(RTCSEM));
	return E_OK;
}

/*
 *  RTCの時刻取り出し関数
 *
 *  時刻の設定はPONIXのtm構造体を使用する
 *  PONIXのインクルードがない場合を考慮し、同一項目のtm2をドライバとして定義する。
 */
ER
rtc_get_time(struct tm2 *pt)
{
	uint32_t timetmp = 0;
	uint32_t datetmp = 0;

	if(pt == NULL)
		return E_PAR;
	if(rtcerrorcode != 0)
		return E_SYS;

	SVC_PERROR(wai_sem(RTCSEM));
	/*
	 *  時刻取得
	 */
	timetmp = sil_rew_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_TR)) & RTC_TR_RESERVED_MASK;
	pt->tm_hour = (uint8_t)bcd2byte((uint8_t)((timetmp & (RTC_TR_HT | RTC_TR_HU)) >> 16));
	pt->tm_min = (uint8_t)bcd2byte((uint8_t)((timetmp & (RTC_TR_MNT | RTC_TR_MNU)) >>8));
	pt->tm_sec = (uint8_t)bcd2byte((uint8_t)(timetmp & (RTC_TR_ST | RTC_TR_SU)));

	/*
	 *  日付取得
	 */
	datetmp = sil_rew_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_DR)) & RTC_DR_RESERVED_MASK;
	pt->tm_year = (uint8_t)bcd2byte((uint8_t)((datetmp & (RTC_DR_YT | RTC_DR_YU)) >> 16)) + 30;
	pt->tm_mon = (uint8_t)bcd2byte((uint8_t)((datetmp & (RTC_DR_MT | RTC_DR_MU)) >> 8));
	pt->tm_mday = (uint8_t)bcd2byte((uint8_t)(datetmp & (RTC_DR_DT | RTC_DR_DU)));
	pt->tm_wday = (uint8_t)((datetmp & (RTC_DR_WDU)) >> 13); 

	SVC_PERROR(sig_sem(RTCSEM));
	return E_OK;
}

/*
 *  RTCアラーム設定
 *  parameter1 : parm: Pointer to Alarm structure
 *  parameter2 : ptm: Pointer to struct tm2
 *  return ERコード
 */
ER
rtc_setalarm(RTC_Alarm_t *parm, struct tm2 *ptm)
{
	uint32_t tick = 0;
	uint32_t tmparm = 0, subsecond = 0;
	uint32_t tmp, day;

	if(parm == NULL || ptm == NULL)
		return E_PAR;
	if(rtcerrorcode != 0)
		return E_SYS;

	if(parm->dayselect == ALARMDAYSEL_DATE)
		day = ptm->tm_mday;
	else
		day = ptm->tm_wday;

	/*
	 *  ALARM-AB設定レジスタ値を取得
	 */
	SVC_PERROR(wai_sem(RTCSEM));
    tmparm = ((byte2bcd(ptm->tm_hour) << 16) | (byte2bcd(ptm->tm_min) << 8) |
              (byte2bcd(ptm->tm_sec)) | (byte2bcd(day) << 24) |
              ((uint32_t)parm->dayselect) | (parm->alarmmask)); 
	subsecond = (uint32_t)(parm->subsecond | parm->subsecondmask);

	/* プロテクション解除 */
	sil_wrw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_WPR), 0xCA);
	sil_wrw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_WPR), 0x53);

	if(parm->alarm == RTC_ALARM_A){
		/*
		 *  ALARM-A設定、レジスタ初期化
		 */
		sil_andw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_CR), RTC_CR_ALRAE);
		tmp = sil_rew_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_ISR));
		sil_wrw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_ISR), (~(RTC_ISR_ALRAF | RTC_ISR_INIT) | tmp));
		while((sil_rew_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_ISR)) & RTC_ISR_ALRAWF) == 0){
			if(tick > (RTC_TIMEOUT_VALUE/1000)){
			    /* プロテクション設定 */
				sil_wrw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_WPR), 0xFF);
				SVC_PERROR(sig_sem(RTCSEM));
				return E_TMOUT;
			}
			dly_tsk(1);
			tick++;
		}

		/*
		 *  ALARM-A設定
		 */
		sil_wrw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_ALRMAR), tmparm);
		sil_wrw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_ALRMASSR), subsecond);
		sil_orw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_CR), RTC_CR_ALRAE);
		sil_orw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_CR), RTC_CR_ALRAIE);
		rtcalarmA_callback = parm->callback;
	}
#if defined(TOFF_RTC_ALRMBR)
	else{
		/*
		 *  ALARM-B設定、レジスタ初期化
		 */
		sil_andw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_CR), RTC_CR_ALRBE);
		tmp = sil_rew_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_ISR));
		sil_wrw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_ISR), (~(RTC_ISR_ALRBF | RTC_ISR_INIT) | tmp));
		while((sil_rew_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_ISR)) & RTC_ISR_ALRBWF) == 0){
			if(tick > (RTC_TIMEOUT_VALUE/1000)){
			    /* プロテクション設定 */
				sil_wrw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_WPR), 0xFF);
				SVC_PERROR(sig_sem(RTCSEM));
				return E_TMOUT;
			}
			dly_tsk(1);
			tick++;
		}

		/*
		 *  ALARM-B設定
		 */
		sil_wrw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_ALRMBR), tmparm);
		sil_wrw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_ALRMBSSR), subsecond);
		sil_orw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_CR), RTC_CR_ALRBE);
		sil_orw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_CR), RTC_CR_ALRBIE);
		rtcalarmB_callback = parm->callback;
	}
#endif

	/*
	 * RTC ALARM用EXTI設定
	 */
	sil_orw_mem((uint32_t *)(TADR_EXTI_BASE+TOFF_EXTI_IMR1), EXTI_IMR_MR18);
	sil_orw_mem((uint32_t *)(TADR_EXTI_BASE+TOFF_EXTI_RTSR1), EXTI_RTSR_TR18);

    /* プロテクション設定 */
	sil_wrw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_WPR), 0xFF);
	SVC_PERROR(sig_sem(RTCSEM));
	return E_OK;
}

/*
 *  RTCアラーム停止
 *  parameter1 : Alarm: アラーム設定
 *  return ERコード
 */
ER
rtc_stopalarm(uint32_t Alarm)
{
	uint32_t tick = 0;

	if(rtcerrorcode != 0)
		return E_SYS;
	SVC_PERROR(wai_sem(RTCSEM));
	/* プロテクション解除 */
	sil_wrw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_WPR), 0xCA);
	sil_wrw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_WPR), 0x53);

	if(Alarm == RTC_ALARM_A){
		/*
		 *  ALARM-A割込みイネーブル解除
		 */
		sil_andw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_CR), RTC_CR_ALRAE);
		sil_andw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_CR), RTC_CR_ALRAIE);
		while((sil_rew_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_ISR)) & RTC_ISR_ALRAWF) == 0){
			if(tick > (RTC_TIMEOUT_VALUE/1000)){
			    /* プロテクション設定 */
				sil_wrw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_WPR), 0xFF);
				return E_TMOUT;
			}
			dly_tsk(1);
			tick++;
		}
		rtcalarmA_callback = NULL;
	}
#if defined(TOFF_RTC_ALRMBR)
	else{
		/*
		 *  ALARM-B割込みイネーブル解除
		 */
		sil_andw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_CR), RTC_CR_ALRBE);
		sil_andw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_CR), RTC_CR_ALRBIE);
		while((sil_rew_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_ISR)) & RTC_ISR_ALRBWF) == 0){
			if( tick > RTC_TIMEOUT_VALUE){
			    /* プロテクション設定 */
				sil_wrw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_WPR), 0xFF);
				return E_TMOUT;
			}
			dly_tsk(1);
			tick++;
		}
		rtcalarmB_callback = NULL;
	}
#endif
    /* プロテクション設定 */
	sil_wrw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_WPR), 0xFF);
	SVC_PERROR(sig_sem(RTCSEM));
	return E_OK; 
}

/*
 *  RTCアラーム設定値取得
 *  parameter1 : parm: Pointer to Alarm structure
 *  parameter2 : ptm: Pointer to struct tm2
 *  return ERコード
 */
ER
rtc_getalarm(RTC_Alarm_t *parm, struct tm2 *ptm, uint32_t Alarm)
{
	uint32_t tmparm = 0;
	uint32_t subsecond = 0;

	if(parm == NULL || ptm == NULL)
		return E_PAR;
	if(rtcerrorcode != 0)
		return E_SYS;

	SVC_PERROR(wai_sem(RTCSEM));
	if(Alarm == RTC_ALARM_A){
		/*
		  ALARM-A レジスタ取得
		 */
		parm->alarm = RTC_ALARM_A;
		tmparm = sil_rew_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_ALRMAR));
		subsecond = sil_rew_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_ALRMASSR)) & RTC_ALRMASSR_SS;
	}
#if defined(TOFF_RTC_ALRMBR)
	else{
		/*
		  ALARM-B レジスタ取得
		 */
		parm->alarm = RTC_ALARM_B;
		tmparm = sil_rew_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_ALRMBR));
		subsecond = sil_rew_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_ALRMBSSR)) & RTC_ALRMBSSR_SS;
	}
#endif

	/*
	 *  レジスタからパラメータに変換
	 */
	ptm->tm_hour = bcd2byte((uint8_t)((tmparm & (RTC_ALRMAR_HT | RTC_ALRMAR_HU)) >> 16));
	ptm->tm_min  = bcd2byte((uint8_t)((tmparm & (RTC_ALRMAR_MNT | RTC_ALRMAR_MNU)) >> 8));
	ptm->tm_sec = bcd2byte((uint8_t)(tmparm & (RTC_ALRMAR_ST | RTC_ALRMAR_SU)));
	parm->subsecond = (uint32_t) subsecond;
	parm->dayselect = (uint32_t)(tmparm & RTC_ALRMAR_WDSEL);
	if(parm->dayselect == ALARMDAYSEL_DATE)
		ptm->tm_mday = bcd2byte((uint8_t)((tmparm & (RTC_ALRMAR_DT | RTC_ALRMAR_DU)) >> 24));
	else
		ptm->tm_wday = bcd2byte((uint8_t)((tmparm & (RTC_ALRMAR_DT | RTC_ALRMAR_DU)) >> 24));

	parm->alarmmask = (uint32_t)(tmparm & ALARMMASK_ALL);
	SVC_PERROR(sig_sem(RTCSEM));
	return E_OK;
}

/*
 *  RTC割込みハンドラ
 */
void rtc_handler(void)
{
	uint32_t tmp;

	if((sil_rew_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_ISR)) & RTC_CR_ALRAE) != 0){
		/*
		 * ALARM-A割込み確認
		 */
		if((sil_rew_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_CR)) & RTC_CR_ALRAIE) != 0){
			/*
			 *  ALARM-Aコールバック
			 */
			if(rtcalarmA_callback != NULL)
				rtcalarmA_callback();
			/*
			 *  ALARM-A割込みクリア
			 */
			tmp = sil_rew_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_ISR)) & RTC_ISR_INIT;
			sil_wrw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_ISR), (~(RTC_ISR_ALRAF | RTC_ISR_INIT) | tmp));
		}
	}
#if defined (RTC_CR_ALRBE)
	if((sil_rew_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_ISR)) & RTC_CR_ALRBE) != 0){
		/*
		 * ALARM-B割込み確認
		 */
		if((sil_rew_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_CR)) & RTC_CR_ALRBIE) != 0){
			/*
			 *  ALARM-Bコールバック
			 */
			if(rtcalarmB_callback != NULL)
				rtcalarmB_callback();
			/*
			 *  ALARM-B割込みクリア
			 */
			tmp = sil_rew_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_ISR)) & RTC_ISR_INIT;
			sil_wrw_mem((uint32_t *)(TADR_RTC_BASE+TOFF_RTC_ISR), (~(RTC_ISR_ALRBF | RTC_ISR_INIT) | tmp));
		}
	}
#endif
	/*
	 *  EXTI RTCペンディングクリア
	 */
	sil_wrw_mem((uint32_t *)(TADR_EXTI_BASE+TOFF_EXTI_PR1), EXTI_PR_PR18);
}

