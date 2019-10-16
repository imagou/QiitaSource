/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2008-2011 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2015      by 3rd Designing Center
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
 *  @(#) $Id: target_inithook.c 698 2015-08-12 18:39:21Z roi $
 */

#include <sil.h>
#include "stm32f4xx.h"

/*
 *  初期化プログラム（stm32f-e407用）
 */

#define HSE_STARTUP_TIMEOUT 0x0500		/* HSE用タイムアウト設定値 */

/*
 *  PLL設定値
 */
#define PLL_M      12
#define PLL_N      240
#define PLL_P      2
#define PLL_Q      5
#define PLL_R      2

#define RCC_CFGR_SW       (RCC_CFGR_SW_0 | RCC_CFGR_SW_1)
#define RCC_CFGR_SWS      (RCC_CFGR_SWS_0 | RCC_CFGR_SWS_1)

/*
 *  低レベルのターゲット依存の初期化
 *
 *  スタートアップモジュールの中で，メモリの初期化の前に呼び出される．
 */
void hardware_init_hook(void)
{
	unsigned int StartUpCounter = 0, HSEStatus = 0;

	/*
	 *  RCCのリセットとコンフィギュレーション
	 */
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) | RCC_CR_HSION);
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR), 0x00000000);
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & ~(RCC_CR_PLLON | RCC_CR_CSSON | RCC_CR_HSEON));
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLLCFGR), RCC_CFGR_MCO2PRE_2 | RCC_CFGR_MCO1PRE_2
					 | RCC_CFGR_PPRE2_0 | RCC_CFGR_PPRE1_DIV2 | RCC_CFGR_HPRE_0);

	/* Reset HSEBYP bit */
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & ~RCC_CR_HSEBYP);

	/*
	 *  全割込み禁止
	 */
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CIR), 0x00000000);

	/* SystemInit_ExtMemCtl(); no ExtMem */

	/*
	 *  HSE有効化
	 */
	sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) | RCC_CR_HSEON);

	/*
	 *  HSEレディ待ち
	 */
	do{
		HSEStatus = sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_HSERDY;
		StartUpCounter++;
	}while((HSEStatus == 0) && (StartUpCounter != HSE_STARTUP_TIMEOUT));

	if((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_HSERDY) != 0){
		/*
		 *  HCLKのコンフィギュレーション
		 */
		sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR), sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR)) | RCC_CFGR_HPRE_DIV1);

		/*
		 *  PCLK2のコンフィギュレーション
		 */
		sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR), sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR)) | RCC_CFGR_PPRE2_DIV2);

		/*
		 *  PCLK1のコンフィギュレーション
	 	 */
		sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR), sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR)) | RCC_CFGR_PPRE1_DIV4);

		/*
		 *  PLL設定
		 */
		sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_PLLCFGR), PLL_M | (PLL_N << 6) | (((PLL_P >> 1) -1) << 16) |
                   (RCC_PLLCFGR_PLLSRC_HSE) | (PLL_Q << 24) | (PLL_R << 28));

 		/*
		 *  PLLを有効化
		 */
		sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR), sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) | RCC_CR_PLLON);

		/*
		 *  PLLレディ待ち
		 */
		while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CR)) & RCC_CR_PLLRDY) == 0)
		{
		}

		/*
		 *  FLASHプリフェッチ最適化
		 */
		sil_wrw_mem((uint32_t *)(TADR_FLASH_R_BASE+TOFF_FLASH_ACR), FLASH_ACR_PRFTEN | FLASH_ACR_ICEN | FLASH_ACR_DCEN | 0x03);

		/*
		 *  PLLをシステムクロックソースとして設定
		 */
		sil_wrw_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR), (sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR)) & ~RCC_CFGR_SW) | RCC_CFGR_SW_PLL);

		/*
		 *  ソース設定完了まで待ち
		 */
		while((sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CFGR)) & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL)
		{
		}
	}
	else{
		/*
		 *  HSE初期化エラー
		 */
	}
}

