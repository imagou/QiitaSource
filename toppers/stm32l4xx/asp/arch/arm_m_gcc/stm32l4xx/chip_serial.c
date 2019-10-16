/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2008-2011 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2015-2016 by 3rd Designing Center
 *              Imageing System Development Division RICOH COMPANY, LTD.
 *  Copyright (C) 2017-2019 by TOPPERS PROJECT Educational Working Group.
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
 *  @(#) $Id: chip_serial.c 698 2019-01-23 11:48:37Z roi $
 */

/*
 *  シリアルI/Oデバイス（SIO）ドライバ（stm32l4xx用）
 */

#include <kernel.h>
#include <t_syslog.h>
#include "target_stddef.h"
#include "target_serial.h"
#include "target_syssvc.h"

/*
 *  SIL関数のマクロ定義
 */
#define sil_orw_mem(a, b)		sil_wrw_mem((a), sil_rew_mem(a) | (b))
#define sil_andw_mem(a, b)		sil_wrw_mem((a), sil_rew_mem(a) & ~(b))
#define sil_modw_mem(a, b, c)	sil_wrw_mem((a), (sil_rew_mem(a) & (~b)) | (c))

/*
 * レジスタ設定値
 */
#define PORT2SIOPID(x)	((x) + 1)
#define INDEX_PORT(x)	((x) - 1)
#define GET_SIOPCB(x)	(&siopcb_table[INDEX_PORT(x)])

#if !defined(HSI_VALUE)
#define HSI_VALUE      8000000				/* Value of the Internal oscillator in Hz*/
#endif /* HSI_VALUE */
#if !defined(LSE_VALUE)
#define LSE_VALUE      32768				/* Value of the LSE oscillator in Hz */
#endif /* LSE_VALUE */

/*
 *  GPIO Configuration Mode enumeration
 */
#define GPIO_Mode_IN    0x0					/* GPIO Input Mode */
#define GPIO_Mode_OUT   GPIO_MODER_MODER0	/* GPIO Output Mode */
#define GPIO_Mode_AF    GPIO_MODER_MODER1	/* GPIO Alternate function Mode */
#define GPIO_Mode_AN    GPIO_MODER_MODER2	/* GPIO Analog Mode */

/*
 *  GPIO Output Maximum frequency enumeration
 */
#define GPIO_Speed_2MHz   0x0						/* Low speed */
#define GPIO_Speed_25MHz  GPIO_OSPEEDER_OSPEEDR0	/* Medium speed */
#define GPIO_Speed_50MHz  GPIO_OSPEEDER_OSPEEDR1	/* Fast speed */
#define GPIO_Speed_100MHz GPIO_OSPEEDER_OSPEEDR2	/* High speed on 30 pF (80 MHz Output max speed on 15 pF) */

/*
 *  GPIO Output type enumeration
 */
#define GPIO_OType_PP   0x0
#define GPIO_OType_OD   0x1

/*
 *  GPIO Configuration PullUp PullDown enumeration
 */
#define GPIO_PuPd_NOPULL 0x0
#define GPIO_PuPd_UP     GPIO_PUPDR_PUPDR0
#define GPIO_PuPd_DOWN   GPIO_PUPDR_PUPDR1

/*
 *  USART Word Length
 */
#define USART_WordLegth_7b      USART_CR1_M1	/* 7-bit long UART frame */
#define USART_WordLength_8b     0x00000000		/* 8-bit long UART frame */
#define USART_WordLength_9b     USART_CR1_M0	/* 9-bit long UART frame */

/*
 *  USART Stop Bits
 */
#define USART_StopBits_0_5      USART_CR2_STOP_0
#define USART_StopBits_1        0x00000000
#define USART_StopBits_1_5      (USART_CR2_STOP_0 | USART_CR2_STOP_1)
#define USART_StopBits_2        USART_CR2_STOP_1

/*
 *  USART Parity
 */
#define USART_Parity_No         0x0000
#define USART_Parity_Even       USART_CR1_PCE
#define USART_Parity_Odd        (USART_CR1_PCE | USART_CR1_PS) 

/*
 *  USART MODE
 */
#define USART_Mode_Rx           USART_CR1_RE
#define USART_Mode_Tx           USART_CR1_TE


/*
 * USART HARDWARE FLOW制御
 */
#define USART_HardwareFlowControl_None       0x00000000
#define USART_HardwareFlowControl_RTS        USART_CR3_RTSE
#define USART_HardwareFlowControl_CTS        USART_CR3_CTSE
#define USART_HardwareFlowControl_RTS_CTS    (USART_CR3_RTSE | USART_CR3_CTSE)

#define CR1_CLEAR_MASK          (USART_CR1_M | USART_CR1_PCE | USART_CR1_PS | USART_CR1_TE | USART_CR1_RE)
#define CR3_CLEAR_MASK          (USART_CR3_RTSE | USART_CR3_CTSE)

#ifndef U2_GPIOSPEED
#define U2_GPIOSPEED            GPIO_Speed_50MHz
#endif

#define RCC_USARTCLKSOURCE_PCLK              0x00000000 
#define RCC_USARTCLKSOURCE_SYSCLK            RCC_CCIPR_USART1SEL_0
#define RCC_USARTCLKSOURCE_HSI               RCC_CCIPR_USART1SEL_1
#define RCC_USARTCLKSOURCE_LSE               (RCC_CCIPR_USART1SEL_0 | RCC_CCIPR_USART1SEL_1)

#define UART_CLOCKPRESCALER     0x00000000
#ifndef TOFF_USART_PRESC
#define UART_CLOCK_DIV_FACTOR   1			/* 必ず、1に設定 */
#else
#define UART_CLOCK_DIV_FACTOR   1
#endif


/*
 *  シリアルI/Oポート初期化ブロックの定義
 */
typedef struct sio_port_initialization_block {
	uint32_t base;
	INTNO    intno_usart;
} SIOPINIB;

/*
 *  兼用GPIOポート初期化ブロックの定義
 */
typedef struct gpio_port_initialization_block {
	uint32_t clockbase/* pfr*/;		/* PFRxレジスタアドレス */
	uint32_t clock_set;
	uint32_t portbase;
	uint32_t port_set;
	uint32_t gpio_af;
	uint32_t srcindex;
	uint32_t resetbase;
	uint32_t reset_bit;

	uint32_t txportbase;
	uint32_t txpinport;
	uint32_t txmode_msk;
	uint32_t txmode_set;
	uint32_t txspeed_msk;
	uint32_t txspeed_set;
	uint32_t txtype_msk;
	uint32_t txtype_set;
	uint32_t txpupd_msk;
	uint32_t txpupd_set;

	uint32_t rxportbase;
	uint32_t rxpinport;
	uint32_t rxmode_msk;
	uint32_t rxmode_set;
	uint32_t rxspeed_msk;
	uint32_t rxspeed_set;
	uint32_t rxtype_msk;
	uint32_t rxtype_set;
	uint32_t rxpupd_msk;
	uint32_t rxpupd_set;
} GPIOINIB;

/*
 *  シリアルI/Oポート管理ブロックの定義
 */
struct sio_port_control_block {
	const SIOPINIB  *p_siopinib;  /* シリアルI/Oポート初期化ブロック */
	const GPIOINIB  *p_gpioinib;  /* 兼用GPIOポート初期化ブロック */
	intptr_t        exinf;        /* 拡張情報 */
	bool_t          opnflg;       /* オープン済みフラグ */
};

/*
 * シリアルI/Oポート初期化ブロック
 */
const SIOPINIB siopinib_table[TNUM_SIOP] = {
	{(uint32_t)USART1_BASE, (INTNO)INTNO_SIO1},
#if TNUM_SIOP >= 2
	{(uint32_t)USART2_BASE, (INTNO)INTNO_SIO2},
#endif
};

/*
 * 兼用GPIOポート初期化ブロック
 */
const GPIOINIB gpioinib_table[TNUM_SIOP] = {
	{(uint32_t)(TADR_RCC_BASE+TOFF_U1_APBNER), (uint32_t)ENABLE_U1_PORT,
     (uint32_t)(TADR_RCC_BASE+TOFF_RCC_AHB2ENR), (uint32_t)ENABLE_U1_GPIO,
	 (uint32_t)GPIO_U1_AF, (uint32_t)U1_SRCINDEX,
	 (uint32_t)(TADR_RCC_BASE+TOFF_U1_APBRSTR), (uint32_t)RESET_U1_BIT,
     (uint32_t)TADR_U1_GPIO_BASE, (uint32_t)TX1_PINPOS,
     (uint32_t)(GPIO_MODER_MODER2 << (TX1_PINPOS*2)), (uint32_t)(GPIO_Mode_AF << (TX1_PINPOS*2)),
     (uint32_t)(GPIO_OSPEEDER_OSPEEDR2 << (TX1_PINPOS*2)), (uint32_t)(U1_GPIOSPEED << (TX1_PINPOS*2)),
     (uint32_t)(GPIO_OTYPER_OT << TX1_PINPOS), (uint32_t)(GPIO_OType_PP << TX1_PINPOS),
     (uint32_t)(GPIO_PUPDR_PUPDR2 << (TX1_PINPOS*2)), (uint32_t)(GPIO_PuPd_UP << (TX1_PINPOS*2)),
     (uint32_t)TADR_U1_GPIO_BASE, (uint32_t)RX1_PINPOS,
     (uint32_t)(GPIO_MODER_MODER2 << (RX1_PINPOS*2)), (uint32_t)(GPIO_Mode_AF << (RX1_PINPOS*2)),
     (uint32_t)(GPIO_OSPEEDER_OSPEEDR2 << (RX1_PINPOS*2)), (uint32_t)(U1_GPIOSPEED << (RX1_PINPOS*2)),
     (uint32_t)(GPIO_OTYPER_OT << RX1_PINPOS), (uint32_t)(GPIO_OType_PP << RX1_PINPOS),
     (uint32_t)(GPIO_PUPDR_PUPDR2 << (RX1_PINPOS*2)), (uint32_t)(GPIO_PuPd_UP << (RX1_PINPOS*2))
#if TNUM_SIOP >= 2
    },
	{(uint32_t)(TADR_RCC_BASE+TOFF_U2_APBNER), (uint32_t)ENABLE_U2_PORT,
     (uint32_t)(TADR_RCC_BASE+TOFF_RCC_AHB2ENR), (uint32_t)ENABLE_U2_GPIO,
	 (uint32_t)GPIO_U2_AF, (uint32_t)U2_SRCINDEX,
	 (uint32_t)(TADR_RCC_BASE+TOFF_U2_APBRSTR), (uint32_t)RESET_U2_BIT,
     (uint32_t)TADR_U2_GPIO_BASE, (uint32_t)TX2_PINPOS,
     (uint32_t)(GPIO_MODER_MODER2 << (TX2_PINPOS*2)), (uint32_t)(GPIO_Mode_AF << (TX2_PINPOS*2)),
     (uint32_t)(GPIO_OSPEEDER_OSPEEDR2 << (TX2_PINPOS*2)), (uint32_t)(U2_GPIOSPEED << (TX2_PINPOS*2)),
     (uint32_t)(GPIO_OTYPER_OT << TX2_PINPOS), (uint32_t)(GPIO_OType_PP << TX2_PINPOS),
     (uint32_t)(GPIO_PUPDR_PUPDR2 << (TX2_PINPOS*2)), (uint32_t)(GPIO_PuPd_UP << (TX2_PINPOS*2)),
     (uint32_t)TADR_U2_GPIO_BASE, (uint32_t)RX2_PINPOS,
     (uint32_t)(GPIO_MODER_MODER2 << (RX2_PINPOS*2)), (uint32_t)(GPIO_Mode_AF << (RX2_PINPOS*2)),
     (uint32_t)(GPIO_OSPEEDER_OSPEEDR2 << (RX2_PINPOS*2)), (uint32_t)(U2_GPIOSPEED << (RX2_PINPOS*2)),
     (uint32_t)(GPIO_OTYPER_OT << RX2_PINPOS), (uint32_t)(GPIO_OType_PP << RX2_PINPOS),
     (uint32_t)(GPIO_PUPDR_PUPDR2 << (RX2_PINPOS*2)), (uint32_t)(GPIO_PuPd_UP << (RX2_PINPOS*2)),
#endif
    }
};

/*
 *  シリアルI/Oポート管理ブロックのエリア
 */
SIOPCB	siopcb_table[TNUM_SIOP];

/*
 *  シリアルI/OポートIDから管理ブロックを取り出すためのマクロ
 */
#define INDEX_SIOP(siopid)	((uint_t)((siopid) - 1))
#define get_siopcb(siopid)	(&(siopcb_table[INDEX_SIOP(siopid)]))

static void setup_gpio_source(uint32_t base, uint8_t source, uint8_t select)
{
	uint32_t tmpreg, regoff;
	regoff = TOFF_GPIO_AFR0+((source>>1) & 0x4);
	tmpreg = (sil_rew_mem((uint32_t *)(base+regoff)) & ~(0xF << ((source & 0x07) * 4)))
			    | (select << ((source & 0x07) * 4));
	sil_wrw_mem((uint32_t *)(base+regoff), tmpreg);
}

void put_hex(char a, int val)
{
	int i, j;
	target_fput_log(a);
	target_fput_log(' ');
	for(i = 28 ; i >= 0 ; i-= 4){
		j = (val >> i) & 0xf;;
		if(j > 9)
			j += ('A'-10);
		else
			j += '0';
		target_fput_log(j);
	}
	target_fput_log('\n');
}

/*
 *  SIOドライバの初期化
 */
void
sio_initialize(intptr_t exinf)
{
	SIOPCB	*p_siopcb;
	uint_t	i;

	/*
	 *  シリアルI/Oポート管理ブロックの初期化
	 */
	for (p_siopcb = siopcb_table, i = 0; i < TNUM_SIOP; p_siopcb++, i++) {
		p_siopcb->p_siopinib = &(siopinib_table[i]);
		p_siopcb->p_gpioinib = &(gpioinib_table[i]);
		p_siopcb->opnflg = false;
	}
}


/*
 *  シリアルI/Oポートのオープン
 */
SIOPCB *
sio_opn_por(ID siopid, intptr_t exinf)
{
	SIOPCB          *p_siopcb;
	const SIOPINIB  *p_siopinib;
	const GPIOINIB  *p_gpioinib;
	bool_t   opnflg;
	ER       ercd;
	uint32_t base, txbase, rxbase;
	uint32_t apbclock, tmp;

	p_siopcb = get_siopcb(siopid);
	p_siopinib = p_siopcb->p_siopinib;
	p_gpioinib = p_siopcb->p_gpioinib;

	/*
	 *  オープンしたポートがあるかをopnflgに読んでおく．
	 */
	opnflg = p_siopcb->opnflg;

	p_siopcb->exinf = exinf;
	txbase = p_gpioinib->txportbase;
	rxbase = p_gpioinib->rxportbase;

	if(txbase == 0 || rxbase == 0)	/* no usart port */
		goto sio_opn_exit;

	/*
	 *  ハードウェアの初期化
	 */
	sil_orw_mem((uint32_t *)p_gpioinib->clockbase, p_gpioinib->clock_set);
	sil_orw_mem((uint32_t *)p_gpioinib->portbase, p_gpioinib->port_set);
	sil_modw_mem((uint32_t *)(txbase+TOFF_GPIO_MODER), p_gpioinib->txmode_msk, p_gpioinib->txmode_set);
	sil_modw_mem((uint32_t *)(txbase+TOFF_GPIO_OSPEEDR), p_gpioinib->txspeed_msk, p_gpioinib->txspeed_set);
	sil_modw_mem((uint32_t *)(txbase+TOFF_GPIO_OTYPER), p_gpioinib->txtype_msk, p_gpioinib->txtype_set);
	sil_modw_mem((uint32_t *)(txbase+TOFF_GPIO_PUPDR), p_gpioinib->txpupd_msk, p_gpioinib->txpupd_set);
	sil_modw_mem((uint32_t *)(rxbase+TOFF_GPIO_MODER), p_gpioinib->rxmode_msk, p_gpioinib->rxmode_set);
	sil_modw_mem((uint32_t *)(rxbase+TOFF_GPIO_OSPEEDR), p_gpioinib->rxspeed_msk, p_gpioinib->rxspeed_set);
	sil_modw_mem((uint32_t *)(rxbase+TOFF_GPIO_OTYPER), p_gpioinib->rxtype_msk, p_gpioinib->rxtype_set);
	sil_modw_mem((uint32_t *)(rxbase+TOFF_GPIO_PUPDR), p_gpioinib->rxpupd_msk, p_gpioinib->rxpupd_set);
	setup_gpio_source(txbase, p_gpioinib->txpinport, p_gpioinib->gpio_af);
	setup_gpio_source(rxbase, p_gpioinib->rxpinport, p_gpioinib->gpio_af);

	base = p_siopinib->base;

	sil_andw_mem((uint32_t *)(base+TOFF_USART_CR1), USART_CR1_UE);
	sil_modw_mem((uint32_t *)(base+TOFF_USART_CR1), CR1_CLEAR_MASK, (USART_WordLength_8b | USART_Parity_No | USART_Mode_Rx | USART_Mode_Tx));
	sil_modw_mem((uint32_t *)(base+TOFF_USART_CR2), USART_CR2_STOP, USART_StopBits_1);
	sil_modw_mem((uint32_t *)(base+TOFF_USART_CR3), CR3_CLEAR_MASK, USART_HardwareFlowControl_None);

	tmp = (sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CCIPR)) >> p_gpioinib->srcindex) & RCC_CCIPR_USART1SEL;
	if(base == TADR_LPUART1_BASE){	/* LPUART */
#ifdef TOFF_USART_PRESC
		sil_modw_mem((uint32_t *)(base+TOFF_USART_PRESC), USART_PRESC_PRESCALER, UART_CLOCKPRESCALER);	/* DIV1 */
#endif
		switch(tmp){
		case RCC_USARTCLKSOURCE_SYSCLK:
			apbclock = SysFreHCLK;
			break;
		case RCC_USARTCLKSOURCE_HSI:
			apbclock = HSI_VALUE;
			break;
		case RCC_USARTCLKSOURCE_LSE:
			apbclock = LSE_VALUE;
			break;
		default:
			apbclock = SysFrePCLK1;
			break;
		}

		tmp = (((unsigned long long)(apbclock / UART_CLOCK_DIV_FACTOR) * 256U) + (BPS_SETTING / 2U)) / BPS_SETTING;
	}
	else{
		switch(tmp){
		case RCC_USARTCLKSOURCE_HSI:
			apbclock = HSI_VALUE;
			break;
		case RCC_USARTCLKSOURCE_LSE:
			apbclock = LSE_VALUE;
			break;
		case RCC_USARTCLKSOURCE_SYSCLK:
			apbclock = SysFreHCLK;
			break;
		default:
			apbclock = SysFrePCLK1;
			break;
		}

		if((sil_rew_mem((uint32_t *)(base+TOFF_USART_CR1)) & USART_CR1_OVER8) != 0){
			uint32_t usartdiv = ((apbclock*2) + (BPS_SETTING/2)) / BPS_SETTING;
			tmp = usartdiv & 0xFFF0U;
			tmp |= (uint16_t)((usartdiv & 0x0000000F) >> 1);
		}
		else{
			tmp = (apbclock + (BPS_SETTING/2)) / BPS_SETTING;
		}
	}
	sil_wrw_mem((uint32_t *)(base+TOFF_USART_BRR), tmp);
	sil_orw_mem((uint32_t *)(base+TOFF_USART_CR3), USART_CR3_EIE);
	sil_orw_mem((uint32_t *)(base+TOFF_USART_CR1), (USART_CR1_PEIE | USART_CR1_RXNEIE));
	p_siopcb->opnflg = true;

	/*
	 *  シリアルI/O割込みのマスクを解除する．
	 */
	if (!opnflg) {
		ercd = ena_int(p_siopinib->intno_usart);
		assert(ercd == E_OK);
	}
	sil_orw_mem((uint32_t *)(base+TOFF_USART_CR1), USART_CR1_UE);

sio_opn_exit:;
	return(p_siopcb);
}

/*
 *  シリアルI/Oポートのクローズ
 */
void
sio_cls_por(SIOPCB *p_siopcb)
{
	const SIOPINIB  *p_siopinib;
	const GPIOINIB  *p_gpioinib;

	p_siopinib = p_siopcb->p_siopinib;
	p_gpioinib = p_siopcb->p_gpioinib;

	/*
	 *  シリアルI/O割込みをマスクする．
	 */
	if ((p_siopcb->opnflg)) {
		dis_int(p_siopcb->p_siopinib->intno_usart);
		sil_andw_mem((uint32_t *)(p_siopinib->base+TOFF_USART_CR1), USART_CR1_UE);
		sil_andw_mem((uint32_t *)p_gpioinib->clockbase, p_gpioinib->clock_set);
	}
	p_siopcb->opnflg = false;
}

/*
 *  SIOの割込みサービスルーチン
 */

Inline bool_t
sio_putready(SIOPCB* p_siopcb)
{
	uint32_t cr1 = sil_rew_mem((uint32_t *)(p_siopcb->p_siopinib->base+TOFF_USART_CR1));
	uint32_t isr = sil_rew_mem((uint32_t *)(p_siopcb->p_siopinib->base+TOFF_USART_ISR));

	if ((cr1 & USART_CR1_TXEIE) != 0 && (isr & USART_ISR_TC) != 0)
	{
		return 1;
	}
	return 0;
}

Inline bool_t
sio_getready(SIOPCB* p_siopcb)
{
	uint32_t cr1 = sil_rew_mem((uint32_t *)(p_siopcb->p_siopinib->base+TOFF_USART_CR1));
	uint32_t isr = sil_rew_mem((uint32_t *)(p_siopcb->p_siopinib->base+TOFF_USART_ISR));
	uint16_t temp;

	if ((isr & (USART_ISR_ORE | USART_ISR_NE | USART_ISR_FE | USART_ISR_PE)) != 0) {
		temp = 0;
		sil_dly_nse(100*1000);
		syslog_2(LOG_INFO, "sio_usart_isr error (%d) isr[%04x] !", p_siopcb->p_siopinib->intno_usart, isr);
		sil_andw_mem((uint32_t *)(p_siopcb->p_siopinib->base+TOFF_USART_CR3), USART_CR3_EIE);
		temp = sil_reh_mem((uint16_t *)(p_siopcb->p_siopinib->base+TOFF_USART_RDR));
		(void)(temp);
		return 0;
	}
	if ((cr1 & USART_CR1_RXNEIE) != 0 && (isr & USART_ISR_RXNE) != 0) {
		return 1;
	}
	return 0;
}

void
sio_usart_isr(intptr_t exinf)
{
	SIOPCB          *p_siopcb;

	p_siopcb = get_siopcb(exinf);

	if (sio_getready(p_siopcb)) {
		sio_irdy_rcv(p_siopcb->exinf);
	}
	if (sio_putready(p_siopcb)) {
		sio_irdy_snd(p_siopcb->exinf);
	}
}

/*
 *  シリアルI/Oポートへの文字送信
 */
bool_t
sio_snd_chr(SIOPCB *p_siopcb, char c)
{
	if (sio_putready(p_siopcb)) {
		sil_wrh_mem((uint16_t *)(p_siopcb->p_siopinib->base+TOFF_USART_TDR), (uint16_t)c);
		return true;
	}
	return false;
}

/*
 *  シリアルI/Oポートからの文字受信
 */
int_t
sio_rcv_chr(SIOPCB *p_siopcb)
{
	int_t c = -1;

	if (sio_getready(p_siopcb)) {
		c = sil_reh_mem((uint16_t *)(p_siopcb->p_siopinib->base+TOFF_USART_RDR)) & 0xFF;
	}
	return c;
}

/*
 *  シリアルI/Oポートからのコールバックの許可
 */
void
sio_ena_cbr(SIOPCB *p_siopcb, uint_t cbrtn)
{
	switch (cbrtn) {
	case SIO_RDY_SND:
		sil_orw_mem((uint32_t *)(p_siopcb->p_siopinib->base+TOFF_USART_CR1), USART_CR1_TXEIE);
		break;
	case SIO_RDY_RCV:
		sil_orw_mem((uint32_t *)(p_siopcb->p_siopinib->base+TOFF_USART_CR1), USART_CR1_RXNEIE);
		break;
	}
}

/*
 *  シリアルI/Oポートからのコールバックの禁止
 */
void
sio_dis_cbr(SIOPCB *p_siopcb, uint_t cbrtn)
{
	switch (cbrtn) {
	case SIO_RDY_SND:
		sil_andw_mem((uint32_t *)(p_siopcb->p_siopinib->base+TOFF_USART_CR1), USART_CR1_TXEIE);
		break;
	case SIO_RDY_RCV:
		sil_andw_mem((uint32_t *)(p_siopcb->p_siopinib->base+TOFF_USART_CR1), USART_CR1_RXNEIE);
		break;
	}
}

/*
 *  1文字出力（ポーリングでの出力）
 */
void sio_pol_snd_chr(int8_t c, ID siopid)
{
	uint32_t base = siopinib_table[INDEX_PORT(siopid)].base;

	sil_wrh_mem((uint16_t *)(base+TOFF_USART_TDR), (uint16_t)c);
	while(0 == (sil_rew_mem((uint32_t *)(base+TOFF_USART_ISR)) & USART_ISR_TC));

	/*
	 *  出力が完全に終わるまで待つ
	 */
	volatile int n = SystemFrequency/BPS_SETTING;
	while(n--);
}

/*
 *  ターゲットのシリアル初期化
 */
void chip_uart_init(ID siopid)
{
	const GPIOINIB  *p_gpioinib = &gpioinib_table[INDEX_PORT(siopid)];
	const SIOPINIB  *p_siopinib = &siopinib_table[INDEX_PORT(siopid)];
	uint32_t base, txbase, rxbase;
	uint32_t apbclock, tmp;

	txbase = p_gpioinib->txportbase;
	rxbase = p_gpioinib->rxportbase;

	sil_andw_mem((uint32_t *)(p_gpioinib->resetbase), p_gpioinib->reset_bit);

	sil_orw_mem((uint32_t *)p_gpioinib->clockbase, p_gpioinib->clock_set);
	sil_orw_mem((uint32_t *)p_gpioinib->portbase, p_gpioinib->port_set);
	sil_modw_mem((uint32_t *)(txbase+TOFF_GPIO_MODER), p_gpioinib->txmode_msk, p_gpioinib->txmode_set);
	sil_modw_mem((uint32_t *)(txbase+TOFF_GPIO_OSPEEDR), p_gpioinib->txspeed_msk, p_gpioinib->txspeed_set);
	sil_modw_mem((uint32_t *)(txbase+TOFF_GPIO_OTYPER), p_gpioinib->txtype_msk, p_gpioinib->txtype_set);
	sil_modw_mem((uint32_t *)(txbase+TOFF_GPIO_PUPDR), p_gpioinib->txpupd_msk, p_gpioinib->txpupd_set);
	sil_modw_mem((uint32_t *)(rxbase+TOFF_GPIO_MODER), p_gpioinib->rxmode_msk, p_gpioinib->rxmode_set);
	sil_modw_mem((uint32_t *)(rxbase+TOFF_GPIO_OSPEEDR), p_gpioinib->rxspeed_msk, p_gpioinib->rxspeed_set);
	sil_modw_mem((uint32_t *)(rxbase+TOFF_GPIO_OTYPER), p_gpioinib->rxtype_msk, p_gpioinib->rxtype_set);
	sil_modw_mem((uint32_t *)(rxbase+TOFF_GPIO_PUPDR), p_gpioinib->rxpupd_msk, p_gpioinib->rxpupd_set);
	setup_gpio_source(txbase, p_gpioinib->txpinport, p_gpioinib->gpio_af);
	setup_gpio_source(rxbase, p_gpioinib->rxpinport, p_gpioinib->gpio_af);

	base = p_siopinib->base;

	sil_andw_mem((uint32_t *)(base+TOFF_USART_CR1), USART_CR1_UE);
	sil_modw_mem((uint32_t *)(base+TOFF_USART_CR1), CR1_CLEAR_MASK, (USART_WordLength_8b | USART_Parity_No | USART_Mode_Rx | USART_Mode_Tx));
	sil_modw_mem((uint32_t *)(base+TOFF_USART_CR2), USART_CR2_STOP, USART_StopBits_1);
	sil_modw_mem((uint32_t *)(base+TOFF_USART_CR3), CR3_CLEAR_MASK, USART_HardwareFlowControl_None);

	tmp = (sil_rew_mem((uint32_t *)(TADR_RCC_BASE+TOFF_RCC_CCIPR)) >> p_gpioinib->srcindex) & RCC_CCIPR_USART1SEL;
	if(base == TADR_LPUART1_BASE){	/* LPUART */
#ifdef TOFF_USART_PRESC
		sil_modw_mem((uint32_t *)(base+TOFF_USART_PRESC), USART_PRESC_PRESCALER, UART_CLOCKPRESCALER);	/* DIV1 */
#endif
		switch(tmp){
		case RCC_USARTCLKSOURCE_SYSCLK:
			apbclock = SysFreHCLK;
			break;
		case RCC_USARTCLKSOURCE_HSI:
			apbclock = HSI_VALUE;
			break;
		case RCC_USARTCLKSOURCE_LSE:
			apbclock = LSE_VALUE;
			break;
		default:
			apbclock = SysFrePCLK1;
			break;
		}

		tmp = (((unsigned long long)(apbclock / UART_CLOCK_DIV_FACTOR) * 256U) + (BPS_SETTING / 2U)) / BPS_SETTING;
	}
	else{
		switch(tmp){
		case RCC_USARTCLKSOURCE_HSI:
			apbclock = HSI_VALUE;
			break;
		case RCC_USARTCLKSOURCE_LSE:
			apbclock = LSE_VALUE;
			break;
		case RCC_USARTCLKSOURCE_SYSCLK:
			apbclock = SysFreHCLK;
			break;
		default:
			apbclock = SysFrePCLK1;
			break;
		}

		if((sil_rew_mem((uint32_t *)(base+TOFF_USART_CR1)) & USART_CR1_OVER8) != 0){
			uint32_t usartdiv = ((apbclock*2) + (BPS_SETTING/2)) / BPS_SETTING;
			tmp = usartdiv & 0x0000FFF0;
			tmp |= (uint16_t)((usartdiv & 0x0000000F) >> 1);
		}
		else{
			tmp = (apbclock + (BPS_SETTING/2)) / BPS_SETTING;
		}
	}
	sil_wrw_mem((uint32_t *)(base+TOFF_USART_BRR), tmp);
	sil_andw_mem((uint32_t *)(base+TOFF_USART_CR1), (USART_CR1_TXEIE | USART_CR1_RXNEIE));
	sil_orw_mem((uint32_t *)(base+TOFF_USART_CR1), USART_CR1_UE);
}
