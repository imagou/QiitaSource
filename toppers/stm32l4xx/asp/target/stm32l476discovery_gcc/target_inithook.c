/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2008-2011 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2016-2016 by 3rd Designing Center
 *              Imageing System Development Division RICOH COMPANY, LTD.
 *  Copyright (C) 2017-2018 by TOPPERS PROJECT Educational Working Group.
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
 *  @(#) $Id: target_inithook.c 698 2018-08-28 10:09:46Z roi $
 */

#include <sil.h>
#include "_renamed_stm32l4xx.h"

/*
 *  初期化プログラム（stm32l476-discovery用）
 */

#define sil_modw_mem(addr, mask, val)	sil_wrw_mem((addr), ((sil_rew_mem(addr) & ~(mask)) | (val)))
#define sil_andw_mem(addr, mask)		sil_wrw_mem((addr), (sil_rew_mem(addr) & ~(mask)))
#define sil_orw_mem(addr, val)			sil_wrw_mem((addr), (sil_rew_mem(addr) | (val)))


#define HSI_TIMEOUT_VALUE          (2000U)      /* 2 ms (minimum Tick + 1U) */
#define PLL_TIMEOUT_VALUE          (2000U)      /* 2 ms (minimum Tick + 1U) */
#define MSI_TIMEOUT_VALUE          (2000U)      /* 2 ms (minimum Tick + 1U) */
#define LSE_TIMEOUT_VALUE          (5000*1000)
#define DBP_TIMEOUT_VALUE          (100*1000)
#define PWR_FLAG_TIMEOUT_VALUE     (50)			/* 50micro sec */
#define CLOCKSWITCH_TIMEOUT_VALUE  (5000000U)	/* 5 s    */

#define RCC_MSIRANGE               RCC_CR_MSIRANGE_11
#define MAX_MSIRANGE               12

#if !defined(MSI_RANGE)
#define MSI_RANGE                  0
#endif

#if !defined(HSE_VALUE)
#define HSE_VALUE                  8000000  /* Value of the External oscillator in Hz */
#endif /* HSE_VALUE */
#if !defined(HSI_VALUE)
#define HSI_VALUE                  16000000	/* Value of the Internal oscillator in Hz*/
#endif /* HSI_VALUE */

/* PLL_VCO = (HSE_VALUE or HSI_VALUE / PLL_M) * PLL_N */
#define PLL_M      6
#define PLL_N      40

/* SYSCLK = PLL_VCO / PLL_P */
#define PLL_P      7

/* USB OTG FS, SDIO and RNG Clock =  PLL_VCO / PLLQ */
#define PLL_Q      4

/* I2SCLK =  PLLVCO / PLLR */                          
#define PLL_R      4	/* Possible value between 2 and 7 */

#define RCC_MSICALIBRATION_DEFAULT     0		/* Default MSI calibration trimming value */

#define RCC_USBCLKSOURCE_MSI           RCC_CCIPR_CLK48SEL


/*
 *  VOLTAGE SCALEの定義
 */
#define PWR_REGULATOR_VOLTAGE_SCALE1   PWR_CR1_VOS_0     /* Voltage scaling range 1 */
#define PWR_REGULATOR_VOLTAGE_SCALE2   PWR_CR1_VOS_1     /* Voltage scaling range 2 */


/*
 *  MSIRANGE対応クロックテーブル
 */
static const uint32_t MSIRangeTable[MAX_MSIRANGE] = {100000, 200000, 400000, 800000, 1000000, 2000000, \
                                      4000000, 8000000, 16000000, 24000000, 32000000, 48000000};

uint32_t SystemFrequency;


/*
 *  VOLTAGE SCALE設定
 *  param    VoltageScaling
 *           This parameter can be one of the following values:
 *            @arg @ref PWR_REGULATOR_VOLTAGE_SCALE1 Regulator voltage output range 1 mode,
 *                                                typical output voltage at 1.2 V,
 *                                                system frequency up to 80 MHz.
 *            @arg @ref PWR_REGULATOR_VOLTAGE_SCALE2 Regulator voltage output range 2 mode,
 *                                                typical output voltage at 1.0 V,
 *                                                system frequency up to 26 MHz.
 *  return  正常終了ならE_OKを返す
 */
static ER
PWRE_ControlVoltageScaling(uint32_t VoltageScaling)
{
	uint32_t tick = 0;
	uint32_t tmp;

	if(VoltageScaling != PWR_REGULATOR_VOLTAGE_SCALE1 && VoltageScaling != PWR_REGULATOR_VOLTAGE_SCALE2)
		return E_PAR;

	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_APB1ENR1), RCC_APB1ENR1_PWREN);
	tmp = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_APB1ENR1));
	(void)(tmp);

	if(VoltageScaling == PWR_REGULATOR_VOLTAGE_SCALE1){	/* SCALE1設定 */
		if((sil_rew_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR1)) & PWR_CR1_VOS) != PWR_REGULATOR_VOLTAGE_SCALE1){
			sil_modw_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR1), PWR_CR1_VOS, PWR_REGULATOR_VOLTAGE_SCALE1);

			/*
			 *  VOSFがクリアされるまで待ち
			 */
			while((sil_rew_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_SR2)) & PWR_SR2_VOSF) != 0){
				if(tick > PWR_FLAG_TIMEOUT_VALUE)
					return E_TMOUT;
				tick++;
				sil_dly_nse(1000);
			}
		}

		/*
		 * LOW POWERモードをリセット
		 */
		sil_andw_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR1), PWR_CR1_LPR);

		/*
		 *  REGLPFがクリアされるまで待ち
		 */
		tick = 0;
		while((sil_rew_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_SR2)) & PWR_SR2_REGLPF) != 0){
			if(tick > PWR_FLAG_TIMEOUT_VALUE)
				return E_TMOUT;
			tick++;
			sil_dly_nse(1000);
		}
	}
	else{		/* SCALE2設定 */
		if((sil_rew_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR1)) & PWR_CR1_VOS) != PWR_REGULATOR_VOLTAGE_SCALE2){
			sil_modw_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR1), PWR_CR1_VOS, PWR_REGULATOR_VOLTAGE_SCALE1);
		}

		/*
		 * LOW POWERモードをセット
		 */
		sil_orw_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR1), PWR_CR1_LPR);
	}
	sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_APB1ENR1), RCC_APB1ENR1_PWREN);
	return E_OK;
}

/*
 *  MSIRANGEに合わせて適切なFLASH LATENCYを設定する
 *  param   msirange MSIRANG値
 *  return  正常終了ならE_OKを返す
 */
static ER
RCC_SetFlashLatencyFromMSIRange(unsigned int msirange)
{
	uint32_t vos = 0;
	uint32_t latency = FLASH_ACR_LATENCY_0WS;	/* default value 0WS */
	uint32_t sysclk  = MSIRangeTable[(msirange >> 4)];

	if((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_APB1ENR1)) & RCC_APB1ENR1_PWREN) != 0){
		vos = sil_rew_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR1)) & PWR_CR1_VOS;
	}
	else{
		sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_APB1ENR1), RCC_APB1ENR1_PWREN);
		vos = sil_rew_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR1)) & PWR_CR1_VOS;
		sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_APB1ENR1), RCC_APB1ENR1_PWREN);
	}

	if(vos == PWR_CR1_VOS_0){		/* VOLTAGE_SCALE1 */
	    if(sysclk > 16000000){		/* 16MHzより大 */
			if(sysclk > 32000000)	/* 32MHzより大 */
				latency = FLASH_ACR_LATENCY_2WS; /* 2WS */
			else					/* 24MHzまたは 32MHz */
				latency = FLASH_ACR_LATENCY_1WS; /* 1WS */
		}
		/* その他は 0WS */
	}
	else{							/* VOLTAGE_SCALE2 */
		if(sysclk > 16000000)		/* 16MHzより大 */
			latency = FLASH_ACR_LATENCY_3WS; /* 3WS */
		else{
			if(sysclk == 16000000)	/* 16MHz */
				latency = FLASH_ACR_LATENCY_2WS; /* 2WS */
			else if(sysclk == 8000000)	/* 8MHz */
				latency = FLASH_ACR_LATENCY_1WS; /* 1WS */
			/* その他は 0WS */
		}
	}
	/*
	 *  FLASH LATENCY設定
	 */
	sil_modw_mem((uint32_t *)(TADR_FLASH_R_BASE+TOFF_FLASH_ACR), FLASH_ACR_LATENCY, latency);

	/*
	 *  FLASH LATENCY設定確認
	 */
	if((sil_rew_mem((uint32_t *)(TADR_FLASH_R_BASE+TOFF_FLASH_ACR)) & FLASH_ACR_LATENCY) != latency)
		return E_SYS;
	return E_OK;
}

/*
 *  最大システムクロック設定
 *  設定値は以下の通り
 *      System Clock source            = PLL (MSI)
 *      SYSCLK(Hz)                     = 80000000
 *      HCLK(Hz)                       = 80000000
 *      AHB Prescaler                  = 1
 *      APB1 Prescaler                 = 1
 *      APB2 Prescaler                 = 1
 *      MSI Frequency(Hz)              = 4000000
 *      PLL_M                          = 6
 *      PLL_N                          = 40
 *      PLL_R                          = 2
 *      PLL_P                          = 7
 *      PLL_Q                          = 4
 *      Flash Latency(WS)              = 4
 *  return  正常終了ならE_OKを返す
 */
static ER
SystemClock_Config(void)
{
	ER       ercd;
	uint32_t msi_range = 0;
	bool_t   pwrclkchanged = false;
	uint32_t tick = 0;

	if((ercd = PWRE_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1)) != E_OK)
		return ercd;


	if((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_APB1ENR1)) & RCC_APB1ENR1_PWREN) == 0){
		sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_APB1ENR1), RCC_APB1ENR1_PWREN);
		pwrclkchanged = 1;
	}

	/*
	 *  LSE ENABLE
	 */
	if((sil_rew_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR1)) & PWR_CR1_DBP) == 0){
		sil_orw_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR1), PWR_CR1_DBP);
		while((sil_rew_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR1)) & PWR_CR1_DBP) == 0){
			if(tick > DBP_TIMEOUT_VALUE)
				return E_TMOUT;
			tick++;
			sil_dly_nse(1000);
		}
	}

	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_BDCR), RCC_BDCR_LSEON);
	tick = 0;
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_BDCR)) & RCC_BDCR_LSERDY) == 0){
		if(tick > LSE_TIMEOUT_VALUE)
			return E_TMOUT;
		tick++;
		sil_dly_nse(1000);
    }

	if(pwrclkchanged)
		sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_APB1ENR1), RCC_APB1ENR1_PWREN);

	/*
	 * Disable the LSE Clock Security System.
	 */
	sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_BDCR), RCC_BDCR_LSECSSON);
	sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CIER), RCC_CIFR_LSECSSF);

	/*
	 *  MSI設定
	 */
    if((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR)) & RCC_CFGR_SWS) == RCC_CFGR_SWS_MSI){
		/*
		 *  MSIをシステムクロックとして使用時、MSIのレンジを取出しRCC_MSIRANGEに設定しなおす
		 */
		if((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_MSIRGSEL) != 0)
			msi_range = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_MSIRANGE;
		else
			msi_range = (sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CSR)) & RCC_CSR_MSISRANGE) >> 4;
		if(RCC_MSIRANGE > msi_range){
			/*
			 *  現状より高い場合、FLASH LATENCYを再設定
			 */
			if(RCC_SetFlashLatencyFromMSIRange(RCC_MSIRANGE) != E_OK){
				return E_TMOUT;
			}

			/*
			 *  RCC_MSIRANGEに再設定
			 */
			sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_MSIRGSEL);
			sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_MSIRANGE, RCC_MSIRANGE);
			sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_ICSCR), RCC_ICSCR_MSITRIM, RCC_MSICALIBRATION_DEFAULT << 8);
		}
		else{
			/*
			 *  現状より低い場合、先にRCC_MSIRANGEに再設定
			 */
			sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_MSIRGSEL);
			sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_MSIRANGE, RCC_MSIRANGE);
			sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_ICSCR), RCC_ICSCR_MSITRIM, RCC_MSICALIBRATION_DEFAULT << 8);

			/*
			 *  FLASH LATENCYを再設定
			 */
			if(RCC_SetFlashLatencyFromMSIRange(RCC_MSIRANGE) != E_OK){
				return E_TMOUT;
			}
		}
    }
    else{
		/*
		 *  MSIがSYSCLKでない場合、起動
		 */
		sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_MSION);

        /*
		 *  MSI READY待ち
		 */
		tick = 0;
        while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_MSIRDY) == 0){
			if(tick > MSI_TIMEOUT_VALUE){
				return E_TMOUT;
			}
			tick++;
			sil_dly_nse(1000);
		}

		/*
		 *  RCC_MSIRANGE設定
		 */
		sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_MSIRGSEL);
		sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_MSIRANGE, RCC_MSIRANGE);
		sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_ICSCR), RCC_ICSCR_MSITRIM, RCC_MSICALIBRATION_DEFAULT << 8);
	}

	/*
	 *  Enable MSI Auto-calibration through LSE
	 */
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_MSIPLLEN);

	/*
	 *  Select MSI output as USB clock source
	 */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CCIPR), RCC_CCIPR_CLK48SEL, RCC_USBCLKSOURCE_MSI);

    /*
	 *  PLL設定
	 */
    if((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR)) & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL){
		/*
		 *  PLLがSYSCLKでない場合、PLL停止
		 */
		sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_PLLON);

		/*
		 *  PLL停止待ち
		 */
		tick = 0;
		while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_PLLRDY) != 0){
			if(tick > PLL_TIMEOUT_VALUE){
				return E_TMOUT;
			}
			tick++;
			sil_dly_nse(1000);
 		}

		/*
		 *  PLLクロック設定
		 */
		sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLLCFGR), ((PLL_M - 1) << 4) | (PLL_N << 8) | ((PLL_P >> 4) << 17) | \
                   RCC_PLLCFGR_PLLSRC_MSI | (((PLL_Q >> 1) - 1) << 21) | (((PLL_R >> 1) - 1) << 25));

		/*
		 *  PLL再起動
		 */
		sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_PLLON);

		/*
		 *  PLL システムクロック出力
		 */
		sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLLCFGR), RCC_PLLCFGR_PLLREN);

		/*
		 *  PLL READY待ち
		 */
        tick = 0;
		while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_PLLRDY) == 0){
			if(tick > PLL_TIMEOUT_VALUE){
				return E_TMOUT;
			}
			tick++;
			sil_dly_nse(1000);
		}
	}
	else
		return E_SYS;

	/*
	 *  要求のFLASH LATENCYが現状より高い場合、先にFLASHのLATENCY設定を行う
	 */
	if(FLASH_ACR_LATENCY_4WS > (sil_rew_mem((uint32_t *)(TADR_FLASH_R_BASE+TOFF_FLASH_ACR)) & FLASH_ACR_LATENCY)){
		/*
		 *  LATENCYを設定し、設定確認
		 */
		sil_modw_mem((uint32_t *)(TADR_FLASH_R_BASE+TOFF_FLASH_ACR), FLASH_ACR_LATENCY, FLASH_ACR_LATENCY_4WS);
		if((sil_rew_mem((uint32_t *)(TADR_FLASH_R_BASE+TOFF_FLASH_ACR)) & FLASH_ACR_LATENCY) != FLASH_ACR_LATENCY_4WS){
			return E_SYS;
		}
	}

	/*
	 *  HCLKの分周値設定
	 */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR), RCC_CFGR_HPRE, RCC_CFGR_HPRE_DIV1);

	/*
	 *  SYSCLKをPLLに変更後、設定確認
	 */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR), RCC_CFGR_SW, RCC_CFGR_SW_PLL);

	tick = 0;
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR)) & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL){
		if(tick > CLOCKSWITCH_TIMEOUT_VALUE){
			return E_TMOUT;
		}
		tick++;
		sil_dly_nse(1000);
	}

	/*
	 *  要求のFLASH LATENCYが現状より低い場合、後でFLASHのLATENCY設定を行う
	 */
	if(FLASH_ACR_LATENCY_4WS < (sil_rew_mem((uint32_t *)(TADR_FLASH_R_BASE+TOFF_FLASH_ACR)) & FLASH_ACR_LATENCY)){
		/*
		 *  LATENCYを設定し、設定確認
		 */
		sil_modw_mem((uint32_t *)(TADR_FLASH_R_BASE+TOFF_FLASH_ACR), FLASH_ACR_LATENCY, FLASH_ACR_LATENCY_4WS);
		if((sil_rew_mem((uint32_t *)(TADR_FLASH_R_BASE+TOFF_FLASH_ACR)) & FLASH_ACR_LATENCY) != FLASH_ACR_LATENCY_4WS){
			return E_SYS;
		}
	}
	SystemFrequency = 80000000;

	/*
	 *  PCLK1の分周値を設定
	 */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR), RCC_CFGR_PPRE1, RCC_CFGR_PPRE1_DIV1);

	/*
	 *  PCLK2の分周値を設定
	 */
	sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR), RCC_CFGR_PPRE2, RCC_CFGR_PPRE2_DIV1);
	return E_OK;
}

/*
 *  MSI設定によるクロック設定
 *  設定値は以下の通り
 *      System Clock source            = MSI
 *      SYSCLK(Hz)                     = msirangeのクロック値
 *      HCLK(Hz)                       = msirangeのクロック値
 *      AHB Prescaler                  = 1(停止)
 *      APB1 Prescaler                 = 1(停止)
 *      APB2 Prescaler                 = 1(停止)
 *      MSI Frequency(Hz)              = msirangeのクロック値
 *      PLL_M                          = 1
 *      PLL_N                          = 80
 *      PLL_R                          = 2
 *      PLL_P                          = 7
 *      PLL_Q                          = 4
 *      Flash Latency(WS)              = msirangeに従ったLATENCY
 *  param   msirange
 *  return  正常終了ならE_OKを返す
 */
static ER
SystemLowClock_Config(uint8_t msirange)
{
	uint32_t tick = 0;
	ER ercd = E_OK;

	if(msirange == 0 || msirange >= MAX_MSIRANGE)
		return E_PAR;

	if(MSIRangeTable[msirange] == SystemFrequency)
		return E_OK;

	if((ercd = PWRE_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1)) != E_OK)
		return ercd;

	/*
	 *  MSI設定
	 */
    if((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR)) & RCC_CFGR_SWS) == RCC_CFGR_SWS_MSI){
		uint32_t msi_range;
		/*
		 *  MSIをシステムクロックとして使用時、MSIのレンジを取出しmsirangeに設定しなおす
		 */
		if((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_MSIRGSEL) != 0)
			msi_range = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_MSIRANGE;
		else
			msi_range = (sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CSR)) & RCC_CSR_MSISRANGE) >> 4;
		if((msirange<<4) > msi_range){
			/*
			 *  現状より高い場合、FLASH LATENCYを再設定
			 */
			if(RCC_SetFlashLatencyFromMSIRange((msirange<<4)) != E_OK){
				return E_TMOUT;
			}

			/*
			 *  msirangeに再設定
			 */
			sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_MSIRGSEL);
			sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_MSIRANGE, (msirange<<4));
			sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_ICSCR), RCC_ICSCR_MSITRIM, RCC_MSICALIBRATION_DEFAULT << 8);
		}
		else{
			/*
			 *  現状より低い場合、先にmsirangeに再設定
			 */
			sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_MSIRGSEL);
			sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_MSIRANGE, (msirange<<4));
			sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_ICSCR), RCC_ICSCR_MSITRIM, RCC_MSICALIBRATION_DEFAULT << 8);

			/*
			 *  FLASH LATENCYを再設定
			 */
			if(RCC_SetFlashLatencyFromMSIRange((msirange<<4)) != E_OK){
				return E_TMOUT;
			}
		}
    }
    else{
		/*
		 *  MSIがSYSCLKでない場合、起動
		 */
		sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_MSION);

        /*
		 *  MSI READY待ち
		 */
        while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_MSIRDY) == 0){
			if(tick > MSI_TIMEOUT_VALUE){
				return E_TMOUT;
			}
			tick++;
			sil_dly_nse(1000);
		}

		/*
		 *  msirange設定
		 */
		sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_MSIRGSEL);
		sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_MSIRANGE, (msirange<<4));
		sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_ICSCR), RCC_ICSCR_MSITRIM, RCC_MSICALIBRATION_DEFAULT << 8);

		sil_modw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR), RCC_CFGR_SW, RCC_CFGR_SW_MSI);

		tick = 0;
		while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR)) & RCC_CFGR_SWS) != RCC_CFGR_SWS_MSI){
			if(tick > CLOCKSWITCH_TIMEOUT_VALUE)
				return E_TMOUT;
			tick++;
			sil_dly_nse(1000);
		}
	}

	if((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_PLLON) != 0){
		/*
		 *  PLL停止
		 */
		sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_PLLON);

        /*
		 *  SAIクロック停止設定
		 */
		if((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & (RCC_CR_PLLSAI1RDY | RCC_CR_PLLSAI2RDY)) == 0){
			sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLLCFGR), RCC_PLLCFGR_PLLSRC);
		}

		/*
		 *  PLLP/PLLQ/PLLR停止
		 */
		sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLLCFGR), (RCC_PLLCFGR_PLLPEN | RCC_PLLCFGR_PLLQEN | RCC_PLLCFGR_PLLREN));

        /*
		 *  PLL停止待ち
		 */
		tick = 0;
		while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_PLLRDY) != 0){
			if(tick > PLL_TIMEOUT_VALUE)
				return E_TMOUT;
			tick++;
			sil_dly_nse(1000);
		}
	}
	SystemFrequency = MSIRangeTable[msirange];

	if(SystemFrequency <= 20000000){
		ercd = PWRE_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE2);
	}
	return ercd;
}

/*
 *  起動クロックの取り出し
 */
uint32_t
sysclock_init_value(void)
{
#if MSI_RANGE != 0
	return MSIRangeTable[MSI_RANGE];
#else
	return 80000000;	/* 80 MHz */
#endif
}

/*
 *  システムクロック変更
 */
ER
sysclock_change(uint8_t range)
{
	if(range == 0)
		return SystemClock_Config();
	else
		return SystemLowClock_Config(range);
}

/*
 *  システムクロックコンフィギュレーション
 */
ER
sysclock_config(int mode)
{
	return SystemClock_Config();
}

#ifndef TOPPERS_RAM_EXEC
/*
 *  低レベルのターゲット依存の初期化
 *
 *  スタートアップモジュールの中で，メモリの初期化の前に呼び出される．
 */
void hardware_init_hook(void)
{
	/*
	 * RCCのリセットとコンフィギュレーション
	 */
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_MSION);
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR), 0x00000000);
	sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR),
			 (RCC_CR_PLLSAI2ON | RCC_CR_PLLSAI1ON | RCC_CR_PLLON | RCC_CR_HSEBYP | RCC_CR_HSEON));
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLLCFGR), RCC_PLLCFGR_PLLN_4);

	/* Reset HSEBYP bit */
	sil_andw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_HSEBYP);

	/*
	 *  全割込み禁止
	 */
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CIER), 0x00000000);

	if(sysclock_change(MSI_RANGE) != E_OK){
		while(1){}
	}

	/*
	 *  PCLK設定
	 */
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CCIPR), 0x00000000);
}
#endif

