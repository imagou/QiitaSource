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
 *  @(#) $Id: rtc.h 698 2017-07-27 17:12:38Z roi $
 */
/*
 * 
 * RTC用デバイスドライバ用デバイス操作関数群の外部宣言
 *
 */

#ifndef _RTC_H_
#define _RTC_H_

/*
 *  RTCアラーム定義
 */
#define RTC_ALARM_A     RTC_CR_ALRAE
#define RTC_ALARM_B     RTC_CR_ALRBE

/*
 *  RTC日付、ウィークディ定義
 */
#define ALARMDAYSEL_DATE    0x00000000
#define ALARMDAYSEL_WEEKDAY 0x40000000

/*
 *  RTCマスク定義
 */
#define ALARMMASK_NONE      0x00000000
#define ALARMMASK_DATESEL   RTC_ALRMAR_MSK4
#define ALARMMASK_HOURS     RTC_ALRMAR_MSK3
#define ALARMMASK_MINUTES   RTC_ALRMAR_MSK2
#define ALARMMASK_SECONDS   RTC_ALRMAR_MSK1
#define ALARMMASK_ALL       (RTC_ALRMAR_MSK1 | RTC_ALRMAR_MSK2 | RTC_ALRMAR_MSK3 | RTC_ALRMAR_MSK4)

/*
 *  RTCサブセカンドアラームマッチ定義
 */
#define ALARMSSMASK_ALL     0x00000000	/* All Alarm SS fields are masked. */
#define ALARMSSMASK_SS14_1  0x01000000	/* SS[0]がマッチでアラーム */
#define ALARMSSMASK_SS14_2  0x02000000	/* SS[1:0]がマッチでアラーム */
#define ALARMSSMASK_SS14_3  0x03000000	/* SS[2-0]がマッチでアラーム */
#define ALARMSSMASK_SS14_4  0x04000000	/* SS[3-0]がマッチでアラーム */
#define ALARMSSMASK_SS14_5  0x05000000	/* SS[4-0]がマッチでアラーム */
#define ALARMSSMASK_SS14_6  0x06000000	/* SS[5-0]がマッチでアラーム */
#define ALARMSSMASK_SS14_7  0x07000000	/* SS[6-0]がマッチでアラーム */
#define ALARMSSMASK_SS14_8  0x08000000	/* SS[7-0]がマッチでアラーム */
#define ALARMSSMASK_SS14_9  0x09000000	/* SS[8-0]がマッチでアラーム */
#define ALARMSSMASK_SS14_10 0x0A000000	/* SS[9-0]がマッチでアラーム */
#define ALARMSSMASK_SS14_11 0x0B000000	/* SS[10-0]がマッチでアラーム */
#define ALARMSSMASK_SS14_12 0x0C000000	/* SS[11-0]がマッチでアラーム */
#define ALARMSSMASK_SS14_13 0x0D000000	/* SS[12-0]がマッチでアラーム */
#define ALARMSSMASK_SS14    0x0E000000	/* SS[13-0]がマッチでアラーム */
#define ALARMSSMASK_NONE    0x0F000000	/* SS[14-0]がマッチでアラーム */

#define RTC_ERROR_LSI   0x00000001
#define RTC_ERROR_LSE   0x00000002
#define RTC_ERROR_RTC   0x00000004

#define INHNO_ALARM     IRQ_VECTOR_RTC_WKUP
#define INTNO_ALARM     IRQ_VECTOR_RTC_WKUP

#define INTPRI_ALARM     -1		/* 割込み優先度 */
#define INTATR_ALARM     0		/* 割込み属性 */

/*
 *  日時設定用の構造体を定義
 */
struct tm2 {
  int	tm_sec;			/* 秒 */
  int	tm_min;			/* 分 */
  int	tm_hour;		/* 時 */
  int	tm_mday;		/* 月中の日 */
  int	tm_mon;			/* 月 */
  int	tm_year;		/* 年 */
  int	tm_wday;		/* 曜日 */
  int	tm_yday;		/* 年中の日 */
  int	tm_isdst;
};

/*
 *  RTCアラーム構造体
 */
typedef struct
{
	uint32_t            alarm;				/* アラーム選択 */
	uint32_t            alarmmask;			/* アラームマスク設定 */
	uint32_t            subsecondmask;		/* アラームサブセカンドマスク */
	uint32_t            dayselect;			/* アラーム日付設定 */
	uint32_t            subsecond;			/* アラームサブセカンド */
	void                (*callback)(void);	/* アラームコールバック */
}RTC_Alarm_t;


extern uint32_t rtcerrorcode;

extern void rtc_init(intptr_t exinf);
extern ER rtc_set_time(struct tm2 *pt);
extern ER rtc_get_time(struct tm2 *pt);
extern ER rtc_setalarm(RTC_Alarm_t *parm, struct tm2 *ptm);
extern ER rtc_stopalarm(uint32_t Alarm);
extern ER rtc_getalarm(RTC_Alarm_t *parm, struct tm2 *ptm, uint32_t Alarm);
extern void rtc_handler(void);
extern void rtc_info_init(intptr_t exinf);

#endif

