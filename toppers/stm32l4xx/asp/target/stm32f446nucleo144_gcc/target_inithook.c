/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2008-2011 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2016      by 3rd Designing Center
 *              Imageing System Development Division RICOH COMPANY, LTD.
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
 *  @(#) $Id: target_inithook.c 698 2016-06-14 13:48:08Z roi $
 */

#include <sil.h>
#include "stm32f4xx.h"

/*
 *  初期化プログラム（stm32f446-nucleo144用）
 */

#define HSE_STARTUP_TIMEOUT          0x0500		/* HSE用タイムアウト設定値 */
#define PWR_OVERDRIVE_TIMEOUT_VALUE  1000

/*
 *  PLL設定値
 */
#define PLL_M      8
#define PLL_N      360
#define PLL_P      2
#define PLL_Q      7
#define PLL_R      2

#define PWR_REGULATOR_VOLTAGE_SCALE1   PWR_CR_VOS				/* VOLTAGEスケール1:168MHz、オーバードライブ時180MHz */
#define PWR_REGULATOR_VOLTAGE_SCALE2   PWR_CR_VOS_1				/* VOLTAGEスケール2:144MHz、オーバードライブ時168MHz */
#define PWR_REGULATOR_VOLTAGE_SCALE3   PWR_CR_VOS_0				/* VOLTAGEスケール3:120MHz. */

#define RCC_CFGR_SW        (RCC_CFGR_SW_0 | RCC_CFGR_SW_1)
#define RCC_CFGR_SWS       (RCC_CFGR_SWS_0 | RCC_CFGR_SWS_1)
#define RCC_CFGR_HPRE      (RCC_CFGR_HPRE_0 | RCC_CFGR_HPRE_1 | RCC_CFGR_HPRE_2 | RCC_CFGR_HPRE_3)
#define RCC_CFGR_PPRE1     (RCC_CFGR_PPRE1_0 | RCC_CFGR_PPRE1_1 | RCC_CFGR_PPRE1_2)
#define RCC_CFGR_PPRE2     (RCC_CFGR_PPRE2_0 | RCC_CFGR_PPRE2_1 | RCC_CFGR_PPRE2_2)
#define RCC_PLLCFGR_PLLM   (RCC_PLLCFGR_PLLM_0 | RCC_PLLCFGR_PLLM_1 | RCC_PLLCFGR_PLLM_2 \
                           | RCC_PLLCFGR_PLLM_3 | RCC_PLLCFGR_PLLM_4 | RCC_PLLCFGR_PLLM_5)
#define RCC_PLLCFGR_PLLN   (RCC_PLLCFGR_PLLN_0 | RCC_PLLCFGR_PLLN_1 | RCC_PLLCFGR_PLLN_2 | RCC_PLLCFGR_PLLN_3 \
                           | RCC_PLLCFGR_PLLN_4 | RCC_PLLCFGR_PLLN_5 | RCC_PLLCFGR_PLLN_6 | RCC_PLLCFGR_PLLN_7 | RCC_PLLCFGR_PLLN_8)
#define RCC_PLLCFGR_PLLP   (RCC_PLLCFGR_PLLP_0 | RCC_PLLCFGR_PLLP_1)
#define RCC_PLLCFGR_PLLSRC (RCC_PLLCFGR_PLLSRC_HSE)
#define RCC_CR_HSITRIM     (RCC_CR_HSITRIM_0 | RCC_CR_HSITRIM_1 | RCC_CR_HSITRIM_2 | RCC_CR_HSITRIM_3 | RCC_CR_HSITRIM_4)
#define FLASH_ACR_LATENCY  (FLASH_ACR_LATENCY_0WS | FLASH_ACR_LATENCY_1WS | FLASH_ACR_LATENCY_2WS | FLASH_ACR_LATENCY_3WS \
                           | FLASH_ACR_LATENCY_4WS | FLASH_ACR_LATENCY_5WS | FLASH_ACR_LATENCY_6WS | FLASH_ACR_LATENCY_7WS)

/*
 *  RCC_BitAddress_AliasRegion RCC BitAddress AliasRegion
 *  RCC registers bit address in the alias region
 */
#define RCC_OFFSET               (TADR_RCC_BASE - PERIPH_BASE)
/* Alias word address of HSION bit */
#define RCC_CR_OFFSET            (RCC_OFFSET + 0x00)
#define RCC_HSION_BIT_NUMBER     0x00
#define RCC_CR_HSION_BB          (PERIPH_BB_BASE + (RCC_CR_OFFSET * 32) + (RCC_HSION_BIT_NUMBER * 4))
/* Alias word address of PLLON bit */
#define RCC_PLLON_BIT_NUMBER     0x18
#define RCC_CR_PLLON_BB          (PERIPH_BB_BASE + (RCC_CR_OFFSET * 32) + (RCC_PLLON_BIT_NUMBER * 4))

#define RCC_PLLSAION_BIT_NUMBER  0x1C
#define RCC_CR_PLLSAION_BB       (PERIPH_BB_BASE + (RCC_CR_OFFSET * 32) + (RCC_PLLSAION_BIT_NUMBER * 4))

/*
 *  ACR register byte 0 (Bits[7:0]) base address
 */
#define ACR_BYTE0_ADDRESS        (0x40023C00)
/*
 *  CR register byte 3 (Bits[23:16]) base address
 */
#define RCC_CR_BYTE2_ADDRESS     (0x40023802)

#define RCC_HSE_BYPASS           0x05

#define PWR_OFFSET               (TADR_PWR_BASE - PERIPH_BASE)
#define PWR_CR_OFFSET            0x00
#define PWR_CSR_OFFSET           0x04
#define PWR_CR_OFFSET_BB         (PWR_OFFSET + PWR_CR_OFFSET)
#define PWR_CSR_OFFSET_BB        (PWR_OFFSET + PWR_CSR_OFFSET)

#define ODEN_BIT_NUMBER          16
#define CR_ODEN_BB               (unsigned int)(PERIPH_BB_BASE + (PWR_CR_OFFSET_BB * 32) + (ODEN_BIT_NUMBER * 4))

#define ODSWEN_BIT_NUMBER        17
#define CR_ODSWEN_BB             (unsigned int)(PERIPH_BB_BASE + (PWR_CR_OFFSET_BB * 32) + (ODSWEN_BIT_NUMBER * 4))

#define RCC_CLK48CLKSOURCE_PLLQ    0x00000000
#define RCC_CLK48CLKSOURCE_PLLSAIP RCC_DCKCFGR2_CK48MSEL

#define PLL_TIMEOUT_VALUE          1000		/* 100 ms */
#define PLLSAI_TIMEOUT_VALUE       20		/* 2ms */
#define CLOCKSWITCH_TIMEOUT_VALUE  50000	/* 5 s */

#define sil_mdw_mem(addr, mask, val)	sil_wrw_mem((addr), ((sil_rew_mem(addr) & ~(mask)) | (val)))
#define sil_anw_mem(addr, mask)			sil_wrw_mem((addr), (sil_rew_mem(addr) & ~(mask)))
#define sil_orw_mem(addr, val)			sil_wrw_mem((addr), (sil_rew_mem(addr) | (val)))

/*
 *  USB CLOCK CONFIGURATION
 */
ER USB_RCC_PeriphCLKConfig(uint32_t pllsaim, uint32_t pllsan, uint32_t pllsaip)
{
	uint32_t tickstart = 0U;
	uint32_t pllsaiq = 0U;

    /*
	 * クロック48ソース設定
	 */
	sil_mdw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_DCKCFGR2), RCC_DCKCFGR2_CK48MSEL, RCC_CLK48CLKSOURCE_PLLSAIP);

    /*
	 *  PLLSAIクロックを停止
	 */
	sil_wrw_mem((uint32_t *)RCC_CR_PLLSAION_BB, 0);

	tickstart = 0;
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_PLLSAIRDY) != 0){
		if(tickstart  > (PLLSAI_TIMEOUT_VALUE*100)){
			return E_TMOUT;
		}
		sil_dly_nse(1000);
		tickstart++;
	}

    /*
	 *  PLLSAIクロック設定
	 */
	pllsaiq = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLLSAICFGR)) & RCC_PLLSAICFGR_PLLSAIQ;
	/* Configure the PLLSAI division factors */
	/* PLLSAI_VCO = f(VCO clock) = f(PLLSAI clock input) * (PLLI2SN/PLLSAIM) */
	/* 48CLK = f(PLLSAI clock output) = f(VCO clock) / PLLSAIP */
	pllsaiq |= (pllsaim | (pllsan << 6)  | (((pllsaip >> 1) -1) << 16));
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLLSAICFGR), pllsaiq);

    /*
	 *  PLLSAIクロックを再開
	 */
	sil_wrw_mem((uint32_t *)RCC_CR_PLLSAION_BB, 1);

	tickstart = 0;
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & (RCC_CR_PLLSAIRDY)) == 0){
		if( tickstart > (PLLSAI_TIMEOUT_VALUE*100)){
			return E_TMOUT;
		}
		sil_dly_nse(1000);
		tickstart++;
	}
	return E_OK;
}

/*
 *  システムクロックコンフィギュレーション
 */
ER sysclock_config(int mode)
{
	unsigned int tickstart = 0;
	unsigned int tmp;

 	/*
	 *  パワークロック有効化
	 */
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_APB1ENR), RCC_APB1ENR_PWREN);
	tmp = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_APB1ENR));

	/*
	 *  VOLTAGE設定
	 */
	sil_mdw_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR), (PWR_CR_VOS), PWR_REGULATOR_VOLTAGE_SCALE1);
	tmp = sil_rew_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CR));

	/*
	 *  HSE初期設定
	 */
	sil_wrb_mem((uint8_t *)RCC_CR_BYTE2_ADDRESS, RCC_HSE_BYPASS);

	/*
	 *  HSEレディ待ち
	 */
	while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_HSERDY) == 0){
		if(tickstart > HSE_STARTUP_TIMEOUT){
			return E_TMOUT;
		}
		tickstart++;
		sil_dly_nse(1000*100);
	}

    /*
	 *  スイッチセレクトがPLLでない場合、PLLを停止して再設定
	 */
	if((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR)) & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL){
        /*
	　　 *  PLL停止
		 */
		sil_wrw_mem((uint32_t *)(RCC_CR_PLLON_BB), 0);

        /*
		 *  PLL停止待ち
		 */
        tickstart = 0;
        while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_PLLRDY) != 0){
			tickstart++;
			sil_dly_nse(100*1000);
			if(tickstart > PLL_TIMEOUT_VALUE){
				return E_TMOUT;
			}
        }

        /*
		 *  PLL設定
		 */
		sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLLCFGR), PLL_M | (PLL_N << 6) | (((PLL_P >> 1) -1) << 16) |
                   (RCC_PLLCFGR_PLLSRC_HSE) | (PLL_Q << 24) | (PLL_R << 28));
        /*
		 *  PLL再開
		 */
		sil_wrw_mem((uint32_t *)(RCC_CR_PLLON_BB), 1);

        /*
		 *  PLL開始待ち
		 */
		tickstart = 0;
        while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_PLLRDY) == 0){
			tickstart++;
			sil_dly_nse(100*1000);
			if( tickstart  > PLL_TIMEOUT_VALUE){
				return E_TMOUT;
			}
		}
	}

	/*
	 *  オーバードライブ用クロック開始
	 */
	sil_wrw_mem((uint32_t *)(CR_ODEN_BB), 1);

	tickstart = 0;
	while((sil_rew_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CSR)) & PWR_CSR_ODRDY) == 0){
		tickstart++;
		sil_dly_nse(100*1000);
		if( tickstart  > PWR_OVERDRIVE_TIMEOUT_VALUE){
			return E_TMOUT;
		}
	}

	/*
	 *  オーバードライブ設定
	 */
	sil_wrw_mem((uint32_t *)(CR_ODSWEN_BB), 1);

	tickstart = 0;
	while((sil_rew_mem((uint32_t *)(TADR_PWR_BASE+TOFF_PWR_CSR)) & PWR_CSR_ODSWRDY) == 0){
		tickstart++;
		sil_dly_nse(100*1000);
		if( tickstart > PWR_OVERDRIVE_TIMEOUT_VALUE){
			return E_TMOUT;
		}
	}

	/*
	 *  USBのクロック設定
	 */
	USB_RCC_PeriphCLKConfig(8, 384, 8);

	/*
	 *  FLASH設定を5WSに設定
	 */
	sil_wrb_mem((uint8_t *)ACR_BYTE0_ADDRESS, FLASH_ACR_LATENCY_5WS);

	/*
	 *  FLASH設定が反映されなければエラー終了
	 */
    if((sil_rew_mem((uint32_t *)(TADR_FLASH_R_BASE+TOFF_FLASH_ACR)) & FLASH_ACR_LATENCY) != FLASH_ACR_LATENCY_5WS){
      return E_SYS;
    }

    /*
	 *  HCLKのクロック設定
	 */
	sil_mdw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR), (RCC_CFGR_HPRE), RCC_CFGR_HPRE_DIV1);

	/*
	 *  PLLがREADYにならなければエラー
	 */
	if((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_PLLRDY) == 0){
		return E_SYS;
	}

	sil_mdw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR), (RCC_CFGR_SW), RCC_CFGR_SW_PLL);

    /*
	 *  スイッチセレクトがPLLになるまで待ち
	 */
	tickstart = 0;
	while ((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR)) & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL){
		tickstart++;
		sil_dly_nse(100*1000);
		if( tickstart > CLOCKSWITCH_TIMEOUT_VALUE){
            return E_TMOUT;
		}
	}

	/*
	 *  PCLK1のコンフィギュレーション
	 */
	sil_mdw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR), (RCC_CFGR_PPRE1), RCC_CFGR_PPRE1_DIV4);

	/*
	 *  PCLK2のコンフィギュレーション
	 */
	sil_mdw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR), (RCC_CFGR_PPRE2), (RCC_CFGR_PPRE1_DIV2 << 3));
	return E_OK;
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
	sil_orw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_HSION);
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR), 0x00000000);
	sil_anw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), (RCC_CR_PLLON | RCC_CR_CSSON | RCC_CR_HSEON));
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLLCFGR), RCC_CFGR_MCO2PRE_2 | RCC_CFGR_MCO1PRE_2
					 | RCC_CFGR_PPRE2_0 | RCC_CFGR_PPRE1_DIV2 | RCC_CFGR_HPRE_0);

	/* Reset HSEBYP bit */
	sil_anw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), RCC_CR_HSEBYP);

	/*
	 *  全割込み禁止
	 */
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CIR), 0x00000000);

	sysclock_config(0);
}
#endif

