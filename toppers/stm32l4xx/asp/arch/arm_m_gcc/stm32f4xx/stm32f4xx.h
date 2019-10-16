/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2015      by 3rd Designing Center
 *              Imageing System Development Division RICOH COMPANY, LTD.
 *  Copyright (C) 2017-2018 by TOPPERS PROJECT
 *                             Educational Working Group.
 *
 *  上記著作権者は，以下の (1)〜(4) の条件か，Free Software Foundation 
 *  によって公表されている GNU General Public License の Version 2 に記
 *  述されている条件を満たす場合に限り，本ソフトウェア（本ソフトウェア
 *  を改変したものを含む．以下同じ）を使用・複製・改変・再配布（以下，
 *  利用と呼ぶ）することを無償で許諾する．
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
 *
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，その適用可能性も
 *  含めて，いかなる保証も行わない．また，本ソフトウェアの利用により直
 *  接的または間接的に生じたいかなる損害に関しても，その責任を負わない．
 * 
 *  @(#) $Id: stm32f4xx.h,v 1.4 2018/11/05 20:08:41 roi Exp $
 */

#ifndef _STM32F4XX_H_
#define _STM32F4XX_H_

#include <sil.h>
#include "cmsis_f4.h"

/*
 *  割込み番号の最大値
 */
#define TMAX_INTNO          (16 + 82)

/*
 *  割込み優先度のビット幅
 */
#define TBITW_IPRI          4

/*
 *  INTERRUPT NUMBER
 */
#define IRQ_VECTOR_WWDG             (16 + 0)	/* Window WatchDog Interrupt */
#define IRQ_VECTOR_PVD              (16 + 1)	/* PVD through EXTI Line detection Interrupt */
#define IRQ_VECTOR_TAMP_STAMP       (16 + 2)	/* Tamper and TimeStamp interrupts through the EXTI line */
#define IRQ_VECTOR_RTC_WKUP         (16 + 3)	/* RTC Wakeup interrupt through the EXTI line */
#define IRQ_VECTOR_FLASH            (16 + 4)	/* FLASH global Interrupt */
#define IRQ_VECTOR_RCC              (16 + 5)	/* RCC global Interrupt */
#define IRQ_VECTOR_EXTI0            (16 + 6)	/* EXTI Line0 Interrupt */
#define IRQ_VECTOR_EXTI1            (16 + 7)	/* EXTI Line1 Interrupt */
#define IRQ_VECTOR_EXTI2            (16 + 8)	/* EXTI Line2 Interrupt */
#define IRQ_VECTOR_EXTI3            (16 + 9)	/* EXTI Line3 Interrupt */
#define IRQ_VECTOR_EXTI4            (16 + 10)	/* EXTI Line4 Interrupt */
#define IRQ_VECTOR_DMA1_STREAM0     (16 + 11)	/* DMA1 Stream 0 global Interrupt */
#define IRQ_VECTOR_DMA1_STREAM1     (16 + 12)	/* DMA1 Stream 1 global Interrupt */
#define IRQ_VECTOR_DMA1_STREAM2     (16 + 13)	/* DMA1 Stream 2 global Interrupt */
#define IRQ_VECTOR_DMA1_STREAM3     (16 + 14)	/* DMA1 Stream 3 global Interrupt */
#define IRQ_VECTOR_DMA1_STREAM4     (16 + 15)	/* DMA1 Stream 4 global Interrupt */
#define IRQ_VECTOR_DMA1_STREAM5     (16 + 16)	/* DMA1 Stream 5 global Interrupt */
#define IRQ_VECTOR_DMA1_STREAM6     (16 + 17)	/* DMA1 Stream 6 global Interrupt */
#define IRQ_VECTOR_ADC              (16 + 18)	/* ADC1, ADC2 and ADC3 global Interrupts */
#define IRQ_VECTOR_CAN1_TX          (16 + 19)	/* CAN1 TX Interrupt */
#define IRQ_VECTOR_CAN1_RX0         (16 + 20)	/* CAN1 RX0 Interrupt */
#define IRQ_VECTOR_CAN1_RX1         (16 + 21)	/* CAN1 RX1 Interrupt */
#define IRQ_VECTOR_CAN1_SCE         (16 + 22)	/* CAN1 SCE Interrupt */
#define IRQ_VECTOR_EXTI9_5          (16 + 23)	/* External Line[9:5] Interrupts */
#define IRQ_VECTOR_TIM1_BRK_TIM9    (16 + 24)	/* TIM1 Break interrupt and TIM9 global interrupt */
#define IRQ_VECTOR_TIM1_UP_TIM10    (16 + 25)	/* TIM1 Update Interrupt and TIM10 global interrupt */
#define IRQ_VECTOR_TIM1_TRG_COM_TIM11 (16+26)	/* TIM1 Trigger and Commutation Interrupt and TIM11 global interrupt */
#define IRQ_VECTOR_TIM1_CC          (16 + 27)	/* TIM1 Capture Compare Interrupt */
#define IRQ_VECTOR_TIM2             (16 + 28)	/* TIM2 global Interrupt */
#define IRQ_VECTOR_TIM3             (16 + 29)	/* TIM3 global Interrupt */
#define IRQ_VECTOR_TIM4             (16 + 30)	/* TIM4 global Interrupt */
#define IRQ_VECTOR_I2C1_EV          (16 + 31)	/* I2C1 Event Interrupt */
#define IRQ_VECTOR_I2C1_ER          (16 + 32)	/* I2C1 Error Interrupt */
#define IRQ_VECTOR_I2C2_EV          (16 + 33)	/* I2C2 Event Interrupt */
#define IRQ_VECTOR_I2C2_ER          (16 + 34)	/* I2C2 Error Interrupt */
#define IRQ_VECTOR_SPI1             (16 + 35)	/* SPI1 global Interrupt */
#define IRQ_VECTOR_SPI2             (16 + 36)	/* SPI2 global Interrupt */
#define IRQ_VECTOR_USART1           (16 + 37)	/* USART1 global Interrupt */
#define IRQ_VECTOR_USART2           (16 + 38)	/* USART2 global Interrupt */
#define IRQ_VECTOR_USART3           (16 + 39)	/* USART3 global Interrupt */
#define IRQ_VECTOR_EXTI15_10        (16 + 40)	/* External Line[15:10] Interrupts */
#define IRQ_VECTOR_RTC_ALARM        (16 + 41)	/* RTC Alarm (A and B) through EXTI Line Interrupt */
#define IRQ_VECTOR_OTG_FS_WKUP      (16 + 42)	/* USB OTG FS Wakeup through EXTI line interrupt */
#define IRQ_VECTOR_TIM8_BRK_TIM12   (16 + 43)	/* TIM8 Break Interrupt and TIM12 global interrupt */
#define IRQ_VECTOR_TIM8_UP_TIM13    (16 + 44)	/* TIM8 Update Interrupt and TIM13 global interrupt */
#define IRQ_VECTOR_TIM8_TRG_COM_TIM14 (16+45)	/* TIM8 Trigger and Commutation Interrupt and TIM14 global interrupt */
#define IRQ_VECTOR_TIM8_CC          (16 + 46)	/* TIM8 Capture Compare Interrupt */
#define IRQ_VECTOR_DMA1_STREAM7     (16 + 47)	/* DMA1 Stream7 Interrupt */
#define IRQ_VECTOR_FSMC             (16 + 48)	/* FSMC global Interrupt */
#define IRQ_VECTOR_SDIO             (16 + 49)	/* SDIO global Interrupt */
#define IRQ_VECTOR_TIM5             (16 + 50)	/* TIM5 global Interrupt */
#define IRQ_VECTOR_SPI3             (16 + 51)	/* SPI3 global Interrupt */
#define IRQ_VECTOR_UART4            (16 + 52)	/* UART4 global Interrupt */
#define IRQ_VECTOR_UART5            (16 + 53)	/* UART5 global Interrupt */
#define IRQ_VECTOR_TIM6_DAC         (16 + 54)	/* TIM6 global and DAC1&2 underrun error interrupts */
#define IRQ_VECTOR_TIM7             (16 + 55)	/* TIM7 global interrupt */
#define IRQ_VECTOR_DMA2_STREAM0     (16 + 56)	/* DMA2 Stream 0 global Interrupt */
#define IRQ_VECTOR_DMA2_STREAM1     (16 + 57)	/* DMA2 Stream 1 global Interrupt */
#define IRQ_VECTOR_DMA2_STREAM2     (16 + 58)	/* DMA2 Stream 2 global Interrupt */
#define IRQ_VECTOR_DMA2_STREAM3     (16 + 59)	/* DMA2 Stream 3 global Interrupt */
#define IRQ_VECTOR_DMA2_STREAM4     (16 + 60)	/* DMA2 Stream 4 global Interrupt */
#define IRQ_VECTOR_ETH              (16 + 61)	/* Ethernet global Interrupt */
#define IRQ_VECTOR_ETH_WKUP         (16 + 62)	/* Ethernet Wakeup through EXTI line Interrupt */
#define IRQ_VECTOR_CAN2_TX          (16 + 63)	/* CAN2 TX Interrupt */
#define IRQ_VECTOR_CAN2_RX0         (16 + 64)	/* CAN2 RX0 Interrupt */
#define IRQ_VECTOR_CAN2_RX1         (16 + 65)	/* CAN2 RX1 Interrupt */
#define IRQ_VECTOR_CAN2_SCE         (16 + 66)	/* CAN2 SCE Interrupt */
#define IRQ_VECTOR_OTG_FS           (16 + 67)	/* USB OTG FS global Interrupt */
#define IRQ_VECTOR_DMA2_STREAM5     (16 + 68)	/* DMA2 Stream 5 global interrupt */
#define IRQ_VECTOR_DMA2_STREAM6     (16 + 69)	/* DMA2 Stream 6 global interrupt */
#define IRQ_VECTOR_DMA2_STREAM7     (16 + 70)	/* DMA2 Stream 7 global interrupt */
#define IRQ_VECTOR_USART6           (16 + 71)	/* USART6 global interrupt */
#define IRQ_VECTOR_I2C3_EV          (16 + 72)	/* I2C3 event interrupt */
#define IRQ_VECTOR_I2C3_ER          (16 + 73)	/* I2C3 error interrupt */
#define IRQ_VECTOR_OTG_HS_EP1_OUT   (16 + 74)	/* USB OTG HS End Point 1 Out global interrupt */
#define IRQ_VECTOR_OTG_HS_EP1_IN    (16 + 75)	/* USB OTG HS End Point 1 In global interrupt */
#define IRQ_VECTOR_OTG_HS_WKUP      (16 + 76)	/* USB OTG HS Wakeup through EXTI interrupt */
#define IRQ_VECTOR_OTG_HS           (16 + 77)	/* USB OTG HS global interrupt */
#define IRQ_VECTOR_DCMI             (16 + 78)	/* DCMI global interrupt */
#define IRQ_VECTOR_CRYP             (16 + 79)	/* CRYP crypto global interrupt */
#define IRQ_VECTOR_HASH_RNG         (16 + 80)	/* Hash and Rng global interrupt */
#define IRQ_VECTOR_FPU              (16 + 81)	/* FPU global interrupt */

/*
 *  PERIPHERAL MEMORY MAP
 */
#define FLASH_BASE          0x08000000	/* FLASH(up to 1 MB) base address in the alias region                         */
#define CCMDATARAM_BASE     0x10000000	/* CCM(core coupled memory) data RAM(64 KB) base address in the alias region  */
#define SRAM1_BASE          0x20000000	/* SRAM1(112 KB) base address in the alias region                             */
#define SRAM2_BASE          0x2001C000	/* SRAM2(16 KB) base address in the alias region                              */
#define PERIPH_BASE         0x40000000	/* Peripheral base address in the alias region                                */
#define BKPSRAM_BASE        0x40024000	/* Backup SRAM(4 KB) base address in the alias region                         */
#define FSMC_R_BASE         0xA0000000	/* FSMC registers base address                                                */

#define CCMDATARAM_BB_BASE  0x12000000	/* CCM(core coupled memory) data RAM(64 KB) base address in the bit-band region  */
#define SRAM1_BB_BASE       0x22000000	/* SRAM1(112 KB) base address in the bit-band region                             */
#define SRAM2_BB_BASE       0x2201C000	/* SRAM2(16 KB) base address in the bit-band region                              */
#define PERIPH_BB_BASE      0x42000000	/* Peripheral base address in the bit-band region                                */
#if defined(TOPPERS_STM32F401_NUCLE) || defined(TOPPERS_STM32F446_NUCLEO64) || defined(TOPPERS_STM32F446_NUCLEO144)
#define BKPSRAM_BB_BASE     0x42480000	/* Backup SRAM(4 KB) base address in the bit-band region                         */
#else
#define BKPSRAM_BB_BASE     0x42024000	/* Backup SRAM(4 KB) base address in the bit-band region                         */
#endif

/* Peripheral memory map */
#define APB1PERIPH_BASE     PERIPH_BASE
#define APB2PERIPH_BASE     (PERIPH_BASE + 0x00010000)
#define AHB1PERIPH_BASE     (PERIPH_BASE + 0x00020000)
#define AHB2PERIPH_BASE     (PERIPH_BASE + 0x10000000)

/* USB registers base address */
#define USB_OTG_FS_PERIPH_BASE  0x50000000

#define USB_OTG_DEVICE_BASE         0x800
#define USB_OTG_IN_ENDPOINT_BASE    0x900
#define USB_OTG_OUT_ENDPOINT_BASE   0xB00
#define USB_OTG_HOST_BASE           0x400
#define USB_OTG_HOST_PORT_BASE      0x440
#define USB_OTG_HOST_CHANNEL_BASE   0x500
#define USB_OTG_PCGCCTL_BASE        0xE00
#define USB_OTG_FIFO_BASE           0x1000
#define USB_OTG_FIFO_SIZE           0x1000

/*
 *  TIM
 */
#define TADR_TIM2_BASE      (APB1PERIPH_BASE + 0x0000)
#define TADR_TIM3_BASE      (APB1PERIPH_BASE + 0x0400)
#define TADR_TIM4_BASE      (APB1PERIPH_BASE + 0x0800)
#define TADR_TIM5_BASE      (APB1PERIPH_BASE + 0x0C00)
#define TADR_TIM6_BASE      (APB1PERIPH_BASE + 0x1000)
#define TADR_TIM7_BASE      (APB1PERIPH_BASE + 0x1400)
#define TADR_TIM12_BASE     (APB1PERIPH_BASE + 0x1800)
#define TADR_TIM13_BASE     (APB1PERIPH_BASE + 0x1C00)
#define TADR_TIM14_BASE     (APB1PERIPH_BASE + 0x2000)
#define TADR_TIM1_BASE      (APB2PERIPH_BASE + 0x0000)
#define TADR_TIM8_BASE      (APB2PERIPH_BASE + 0x0400)
#define TADR_TIM9_BASE      (APB2PERIPH_BASE + 0x4000)
#define TADR_TIM10_BASE     (APB2PERIPH_BASE + 0x4400)
#define TADR_TIM11_BASE     (APB2PERIPH_BASE + 0x4800)
#define TOFF_TIM_CR1        0x0000		/* (RW-16) TIM control register 1 */
  #define TIM_CR1_CEN        0x0001		/* Counter enable */
  #define TIM_CR1_UDIS       0x0002		/* Update disable */
  #define TIM_CR1_URS        0x0004		/* Update request source */
  #define TIM_CR1_OPM        0x0008		/* One pulse mode */
  #define TIM_CR1_DIR        0x0010		/* Direction */
  #define TIM_CR1_CMS_0      0x0020		/* CMS[1:0] bit 0 */
  #define TIM_CR1_CMS_1      0x0040		/* CMS[1:0] bit 1 */
  #define TIM_CR1_ARPE       0x0080		/* Auto-reload preload enable */
  #define TIM_CR1_CKD_0      0x0100		/* CKD[1:0] bit 0 */
  #define TIM_CR1_CKD_1      0x0200		/* CKD[1:0] bit 1 */
#define TOFF_TIM_CR2        0x0004		/* (RW-16) TIM control register 2 */
#define TOFF_TIM_SMCR       0x0008		/* (RW-16) TIM slave mode control register */
#define TOFF_TIM_DIER       0x000C		/* (RW-16) TIM DMA/interrupt enable register */
  #define TIM_DIER_UIE       0x0001		/* Update interrupt enable */
  #define TIM_DIER_CC1IE     0x0002		/* Capture/Compare 1 interrupt enable */
  #define TIM_DIER_CC2IE     0x0004		/* Capture/Compare 2 interrupt enable */
  #define TIM_DIER_CC3IE     0x0008		/* Capture/Compare 3 interrupt enable */
  #define TIM_DIER_CC4IE     0x0010		/* Capture/Compare 4 interrupt enable */
  #define TIM_DIER_COMIE     0x0020		/* COM interrupt enable */
  #define TIM_DIER_TIE       0x0040		/* Trigger interrupt enable */
  #define TIM_DIER_BIE       0x0080		/* Break interrupt enable */
  #define TIM_DIER_UDE       0x0100		/* Update DMA request enable */
  #define TIM_DIER_CC1DE     0x0200		/* Capture/Compare 1 DMA request enable */
  #define TIM_DIER_CC2DE     0x0400		/* Capture/Compare 2 DMA request enable */
  #define TIM_DIER_CC3DE     0x0800		/* Capture/Compare 3 DMA request enable */
  #define TIM_DIER_CC4DE     0x1000		/* Capture/Compare 4 DMA request enable */
  #define TIM_DIER_COMDE     0x2000		/* COM DMA request enable */
  #define TIM_DIER_TDE       0x4000		/* Trigger DMA request enable */
#define TOFF_TIM_SR         0x0010		/* (RW-16) TIM status register */
  #define TIM_SR_UIF         0x0001		/* Update interrupt Flag */
  #define TIM_SR_CC1IF       0x0002		/* Capture/Compare 1 interrupt Flag */
  #define TIM_SR_CC2IF       0x0004		/* Capture/Compare 2 interrupt Flag */
  #define TIM_SR_CC3IF       0x0008		/* Capture/Compare 3 interrupt Flag */
  #define TIM_SR_CC4IF       0x0010		/* Capture/Compare 4 interrupt Flag */
  #define TIM_SR_COMIF       0x0020		/* COM interrupt Flag */
  #define TIM_SR_TIF         0x0040		/* Trigger interrupt Flag */
  #define TIM_SR_BIF         0x0080		/* Break interrupt Flag */
  #define TIM_SR_CC1OF       0x0200		/* Capture/Compare 1 Overcapture Flag */
  #define TIM_SR_CC2OF       0x0400		/* Capture/Compare 2 Overcapture Flag */
  #define TIM_SR_CC3OF       0x0800		/* Capture/Compare 3 Overcapture Flag */
  #define TIM_SR_CC4OF       0x1000		/* Capture/Compare 4 Overcapture Flag */
#define TOFF_TIM_EGR        0x0014		/* (RW-16) TIM event generation register */
#define TOFF_TIM_CCMR1      0x0018		/* (RW-16) TIM capture/compare mode register 1 */
#define TOFF_TIM_CCMR2      0x001C		/* (RW-16) TIM capture/compare mode register 2 */
#define TOFF_TIM_CCER       0x0020		/* (RW-16) TIM capture/compare enable register */
#define TOFF_TIM_CNT        0x0024		/* (RW)    TIM counter register */
#define TOFF_TIM_PSC        0x0028		/* (RW-16) TIM prescaler */
#define TOFF_TIM_ARR        0x002C		/* (RW)    TIM auto-reload register */
#define TOFF_TIM_RCR        0x0030		/* (RW-16) TIM repetition counter register */
#define TOFF_TIM_CCR1       0x0034		/* (RW)    TIM capture/compare register 1 */
#define TOFF_TIM_CCR2       0x0038		/* (RW)    TIM capture/compare register 2 */
#define TOFF_TIM_CCR3       0x003C		/* (RW)    TIM capture/compare register 3 */
#define TOFF_TIM_CCR4       0x0040		/* (RW)    TIM capture/compare register 4 */
#define TOFF_TIM_BDTR       0x0044		/* (RW-16) TIM break and dead-time register */
#define TOFF_TIM_DCR        0x0048		/* (RW-16) TIM DMA control register */
#define TOFF_TIM_DMAR       0x004C		/* (RW-16) TIM DMA address for full transfer */
#define TOFF_TIM_OR         0x0050		/* (RW-16) TIM option register */

/*
 *  REAL-TIME CLOCK
 */
#define TADR_RTC_BASE       (APB1PERIPH_BASE + 0x2800)
#define TOFF_RTC_TR         0x0000		/* (RW) RTC time register */
  #define RTC_TR_PM                0x00400000
  #define RTC_TR_HT                0x00300000
  #define RTC_TR_HT_0              0x00100000
  #define RTC_TR_HT_1              0x00200000
  #define RTC_TR_HU                0x000F0000
  #define RTC_TR_HU_0              0x00010000
  #define RTC_TR_HU_1              0x00020000
  #define RTC_TR_HU_2              0x00040000
  #define RTC_TR_HU_3              0x00080000
  #define RTC_TR_MNT               0x00007000
  #define RTC_TR_MNT_0             0x00001000
  #define RTC_TR_MNT_1             0x00002000
  #define RTC_TR_MNT_2             0x00004000
  #define RTC_TR_MNU               0x00000F00
  #define RTC_TR_MNU_0             0x00000100
  #define RTC_TR_MNU_1             0x00000200
  #define RTC_TR_MNU_2             0x00000400
  #define RTC_TR_MNU_3             0x00000800
  #define RTC_TR_ST                0x00000070
  #define RTC_TR_ST_0              0x00000010
  #define RTC_TR_ST_1              0x00000020
  #define RTC_TR_ST_2              0x00000040
  #define RTC_TR_SU                0x0000000F
  #define RTC_TR_SU_0              0x00000001
  #define RTC_TR_SU_1              0x00000002
  #define RTC_TR_SU_2              0x00000004
  #define RTC_TR_SU_3              0x00000008
#define TOFF_RTC_DR         0x0004		/* (RW) RTC date register */
  #define RTC_DR_YT                0x00F00000
  #define RTC_DR_YT_0              0x00100000
  #define RTC_DR_YT_1              0x00200000
  #define RTC_DR_YT_2              0x00400000
  #define RTC_DR_YT_3              0x00800000
  #define RTC_DR_YU                0x000F0000
  #define RTC_DR_YU_0              0x00010000
  #define RTC_DR_YU_1              0x00020000
  #define RTC_DR_YU_2              0x00040000
  #define RTC_DR_YU_3              0x00080000
  #define RTC_DR_WDU               0x0000E000
  #define RTC_DR_WDU_0             0x00002000
  #define RTC_DR_WDU_1             0x00004000
  #define RTC_DR_WDU_2             0x00008000
  #define RTC_DR_MT                0x00001000
  #define RTC_DR_MU                0x00000F00
  #define RTC_DR_MU_0              0x00000100
  #define RTC_DR_MU_1              0x00000200
  #define RTC_DR_MU_2              0x00000400
  #define RTC_DR_MU_3              0x00000800
  #define RTC_DR_DT                0x00000030
  #define RTC_DR_DT_0              0x00000010
  #define RTC_DR_DT_1              0x00000020
  #define RTC_DR_DU                0x0000000F
  #define RTC_DR_DU_0              0x00000001
  #define RTC_DR_DU_1              0x00000002
  #define RTC_DR_DU_2              0x00000004
  #define RTC_DR_DU_3              0x00000008
#define TOFF_RTC_CR         0x0008		/* (RW) RTC control register */
  #define RTC_CR_COE               0x00800000
  #define RTC_CR_OSEL              0x00600000
  #define RTC_CR_OSEL_0            0x00200000
  #define RTC_CR_OSEL_1            0x00400000
  #define RTC_CR_POL               0x00100000
  #define RTC_CR_COSEL             0x00080000
  #define RTC_CR_BCK               0x00040000
  #define RTC_CR_SUB1H             0x00020000
  #define RTC_CR_ADD1H             0x00010000
  #define RTC_CR_TSIE              0x00008000
  #define RTC_CR_WUTIE             0x00004000
  #define RTC_CR_ALRBIE            0x00002000
  #define RTC_CR_ALRAIE            0x00001000
  #define RTC_CR_TSE               0x00000800
  #define RTC_CR_WUTE              0x00000400
  #define RTC_CR_ALRBE             0x00000200
  #define RTC_CR_ALRAE             0x00000100
  #define RTC_CR_DCE               0x00000080
  #define RTC_CR_FMT               0x00000040
  #define RTC_CR_BYPSHAD           0x00000020
  #define RTC_CR_REFCKON           0x00000010
  #define RTC_CR_TSEDGE            0x00000008
  #define RTC_CR_WUCKSEL           0x00000007
  #define RTC_CR_WUCKSEL_0         0x00000001
  #define RTC_CR_WUCKSEL_1         0x00000002
  #define RTC_CR_WUCKSEL_2         0x00000004
#define TOFF_RTC_ISR        0x000C		/* (RW) RTC initialization and status register */
  #define RTC_ISR_RECALPF          0x00010000
  #define RTC_ISR_TAMP1F           0x00002000
  #define RTC_ISR_TAMP2F           0x00004000
  #define RTC_ISR_TSOVF            0x00001000
  #define RTC_ISR_TSF              0x00000800
  #define RTC_ISR_WUTF             0x00000400
  #define RTC_ISR_ALRBF            0x00000200
  #define RTC_ISR_ALRAF            0x00000100
  #define RTC_ISR_INIT             0x00000080
  #define RTC_ISR_INITF            0x00000040
  #define RTC_ISR_RSF              0x00000020
  #define RTC_ISR_INITS            0x00000010
  #define RTC_ISR_SHPF             0x00000008
  #define RTC_ISR_WUTWF            0x00000004
  #define RTC_ISR_ALRBWF           0x00000002
  #define RTC_ISR_ALRAWF           0x00000001
#define TOFF_RTC_PRER       0x0010		/* (RW) RTC prescaler register */
#define TOFF_RTC_WUTR       0x0014		/* (RW) RTC wakeup timer register */
#define TOFF_RTC_CALIBR     0x0018		/* (RW) RTC calibration register */
#define TOFF_RTC_ALRMAR     0x001C		/* (RW) RTC alarm A register */
  #define RTC_ALRMAR_MSK4          0x80000000
  #define RTC_ALRMAR_WDSEL         0x40000000
  #define RTC_ALRMAR_DT            0x30000000
  #define RTC_ALRMAR_DT_0          0x10000000
  #define RTC_ALRMAR_DT_1          0x20000000
  #define RTC_ALRMAR_DU            0x0F000000
  #define RTC_ALRMAR_DU_0          0x01000000
  #define RTC_ALRMAR_DU_1          0x02000000
  #define RTC_ALRMAR_DU_2          0x04000000
  #define RTC_ALRMAR_DU_3          0x08000000
  #define RTC_ALRMAR_MSK3          0x00800000
  #define RTC_ALRMAR_PM            0x00400000
  #define RTC_ALRMAR_HT            0x00300000
  #define RTC_ALRMAR_HT_0          0x00100000
  #define RTC_ALRMAR_HT_1          0x00200000
  #define RTC_ALRMAR_HU            0x000F0000
  #define RTC_ALRMAR_HU_0          0x00010000
  #define RTC_ALRMAR_HU_1          0x00020000
  #define RTC_ALRMAR_HU_2          0x00040000
  #define RTC_ALRMAR_HU_3          0x00080000
  #define RTC_ALRMAR_MSK2          0x00008000
  #define RTC_ALRMAR_MNT           0x00007000
  #define RTC_ALRMAR_MNT_0         0x00001000
  #define RTC_ALRMAR_MNT_1         0x00002000
  #define RTC_ALRMAR_MNT_2         0x00004000
  #define RTC_ALRMAR_MNU           0x00000F00
  #define RTC_ALRMAR_MNU_0         0x00000100
  #define RTC_ALRMAR_MNU_1         0x00000200
  #define RTC_ALRMAR_MNU_2         0x00000400
  #define RTC_ALRMAR_MNU_3         0x00000800
  #define RTC_ALRMAR_MSK1          0x00000080
  #define RTC_ALRMAR_ST            0x00000070
  #define RTC_ALRMAR_ST_0          0x00000010
  #define RTC_ALRMAR_ST_1          0x00000020
  #define RTC_ALRMAR_ST_2          0x00000040
  #define RTC_ALRMAR_SU            0x0000000F
  #define RTC_ALRMAR_SU_0          0x00000001
  #define RTC_ALRMAR_SU_1          0x00000002
  #define RTC_ALRMAR_SU_2          0x00000004
  #define RTC_ALRMAR_SU_3          0x00000008
#define TOFF_RTC_ALRMBR     0x0020		/* (RW) RTC alarm B register */
  #define RTC_ALRMBR_MSK4          0x80000000
  #define RTC_ALRMBR_WDSEL         0x40000000
  #define RTC_ALRMBR_DT            0x30000000
  #define RTC_ALRMBR_DT_0          0x10000000
  #define RTC_ALRMBR_DT_1          0x20000000
  #define RTC_ALRMBR_DU            0x0F000000
  #define RTC_ALRMBR_DU_0          0x01000000
  #define RTC_ALRMBR_DU_1          0x02000000
  #define RTC_ALRMBR_DU_2          0x04000000
  #define RTC_ALRMBR_DU_3          0x08000000
  #define RTC_ALRMBR_MSK3          0x00800000
  #define RTC_ALRMBR_PM            0x00400000
  #define RTC_ALRMBR_HT            0x00300000
  #define RTC_ALRMBR_HT_0          0x00100000
  #define RTC_ALRMBR_HT_1          0x00200000
  #define RTC_ALRMBR_HU            0x000F0000
  #define RTC_ALRMBR_HU_0          0x00010000
  #define RTC_ALRMBR_HU_1          0x00020000
  #define RTC_ALRMBR_HU_2          0x00040000
  #define RTC_ALRMBR_HU_3          0x00080000
  #define RTC_ALRMBR_MSK2          0x00008000
  #define RTC_ALRMBR_MNT           0x00007000
  #define RTC_ALRMBR_MNT_0         0x00001000
  #define RTC_ALRMBR_MNT_1         0x00002000
  #define RTC_ALRMBR_MNT_2         0x00004000
  #define RTC_ALRMBR_MNU           0x00000F00
  #define RTC_ALRMBR_MNU_0         0x00000100
  #define RTC_ALRMBR_MNU_1         0x00000200
  #define RTC_ALRMBR_MNU_2         0x00000400
  #define RTC_ALRMBR_MNU_3         0x00000800
  #define RTC_ALRMBR_MSK1          0x00000080
  #define RTC_ALRMBR_ST            0x00000070
  #define RTC_ALRMBR_ST_0          0x00000010
  #define RTC_ALRMBR_ST_1          0x00000020
  #define RTC_ALRMBR_ST_2          0x00000040
  #define RTC_ALRMBR_SU            0x0000000F
  #define RTC_ALRMBR_SU_0          0x00000001
  #define RTC_ALRMBR_SU_1          0x00000002
  #define RTC_ALRMBR_SU_2          0x00000004
  #define RTC_ALRMBR_SU_3          0x00000008
#define TOFF_RTC_WPR        0x0024		/* (RW) RTC write protection register */
#define TOFF_RTC_SSR        0x0028		/* (RW) RTC sub second register */
#define TOFF_RTC_SHIFTR     0x002C		/* (RW) RTC shift control register */
#define TOFF_RTC_TSTR       0x0030		/* (RW) RTC time stamp time register */
#define TOFF_RTC_TSDR       0x0034		/* (RW) RTC time stamp date register */
#define TOFF_RTC_TSSSR      0x0038		/* (RW) RTC time-stamp sub second register */
#define TOFF_RTC_CALR       0x003C		/* (RW) RTC calibration register */
#define TOFF_RTC_TAFCR      0x0040		/* (RW) RTC tamper and alternate function configuration register */
#define TOFF_RTC_ALRMASSR   0x0044		/* (RW) RTC alarm A sub second register */
  #define RTC_ALRMASSR_MASKSS      0x0F000000
  #define RTC_ALRMASSR_MASKSS_0    0x01000000
  #define RTC_ALRMASSR_MASKSS_1    0x02000000
  #define RTC_ALRMASSR_MASKSS_2    0x04000000
  #define RTC_ALRMASSR_MASKSS_3    0x08000000
  #define RTC_ALRMASSR_SS          0x00007FFF
#define TOFF_RTC_ALRMBSSR   0x0048		/* (RW) RTC alarm B sub second register */
  #define RTC_ALRMBSSR_MASKSS      0x0F000000
  #define RTC_ALRMBSSR_MASKSS_0    0x01000000
  #define RTC_ALRMBSSR_MASKSS_1    0x02000000
  #define RTC_ALRMBSSR_MASKSS_2    0x04000000
  #define RTC_ALRMBSSR_MASKSS_3    0x08000000
  #define RTC_ALRMBSSR_SS          0x00007FFF
#define TOFF_RTC_BKP0R      0x0050		/* (RW) RTC backup register 0 */
#define TOFF_RTC_BKP1R      0x0054		/* (RW) RTC backup register 1 */
#define TOFF_RTC_BKP2R      0x0058		/* (RW) RTC backup register 2 */
#define TOFF_RTC_BKP3R      0x005C		/* (RW) RTC backup register 3 */
#define TOFF_RTC_BKP4R      0x0060		/* (RW) RTC backup register 4 */
#define TOFF_RTC_BKP5R      0x0064		/* (RW) RTC backup register 5 */
#define TOFF_RTC_BKP6R      0x0068		/* (RW) RTC backup register 6 */
#define TOFF_RTC_BKP7R      0x006C		/* (RW) RTC backup register 7 */
#define TOFF_RTC_BKP8R      0x0070		/* (RW) RTC backup register 8 */
#define TOFF_RTC_BKP9R      0x0074		/* (RW) RTC backup register 9 */
#define TOFF_RTC_BKP10R     0x0078		/* (RW) RTC backup register 10 */
#define TOFF_RTC_BKP11R     0x007C		/* (RW) RTC backup register 11 */
#define TOFF_RTC_BKP12R     0x0080		/* (RW) RTC backup register 12 */
#define TOFF_RTC_BKP13R     0x0084		/* (RW) RTC backup register 13 */
#define TOFF_RTC_BKP14R     0x0088		/* (RW) RTC backup register 14 */
#define TOFF_RTC_BKP15R     0x008C		/* (RW) RTC backup register 15 */
#define TOFF_RTC_BKP16R     0x0090		/* (RW) RTC backup register 16 */
#define TOFF_RTC_BKP17R     0x0094		/* (RW) RTC backup register 17 */
#define TOFF_RTC_BKP18R     0x0098		/* (RW) RTC backup register 18 */
#define TOFF_RTC_BKP19R     0x009C		/* (RW) RTC backup register 19 */

/*
 *  WINDOW WATCHDOG
 */
#define TADR_WWDG_BASE      (APB1PERIPH_BASE + 0x2C00)
#define TOFF_WWDG_CR        0x0000		/* (RW) WWDG Control register */
  #define WWDG_CR_T           0x0000007F	/* T[6:0] bits (7-Bit counter (MSB to LSB)) */
  #define WWDG_CR_T_0         0x00000001
  #define WWDG_CR_T_1         0x00000002
  #define WWDG_CR_T_2         0x00000004
  #define WWDG_CR_T_3         0x00000008
  #define WWDG_CR_T_4         0x00000010
  #define WWDG_CR_T_5         0x00000020
  #define WWDG_CR_T_6         0x00000040
  #define WWDG_CR_T0          WWDG_CR_T_0
  #define WWDG_CR_T1          WWDG_CR_T_1
  #define WWDG_CR_T2          WWDG_CR_T_2
  #define WWDG_CR_T3          WWDG_CR_T_3
  #define WWDG_CR_T4          WWDG_CR_T_4
  #define WWDG_CR_T5          WWDG_CR_T_5
  #define WWDG_CR_T6          WWDG_CR_T_6
  #define WWDG_CR_WDGA        0x00000080	/* Activation bit */
#define TOFF_WWDG_CFR       0x0004		/* (RW) WWDG Configuration register */
  #define WWDG_CFR_W          0x0000007F	/* W[6:0] bits (7-bit window value) */
  #define WWDG_CFR_W_0        0x00000001
  #define WWDG_CFR_W_1        0x00000002
  #define WWDG_CFR_W_2        0x00000004
  #define WWDG_CFR_W_3        0x00000008
  #define WWDG_CFR_W_4        0x00000010
  #define WWDG_CFR_W_5        0x00000020
  #define WWDG_CFR_W_6        0x00000040
  #define WWDG_CFR_W0         WWDG_CFR_W_0
  #define WWDG_CFR_W1         WWDG_CFR_W_1
  #define WWDG_CFR_W2         WWDG_CFR_W_2
  #define WWDG_CFR_W3         WWDG_CFR_W_3
  #define WWDG_CFR_W4         WWDG_CFR_W_4
  #define WWDG_CFR_W5         WWDG_CFR_W_5
  #define WWDG_CFR_W6         WWDG_CFR_W_6
  #define WWDG_CFR_WDGTB      0x00000180	/* WDGTB[1:0] bits (Timer Base) */
  #define WWDG_CFR_WDGTB_0    0x00000080
  #define WWDG_CFR_WDGTB_1    0x00000100
  #define WWDG_CFR_WDGTB0     WWDG_CFR_WDGTB_0
  #define WWDG_CFR_WDGTB1     WWDG_CFR_WDGTB_1
  #define WWDG_CFR_EWI        0x00000200	/* Early Wakeup Interrupt */
#define TOFF_WWDG_SR        0x0008		/* (R)  WWDG Status register */
  #define WWDG_SR_EWIF        0x00000001	/* Early Wakeup Interrupt Flag */

/*
 *  INDEPENDENT WATCHDOG
 */
#define TADR_IWDG_BASE      (APB1PERIPH_BASE + 0x3000)
#define TOFF_IWDG_KR        0x0000		/* (RW) IWDG Key register */
#define TOFF_IWDG_PR        0x0004		/* (RW) IWDG Prescaler register */
#define TOFF_IWDG_RLR       0x0008		/* (RW) IWDG Reload register */
#define TOFF_IWDG_SR        0x000C		/* (RW) IWDG Status register */

/*
 *  SERIAL PERIPHERAL IINTERFACE
 */
#define TADR_I2S2EXT_BASE   (APB1PERIPH_BASE + 0x3400)
#define TADR_SPI2_BASE      (APB1PERIPH_BASE + 0x3800)
#define TADR_SPI3_BASE      (APB1PERIPH_BASE + 0x3C00)
#define TADR_I2S3EXT_BASE   (APB1PERIPH_BASE + 0x4000)
#define TADR_SPI1_BASE      (APB2PERIPH_BASE + 0x3000)
#define TOFF_SPI_CR1        0x0000		/* (RW) SPI control register 1 (not used in I2S mode) */
  #define SPI_CR1_CPHA             0x00000001	/* Clock Phase */
  #define SPI_CR1_CPOL             0x00000002	/* Clock Polarity */
  #define SPI_CR1_MSTR             0x00000004	/* Master Selection */
  #define SPI_CR1_BR               0x00000038	/* Baud Rate Control */
  #define SPI_CR1_BR_0             0x00000008	/* Bit 0 */
  #define SPI_CR1_BR_1             0x00000010	/* Bit 1 */
  #define SPI_CR1_BR_2             0x00000020	/* Bit 2 */
  #define SPI_CR1_SPE              0x00000040	/* SPI Enable */
  #define SPI_CR1_LSBFIRST         0x00000080	/* Frame Format */
  #define SPI_CR1_SSI              0x00000100	/* Internal slave select */
  #define SPI_CR1_SSM              0x00000200	/* Software slave management */
  #define SPI_CR1_RXONLY           0x00000400	/* Receive only */
  #define SPI_CR1_DFF              0x00000800	/* Data Frame Format */
  #define SPI_CR1_CRCNEXT          0x00001000	/* Transmit CRC next */
  #define SPI_CR1_CRCEN            0x00002000	/* Hardware CRC calculation enable */
  #define SPI_CR1_BIDIOE           0x00004000	/* Output enable in bidirectional mode */
  #define SPI_CR1_BIDIMODE         0x00008000	/* Bidirectional data mode enable */
#define TOFF_SPI_CR2        0x0004		/* (RW) SPI control register 2 */
  #define SPI_CR2_RXDMAEN          0x00000001	/* Rx Buffer DMA Enable */
  #define SPI_CR2_TXDMAEN          0x00000002	/* Tx Buffer DMA Enable */
  #define SPI_CR2_SSOE             0x00000004	/* SS Output Enable */
  #define SPI_CR2_FRF              0x00000010	/* Frame Format */
  #define SPI_CR2_ERRIE            0x00000020	/* Error Interrupt Enable */
  #define SPI_CR2_RXNEIE           0x00000040	/* RX buffer Not Empty Interrupt Enable */
  #define SPI_CR2_TXEIE            0x00000080	/* Tx buffer Empty Interrupt Enable */
#define TOFF_SPI_SR         0x0008		/* (RW) SPI status register */
  #define SPI_SR_RXNE              0x00000001	/* Receive buffer Not Empty */
  #define SPI_SR_TXE               0x00000002	/* Transmit buffer Empty */
  #define SPI_SR_CHSIDE            0x00000004	/* Channel side */
  #define SPI_SR_UDR               0x00000008	/* Underrun flag */
  #define SPI_SR_CRCERR            0x00000010	/* CRC Error flag */
  #define SPI_SR_MODF              0x00000020	/* Mode fault */
  #define SPI_SR_OVR               0x00000040	/* Overrun flag */
  #define SPI_SR_BSY               0x00000080	/* Busy flag */
  #define SPI_SR_FRE               0x00000100	/* Frame format error flag */
#define TOFF_SPI_DR         0x000C		/* (RW) SPI data register */
#define TOFF_SPI_CRCPR      0x0010		/* (RW) SPI CRC polynomial register (not used in I2S mode) */
#define TOFF_SPI_RXCRCR     0x0014		/* (RW) SPI RX CRC register (not used in I2S mode) */
#define TOFF_SPI_TXCRCR     0x0018		/* (RW) SPI TX CRC register (not used in I2S mode) */
#define TOFF_SPI_I2SCFGR    0x001C		/* (RW) SPI_I2S configuration register */
  #define SPI_I2SCFGR_CHLEN        0x00000001	/* Channel length (number of bits per audio channel) */
  #define SPI_I2SCFGR_DATLEN       0x00000006	/* DATLEN[1:0] bits (Data length to be transferred)  */
  #define SPI_I2SCFGR_DATLEN_0     0x00000002	/* Bit 0 */
  #define SPI_I2SCFGR_DATLEN_1     0x00000004	/* Bit 1 */
  #define SPI_I2SCFGR_CKPOL        0x00000008	/* steady state clock polarity */
  #define SPI_I2SCFGR_I2SSTD       0x00000030	/* I2SSTD[1:0] bits (I2S standard selection) */
  #define SPI_I2SCFGR_I2SSTD_0     0x00000010	/* Bit 0 */
  #define SPI_I2SCFGR_I2SSTD_1     0x00000020	/* Bit 1 */
  #define SPI_I2SCFGR_PCMSYNC      0x00000080	/* PCM frame synchronization */
  #define SPI_I2SCFGR_I2SCFG       0x00000300	/* I2SCFG[1:0] bits (I2S configuration mode) */
  #define SPI_I2SCFGR_I2SCFG_0     0x00000100	/* Bit 0 */
  #define SPI_I2SCFGR_I2SCFG_1     0x00000200	/* Bit 1 */
  #define SPI_I2SCFGR_I2SE         0x00000400	/* I2S Enable */
  #define SPI_I2SCFGR_I2SMOD       0x00000800	/* I2S mode selection */
#define TOFF_SPI_I2SPR      0x0020		/* (RW) SPI_I2S prescaler register */

/*
 *  UNIVERSAL SYNCHRONOUS ASYNCHORONOUS RECEIVER TRANSMITTER
 */
#define TADR_USART2_BASE    (APB1PERIPH_BASE + 0x4400)
#define TADR_USART3_BASE    (APB1PERIPH_BASE + 0x4800)
#define TADR_UART4_BASE     (APB1PERIPH_BASE + 0x4C00)
#define TADR_UART5_BASE     (APB1PERIPH_BASE + 0x5000)
#define TADR_USART1_BASE    (APB2PERIPH_BASE + 0x1000)
#define TADR_USART6_BASE    (APB2PERIPH_BASE + 0x1400)
#define TOFF_USART_SR       0x0000		/* (RW-16) USART Status register */
  #define USART_SR_PE        0x0001		/* Parity Error */
  #define USART_SR_FE        0x0002		/* Framing Error */
  #define USART_SR_NE        0x0004		/* Noise Error Flag */
  #define USART_SR_ORE       0x0008		/* OverRun Error */
  #define USART_SR_IDLE      0x0010		/* IDLE line detected */
  #define USART_SR_RXNE      0x0020		/* Read Data Register Not Empty */
  #define USART_SR_TC        0x0040		/* Transmission Complete */
  #define USART_SR_TXE       0x0080		/* Transmit Data Register Empty */
  #define USART_SR_LBD       0x0100		/* LIN Break Detection Flag */
  #define USART_SR_CTS       0x0200		/* CTS Flag */
#define TOFF_USART_DR       0x0004		/* (RW-16) USART Data register */
#define TOFF_USART_BRR      0x0008		/* (RW-16) USART Baud rate register */
#define TOFF_USART_CR1      0x000C		/* (RW-16) USART Control register 1 */
  #define USART_CR1_SBK      0x0001		/* Send Break */
  #define USART_CR1_RWU      0x0002		/* Receiver wakeup */
  #define USART_CR1_RE       0x0004		/* Receiver Enable */
  #define USART_CR1_TE       0x0008		/* Transmitter Enable */
  #define USART_CR1_IDLEIE   0x0010		/* IDLE Interrupt Enable */
  #define USART_CR1_RXNEIE   0x0020		/* RXNE Interrupt Enable */
  #define USART_CR1_TCIE     0x0040		/* Transmission Complete Interrupt Enable */
  #define USART_CR1_TXEIE    0x0080		/* PE Interrupt Enable */
  #define USART_CR1_PEIE     0x0100		/* PE Interrupt Enable */
  #define USART_CR1_PS       0x0200		/* Parity Selection */
  #define USART_CR1_PCE      0x0400		/* Parity Control Enable */
  #define USART_CR1_WAKE     0x0800		/* Wakeup method */
  #define USART_CR1_M        0x1000		/* Word length */
  #define USART_CR1_UE       0x2000		/* USART Enable */
  #define USART_CR1_OVER8    0x8000		/* USART Oversampling by 8 enable */
#define TOFF_USART_CR2      0x0010		/* (RW-16) USART Control register 2 */
  #define USART_CR2_ADD      0x000F		/* Address of the USART node */
  #define USART_CR2_LBDL     0x0020		/* LIN Break Detection Length */
  #define USART_CR2_LBDIE    0x0040		/* LIN Break Detection Interrupt Enable */
  #define USART_CR2_LBCL     0x0100		/* Last Bit Clock pulse */
  #define USART_CR2_CPHA     0x0200		/* Clock Phase */
  #define USART_CR2_CPOL     0x0400		/* Clock Polarity */
  #define USART_CR2_CLKEN    0x0800		/* Clock Enable */
  #define USART_CR2_STOP     0x3000		/* STOP[1:0] bits (STOP bits) */
  #define USART_CR2_STOP_0   0x1000		/* Bit 0 */
  #define USART_CR2_STOP_1   0x2000		/* Bit 1 */
  #define USART_CR2_LINEN    0x4000		/* LIN mode enable */
#define TOFF_USART_CR3      0x0014		/* (RW-16) USART Control register 3 */
  #define USART_CR3_EIE      0x0001		/* Error Interrupt Enable */
  #define USART_CR3_IREN     0x0002		/* IrDA mode Enable */
  #define USART_CR3_IRLP     0x0004		/* IrDA Low-Power */
  #define USART_CR3_HDSEL    0x0008		/* Half-Duplex Selection */
  #define USART_CR3_NACK     0x0010		/* Smartcard NACK enable */
  #define USART_CR3_SCEN     0x0020		/* Smartcard mode enable */
  #define USART_CR3_DMAR     0x0040		/* DMA Enable Receiver */
  #define USART_CR3_DMAT     0x0080		/* DMA Enable Transmitter */
  #define USART_CR3_RTSE     0x0100		/* RTS Enable */
  #define USART_CR3_CTSE     0x0200		/* CTS Enable */
  #define USART_CR3_CTSIE    0x0400		/* CTS Interrupt Enable */
  #define USART_CR3_ONEBIT   0x0800		/* USART One bit method enable */
#define TOFF_USART_GTPR     0x0018		/* (RW-16) USART Guard time and prescaler register */
  #define USART_GTPR_PSC     0x00FF		/* PSC[7:0] bits (Prescaler value) */
  #define USART_GTPR_PSC_0   0x0001		/* Bit 0 */
  #define USART_GTPR_PSC_1   0x0002		/* Bit 1 */
  #define USART_GTPR_PSC_2   0x0004		/* Bit 2 */
  #define USART_GTPR_PSC_3   0x0008		/* Bit 3 */
  #define USART_GTPR_PSC_4   0x0010		/* Bit 4 */
  #define USART_GTPR_PSC_5   0x0020		/* Bit 5 */
  #define USART_GTPR_PSC_6   0x0040		/* Bit 6 */
  #define USART_GTPR_PSC_7   0x0080		/* Bit 7 */
  #define USART_GTPR_GT      0xFF00		/* Guard time value */

/*
 *  INTER-INTERATED CIRCUIT IINTERFACE(16)
 */
#define TADR_I2C1_BASE      (APB1PERIPH_BASE + 0x5400)
#define TADR_I2C2_BASE      (APB1PERIPH_BASE + 0x5800)
#define TADR_I2C3_BASE      (APB1PERIPH_BASE + 0x5C00)
#define TOFF_I2C_CR1        0x0000		/* (RW-16) I2C Control register 1 */
  #define I2C_CR1_PE         0x00000001	/* Peripheral Enable */
  #define I2C_CR1_SMBUS      0x00000002	/* SMBus Mode */
  #define I2C_CR1_SMBTYPE    0x00000008	/* SMBus Type */
  #define I2C_CR1_ENARP      0x00000010	/* ARP Enable */
  #define I2C_CR1_ENPEC      0x00000020	/* PEC Enable */
  #define I2C_CR1_ENGC       0x00000040	/* General Call Enable */
  #define I2C_CR1_NOSTRETCH  0x00000080	/* Clock Stretching Disable (Slave mode) */
  #define I2C_CR1_START      0x00000100	/* Start Generation */
  #define I2C_CR1_STOP       0x00000200	/* Stop Generation */
  #define I2C_CR1_ACK        0x00000400	/* Acknowledge Enable */
  #define I2C_CR1_POS        0x00000800	/* Acknowledge/PEC Position (for data reception) */
  #define I2C_CR1_PEC        0x00001000	/* Packet Error Checking */
  #define I2C_CR1_ALERT      0x00002000	/* SMBus Alert */
  #define I2C_CR1_SWRST      0x00008000	/* Software Reset */
#define TOFF_I2C_CR2        0x0004		/* (RW-16) I2C Control register 2 */
  #define I2C_CR2_FREQ       0x0000003F	/* FREQ[5:0] bits (Peripheral Clock Frequency) */
  #define I2C_CR2_FREQ_0     0x00000001	/* Bit 0 */
  #define I2C_CR2_FREQ_1     0x00000002	/* Bit 1 */
  #define I2C_CR2_FREQ_2     0x00000004	/* Bit 2 */
  #define I2C_CR2_FREQ_3     0x00000008	/* Bit 3 */
  #define I2C_CR2_FREQ_4     0x00000010	/* Bit 4 */
  #define I2C_CR2_FREQ_5     0x00000020	/* Bit 5 */
  #define I2C_CR2_ITERREN    0x00000100	/* Error Interrupt Enable  */
  #define I2C_CR2_ITEVTEN    0x00000200	/* Event Interrupt Enable  */
  #define I2C_CR2_ITBUFEN    0x00000400	/* Buffer Interrupt Enable */
  #define I2C_CR2_DMAEN      0x00000800	/* DMA Requests Enable */
  #define I2C_CR2_LAST       0x00001000	/* DMA Last Transfer */
#define TOFF_I2C_OAR1       0x0008		/* (RW-16) I2C Own address register 1 */
  #define I2C_OAR1_ADD1_7   0x000000FE	/* Interface Address */
  #define I2C_OAR1_ADD8_9   0x00000300	/* Interface Address */
  #define I2C_OAR1_ADD0      0x00000001	/* Bit 0 */
  #define I2C_OAR1_ADD1      0x00000002	/* Bit 1 */
  #define I2C_OAR1_ADD2      0x00000004	/* Bit 2 */
  #define I2C_OAR1_ADD3      0x00000008	/* Bit 3 */
  #define I2C_OAR1_ADD4      0x00000010	/* Bit 4 */
  #define I2C_OAR1_ADD5      0x00000020	/* Bit 5 */
  #define I2C_OAR1_ADD6      0x00000040	/* Bit 6 */
  #define I2C_OAR1_ADD7      0x00000080	/* Bit 7 */
  #define I2C_OAR1_ADD8      0x00000100	/* Bit 8 */
  #define I2C_OAR1_ADD9      0x00000200	/* Bit 9 */
  #define I2C_OAR1_OA1EN     0x00004000	/* Own address 1 enable */
  #define I2C_OAR1_ADDMODE   0x00008000	/* Addressing Mode (Slave mode) */
#define TOFF_I2C_OAR2       0x000C		/* (RW-16) I2C Own address register 2 */
#define TOFF_I2C_DR         0x0010		/* (RW-16) I2C Data register */
#define TOFF_I2C_SR1        0x0014		/* (R-16)  I2C Status register 1 */
  #define I2C_SR1_SB         0x00000001	/* Start Bit (Master mode) */
  #define I2C_SR1_ADDR       0x00000002	/* Address sent (master mode)/matched (slave mode) */
  #define I2C_SR1_BTF        0x00000004	/* Byte Transfer Finished */
  #define I2C_SR1_ADD10      0x00000008	/* 10-bit header sent (Master mode) */
  #define I2C_SR1_STOPF      0x00000010	/* Stop detection (Slave mode) */
  #define I2C_SR1_RXNE       0x00000040	/* Data Register not Empty (receivers) */
  #define I2C_SR1_TXE        0x00000080	/* Data Register Empty (transmitters) */
  #define I2C_SR1_BERR       0x00000100	/* Bus Error */
  #define I2C_SR1_ARLO       0x00000200	/* Arbitration Lost (master mode) */
  #define I2C_SR1_AF         0x00000400	/* Acknowledge Failure */
  #define I2C_SR1_OVR        0x00000800	/* Overrun/Underrun */
  #define I2C_SR1_PECERR     0x00001000	/* PEC Error in reception */
  #define I2C_SR1_TIMEOUT    0x00004000	/* Timeout or Tlow Error */
  #define I2C_SR1_SMBALERT   0x00008000	/* SMBus Alert */
#define TOFF_I2C_SR2        0x0018		/* (R-16)  I2C Status register 2 */
  #define I2C_SR2_MSL        0x00000001	/* Master/Slave */
  #define I2C_SR2_BUSY       0x00000002	/* Bus Busy */
  #define I2C_SR2_TRA        0x00000004	/* Transmitter/Receiver */
  #define I2C_SR2_GENCALL    0x00000010	/* General Call Address (Slave mode) */
  #define I2C_SR2_SMBDEFAULT 0x00000020	/* SMBus Device Default Address (Slave mode) */
  #define I2C_SR2_SMBHOST    0x00000040	/* SMBus Host Header (Slave mode) */
  #define I2C_SR2_DUALF      0x00000080	/* Dual Flag (Slave mode) */
  #define I2C_SR2_PEC        0x0000FF00	/* Packet Error Checking Register */
#define TOFF_I2C_CCR        0x001C		/* (RW-16) I2C Clock control register */
  #define I2C_CCR_CCR        0x00000FFF	/* Clock Control Register in Fast/Standard mode (Master mode) */
  #define I2C_CCR_DUTY       0x00004000	/* Fast Mode Duty Cycle */
  #define I2C_CCR_FS         0x00008000	/* I2C Master Mode Selection */
#define TOFF_I2C_TRISE      0x0020		/* (RW-16) I2C TRISE register */

/*
 *  CONTROLLER AREA NETWORK
 */
#define TADR_CAN1_BASE      (APB1PERIPH_BASE + 0x6400)
#define TADR_CAN2_BASE      (APB1PERIPH_BASE + 0x6800)
#define TOFF_CAN_MCR        0x0000		/* (RW) CAN master control register */
#define TOFF_CAN_MSR        0x0004		/* (R)  CAN master status register */
#define TOFF_CAN_TSR        0x0008		/* (R)  CAN transmit status register */
#define TOFF_CAN_RF0R       0x000C		/* (RW) CAN receive FIFO 0 register */
#define TOFF_CAN_RF1R       0x0010		/* (RW) CAN receive FIFO 1 register */
#define TOFF_CAN_IER        0x0014		/* (RW) CAN interrupt enable register */
#define TOFF_CAN_ESR        0x0018		/* (RW) CAN error status register */
#define TOFF_CAN_BTR        0x001C		/* (RW) CAN bit timing register */
										/* CAN TX MailBox */
#define TOFF_CAN_TIR1       0x0180		/* (RW) CAN(1) TX mailbox identifier register */
#define TOFF_CAN_TDTR1      0x0184		/* (RW) CAN(1) mailbox data length control and time stamp register */
#define TOFF_CAN_TDLR1      0x0188		/* (RW) CAN(1) mailbox data low register */
#define TOFF_CAN_TDHR1      0x018C		/* (RW) CAN(1) mailbox data high register */
#define TOFF_CAN_TIR2       0x0190		/* (RW) CAN(2) TX mailbox identifier register */
#define TOFF_CAN_TDTR2      0x0194		/* (RW) CAN(2) mailbox data length control and time stamp register */
#define TOFF_CAN_TDLR2      0x0198		/* (RW) CAN(2) mailbox data low register */
#define TOFF_CAN_TDHR2      0x019C		/* (RW) CAN(2) mailbox data high register */
#define TOFF_CAN_TIR3       0x01A0		/* (RW) CAN(3) TX mailbox identifier register */
#define TOFF_CAN_TDTR3      0x01A4		/* (RW) CAN(3) mailbox data length control and time stamp register */
#define TOFF_CAN_TDLR3      0x01A8		/* (RW) CAN(3) mailbox data low register */
#define TOFF_CAN_TDHR3      0x01AC		/* (RW) CAN(3) mailbox data high register */
										/* CAN FIFO MailBox */
#define TOFF_CAN_RIR1       0x01B0		/* (RW) CAN(1) receive FIFO mailbox identifier register */
#define TOFF_CAN_RDTR1      0x01B4		/* (RW) CAN(1) receive FIFO mailbox data length control and time stamp register */
#define TOFF_CAN_RDLR1      0x01B8		/* (RW) CAN(1) receive FIFO mailbox data low register */
#define TOFF_CAN_RDHR1      0x01BC		/* (RW) CAN(1) receive FIFO mailbox data high register */
#define TOFF_CAN_RIR2       0x01C0		/* (RW) CAN(2) receive FIFO mailbox identifier register */
#define TOFF_CAN_RDTR2      0x01C4		/* (RW) CAN(2) receive FIFO mailbox data length control and time stamp register */
#define TOFF_CAN_RDLR2      0x01C8		/* (RW) CAN(2) receive FIFO mailbox data low register */
#define TOFF_CAN_RDHR2      0x01CC		/* (RW) CAN(2) receive FIFO mailbox data high register */
#define TOFF_CAN_FMR        0x0200		/* (RW) CAN filter master register */
#define TOFF_CAN_FM1R       0x0204		/* (RW) CAN filter mode register */
#define TOFF_CAN_FS1R       0x020C		/* (RW) CAN filter scale register */
#define TOFF_CAN_FFA1R      0x0214		/* (RW) CAN filter FIFO assignment register */
#define TOFF_CAN_FA1R       0x0218		/* (RW) CAN filter activation register */
#define TOFF_CAN_FR_BASE    0x0240
#define TOFF_CAN_FR1        0x0240		/* (RW) CAN Filter bank register 1 */
#define TOFF_CAN_FR2        0x0244		/* (RW) CAN Filter bank register 1 */

/*
 *  POWER CONTROL
 */
#define TADR_PWR_BASE       (APB1PERIPH_BASE + 0x7000)
#define TOFF_PWR_CR         0x0000		/* (RW) PWR power control register */
  #define PWR_CR_LPDS              0x00000001	/* Low-Power Deepsleep */
  #define PWR_CR_PDDS              0x00000002	/* Power Down Deepsleep */
  #define PWR_CR_CWUF              0x00000004	/* Clear Wakeup Flag */
  #define PWR_CR_CSBF              0x00000008	/* Clear Standby Flag */
  #define PWR_CR_PVDE              0x00000010	/* Power Voltage Detector Enable */
  #define PWR_CR_PLS_0             0x00000020	/* Bit 0 */
  #define PWR_CR_PLS_1             0x00000040	/* Bit 1 */
  #define PWR_CR_PLS_2             0x00000080	/* Bit 2 */
  #define PWR_CR_DBP               0x00000100	/* Disable Backup Domain write protection */
  #define PWR_CR_FPDS              0x00000200	/* Flash power down in Stop mode */
#if defined(TOPPERS_STM32F401_NUCLEO) || defined(TOPPERS_STM32F446_NUCLEO64) || defined(TOPPERS_STM32F446_NUCLEO144)
  #define PWR_CR_VOS               0x0000C000   /* VOS[1:0] bits (Regulator voltage scaling output selection) */ 
  #define PWR_CR_VOS_0             0x00004000   /* Bit 0 */
  #define PWR_CR_VOS_1             0x00008000   /* Bit 1 */
#else
  #define PWR_CR_VOS               0x00004000	/* Regulator voltage scaling output selection */
#endif
  #define PWR_CR_ODEN              0x00010000	/*  Over Drive enable */
  #define PWR_CR_ODSWEN            0x00020000	/* Over Drive switch enabled */
  #define PWR_CR_UDEN_0            0x00040000	/* Under Drive enable in stop mode Bit 0 */
  #define PWR_CR_UDEN_1            0x00080000	/* Under Drive enable in stop mode Bit 1 */
  /* Legacy define */
  #define PWR_CR_PMODE             PWR_CR_VOS
#define TOFF_PWR_CSR        0x0004		/* (RW) PWR power control/status register */
  #define PWR_CSR_WUF              0x00000001	/* Wakeup Flag */
  #define PWR_CSR_SBF              0x00000002	/* Standby Flag */
  #define PWR_CSR_PVDO             0x00000004	/* PVD Output */
  #define PWR_CSR_BRR              0x00000008	/* Backup regulator ready */
  #define PWR_CSR_EWUP             0x00000100	/* Enable WKUP pin */
  #define PWR_CSR_BRE              0x00000200	/* Backup regulator enable */
  #define PWR_CSR_VOSRDY           0x00004000	/* Regulator voltage scaling output selection ready */
  #define PWR_CSR_ODRDY            0x00010000	/* Over Drive generator ready */
  #define PWR_CSR_ODSWRDY          0x00020000	/* Over Drive Switch ready */
  #define PWR_CSR_UDSWRDY          0x000C0000	/* Under Drive ready */
  /* Legacy define */
  #define PWR_CSR_REGRDY           PWR_CSR_VOSRDY

/*
 *  DIGITAL TO ANALOG CONVTER
 */
#define TADR_DAC_BASE       (APB1PERIPH_BASE + 0x7400)
#define TOFF_DAC_CR         0x0000		/* (RW) DAC control register */
#define TOFF_DAC_SWTRIGR	0x0004		/* (RW) DAC software trigger register */
#define TOFF_DAC_DHR12R1    0x0008		/* (RW) DAC channel1 12-bit right-aligned data holding register */
#define TOFF_DAC_DHR12L1    0x000C		/* (RW) DAC channel1 12-bit left aligned data holding register */
#define TOFF_DAC_DHR8R1     0x0010		/* (RW) DAC channel1 8-bit right aligned data holding register */
#define TOFF_DAC_DHR12R2    0x0014		/* (RW) DAC channel2 12-bit right aligned data holding register */
#define TOFF_DAC_DHR12L2    0x0018		/* (RW) DAC channel2 12-bit left aligned data holding register */
#define TOFF_DAC_DHR8R2     0x001C		/* (RW) DAC channel2 8-bit right-aligned data holding register */
#define TOFF_DAC_DHR12RD    0x0020		/* (RW) Dual DAC 12-bit right-aligned data holding register */
#define TOFF_DAC_DHR12LD    0x0024		/* (RW) DUAL DAC 12-bit left aligned data holding register */
#define TOFF_DAC_DHR8RD     0x0028		/* (RW) DUAL DAC 8-bit right aligned data holding register */
#define TOFF_DAC_DOR1       0x002C		/* (RW) DAC channel1 data output register */
#define TOFF_DAC_DOR2       0x0030		/* (RW) DAC channel2 data output register */
#define TOFF_DAC_SR         0x0034		/* (RW) DAC status register */


/*
 *  ANALOG TO DIGITAL CONVERTER
 */
#define TADR_ADC1_BASE      (APB2PERIPH_BASE + 0x2000)
#define TADR_ADC2_BASE      (APB2PERIPH_BASE + 0x2100)
#define TADR_ADC3_BASE      (APB2PERIPH_BASE + 0x2200)
#define TOFF_ADC_SR         0x0000		/* (RW) ADC status register */
  #define ADC_SR_AWD                0x00000001	/* Analog watchdog flag */
  #define ADC_SR_EOC                0x00000002	/* End of conversion */
  #define ADC_SR_JEOC               0x00000004	/* Injected channel end of conversion */
  #define ADC_SR_JSTRT              0x00000008	/* Injected channel Start flag */
  #define ADC_SR_STRT               0x00000010	/* Regular channel Start flag */
  #define ADC_SR_OVR                0x00000020	/* Overrun flag */
#define TOFF_ADC_CR1        0x0004		/* (RW) ADC control register 1 */
  #define ADC_CR1_AWDCH             0x0000001F	/* AWDCH bits (Analog watchdog channel select bits) */
  #define ADC_CR1_AWDCH_0           0x00000001	/* Bit 0 */
  #define ADC_CR1_AWDCH_1           0x00000002	/* Bit 1 */
  #define ADC_CR1_AWDCH_2           0x00000004	/* Bit 2 */
  #define ADC_CR1_AWDCH_3           0x00000008	/* Bit 3 */
  #define ADC_CR1_AWDCH_4           0x00000010	/* Bit 4 */
  #define ADC_CR1_EOCIE             0x00000020	/* Interrupt enable for EOC */
  #define ADC_CR1_AWDIE             0x00000040	/* Analog Watchdog interrupt enable */
  #define ADC_CR1_JEOCIE            0x00000080	/* Interrupt enable for injected channels */
  #define ADC_CR1_SCAN              0x00000100	/* Scan mode */
  #define ADC_CR1_AWDSGL            0x00000200	/* Enable the watchdog on a single channel in scan mode */
  #define ADC_CR1_JAUTO             0x00000400	/* Automatic injected group conversion */
  #define ADC_CR1_DISCEN            0x00000800	/* Discontinuous mode on regular channels */
  #define ADC_CR1_JDISCEN           0x00001000	/* Discontinuous mode on injected channels */
  #define ADC_CR1_DISCNUM           0x0000E000	/* DISCNUM bits (Discontinuous mode channel count) */
  #define ADC_CR1_DISCNUM_0         0x00002000	/* Bit 0 */
  #define ADC_CR1_DISCNUM_1         0x00004000	/* Bit 1 */
  #define ADC_CR1_DISCNUM_2         0x00008000	/* Bit 2 */
  #define ADC_CR1_JAWDEN            0x00400000	/* Analog watchdog enable on injected channels */
  #define ADC_CR1_AWDEN             0x00800000	/* Analog watchdog enable on regular channels */
  #define ADC_CR1_RES               0x03000000	/* RES bits (Resolution) */
  #define ADC_CR1_RES_0             0x01000000	/* Bit 0 */
  #define ADC_CR1_RES_1             0x02000000	/* Bit 1 */
  #define ADC_CR1_OVRIE             0x04000000	/* Overrun interrupt enable */
#define TOFF_ADC_CR2        0x0008		/* (RW) ADC control register 2 */
  #define ADC_CR2_ADON              0x00000001	/* A/D Converter ON / OFF */
  #define ADC_CR2_CONT              0x00000002	/* Continuous Conversion */
  #define ADC_CR2_DMA               0x00000100	/* Direct Memory access mode */
  #define ADC_CR2_DDS               0x00000200	/* DMA disable selection (Single ADC) */
  #define ADC_CR2_EOCS              0x00000400	/* End of conversion selection */
  #define ADC_CR2_ALIGN             0x00000800	/* Data Alignment */
  #define ADC_CR2_JEXTSEL           0x000F0000	/* JEXTSEL bits (External event select for injected group) */
  #define ADC_CR2_JEXTSEL_0         0x00010000	/* Bit 0 */
  #define ADC_CR2_JEXTSEL_1         0x00020000	/* Bit 1 */
  #define ADC_CR2_JEXTSEL_2         0x00040000	/* Bit 2 */
  #define ADC_CR2_JEXTSEL_3         0x00080000	/* Bit 3 */
  #define ADC_CR2_JEXTEN            0x00300000	/* JEXTEN bits (External Trigger Conversion mode for injected channelsp) */
  #define ADC_CR2_JEXTEN_0          0x00100000	/* Bit 0 */
  #define ADC_CR2_JEXTEN_1          0x00200000	/* Bit 1 */
  #define ADC_CR2_JSWSTART          0x00400000	/* Start Conversion of injected channels */
  #define ADC_CR2_EXTSEL            0x0F000000	/* EXTSEL bits (External Event Select for regular group) */
  #define ADC_CR2_EXTSEL_0          0x01000000	/* Bit 0 */
  #define ADC_CR2_EXTSEL_1          0x02000000	/* Bit 1 */
  #define ADC_CR2_EXTSEL_2          0x04000000	/* Bit 2 */
  #define ADC_CR2_EXTSEL_3          0x08000000	/* Bit 3 */
  #define ADC_CR2_EXTEN             0x30000000	/* EXTEN bits (External Trigger Conversion mode for regular channelsp) */
  #define ADC_CR2_EXTEN_0           0x10000000	/* Bit 0 */
  #define ADC_CR2_EXTEN_1           0x20000000	/* Bit 1 */
  #define ADC_CR2_SWSTART           0x40000000	/* Start Conversion of regular channels */
#define TOFF_ADC_SMPR1      0x000C		/* (RW) ADC sample time register 1 */
  #define ADC_SMPR1_SMP10           0x00000007	/* SMP10 bits (Channel 10 Sample time selection) */
  #define ADC_SMPR1_SMP11           0x00000038	/* SMP11 bits (Channel 11 Sample time selection) */
  #define ADC_SMPR1_SMP12           0x000001C0	/* SMP12 bits (Channel 12 Sample time selection) */
  #define ADC_SMPR1_SMP13           0x00000E00	/* SMP13 bits (Channel 13 Sample time selection) */
  #define ADC_SMPR1_SMP14           0x00007000	/* SMP14 bits (Channel 14 Sample time selection) */
  #define ADC_SMPR1_SMP15           0x00038000	/* SMP15 bits (Channel 15 Sample time selection) */
  #define ADC_SMPR1_SMP16           0x001C0000	/* SMP16 bits (Channel 16 Sample time selection) */
  #define ADC_SMPR1_SMP17           0x00E00000	/* SMP17 bits (Channel 17 Sample time selection) */
  #define ADC_SMPR1_SMP18           0x07000000	/* SMP18 bits (Channel 18 Sample time selection) */
#define TOFF_ADC_SMPR2      0x0010		/* (RW) ADC sample time register 2 */
  #define ADC_SMPR2_SMP0            0x00000007	/* SMP0 bits (Channel 0 Sample time selection) */
  #define ADC_SMPR2_SMP1            0x00000038	/* SMP1 bits (Channel 1 Sample time selection) */
  #define ADC_SMPR2_SMP2            0x000001C0	/* SMP2 bits (Channel 2 Sample time selection) */
  #define ADC_SMPR2_SMP3            0x00000E00	/* SMP3 bits (Channel 3 Sample time selection) */
  #define ADC_SMPR2_SMP4            0x00007000	/* SMP4 bits (Channel 4 Sample time selection) */
  #define ADC_SMPR2_SMP5            0x00038000	/* SMP5 bits (Channel 5 Sample time selection) */
  #define ADC_SMPR2_SMP6            0x001C0000	/* SMP6 bits (Channel 6 Sample time selection) */
  #define ADC_SMPR2_SMP7            0x00E00000	/* SMP7 bits (Channel 7 Sample time selection) */
  #define ADC_SMPR2_SMP8            0x07000000	/* SMP8 bits (Channel 8 Sample time selection) */
  #define ADC_SMPR2_SMP9            0x38000000	/* SMP9 bits (Channel 9 Sample time selection) */
#define TOFF_ADC_JOFR1      0x0014		/* (RW) ADC injected channel data offset register 1 */
#define TOFF_ADC_JOFR2      0x0018		/* (RW) ADC injected channel data offset register 2 */
#define TOFF_ADC_JOFR3      0x001C		/* (RW) ADC injected channel data offset register 3 */
#define TOFF_ADC_JOFR4      0x0020		/* (RW) ADC injected channel data offset register 4 */
#define TOFF_ADC_HTR        0x0024		/* (RW) ADC watchdog higher threshold register */
#define TOFF_ADC_LTR        0x0028		/* (RW) ADC watchdog lower threshold register */
#define TOFF_ADC_SQR1       0x002C		/* (RW) ADC regular sequence register 1 */
  #define ADC_SQR1_SQ13             0x0000001F	/* SQ13 bits (13th conversion in regular sequence) */
  #define ADC_SQR1_SQ14             0x000003E0	/* SQ14 bits (14th conversion in regular sequence) */
  #define ADC_SQR1_SQ15             0x00007C00	/* SQ15 bits (15th conversion in regular sequence) */
  #define ADC_SQR1_SQ16             0x000F8000	/* SQ16 bits (16th conversion in regular sequence) */
  #define ADC_SQR1_L                0x00F00000	/* L[3:0] bits (Regular channel sequence length) */
#define TOFF_ADC_SQR2       0x0030		/* (RW) ADC regular sequence register 2 */
  #define ADC_SQR2_SQ7              0x0000001F	/* SQ7 bits (7th conversion in regular sequence) */
  #define ADC_SQR2_SQ8              0x000003E0	/* SQ8 bits (8th conversion in regular sequence) */
  #define ADC_SQR2_SQ9              0x00007C00	/* SQ9 bits (9th conversion in regular sequence) */
  #define ADC_SQR2_SQ10             0x000F8000	/* SQ10 bits (10th conversion in regular sequence) */
  #define ADC_SQR2_SQ11             0x01F00000	/* SQ11 bits (11th conversion in regular sequence) */
  #define ADC_SQR2_SQ12             0x3E000000	/* SQ12 bits (12th conversion in regular sequence) */
#define TOFF_ADC_SQR3       0x0034		/* (RW) ADC regular sequence register 3 */
  #define ADC_SQR3_SQ1              0x0000001F	/* SQ1 bits (1st conversion in regular sequence) */
  #define ADC_SQR3_SQ2              0x000003E0	/* SQ2 bits (2nd conversion in regular sequence) */
  #define ADC_SQR3_SQ3              0x00007C00	/* SQ3 bits (3rd conversion in regular sequence) */
  #define ADC_SQR3_SQ4              0x000F8000	/* SQ4 bits (4th conversion in regular sequence) */
  #define ADC_SQR3_SQ5              0x01F00000	/* SQ5 bits (5th conversion in regular sequence) */
  #define ADC_SQR3_SQ6              0x3E000000	/* SQ6 bits (6th conversion in regular sequence) */
#define TOFF_ADC_JSQR       0x0038		/* (RW) ADC injected sequence register */
#define TOFF_ADC_JDR1       0x003C		/* (RW) ADC injected data register 1 */
#define TOFF_ADC_JDR2       0x0040		/* (RW) ADC injected data register 2 */
#define TOFF_ADC_JDR3       0x0044		/* (RW) ADC injected data register 3 */
#define TOFF_ADC_JDR4       0x0048		/* (RW) ADC injected data register 4 */
#define TOFF_ADC_DR         0x004C		/* (RW) ADC regular data register */

#define TADR_ADC_BASE       (APB2PERIPH_BASE + 0x2300)
#define TOFF_ADC_CSR        0x0000		/* (RW) ADC Common status register */
#define TOFF_ADC_CCR        0x0004		/* (RW) ADC common control register */
  #define ADC_CCR_MULTI             0x0000001F	/* MULTI[4:0] bits (Multi-ADC mode selection) */  
  #define ADC_CCR_MULTI_0           0x00000001	/* Bit 0 */
  #define ADC_CCR_MULTI_1           0x00000002	/* Bit 1 */
  #define ADC_CCR_MULTI_2           0x00000004	/* Bit 2 */
  #define ADC_CCR_MULTI_3           0x00000008	/* Bit 3 */
  #define ADC_CCR_MULTI_4           0x00000010	/* Bit 4 */
  #define ADC_CCR_DELAY             0x00000F00	/* DELAY[3:0] bits (Delay between 2 sampling phases) */  
  #define ADC_CCR_DELAY_0           0x00000100	/* Bit 0 */
  #define ADC_CCR_DELAY_1           0x00000200	/* Bit 1 */
  #define ADC_CCR_DELAY_2           0x00000400	/* Bit 2 */
  #define ADC_CCR_DELAY_3           0x00000800	/* Bit 3 */
  #define ADC_CCR_DDS               0x00002000	/* DMA disable selection (Multi-ADC mode) */
  #define ADC_CCR_DMA               0x0000C000	/* DMA[1:0] bits (Direct Memory Access mode for multimode) */  
  #define ADC_CCR_DMA_0             0x00004000	/* Bit 0 */
  #define ADC_CCR_DMA_1             0x00008000	/* Bit 1 */
  #define ADC_CCR_ADCPRE            0x00030000	/* ADCPRE[1:0] bits (ADC prescaler) */  
  #define ADC_CCR_ADCPRE_0          0x00010000	/* Bit 0 */
  #define ADC_CCR_ADCPRE_1          0x00020000	/* Bit 1 */
  #define ADC_CCR_VBATE             0x00400000	/* VBAT Enable */
  #define ADC_CCR_TSVREFE           0x00800000	/* Temperature Sensor and VREFINT Enable */
#define TOFF_ADC_CDR        0x0008		/* (RW) ADC common regular data register for dual AND triple modes */

/*
 *  SD HOST INTERFACE
 */
#define TADR_SDIO_BASE      (APB2PERIPH_BASE + 0x2C00)
#define TOFF_SDIO_POWER     0x0000		/* (RW) SDIO power control register */
#define TOFF_SDIO_CLKCR     0x0004		/* (RW) SDI clock control register */
#define TOFF_SDIO_ARG       0x0008		/* (RW) SDIO argument register */
#define TOFF_SDIO_CMD       0x000C		/* (RW) SDIO command register */
#define TOFF_SDIO_RESPCMD   0x0018		/* (R)  SDIO command response register */
#define TOFF_SDIO_RESP      0x0014		/* (R)  SDIO response 1 register */
#define TOFF_SDIO_RESP2     0x0018		/* (R)  SDIO response 2 register */
#define TOFF_SDIO_RESP3     0x001C		/* (R)  SDIO response 3 register */
#define TOFF_SDIO_RESP4     0x0020		/* (R)  SDIO response 4 register */
#define TOFF_SDIO_DTIMER    0x0024		/* (RW) SDIO data timer register */
#define TOFF_SDIO_DLEN      0x0028		/* (RW) SDIO data length register */
#define TOFF_SDIO_DCTRL     0x002C		/* (RW) SDIO data control register */
#define TOFF_SDIO_DCOUNT    0x0030		/* (R)  SDIO data counter register */
#define TOFF_SDIO_STA       0x0034		/* (R)  SDIO status register */
#define TOFF_SDIO_ICR       0x0038		/* (RW) SDIO interrupt clear register */
#define TOFF_SDIO_MASK      0x003C		/* (RW) SDIO mask register */
#define TOFF_SDIO_FIFOCNT   0x0048		/* (R)  SDIO FIFO counter register */
#define TOFF_SDIO_FIFO      0x0080		/* (RW) SDIO data FIFO register */

/*
 *  SYSTEM CONFIGURATION CONTROLLER
 */
#define TADR_SYSCFG_BASE    (APB2PERIPH_BASE + 0x3800)
#define TOFF_SYSCFG_MEMRMP  0x0000		/* (RW) SYSCFG memory remap register */
#define TOFF_SYSCFG_PMC     0x0004		/* (RW) SYSCFG peripheral mode configuration register */
#define TOFF_SYSCFG_EXTICR0 0x0008		/* (RW) SYSCFG external interrupt configuration registers 0 */
#define TOFF_SYSCFG_EXTICR1 0x000C		/* (RW) SYSCFG external interrupt configuration registers 1 */
#define TOFF_SYSCFG_EXTICR2 0x0010		/* (RW) SYSCFG external interrupt configuration registers 2 */
#define TOFF_SYSCFG_EXTICR3 0x0014		/* (RW) SYSCFG external interrupt configuration registers 3 */
#define TOFF_SYSCFG_CMPCR   0x0020		/* (RW) SYSCFG Compensation cell control register */

/*
 *  EXTERNAL INTERRUPT/EVENT CONTROLLER
 */
#define TADR_EXTI_BASE      (APB2PERIPH_BASE + 0x3C00)
#define TOFF_EXTI_IMR       0x0000		/* (RW) EXTI Interrupt mask register */
  #define EXTI_IMR_MR0             0x00000001	/* Interrupt Mask on line 0 */
  #define EXTI_IMR_MR1             0x00000002	/* Interrupt Mask on line 1 */
  #define EXTI_IMR_MR2             0x00000004	/* Interrupt Mask on line 2 */
  #define EXTI_IMR_MR3             0x00000008	/* Interrupt Mask on line 3 */
  #define EXTI_IMR_MR4             0x00000010	/* Interrupt Mask on line 4 */
  #define EXTI_IMR_MR5             0x00000020	/* Interrupt Mask on line 5 */
  #define EXTI_IMR_MR6             0x00000040	/* Interrupt Mask on line 6 */
  #define EXTI_IMR_MR7             0x00000080	/* Interrupt Mask on line 7 */
  #define EXTI_IMR_MR8             0x00000100	/* Interrupt Mask on line 8 */
  #define EXTI_IMR_MR9             0x00000200	/* Interrupt Mask on line 9 */
  #define EXTI_IMR_MR10            0x00000400	/* Interrupt Mask on line 10 */
  #define EXTI_IMR_MR11            0x00000800	/* Interrupt Mask on line 11 */
  #define EXTI_IMR_MR12            0x00001000	/* Interrupt Mask on line 12 */
  #define EXTI_IMR_MR13            0x00002000	/* Interrupt Mask on line 13 */
  #define EXTI_IMR_MR14            0x00004000	/* Interrupt Mask on line 14 */
  #define EXTI_IMR_MR15            0x00008000	/* Interrupt Mask on line 15 */
  #define EXTI_IMR_MR16            0x00010000	/* Interrupt Mask on line 16 */
  #define EXTI_IMR_MR17            0x00020000	/* Interrupt Mask on line 17 */
  #define EXTI_IMR_MR18            0x00040000	/* Interrupt Mask on line 18 */
  #define EXTI_IMR_MR19            0x00080000	/* Interrupt Mask on line 19 */
  #define EXTI_IMR_MR20            0x00100000	/* Interrupt Mask on line 20 */
  #define EXTI_IMR_MR21            0x00200000	/* Interrupt Mask on line 21 */
  #define EXTI_IMR_MR22            0x00400000	/* Interrupt Mask on line 22 */
#define TOFF_EXTI_EMR       0x0004		/* (RW) EXTI Event mask register */
#define TOFF_EXTI_RTSR      0x0008		/* (RW) EXTI Rising trigger selection register */
  #define EXTI_RTSR_TR0            0x00000001	/* Rising trigger event configuration bit of line 0 */
  #define EXTI_RTSR_TR1            0x00000002	/* Rising trigger event configuration bit of line 1 */
  #define EXTI_RTSR_TR2            0x00000004	/* Rising trigger event configuration bit of line 2 */
  #define EXTI_RTSR_TR3            0x00000008	/* Rising trigger event configuration bit of line 3 */
  #define EXTI_RTSR_TR4            0x00000010	/* Rising trigger event configuration bit of line 4 */
  #define EXTI_RTSR_TR5            0x00000020	/* Rising trigger event configuration bit of line 5 */
  #define EXTI_RTSR_TR6            0x00000040	/* Rising trigger event configuration bit of line 6 */
  #define EXTI_RTSR_TR7            0x00000080	/* Rising trigger event configuration bit of line 7 */
  #define EXTI_RTSR_TR8            0x00000100	/* Rising trigger event configuration bit of line 8 */
  #define EXTI_RTSR_TR9            0x00000200	/* Rising trigger event configuration bit of line 9 */
  #define EXTI_RTSR_TR10           0x00000400	/* Rising trigger event configuration bit of line 10 */
  #define EXTI_RTSR_TR11           0x00000800	/* Rising trigger event configuration bit of line 11 */
  #define EXTI_RTSR_TR12           0x00001000	/* Rising trigger event configuration bit of line 12 */
  #define EXTI_RTSR_TR13           0x00002000	/* Rising trigger event configuration bit of line 13 */
  #define EXTI_RTSR_TR14           0x00004000	/* Rising trigger event configuration bit of line 14 */
  #define EXTI_RTSR_TR15           0x00008000	/* Rising trigger event configuration bit of line 15 */
  #define EXTI_RTSR_TR16           0x00010000	/* Rising trigger event configuration bit of line 16 */
  #define EXTI_RTSR_TR17           0x00020000	/* Rising trigger event configuration bit of line 17 */
  #define EXTI_RTSR_TR18           0x00040000	/* Rising trigger event configuration bit of line 18 */
  #define EXTI_RTSR_TR19           0x00080000	/* Rising trigger event configuration bit of line 19 */
  #define EXTI_RTSR_TR20           0x00100000	/* Rising trigger event configuration bit of line 20 */
  #define EXTI_RTSR_TR21           0x00200000	/* Rising trigger event configuration bit of line 21 */
  #define EXTI_RTSR_TR22           0x00400000	/* Rising trigger event configuration bit of line 22 */
#define TOFF_EXTI_FTSR      0x000C		/* (RW) EXTI Falling trigger selection register */
  #define EXTI_FTSR_TR0            0x00000001	/* Falling trigger event configuration bit of line 0 */
  #define EXTI_FTSR_TR1            0x00000002	/* Falling trigger event configuration bit of line 1 */
  #define EXTI_FTSR_TR2            0x00000004	/* Falling trigger event configuration bit of line 2 */
  #define EXTI_FTSR_TR3            0x00000008	/* Falling trigger event configuration bit of line 3 */
  #define EXTI_FTSR_TR4            0x00000010	/* Falling trigger event configuration bit of line 4 */
  #define EXTI_FTSR_TR5            0x00000020	/* Falling trigger event configuration bit of line 5 */
  #define EXTI_FTSR_TR6            0x00000040	/* Falling trigger event configuration bit of line 6 */
  #define EXTI_FTSR_TR7            0x00000080	/* Falling trigger event configuration bit of line 7 */
  #define EXTI_FTSR_TR8            0x00000100	/* Falling trigger event configuration bit of line 8 */
  #define EXTI_FTSR_TR9            0x00000200	/* Falling trigger event configuration bit of line 9 */
  #define EXTI_FTSR_TR10           0x00000400	/* Falling trigger event configuration bit of line 10 */
  #define EXTI_FTSR_TR11           0x00000800	/* Falling trigger event configuration bit of line 11 */
  #define EXTI_FTSR_TR12           0x00001000	/* Falling trigger event configuration bit of line 12 */
  #define EXTI_FTSR_TR13           0x00002000	/* Falling trigger event configuration bit of line 13 */
  #define EXTI_FTSR_TR14           0x00004000	/* Falling trigger event configuration bit of line 14 */
  #define EXTI_FTSR_TR15           0x00008000	/* Falling trigger event configuration bit of line 15 */
  #define EXTI_FTSR_TR16           0x00010000	/* Falling trigger event configuration bit of line 16 */
  #define EXTI_FTSR_TR17           0x00020000	/* Falling trigger event configuration bit of line 17 */
  #define EXTI_FTSR_TR18           0x00040000	/* Falling trigger event configuration bit of line 18 */
  #define EXTI_FTSR_TR19           0x00080000	/* Falling trigger event configuration bit of line 19 */
  #define EXTI_FTSR_TR20           0x00100000	/* Falling trigger event configuration bit of line 20 */
  #define EXTI_FTSR_TR21           0x00200000	/* Falling trigger event configuration bit of line 21 */
  #define EXTI_FTSR_TR22           0x00400000	/* Falling trigger event configuration bit of line 22 */
#define TOFF_EXTI_SWIER     0x0010		/* (RW) EXTI Software interrupt event register */
#define TOFF_EXTI_PR        0x0014		/* (RW) EXTI Pending register */
  #define EXTI_PR_PR0              0x00000001	/* Pending bit for line 0 */
  #define EXTI_PR_PR1              0x00000002	/* Pending bit for line 1 */
  #define EXTI_PR_PR2              0x00000004	/* Pending bit for line 2 */
  #define EXTI_PR_PR3              0x00000008	/* Pending bit for line 3 */
  #define EXTI_PR_PR4              0x00000010	/* Pending bit for line 4 */
  #define EXTI_PR_PR5              0x00000020	/* Pending bit for line 5 */
  #define EXTI_PR_PR6              0x00000040	/* Pending bit for line 6 */
  #define EXTI_PR_PR7              0x00000080	/* Pending bit for line 7 */
  #define EXTI_PR_PR8              0x00000100	/* Pending bit for line 8 */
  #define EXTI_PR_PR9              0x00000200	/* Pending bit for line 9 */
  #define EXTI_PR_PR10             0x00000400	/* Pending bit for line 10 */
  #define EXTI_PR_PR11             0x00000800	/* Pending bit for line 11 */
  #define EXTI_PR_PR12             0x00001000	/* Pending bit for line 12 */
  #define EXTI_PR_PR13             0x00002000	/* Pending bit for line 13 */
  #define EXTI_PR_PR14             0x00004000	/* Pending bit for line 14 */
  #define EXTI_PR_PR15             0x00008000	/* Pending bit for line 15 */
  #define EXTI_PR_PR16             0x00010000	/* Pending bit for line 16 */
  #define EXTI_PR_PR17             0x00020000	/* Pending bit for line 17 */
  #define EXTI_PR_PR18             0x00040000	/* Pending bit for line 18 */
  #define EXTI_PR_PR19             0x00080000	/* Pending bit for line 19 */
  #define EXTI_PR_PR20             0x00100000	/* Pending bit for line 20 */
  #define EXTI_PR_PR21             0x00200000	/* Pending bit for line 21 */
  #define EXTI_PR_PR22             0x00400000	/* Pending bit for line 22 */

/*
 *  GENERAL PURPOSE I/O
 */
#define TADR_GPIOA_BASE     (AHB1PERIPH_BASE + 0x0000)
#define TADR_GPIOB_BASE     (AHB1PERIPH_BASE + 0x0400)
#define TADR_GPIOC_BASE     (AHB1PERIPH_BASE + 0x0800)
#define TADR_GPIOD_BASE     (AHB1PERIPH_BASE + 0x0C00)
#define TADR_GPIOE_BASE     (AHB1PERIPH_BASE + 0x1000)
#define TADR_GPIOF_BASE     (AHB1PERIPH_BASE + 0x1400)
#define TADR_GPIOG_BASE     (AHB1PERIPH_BASE + 0x1800)
#define TADR_GPIOH_BASE     (AHB1PERIPH_BASE + 0x1C00)
#define TADR_GPIOI_BASE     (AHB1PERIPH_BASE + 0x2000)
#define TOFF_GPIO_MODER     0x0000		/* (RW) GPIO port mode register */
  #define GPIO_MODER_MODER0  0x1
  #define GPIO_MODER_MODER1  0x2
  #define GPIO_MODER_MODER2  0x3
#define TOFF_GPIO_OTYPER    0x0004		/* (RW) GPIO port output type register */
  #define GPIO_OTYPER_OT     0x1
#define TOFF_GPIO_OSPEEDR   0x0008		/* (RW) GPIO port output speed register */
  #define GPIO_OSPEEDER_OSPEEDR0 0x1
  #define GPIO_OSPEEDER_OSPEEDR1 0x2
  #define GPIO_OSPEEDER_OSPEEDR2 0x3
#define TOFF_GPIO_PUPDR     0x000C		/* (RW) GPIO port pull-up/pull-down register */
  #define GPIO_PUPDR_PUPDR0  0x1
  #define GPIO_PUPDR_PUPDR1  0x2
  #define GPIO_PUPDR_PUPDR2  0x3
#define TOFF_GPIO_IDR       0x0010		/* (R)  GPIO port input data register */
#define TOFF_GPIO_ODR       0x0014		/* (RW) GPIO port output data register */
#define TOFF_GPIO_BSRRL     0x0018		/* (RW-16) GPIO port bit set/reset low register */
#define TOFF_GPIO_BSRRH     0x001A		/* (RW-16) GPIO port bit set/reset high register */
#define TOFF_GPIO_LCKR      0x001C		/* (RW) GPIO port configuration lock register */
#define TOFF_GPIO_AFR0      0x0020		/* (RW) GPIO alternate function registers */
#define TOFF_GPIO_AFR1      0x0024		/* (RW) GPIO alternate function registers */

/*
 *  CRC CALCULATION UNIT
 */
#define TADR_CRC_BASE       (AHB1PERIPH_BASE + 0x3000)
#define TOFF_CRC_DR         0x0000		/* (RW) CRC Data register */
#define TOFF_CRC_IDR        0x0004		/* (RW-8) CRC Independent data register */
#define TOFF_CRC_CR         0x0008		/* (RW) CRC Control register */

/*
 *  RESET AND CLOCK CONTROL
 */
#define TADR_RCC_BASE       (AHB1PERIPH_BASE + 0x3800)
#define TOFF_RCC_CR         0x0000		/* (RW) RCC clock control register */
  #define RCC_CR_HSION             0x00000001
  #define RCC_CR_HSIRDY            0x00000002
  #define RCC_CR_HSITRIM_0         0x00000008	/* Bit 0 */
  #define RCC_CR_HSITRIM_1         0x00000010	/* Bit 1 */
  #define RCC_CR_HSITRIM_2         0x00000020	/* Bit 2 */
  #define RCC_CR_HSITRIM_3         0x00000040	/* Bit 3 */
  #define RCC_CR_HSITRIM_4         0x00000080	/* Bit 4 */
  #define RCC_CR_HSICAL_0          0x00000100	/* Bit 0 */
  #define RCC_CR_HSICAL_1          0x00000200	/* Bit 1 */
  #define RCC_CR_HSICAL_2          0x00000400	/* Bit 2 */
  #define RCC_CR_HSICAL_3          0x00000800	/* Bit 3 */
  #define RCC_CR_HSICAL_4          0x00001000	/* Bit 4 */
  #define RCC_CR_HSICAL_5          0x00002000	/* Bit 5 */
  #define RCC_CR_HSICAL_6          0x00004000	/* Bit 6 */
  #define RCC_CR_HSICAL_7          0x00008000	/* Bit 7 */
  #define RCC_CR_HSEON             0x00010000
  #define RCC_CR_HSERDY            0x00020000
  #define RCC_CR_HSEBYP            0x00040000
  #define RCC_CR_CSSON             0x00080000
  #define RCC_CR_PLLON             0x01000000
  #define RCC_CR_PLLRDY            0x02000000
  #define RCC_CR_PLLI2SON          0x04000000
  #define RCC_CR_PLLI2SRDY         0x08000000
#if defined(TOPPERS_STM32F446_NUCLEO64) || defined(TOPPERS_STM32F446_NUCLEO144)
  #define RCC_CR_PLLSAION          0x10000000
  #define RCC_CR_PLLSAIRDY         0x20000000
#endif
#define TOFF_RCC_PLLCFGR    0x0004		/* (RW) RCC PLL configuration register */
  #define  RCC_PLLCFGR_PLLM_0      0x00000001
  #define  RCC_PLLCFGR_PLLM_1      0x00000002
  #define  RCC_PLLCFGR_PLLM_2      0x00000004
  #define  RCC_PLLCFGR_PLLM_3      0x00000008
  #define  RCC_PLLCFGR_PLLM_4      0x00000010
  #define  RCC_PLLCFGR_PLLM_5      0x00000020
  #define  RCC_PLLCFGR_PLLN_0      0x00000040
  #define  RCC_PLLCFGR_PLLN_1      0x00000080
  #define  RCC_PLLCFGR_PLLN_2      0x00000100
  #define  RCC_PLLCFGR_PLLN_3      0x00000200
  #define  RCC_PLLCFGR_PLLN_4      0x00000400
  #define  RCC_PLLCFGR_PLLN_5      0x00000800
  #define  RCC_PLLCFGR_PLLN_6      0x00001000
  #define  RCC_PLLCFGR_PLLN_7      0x00002000
  #define  RCC_PLLCFGR_PLLN_8      0x00004000
  #define  RCC_PLLCFGR_PLLP_0      0x00010000
  #define  RCC_PLLCFGR_PLLP_1      0x00020000
  #define  RCC_PLLCFGR_PLLSRC_HSE  0x00400000
  #define  RCC_PLLCFGR_PLLSRC_HSI  0x00000000
  #define  RCC_PLLCFGR_PLLQ_0      0x01000000
  #define  RCC_PLLCFGR_PLLQ_1      0x02000000
  #define  RCC_PLLCFGR_PLLQ_2      0x04000000
  #define  RCC_PLLCFGR_PLLQ_3      0x08000000
#define TOFF_RCC_CFGR       0x0008		/* (RW) RCC clock configuration register */
  #define RCC_CFGR_SW_0            0x00000001	/* Bit 0 */
  #define RCC_CFGR_SW_1            0x00000002	/* Bit 1 */
  #define RCC_CFGR_SW_HSI          0x00000000	/* HSI selected as system clock */
  #define RCC_CFGR_SW_HSE          0x00000001	/* HSE selected as system clock */
  #define RCC_CFGR_SW_PLL          0x00000002	/* PLL selected as system clock */
  #define RCC_CFGR_SWS_0           0x00000004	/* Bit 0 */
  #define RCC_CFGR_SWS_1           0x00000008	/* Bit 1 */
  #define RCC_CFGR_SWS_HSI         0x00000000	/* HSI oscillator used as system clock */
  #define RCC_CFGR_SWS_HSE         0x00000004	/* HSE oscillator used as system clock */
  #define RCC_CFGR_SWS_PLL         0x00000008	/* PLL used as system clock */
  #define RCC_CFGR_HPRE_0          0x00000010	/* Bit 0 */
  #define RCC_CFGR_HPRE_1          0x00000020	/* Bit 1 */
  #define RCC_CFGR_HPRE_2          0x00000040	/* Bit 2 */
  #define RCC_CFGR_HPRE_3          0x00000080	/* Bit 3 */
  #define RCC_CFGR_HPRE_DIV1       0x00000000	/* SYSCLK not divided */
  #define RCC_CFGR_HPRE_DIV2       0x00000080	/* SYSCLK divided by 2 */
  #define RCC_CFGR_HPRE_DIV4       0x00000090	/* SYSCLK divided by 4 */
  #define RCC_CFGR_HPRE_DIV8       0x000000A0	/* SYSCLK divided by 8 */
  #define RCC_CFGR_HPRE_DIV16      0x000000B0	/* SYSCLK divided by 16 */
  #define RCC_CFGR_HPRE_DIV64      0x000000C0	/* SYSCLK divided by 64 */
  #define RCC_CFGR_HPRE_DIV128     0x000000D0	/* SYSCLK divided by 128 */
  #define RCC_CFGR_HPRE_DIV256     0x000000E0	/* SYSCLK divided by 256 */
  #define RCC_CFGR_HPRE_DIV512     0x000000F0	/* SYSCLK divided by 512 */
  #define RCC_CFGR_PPRE1_0         0x00000400	/* Bit 0 */
  #define RCC_CFGR_PPRE1_1         0x00000800	/* Bit 1 */
  #define RCC_CFGR_PPRE1_2         0x00001000	/* Bit 2 */
  #define RCC_CFGR_PPRE1_DIV1      0x00000000	/* HCLK not divided */
  #define RCC_CFGR_PPRE1_DIV2      0x00001000	/* HCLK divided by 2 */
  #define RCC_CFGR_PPRE1_DIV4      0x00001400	/* HCLK divided by 4 */
  #define RCC_CFGR_PPRE1_DIV8      0x00001800	/* HCLK divided by 8 */
  #define RCC_CFGR_PPRE1_DIV16     0x00001C00	/* HCLK divided by 16 */
  #define RCC_CFGR_PPRE2_0         0x00002000	/* Bit 0 */
  #define RCC_CFGR_PPRE2_1         0x00004000	/* Bit 1 */
  #define RCC_CFGR_PPRE2_2         0x00008000	/* Bit 2 */
  #define RCC_CFGR_PPRE2_DIV1      0x00000000	/* HCLK not divided */
  #define RCC_CFGR_PPRE2_DIV2      0x00008000	/* HCLK divided by 2 */
  #define RCC_CFGR_PPRE2_DIV4      0x0000A000	/* HCLK divided by 4 */
  #define RCC_CFGR_PPRE2_DIV8      0x0000C000	/* HCLK divided by 8 */
  #define RCC_CFGR_PPRE2_DIV16     0x0000E000	/* HCLK divided by 16 */
  #define RCC_CFGR_RTCPRE_0        0x00010000
  #define RCC_CFGR_RTCPRE_1        0x00020000
  #define RCC_CFGR_RTCPRE_2        0x00040000
  #define RCC_CFGR_RTCPRE_3        0x00080000
  #define RCC_CFGR_RTCPRE_4        0x00100000
  #define RCC_CFGR_MCO1_0          0x00200000
  #define RCC_CFGR_MCO1_1          0x00400000
  #define RCC_CFGR_I2SSRC          0x00800000
  #define RCC_CFGR_MCO1PRE_0       0x01000000
  #define RCC_CFGR_MCO1PRE_1       0x02000000
  #define RCC_CFGR_MCO1PRE_2       0x04000000
  #define RCC_CFGR_MCO2PRE_0       0x08000000
  #define RCC_CFGR_MCO2PRE_1       0x10000000
  #define RCC_CFGR_MCO2PRE_2       0x20000000
  #define RCC_CFGR_MCO2_0          0x40000000
  #define RCC_CFGR_MCO2_1          0x80000000
#define TOFF_RCC_CIR        0x000C		/* (RW) RCC clock interrupt register */
  #define RCC_CIR_LSIRDYF          0x00000001
  #define RCC_CIR_LSERDYF          0x00000002
  #define RCC_CIR_HSIRDYF          0x00000004
  #define RCC_CIR_HSERDYF          0x00000008
  #define RCC_CIR_PLLRDYF          0x00000010
  #define RCC_CIR_PLLI2SRDYF       0x00000020
  #define RCC_CIR_CSSF             0x00000080
  #define RCC_CIR_LSIRDYIE         0x00000100
  #define RCC_CIR_LSERDYIE         0x00000200
  #define RCC_CIR_HSIRDYIE         0x00000400
  #define RCC_CIR_HSERDYIE         0x00000800
  #define RCC_CIR_PLLRDYIE         0x00001000
  #define RCC_CIR_PLLI2SRDYIE      0x00002000
  #define RCC_CIR_LSIRDYC          0x00010000
  #define RCC_CIR_LSERDYC          0x00020000
  #define RCC_CIR_HSIRDYC          0x00040000
  #define RCC_CIR_HSERDYC          0x00080000
  #define RCC_CIR_PLLRDYC          0x00100000
  #define RCC_CIR_PLLI2SRDYC       0x00200000
  #define RCC_CIR_CSSC             0x00800000
#define TOFF_RCC_AHB1RSTR   0x0010		/* (RW) RCC AHB1 peripheral reset register */
  #define RCC_AHB1RSTR_GPIOARST    0x00000001
  #define RCC_AHB1RSTR_GPIOBRST    0x00000002
  #define RCC_AHB1RSTR_GPIOCRST    0x00000004
  #define RCC_AHB1RSTR_GPIODRST    0x00000008
  #define RCC_AHB1RSTR_GPIOERST    0x00000010
  #define RCC_AHB1RSTR_GPIOFRST    0x00000020
  #define RCC_AHB1RSTR_GPIOGRST    0x00000040
  #define RCC_AHB1RSTR_GPIOHRST    0x00000080
  #define RCC_AHB1RSTR_GPIOIRST    0x00000100
  #define RCC_AHB1RSTR_CRCRST      0x00001000
  #define RCC_AHB1RSTR_DMA1RST     0x00200000
  #define RCC_AHB1RSTR_DMA2RST     0x00400000
  #define RCC_AHB1RSTR_ETHMACRST   0x02000000
  #define RCC_AHB1RSTR_OTGHRST     0x10000000
#define TOFF_RCC_AHB2RSTR   0x0014		/* (RW) RCC AHB2 peripheral reset register */
  #define RCC_AHB2RSTR_DCMIRST     0x00000001
  #define RCC_AHB2RSTR_CRYPRST     0x00000010
  #define RCC_AHB2RSTR_HSAHRST     0x00000020
  #define RCC_AHB2RSTR_RNGRST      0x00000040
  #define RCC_AHB2RSTR_OTGFSRST    0x00000080
#define TOFF_RCC_AHB3RSTR   0x0018		/* (RW) RCC AHB3 peripheral reset register */
  #define RCC_AHB3RSTR_FSMCRST     0x00000001
#define TOFF_RCC_APB1RSTR   0x0020		/* (RW) RCC APB1 peripheral reset register */
  #define RCC_APB1RSTR_TIM2RST     0x00000001
  #define RCC_APB1RSTR_TIM3RST     0x00000002
  #define RCC_APB1RSTR_TIM4RST     0x00000004
  #define RCC_APB1RSTR_TIM5RST     0x00000008
  #define RCC_APB1RSTR_TIM6RST     0x00000010
  #define RCC_APB1RSTR_TIM7RST     0x00000020
  #define RCC_APB1RSTR_TIM12RST    0x00000040
  #define RCC_APB1RSTR_TIM13RST    0x00000080
  #define RCC_APB1RSTR_TIM14RST    0x00000100
  #define RCC_APB1RSTR_WWDGEN      0x00000800
#if defined(TOPPERS_STM32F401_NUCLEO) || defined(TOPPERS_STM32F446_NUCLEO64) || defined(TOPPERS_STM32F446_NUCLEO144)
  #define RCC_APB1RSTR_SPI2RST     0x00004000
  #define RCC_APB1RSTR_SPI3RST     0x00008000
#else
  #define RCC_APB1RSTR_SPI2RST     0x00008000
  #define RCC_APB1RSTR_SPI3RST     0x00010000
#endif
  #define RCC_APB1RSTR_USART2RST   0x00020000
  #define RCC_APB1RSTR_USART3RST   0x00040000
  #define RCC_APB1RSTR_UART4RST    0x00080000
  #define RCC_APB1RSTR_UART5RST    0x00100000
  #define RCC_APB1RSTR_I2C1RST     0x00200000
  #define RCC_APB1RSTR_I2C2RST     0x00400000
  #define RCC_APB1RSTR_I2C3RST     0x00800000
  #define RCC_APB1RSTR_CAN1RST     0x02000000
  #define RCC_APB1RSTR_CAN2RST     0x04000000
  #define RCC_APB1RSTR_PWRRST      0x10000000
  #define RCC_APB1RSTR_DACRST      0x20000000
#define TOFF_RCC_APB2RSTR   0x0024		/* (RW) RCC APB2 peripheral reset register */
  #define RCC_APB2RSTR_TIM1RST     0x00000001
  #define RCC_APB2RSTR_TIM8RST     0x00000002
  #define RCC_APB2RSTR_USART1RST   0x00000010
  #define RCC_APB2RSTR_USART6RST   0x00000020
  #define RCC_APB2RSTR_ADCRST      0x00000100
  #define RCC_APB2RSTR_SDIORST     0x00000800
  #define RCC_APB2RSTR_SPI1RST     0x00001000
  #define RCC_APB2RSTR_SYSCFGRST   0x00004000
  #define RCC_APB2RSTR_TIM9RST     0x00010000
  #define RCC_APB2RSTR_TIM10RST    0x00020000
  #define RCC_APB2RSTR_TIM11RST    0x00040000
  /* Old SPI1RST bit definition, maintained for legacy purpose */
  #define RCC_APB2RSTR_SPI1        RCC_APB2RSTR_SPI1RST
#define TOFF_RCC_AHB1ENR    0x0030		/* (RW) RCC AHB1 peripheral clock register */
  #define RCC_AHB1ENR_GPIOAEN      0x00000001
  #define RCC_AHB1ENR_GPIOBEN      0x00000002
  #define RCC_AHB1ENR_GPIOCEN      0x00000004
  #define RCC_AHB1ENR_GPIODEN      0x00000008
  #define RCC_AHB1ENR_GPIOEEN      0x00000010
  #define RCC_AHB1ENR_GPIOFEN      0x00000020
  #define RCC_AHB1ENR_GPIOGEN      0x00000040
  #define RCC_AHB1ENR_GPIOHEN      0x00000080
  #define RCC_AHB1ENR_GPIOIEN      0x00000100
  #define RCC_AHB1ENR_CRCEN        0x00001000
  #define RCC_AHB1ENR_BKPSRAMEN    0x00040000
  #define RCC_AHB1ENR_CCMDATARAMEN 0x00100000
  #define RCC_AHB1ENR_DMA1EN       0x00200000
  #define RCC_AHB1ENR_DMA2EN       0x00400000
  #define RCC_AHB1ENR_ETHMACEN     0x02000000
  #define RCC_AHB1ENR_ETHMACTXEN   0x04000000
  #define RCC_AHB1ENR_ETHMACRXEN   0x08000000
  #define RCC_AHB1ENR_ETHMACPTPEN  0x10000000
  #define RCC_AHB1ENR_OTGHSEN      0x20000000
  #define RCC_AHB1ENR_OTGHSULPIEN  0x40000000
#define TOFF_RCC_AHB2ENR    0x0034		/* (RW) RCC AHB2 peripheral clock register */
  #define RCC_AHB2ENR_DCMIEN       0x00000001
  #define RCC_AHB2ENR_CRYPEN       0x00000010
  #define RCC_AHB2ENR_HASHEN       0x00000020
  #define RCC_AHB2ENR_RNGEN        0x00000040
  #define RCC_AHB2ENR_OTGFSEN      0x00000080
#define TOFF_RCC_AHB3ENR    0x0038		/* (RW) RCC AHB3 peripheral clock register */
  #define RCC_AHB3ENR_FSMCEN       0x00000001
#define TOFF_RCC_APB1ENR    0x0040		/* (RW) RCC APB1 peripheral clock enable register */
  #define RCC_APB1ENR_TIM2EN       0x00000001
  #define RCC_APB1ENR_TIM3EN       0x00000002
  #define RCC_APB1ENR_TIM4EN       0x00000004
  #define RCC_APB1ENR_TIM5EN       0x00000008
  #define RCC_APB1ENR_TIM6EN       0x00000010
  #define RCC_APB1ENR_TIM7EN       0x00000020
  #define RCC_APB1ENR_TIM12EN      0x00000040
  #define RCC_APB1ENR_TIM13EN      0x00000080
  #define RCC_APB1ENR_TIM14EN      0x00000100
  #define RCC_APB1ENR_WWDGEN       0x00000800
  #define RCC_APB1ENR_SPI2EN       0x00004000
  #define RCC_APB1ENR_SPI3EN       0x00008000
  #define RCC_APB1ENR_USART2EN     0x00020000
  #define RCC_APB1ENR_USART3EN     0x00040000
  #define RCC_APB1ENR_UART4EN      0x00080000
  #define RCC_APB1ENR_UART5EN      0x00100000
  #define RCC_APB1ENR_I2C1EN       0x00200000
  #define RCC_APB1ENR_I2C2EN       0x00400000
  #define RCC_APB1ENR_I2C3EN       0x00800000
  #define RCC_APB1ENR_CAN1EN       0x02000000
  #define RCC_APB1ENR_CAN2EN       0x04000000
  #define RCC_APB1ENR_PWREN        0x10000000
  #define RCC_APB1ENR_DACEN        0x20000000
#define TOFF_RCC_APB2ENR    0x0044		/* (RW) RCC APB2 peripheral clock enable register */
  #define RCC_APB2ENR_TIM1EN       0x00000001
  #define RCC_APB2ENR_TIM8EN       0x00000002
  #define RCC_APB2ENR_USART1EN     0x00000010
  #define RCC_APB2ENR_USART6EN     0x00000020
  #define RCC_APB2ENR_ADC1EN       0x00000100
  #define RCC_APB2ENR_ADC2EN       0x00000200
  #define RCC_APB2ENR_ADC3EN       0x00000400
  #define RCC_APB2ENR_SDIOEN       0x00000800
  #define RCC_APB2ENR_SPI1EN       0x00001000
  #define RCC_APB2ENR_SYSCFGEN     0x00004000
  #define RCC_APB2ENR_TIM11EN      0x00040000
  #define RCC_APB2ENR_TIM10EN      0x00020000
  #define RCC_APB2ENR_TIM9EN       0x00010000
#define TOFF_RCC_AHB1LPENR  0x0050		/* (RW) RCC AHB1 peripheral clock enable in low power mode register */
  #define RCC_AHB1LPENR_GPIOALPEN     0x00000001
  #define RCC_AHB1LPENR_GPIOBLPEN     0x00000002
  #define RCC_AHB1LPENR_GPIOCLPEN     0x00000004
  #define RCC_AHB1LPENR_GPIODLPEN     0x00000008
  #define RCC_AHB1LPENR_GPIOELPEN     0x00000010
  #define RCC_AHB1LPENR_GPIOFLPEN     0x00000020
  #define RCC_AHB1LPENR_GPIOGLPEN     0x00000040
  #define RCC_AHB1LPENR_GPIOHLPEN     0x00000080
  #define RCC_AHB1LPENR_GPIOILPEN     0x00000100
  #define RCC_AHB1LPENR_CRCLPEN       0x00001000
  #define RCC_AHB1LPENR_FLITFLPEN     0x00008000
  #define RCC_AHB1LPENR_SRAM1LPEN     0x00010000
  #define RCC_AHB1LPENR_SRAM2LPEN     0x00020000
  #define RCC_AHB1LPENR_BKPSRAMLPEN   0x00040000
  #define RCC_AHB1LPENR_DMA1LPEN      0x00200000
  #define RCC_AHB1LPENR_DMA2LPEN      0x00400000
  #define RCC_AHB1LPENR_ETHMACLPEN    0x02000000
  #define RCC_AHB1LPENR_ETHMACTXLPEN  0x04000000
  #define RCC_AHB1LPENR_ETHMACRXLPEN  0x08000000
  #define RCC_AHB1LPENR_ETHMACPTPLPEN 0x10000000
  #define RCC_AHB1LPENR_OTGHSLPEN     0x20000000
  #define RCC_AHB1LPENR_OTGHSULPILPEN 0x40000000
#define TOFF_RCC_AHB2LPENR  0x0054		/* (RW) RCC AHB2 peripheral clock enable in low power mode register */
  #define RCC_AHB2LPENR_DCMILPEN   0x00000001
  #define RCC_AHB2LPENR_CRYPLPEN   0x00000010
  #define RCC_AHB2LPENR_HASHLPEN   0x00000020
  #define RCC_AHB2LPENR_RNGLPEN    0x00000040
  #define RCC_AHB2LPENR_OTGFSLPEN  0x00000080
#define TOFF_RCC_AHB3LPENR  0x0058		/* (RW) RCC AHB3 peripheral clock enable in low power mode register */
  #define RCC_AHB3LPENR_FSMCLPEN   0x00000001
#define TOFF_RCC_APB1LPENR  0x0060		/* (RW) RCC APB1 peripheral clock enable in low power mode register */
  #define RCC_APB1LPENR_TIM2LPEN   0x00000001
  #define RCC_APB1LPENR_TIM3LPEN   0x00000002
  #define RCC_APB1LPENR_TIM4LPEN   0x00000004
  #define RCC_APB1LPENR_TIM5LPEN   0x00000008
  #define RCC_APB1LPENR_TIM6LPEN   0x00000010
  #define RCC_APB1LPENR_TIM7LPEN   0x00000020
  #define RCC_APB1LPENR_TIM12LPEN  0x00000040
  #define RCC_APB1LPENR_TIM13LPEN  0x00000080
  #define RCC_APB1LPENR_TIM14LPEN  0x00000100
  #define RCC_APB1LPENR_WWDGLPEN   0x00000800
  #define RCC_APB1LPENR_SPI2LPEN   0x00004000
  #define RCC_APB1LPENR_SPI3LPEN   0x00008000
  #define RCC_APB1LPENR_USART2LPEN 0x00020000
  #define RCC_APB1LPENR_USART3LPEN 0x00040000
  #define RCC_APB1LPENR_UART4LPEN  0x00080000
  #define RCC_APB1LPENR_UART5LPEN  0x00100000
  #define RCC_APB1LPENR_I2C1LPEN   0x00200000
  #define RCC_APB1LPENR_I2C2LPEN   0x00400000
  #define RCC_APB1LPENR_I2C3LPEN   0x00800000
  #define RCC_APB1LPENR_CAN1LPEN   0x02000000
  #define RCC_APB1LPENR_CAN2LPEN   0x04000000
  #define RCC_APB1LPENR_PWRLPEN    0x10000000
  #define RCC_APB1LPENR_DACLPEN    0x20000000
#define TOFF_RCC_APB2LPENR  0x0064		/* (RW) RCC APB2 peripheral clock enable in low power mode register */
  #define RCC_APB2LPENR_TIM1LPEN   0x00000001
  #define RCC_APB2LPENR_TIM8LPEN   0x00000002
  #define RCC_APB2LPENR_USART1LPEN 0x00000010
  #define RCC_APB2LPENR_USART6LPEN 0x00000020
  #define RCC_APB2LPENR_ADC1LPEN   0x00000100
  #define RCC_APB2LPENR_ADC2PEN    0x00000200
  #define RCC_APB2LPENR_ADC3LPEN   0x00000400
  #define RCC_APB2LPENR_SDIOLPEN   0x00000800
  #define RCC_APB2LPENR_SPI1LPEN   0x00001000
  #define RCC_APB2LPENR_SYSCFGLPEN 0x00004000
  #define RCC_APB2LPENR_TIM9LPEN   0x00010000
  #define RCC_APB2LPENR_TIM10LPEN  0x00020000
  #define RCC_APB2LPENR_TIM11LPEN  0x00040000
#define TOFF_RCC_BDCR       0x0070		/* (RW) RCC Backup domain control register */
  #define RCC_BDCR_LSEON           0x00000001
  #define RCC_BDCR_LSERDY          0x00000002
  #define RCC_BDCR_LSEBYP          0x00000004
  #define RCC_BDCR_RTCSEL          0x00000300
  #define RCC_BDCR_RTCSEL_0        0x00000100
  #define RCC_BDCR_RTCSEL_1        0x00000200
  #define RCC_BDCR_RTCEN           0x00008000
  #define RCC_BDCR_BDRST           0x00010000
#define TOFF_RCC_CSR        0x0074		/* (RW) RCC clock control & status register */
  #define RCC_CSR_LSION            0x00000001
  #define RCC_CSR_LSIRDY           0x00000002
  #define RCC_CSR_RMVF             0x01000000
  #define RCC_CSR_BORRSTF          0x02000000
  #define RCC_CSR_PADRSTF          0x04000000
  #define RCC_CSR_PORRSTF          0x08000000
  #define RCC_CSR_SFTRSTF          0x10000000
  #define RCC_CSR_WDGRSTF          0x20000000
  #define RCC_CSR_WWDGRSTF         0x40000000
  #define RCC_CSR_LPWRRSTF         0x80000000
#define TOFF_RCC_SSCGR      0x0080		/* (RW) RCC spread spectrum clock generation register */
  #define RCC_SSCGR_MODPER         0x00001FFF
  #define RCC_SSCGR_INCSTEP        0x0FFFE000
  #define RCC_SSCGR_SPREADSEL      0x40000000
  #define RCC_SSCGR_SSCGEN         0x80000000
#define TOFF_RCC_PLLI2SCFGR 0x0084		/* (RW) RCC PLLI2S configuration register */
  #define RCC_PLLI2SCFGR_PLLI2SN   0x00007FC0
  #define RCC_PLLI2SCFGR_PLLI2SR   0x70000000
#if defined(TOPPERS_STM32F446_NUCLEO64) || defined(TOPPERS_STM32F446_NUCLEO144)
#define TOFF_RCC_PLLSAICFGR 0x0088		/* (RW) RCC PLLSAI configuration register */
  #define RCC_PLLSAICFGR_PLLSAIM   0x0000003F
  #define RCC_PLLSAICFGR_PLLSAIM_0 0x00000001
  #define RCC_PLLSAICFGR_PLLSAIM_1 0x00000002
  #define RCC_PLLSAICFGR_PLLSAIM_2 0x00000004
  #define RCC_PLLSAICFGR_PLLSAIM_3 0x00000008
  #define RCC_PLLSAICFGR_PLLSAIM_4 0x00000010
  #define RCC_PLLSAICFGR_PLLSAIM_5 0x00000020
  #define RCC_PLLSAICFGR_PLLSAIN   0x00007FC0
  #define RCC_PLLSAICFGR_PLLSAIN_0 0x00000040
  #define RCC_PLLSAICFGR_PLLSAIN_1 0x00000080
  #define RCC_PLLSAICFGR_PLLSAIN_2 0x00000100
  #define RCC_PLLSAICFGR_PLLSAIN_3 0x00000200
  #define RCC_PLLSAICFGR_PLLSAIN_4 0x00000400
  #define RCC_PLLSAICFGR_PLLSAIN_5 0x00000800
  #define RCC_PLLSAICFGR_PLLSAIN_6 0x00001000
  #define RCC_PLLSAICFGR_PLLSAIN_7 0x00002000
  #define RCC_PLLSAICFGR_PLLSAIN_8 0x00004000
  #define RCC_PLLSAICFGR_PLLSAIP   0x00030000
  #define RCC_PLLSAICFGR_PLLSAIP_0 0x00010000
  #define RCC_PLLSAICFGR_PLLSAIP_1 0x00020000
  #define RCC_PLLSAICFGR_PLLSAIQ   0x0F000000
  #define RCC_PLLSAICFGR_PLLSAIQ_0 0x01000000
  #define RCC_PLLSAICFGR_PLLSAIQ_1 0x02000000
  #define RCC_PLLSAICFGR_PLLSAIQ_2 0x04000000
  #define RCC_PLLSAICFGR_PLLSAIQ_3 0x08000000
#define TOFF_RCC_DCKCFGR    0x008C		/* (RW) RCC Dedicated Clocks configuration register */
  #define RCC_DCKCFGR_PLLI2SDIVQ   0x0000001F
  #define RCC_DCKCFGR_PLLSAIDIVQ   0x00001F00
  #define RCC_DCKCFGR_SAI1SRC      0x00300000
  #define RCC_DCKCFGR_SAI1SRC_0    0x00100000
  #define RCC_DCKCFGR_SAI1SRC_1    0x00200000
  #define RCC_DCKCFGR_SAI2SRC      0x00C00000
  #define RCC_DCKCFGR_SAI2SRC_0    0x00400000
  #define RCC_DCKCFGR_SAI2SRC_1    0x00800000
  #define RCC_DCKCFGR_TIMPRE       0x01000000
  #define RCC_DCKCFGR_I2S1SRC      0x06000000
  #define RCC_DCKCFGR_I2S1SRC_0    0x02000000
  #define RCC_DCKCFGR_I2S1SRC_1    0x04000000
  #define RCC_DCKCFGR_I2S2SRC      0x18000000
  #define RCC_DCKCFGR_I2S2SRC_0    0x08000000
  #define RCC_DCKCFGR_I2S2SRC_1    0x10000000
#define TOFF_RCC_CKGATENR   0x0090		/* (RW) RCC Clocks Gated ENable Register */
  #define RCC_CKGATENR_AHB2APB1_CKEN 0x00000001
  #define RCC_CKGATENR_AHB2APB2_CKEN 0x00000002
  #define RCC_CKGATENR_CM4DBG_CKEN   0x00000004
  #define RCC_CKGATENR_SPARE_CKEN    0x00000008
  #define RCC_CKGATENR_SRAM_CKEN     0x00000010
  #define RCC_CKGATENR_FLITF_CKEN    0x00000020
  #define RCC_CKGATENR_RCC_CKEN      0x00000040
#define TOFF_RCC_DCKCFGR2   0x0094		/* (RW) RCC Dedicated Clocks configuration register 2 */
  #define RCC_DCKCFGR2_FMPI2C1SEL    0x00C00000
  #define RCC_DCKCFGR2_FMPI2C1SEL_0  0x00400000
  #define RCC_DCKCFGR2_FMPI2C1SEL_1  0x00800000
  #define RCC_DCKCFGR2_CECSEL        0x04000000
  #define RCC_DCKCFGR2_CK48MSEL      0x08000000
  #define RCC_DCKCFGR2_SDIOSEL       0x10000000
  #define RCC_DCKCFGR2_SPDIFRXSEL    0x20000000
#endif

/*
 *  FLASH REGISTERS
 */
#define TADR_FLASH_R_BASE   (AHB1PERIPH_BASE + 0x3C00)
#define TOFF_FLASH_ACR      0x0000		/* (RW) FLASH access control register */
  #define FLASH_ACR_LATENCY_0WS    0x00000000
  #define FLASH_ACR_LATENCY_1WS    0x00000001
  #define FLASH_ACR_LATENCY_2WS    0x00000002
  #define FLASH_ACR_LATENCY_3WS    0x00000003
  #define FLASH_ACR_LATENCY_4WS    0x00000004
  #define FLASH_ACR_LATENCY_5WS    0x00000005
  #define FLASH_ACR_LATENCY_6WS    0x00000006
  #define FLASH_ACR_LATENCY_7WS    0x00000007
  #define FLASH_ACR_PRFTEN         0x00000100
  #define FLASH_ACR_ICEN           0x00000200
  #define FLASH_ACR_DCEN           0x00000400
  #define FLASH_ACR_ICRST          0x00000800
  #define FLASH_ACR_DCRST          0x00001000
  #define FLASH_ACR_BYTE0_ADDRESS  0x40023C00
  #define FLASH_ACR_BYTE2_ADDRESS  0x40023C03
#define TOFF_FLASH_KEYR     0x0004		/* (RW) FLASH key register */
#define TOFF_FLASH_OPTKEYR  0x0008		/* (RW) FLASH option key register */
#define TOFF_FLASH_SR       0x000C		/* (RW) FLASH status register */
  #define FLASH_SR_EOP             0x00000001
  #define FLASH_SR_SOP             0x00000002
  #define FLASH_SR_WRPERR          0x00000010
  #define FLASH_SR_PGAERR          0x00000020
  #define FLASH_SR_PGPERR          0x00000040
  #define FLASH_SR_PGSERR          0x00000080
  #define FLASH_SR_BSY             0x00010000
#define TOFF_FLASH_CR       0x0010		/* (RW) FLASH control register */
  #define FLASH_CR_PG              0x00000001
  #define FLASH_CR_SER             0x00000002
  #define FLASH_CR_MER             0x00000004
  #define FLASH_CR_SNB_0           0x00000008
  #define FLASH_CR_SNB_1           0x00000010
  #define FLASH_CR_SNB_2           0x00000020
  #define FLASH_CR_SNB_3           0x00000040
  #define FLASH_CR_PSIZE_0         0x00000100
  #define FLASH_CR_PSIZE_1         0x00000200
  #define FLASH_CR_STRT            0x00010000
  #define FLASH_CR_EOPIE           0x01000000
  #define FLASH_CR_LOCK            0x80000000
#define TOFF_FLASH_OPTCR    0x0014		/* (RW) FLASH option control register */
  #define FLASH_OPTCR_OPTLOCK      0x00000001
  #define FLASH_OPTCR_OPTSTRT      0x00000002
  #define FLASH_OPTCR_BOR_LEV_0    0x00000004
  #define FLASH_OPTCR_BOR_LEV_1    0x00000008
  #define FLASH_OPTCR_BOR_LEV      0x0000000C
  #define FLASH_OPTCR_WDG_SW       0x00000020
  #define FLASH_OPTCR_nRST_STOP    0x00000040
  #define FLASH_OPTCR_nRST_STDBY   0x00000080
  #define FLASH_OPTCR_RDP_0        0x00000100
  #define FLASH_OPTCR_RDP_1        0x00000200
  #define FLASH_OPTCR_RDP_2        0x00000400
  #define FLASH_OPTCR_RDP_3        0x00000800
  #define FLASH_OPTCR_RDP_4        0x00001000
  #define FLASH_OPTCR_RDP_5        0x00002000
  #define FLASH_OPTCR_RDP_6        0x00004000
  #define FLASH_OPTCR_RDP_7        0x00008000
  #define FLASH_OPTCR_nWRP_0       0x00010000
  #define FLASH_OPTCR_nWRP_1       0x00020000
  #define FLASH_OPTCR_nWRP_2       0x00040000
  #define FLASH_OPTCR_nWRP_3       0x00080000
  #define FLASH_OPTCR_nWRP_4       0x00100000
  #define FLASH_OPTCR_nWRP_5       0x00200000
  #define FLASH_OPTCR_nWRP_6       0x00400000
  #define FLASH_OPTCR_nWRP_7       0x00800000
  #define FLASH_OPTCR_nWRP_8       0x01000000
  #define FLASH_OPTCR_nWRP_9       0x02000000
  #define FLASH_OPTCR_nWRP_10      0x04000000
  #define FLASH_OPTCR_nWRP_11      0x08000000

/* 
 *  DMA CONTROLLER
 */
#define TADR_DMA1_BASE      (AHB1PERIPH_BASE + 0x6000)
#define TADR_DMA2_BASE      (AHB1PERIPH_BASE + 0x6400)
#define TOFF_DMAI_LISR      0x0000		/* (RW) DMA low interrupt status register */
#define TOFF_DMAI_HISR      0x0004		/* (RW) DMA high interrupt status register */
#define TOFF_DMAI_LIFCR     0x0008		/* (RW) DMA low interrupt flag clear register */
#define TOFF_DMAI_HIFCR     0x000C		/* (RW) DMA high interrupt flag clear register */

#define TADR_DMA1_STM0_BASE (TADR_DMA1_BASE + 0x010)
#define TADR_DMA1_STM1_BASE (TADR_DMA1_BASE + 0x028)
#define TADR_DMA1_STM2_BASE (TADR_DMA1_BASE + 0x040)
#define TADR_DMA1_STM3_BASE (TADR_DMA1_BASE + 0x058)
#define TADR_DMA1_STM4_BASE (TADR_DMA1_BASE + 0x070)
#define TADR_DMA1_STM5_BASE (TADR_DMA1_BASE + 0x088)
#define TADR_DMA1_STM6_BASE (TADR_DMA1_BASE + 0x0A0)
#define TADR_DMA1_STM7_BASE (TADR_DMA1_BASE + 0x0B8)
#define TADR_DMA2_STM0_BASE (TADR_DMA2_BASE + 0x010)
#define TADR_DMA2_STM1_BASE (TADR_DMA2_BASE + 0x028)
#define TADR_DMA2_STM2_BASE (TADR_DMA2_BASE + 0x040)
#define TADR_DMA2_STM3_BASE (TADR_DMA2_BASE + 0x058)
#define TADR_DMA2_STM4_BASE (TADR_DMA2_BASE + 0x070)
#define TADR_DMA2_STM5_BASE (TADR_DMA2_BASE + 0x088)
#define TADR_DMA2_STM6_BASE (TADR_DMA2_BASE + 0x0A0)
#define TADR_DMA2_STM7_BASE (TADR_DMA2_BASE + 0x0B8)
#define TOFF_DMAS_CR        0x0000		/* (RW) DMA stream x configuration register      */
  #define DMA_SxCR_CHSEL           0x0E000000
  #define DMA_SxCR_CHSEL_0         0x02000000
  #define DMA_SxCR_CHSEL_1         0x04000000
  #define DMA_SxCR_CHSEL_2         0x08000000
  #define DMA_SxCR_MBURST          0x01800000
  #define DMA_SxCR_MBURST_0        0x00800000
  #define DMA_SxCR_MBURST_1        0x01000000
  #define DMA_SxCR_PBURST          0x00600000
  #define DMA_SxCR_PBURST_0        0x00200000
  #define DMA_SxCR_PBURST_1        0x00400000
  #define DMA_SxCR_ACK             0x00100000
  #define DMA_SxCR_CT              0x00080000
  #define DMA_SxCR_DBM             0x00040000
  #define DMA_SxCR_PL              0x00030000
  #define DMA_SxCR_PL_0            0x00010000
  #define DMA_SxCR_PL_1            0x00020000
  #define DMA_SxCR_PINCOS          0x00008000
  #define DMA_SxCR_MSIZE           0x00006000
  #define DMA_SxCR_MSIZE_0         0x00002000
  #define DMA_SxCR_MSIZE_1         0x00004000
  #define DMA_SxCR_PSIZE           0x00001800
  #define DMA_SxCR_PSIZE_0         0x00000800
  #define DMA_SxCR_PSIZE_1         0x00001000
  #define DMA_SxCR_MINC            0x00000400
  #define DMA_SxCR_PINC            0x00000200
  #define DMA_SxCR_CIRC            0x00000100
  #define DMA_SxCR_DIR             0x000000C0
  #define DMA_SxCR_DIR_0           0x00000040
  #define DMA_SxCR_DIR_1           0x00000080
  #define DMA_SxCR_PFCTRL          0x00000020
  #define DMA_SxCR_TCIE            0x00000010
  #define DMA_SxCR_HTIE            0x00000008
  #define DMA_SxCR_TEIE            0x00000004
  #define DMA_SxCR_DMEIE           0x00000002
  #define DMA_SxCR_EN              0x00000001
#define TOFF_DMAS_NDTR      0x0004		/* (RW) DMA stream x number of data register     */
#define TOFF_DMAS_PAR       0x0008		/* (RW) DMA stream x peripheral address register */
#define TOFF_DMAS_M0AR      0x000C		/* (RW) DMA stream x memory 0 address register   */
#define TOFF_DMAS_M1AR      0x0010		/* (RW) DMA stream x memory 1 address register   */
#define TOFF_DMAS_FCR       0x0014		/* (RW) DMA stream x FIFO control register       */
  #define DMA_SxFCR_FEIE           0x00000080
  #define DMA_SxFCR_FS             0x00000038
  #define DMA_SxFCR_FS_0           0x00000008
  #define DMA_SxFCR_FS_1           0x00000010
  #define DMA_SxFCR_FS_2           0x00000020
  #define DMA_SxFCR_DMDIS          0x00000004
  #define DMA_SxFCR_FTH            0x00000003
  #define DMA_SxFCR_FTH_0          0x00000001
  #define DMA_SxFCR_FTH_1          0x00000002



#define ETH_BASE            (AHB1PERIPH_BASE + 0x8000)
#define ETH_MAC_BASE        (ETH_BASE)
#define ETH_MMC_BASE        (ETH_BASE + 0x0100)
#define ETH_PTP_BASE        (ETH_BASE + 0x0700)
#define ETH_DMA_BASE        (ETH_BASE + 0x1000)



/*
 *  DCMI
 */
#define TADR_DCMI_BASE      (AHB2PERIPH_BASE + 0x50000)
#define TOFF_DCMI_CR        0x0000		/* (RW) DCMI control register 1 */
#define TOFF_DCMI_SR        0x0004		/* (R)  DCMI status register */
#define TOFF_DCMI_RISR      0x0008		/* (R)  DCMI raw interrupt status register */
#define TOFF_DCMI_IER       0x000C		/* (RW) DCMI interrupt enable register */
#define TOFF_DCMI_MISR      0x0010		/* (RW) DCMI masked interrupt status register */
#define TOFF_DCMI_ICR       0x0014		/* (RW) DCMI interrupt clear register */
#define TOFF_DCMI_ESCR      0x0018		/* (RW) DCMI embedded synchronization code register */
#define TOFF_DCMI_ESUR      0x001C		/* (RW) DCMI embedded synchronization unmask register */
#define TOFF_DCMI_CWSTRTR   0x0020		/* (RW) DCMI crop window start */
#define TOFF_DCMI_CWSIZER   0x0024		/* (RW) DCMI crop window size */
#define TOFF_DCMI_DR        0x0028		/* (RW) DCMI data register */

/*
 *  CRYPTO PROCESSER
 */
#define TADR_CRYP_BASE      (AHB2PERIPH_BASE + 0x60000)
#define TOFF_CRYP_CR        0x0000		/* (RW) CRYP control register */
#define TOFF_CRYP_SR        0x0004		/* (R)  CRYP status register */
#define TOFF_CRYP_DR        0x0008		/* (RW) CRYP data input register */
#define TOFF_CRYP_DOUT      0x000C		/* (RW) CRYP data output register */
#define TOFF_CRYP_DMACR     0x0010		/* (RW) CRYP DMA control register */
#define TOFF_CRYP_IMSCR     0x0014		/* (RW) CRYP interrupt mask set/clear register */
#define TOFF_CRYP_RISR      0x0018		/* (RW) CRYP raw interrupt status register */
#define TOFF_CRYP_MISR      0x001C		/* (RW) CRYP masked interrupt status register */
#define TOFF_CRYP_K0LR      0x0020		/* (RW) CRYP key left  register 0 */
#define TOFF_CRYP_K0RR      0x0024		/* (RW) CRYP key right register 0 */
#define TOFF_CRYP_K1LR      0x0028		/* (RW) CRYP key left  register 1 */
#define TOFF_CRYP_K1RR      0x002C		/* (RW) CRYP key right register 1 */
#define TOFF_CRYP_K2LR      0x0030		/* (RW) CRYP key left  register 2 */
#define TOFF_CRYP_K2RR      0x0034		/* (RW) CRYP key right register 2 */
#define TOFF_CRYP_K3LR      0x0038		/* (RW) CRYP key left  register 3 */
#define TOFF_CRYP_K3RR      0x003C		/* (RW) CRYP key right register 3 */
#define TOFF_CRYP_IV0LR     0x0040		/* (RW) CRYP initialization vector left-word  register 0 */
#define TOFF_CRYP_IV0RR     0x0044		/* (RW) CRYP initialization vector right-word register 0 */
#define TOFF_CRYP_IV1LR     0x0048		/* (RW) CRYP initialization vector left-word  register 1 */
#define TOFF_CRYP_IV1RR     0x004C		/* (RW) CRYP initialization vector right-word register 1 */

/*
 *  HASH
 */
#define TADR_HASH_BASE      (AHB2PERIPH_BASE + 0x60400)
#define TOFF_HASH_CR        0x0000		/* (RW) HASH control register */
#define TOFF_HASH_DIN       0x0004		/* (RW) HASH data input register */
#define TOFF_HASH_STR       0x0008		/* (RW) HASH start register */
#define TOFF_HASH_HR0       0x000C		/* (RW) HASH digest registers 0 */
#define TOFF_HASH_HR1       0x0010		/* (RW) HASH digest registers 1 */
#define TOFF_HASH_HR2       0x0014		/* (RW) HASH digest registers 2 */
#define TOFF_HASH_HR3       0x0018		/* (RW) HASH digest registers 3 */
#define TOFF_HASH_HR4       0x001C		/* (RW) HASH digest registers 4 */
#define TOFF_HASH_IMR       0x0020		/* (RW) HASH interrupt enable register */
#define TOFF_HASH_SR        0x0024		/* (R)  HASH status register */
#define TOFF_HASH_CSR0      0x00F8		/* (RW) HASH context swap registers 0 */
#define TOFF_HASH_CSR1      0x00FC		/* (RW) HASH context swap registers 1 */
#define TOFF_HASH_CSR2      0x0100		/* (RW) HASH context swap registers 2 */
#define TOFF_HASH_CSR3      0x0104		/* (RW) HASH context swap registers 3 */
#define TOFF_HASH_CSR4      0x0108		/* (RW) HASH context swap registers 4 */
#define TOFF_HASH_CSR5      0x010C		/* (RW) HASH context swap registers 5 */
#define TOFF_HASH_CSR6      0x0110		/* (RW) HASH context swap registers 6 */
#define TOFF_HASH_CSR7      0x0114		/* (RW) HASH context swap registers 7 */
#define TOFF_HASH_CSR8      0x0118		/* (RW) HASH context swap registers 8 */
#define TOFF_HASH_CSR9      0x011C		/* (RW) HASH context swap registers 9 */
#define TOFF_HASH_CSR10     0x0120		/* (RW) HASH context swap registers 10 */
#define TOFF_HASH_CSR11     0x0124		/* (RW) HASH context swap registers 11 */
#define TOFF_HASH_CSR12     0x0128		/* (RW) HASH context swap registers 12 */
#define TOFF_HASH_CSR13     0x012C		/* (RW) HASH context swap registers 13 */
#define TOFF_HASH_CSR14     0x0130		/* (RW) HASH context swap registers 14 */
#define TOFF_HASH_CSR15     0x0134		/* (RW) HASH context swap registers 15 */
#define TOFF_HASH_CSR16     0x0138		/* (RW) HASH context swap registers 16 */
#define TOFF_HASH_CSR17     0x013C		/* (RW) HASH context swap registers 17 */
#define TOFF_HASH_CSR18     0x0140		/* (RW) HASH context swap registers 18 */
#define TOFF_HASH_CSR19     0x0144		/* (RW) HASH context swap registers 19 */
#define TOFF_HASH_CSR20     0x0148		/* (RW) HASH context swap registers 20 */
#define TOFF_HASH_CSR21     0x014C		/* (RW) HASH context swap registers 21 */
#define TOFF_HASH_CSR22     0x0150		/* (RW) HASH context swap registers 22 */
#define TOFF_HASH_CSR23     0x0154		/* (RW) HASH context swap registers 23 */
#define TOFF_HASH_CSR24     0x0158		/* (RW) HASH context swap registers 24 */
#define TOFF_HASH_CSR25     0x015C		/* (RW) HASH context swap registers 25 */
#define TOFF_HASH_CSR26     0x0160		/* (RW) HASH context swap registers 26 */
#define TOFF_HASH_CSR27     0x0164		/* (RW) HASH context swap registers 27 */
#define TOFF_HASH_CSR28     0x0168		/* (RW) HASH context swap registers 28 */
#define TOFF_HASH_CSR29     0x016C		/* (RW) HASH context swap registers 29 */
#define TOFF_HASH_CSR30     0x0170		/* (RW) HASH context swap registers 30 */
#define TOFF_HASH_CSR31     0x0174		/* (RW) HASH context swap registers 31 */
#define TOFF_HASH_CSR32     0x0178		/* (RW) HASH context swap registers 32 */
#define TOFF_HASH_CSR33     0x017C		/* (RW) HASH context swap registers 33 */
#define TOFF_HASH_CSR34     0x0180		/* (RW) HASH context swap registers 34 */
#define TOFF_HASH_CSR35     0x0184		/* (RW) HASH context swap registers 35 */
#define TOFF_HASH_CSR36     0x0188		/* (RW) HASH context swap registers 36 */
#define TOFF_HASH_CSR37     0x018C		/* (RW) HASH context swap registers 37 */
#define TOFF_HASH_CSR38     0x0190		/* (RW) HASH context swap registers 38 */
#define TOFF_HASH_CSR39     0x0194		/* (RW) HASH context swap registers 39 */
#define TOFF_HASH_CSR40     0x0198		/* (RW) HASH context swap registers 40 */
#define TOFF_HASH_CSR41     0x019C		/* (RW) HASH context swap registers 41 */
#define TOFF_HASH_CSR42     0x01A0		/* (RW) HASH context swap registers 42 */
#define TOFF_HASH_CSR43     0x01A4		/* (RW) HASH context swap registers 43 */
#define TOFF_HASH_CSR44     0x01A8		/* (RW) HASH context swap registers 44 */
#define TOFF_HASH_CSR45     0x01AC		/* (RW) HASH context swap registers 45 */
#define TOFF_HASH_CSR46     0x01B0		/* (RW) HASH context swap registers 46 */
#define TOFF_HASH_CSR47     0x01B4		/* (RW) HASH context swap registers 47 */
#define TOFF_HASH_CSR48     0x01B8		/* (RW) HASH context swap registers 48 */
#define TOFF_HASH_CSR49     0x01BC		/* (RW) HASH context swap registers 49 */
#define TOFF_HASH_CSR50     0x01C0		/* (RW) HASH context swap registers 50 */

/*
 *  RNG
 */
#define TADR_RNG_BASE       (AHB2PERIPH_BASE + 0x60800)
#define TOFF_RNG_CR         0x0000		/* (RW) RNG control register */
#define TOFF_RNG_SR         0x0004		/* (RW) RNG status register */
#define TOFF_RNG_DR         0x0008		/* (RW) RNG data register */

/*
 *  FLEXIBLE STATIC MEMORY
 */
#define TADR_FSMC_R_BASE    (FSMC_R_BASE + 0x0000)

/*
 *  FLEXIBLE STATIC MEMORY CONTROLLER
 */
#define TOFF_FSMC_R_BTCR0   0x0000		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 0 */
#define TOFF_FSMC_R_BTCR1   0x0004		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 1 */
#define TOFF_FSMC_R_BTCR2   0x0008		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 2 */
#define TOFF_FSMC_R_BTCR3   0x000C		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 3 */
#define TOFF_FSMC_R_BTCR4   0x0010		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 4 */
#define TOFF_FSMC_R_BTCR5   0x0014		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 5 */
#define TOFF_FSMC_R_BTCR6   0x0018		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 6 */
#define TOFF_FSMC_R_BTCR7   0x001C		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 7 */

/*
 *  FLEXIBLE STATIC MEMORY CONTROLLER BANK1E
 */
#define TOFF_FSMC_R_BWTR0   0x0104		/* (RW) NOR/PSRAM write timing registers 0 */
#define TOFF_FSMC_R_BWTR1   0x0108		/* (RW) NOR/PSRAM write timing registers 1 */
#define TOFF_FSMC_R_BWTR2   0x010C		/* (RW) NOR/PSRAM write timing registers 2 */
#define TOFF_FSMC_R_BWTR3   0x0110		/* (RW) NOR/PSRAM write timing registers 3 */
#define TOFF_FSMC_R_BWTR4   0x0114		/* (RW) NOR/PSRAM write timing registers 4 */
#define TOFF_FSMC_R_BWTR5   0x0118		/* (RW) NOR/PSRAM write timing registers 5 */
#define TOFF_FSMC_R_BWTR6   0x011C		/* (RW) NOR/PSRAM write timing registers 6 */

/*
 *  FLEXIBLE STATIC MEMORY CONTROLLER BANK2
 */
#define TOFF_FSMC_R_PCR2    0x0060		/* (RW) NAND Flash control register 2 */
#define TOFF_FSMC_R_SR2     0x0064		/* (RW) NAND Flash FIFO status and interrupt register 2 */
#define TOFF_FSMC_R_PMEM2   0x0068		/* (RW) NAND Flash Common memory space timing register 2 */
#define TOFF_FSMC_R_PATT2   0x006C		/* (RW) NAND Flash Attribute memory space timing register 2 */
#define TOFF_FSMC_R_ECCR2   0x0074		/* (RW) NAND Flash ECC result registers 2 */

/*
 *  FLEXIBLE STATIC MEMORY CONTROLLER BANK3
 */
#define TOFF_FSMC_R_PCR3    0x0080		/* (RW) NAND Flash control register 3 */
#define TOFF_FSMC_R_SR3     0x0084		/* (RW) NAND Flash FIFO status and interrupt register 3 */
#define TOFF_FSMC_R_PMEM3   0x0088		/* (RW) NAND Flash Common memory space timing register 3 */
#define TOFF_FSMC_R_PATT3   0x008C		/* (RW) NAND Flash Attribute memory space timing register 3 */
#define TOFF_FSMC_R_ECCR3   0x0094		/* (RW) NAND Flash ECC result registers 3 */

/*
 *  FLEXIBLE STATIC MEMORY CONTROLLER BANK4
 */
#define TOFF_FSMC_R_PCR4    0x00A0		/* (RW) PC Card  control register 4 */
#define TOFF_FSMC_R_SR4     0x00A4		/* (RW) PC Card  FIFO status and interrupt register 4 */
#define TOFF_FSMC_R_PMEM4   0x00A8		/* (RW) PC Card  Common memory space timing register 4 */
#define TOFF_FSMC_R_PATT4   0x00AC		/* (RW) PC Card  Attribute memory space timing register 4 */
#define TOFF_FSMC_R_PIO4    0x00B0		/* (RW) PC Card  I/O space timing register 4 */

/*
 *  DEBUG MCU
 */
#define TADR_DBGMCU_BASE    0xE0042000
#define TOFF_DBGMCU_IDCODE  0x0000		/* (RW) MCU device ID code */
#define TOFF_DBGMCU_CR      0x0004		/* (RW) Debug MCU configuration register */
#define TOFF_DBGMCU_APB1FZ  0x0008		/* (RW) Debug MCU APB1 freeze register */
#define TOFF_DBGMCU_APB2FZ  0x000C		/* (RW) Debug MCU APB2 freeze register */

/*
 *  USB OTG
 */
#define TADR_USB_OTGFS_BASE USB_OTG_FS_PERIPH_BASE
#define TOFF_USBO_GOTGCTL   0x0000		/* (RW) USB_OTG Control and Status Register */
  #define USB_OTG_GOTGCTL_SRQSCS    0x00000001	/* Session request success */
  #define USB_OTG_GOTGCTL_SRQ       0x00000002	/* Session request */
#if defined(TOPPERS_STM32F446_NUCLEO64) || defined(TOPPERS_STM32F446_NUCLEO144)
  #define USB_OTG_GOTGCTL_VBVALOEN  0x00000004	/* VBUS valid override enable */
  #define USB_OTG_GOTGCTL_VBVALOVAL 0x00000008	/* VBUS valid override value */
  #define USB_OTG_GOTGCTL_AVALOEN   0x00000010	/* A-peripheral session valid override enable */
  #define USB_OTG_GOTGCTL_AVALOVAL  0x00000020	/* A-peripheral session valid override value */
  #define USB_OTG_GOTGCTL_BVALOEN   0x00000040	/* B-peripheral session valid override enable */
  #define USB_OTG_GOTGCTL_BVALOVAL  0x00000080	/* B-peripheral session valid override value  */
#endif
  #define USB_OTG_GOTGCTL_HNGSCS    0x00000100	/* Host negotiation success */
  #define USB_OTG_GOTGCTL_HNPRQ     0x00000200	/* HNP request */
  #define USB_OTG_GOTGCTL_HSHNPEN   0x00000400	/* Host set HNP enable */
  #define USB_OTG_GOTGCTL_DHNPEN    0x00000800	/* Device HNP enabled */
#if defined(TOPPERS_STM32F446_NUCLEO64) || defined(TOPPERS_STM32F446_NUCLEO144)
  #define USB_OTG_GOTGCTL_EHEN      0x00001000	/* Embedded host enable */
#endif
  #define USB_OTG_GOTGCTL_CIDSTS    0x00010000	/* Connector ID status */
  #define USB_OTG_GOTGCTL_DBCT      0x00020000	/* Long/short debounce time */
  #define USB_OTG_GOTGCTL_ASVLD     0x00040000	/* A-session valid */
  #define USB_OTG_GOTGCTL_BSVLD     0x00080000	/* B-session valid */
#if defined(TOPPERS_STM32F446_NUCLEO64) || defined(TOPPERS_STM32F446_NUCLEO144)
  #define USB_OTG_GOTGCTL_OTGVER    0x00100000	/* OTG version  */
#endif
#define TOFF_USBO_GOTGINT   0x0004		/* (RW) USB_OTG Interrupt Register */
  #define USB_OTG_GOTGINT_SEDET     0x00000004	/* Session end detected */
  #define USB_OTG_GOTGINT_SRSSCHG   0x00000100	/* Session request success status change */
  #define USB_OTG_GOTGINT_HNSSCHG   0x00000200	/* Host negotiation success status change */
  #define USB_OTG_GOTGINT_HNGDET    0x00020000	/* Host negotiation detected */
  #define USB_OTG_GOTGINT_ADTOCHG   0x00040000	/* A-device timeout change */
  #define USB_OTG_GOTGINT_DBCDNE    0x00080000	/* Debounce done */
#if defined(TOPPERS_STM32F446_NUCLEO64) || defined(TOPPERS_STM32F446_NUCLEO144)
  #define USB_OTG_GOTGINT_IDCHNG    0x00100000	/* Change in ID pin input value */
#endif
#define TOFF_USBO_GAHBCFG   0x0008		/* (RW) Core AHB Configuration Register */
  #define USB_OTG_GAHBCFG_GINT      0x00000001	/* Global interrupt mask */
  #define USB_OTG_GAHBCFG_HBSTLEN   0x0000001E	/* Burst length/type */
  #define USB_OTG_GAHBCFG_HBSTLEN_0 0x00000002	/* Bit 0 */
  #define USB_OTG_GAHBCFG_HBSTLEN_1 0x00000004	/* Bit 1 */
  #define USB_OTG_GAHBCFG_HBSTLEN_2 0x00000008	/* Bit 2 */
  #define USB_OTG_GAHBCFG_HBSTLEN_3 0x00000010	/* Bit 3 */
  #define USB_OTG_GAHBCFG_DMAEN     0x00000020	/* DMA enable */
  #define USB_OTG_GAHBCFG_TXFELVL   0x00000080	/* TxFIFO empty level */
  #define USB_OTG_GAHBCFG_PTXFELVL  0x00000100	/* Periodic TxFIFO empty level */
#define TOFF_USBO_GUSBCFG   0x000C		/* (RW) Core USB Configuration Register */
  #define USB_OTG_GUSBCFG_TOCAL     0x00000007	/* FS timeout calibration */
  #define USB_OTG_GUSBCFG_TOCAL_0   0x00000001	/* Bit 0 */
  #define USB_OTG_GUSBCFG_TOCAL_1   0x00000002	/* Bit 1 */
  #define USB_OTG_GUSBCFG_TOCAL_2   0x00000004	/* Bit 2 */
  #define USB_OTG_GUSBCFG_PHYSEL    0x00000040	/* USB 2.0 high-speed ULPI PHY or USB 1.1 full-speed serial transceiver select */
  #define USB_OTG_GUSBCFG_SRPCAP    0x00000100	/* SRP-capable */
  #define USB_OTG_GUSBCFG_HNPCAP    0x00000200	/* HNP-capable */
  #define USB_OTG_GUSBCFG_TRDT      0x00003C00	/* USB turnaround time */
  #define USB_OTG_GUSBCFG_TRDT_0    0x00000400	/* Bit 0 */
  #define USB_OTG_GUSBCFG_TRDT_1    0x00000800	/* Bit 1 */
  #define USB_OTG_GUSBCFG_TRDT_2    0x00001000	/* Bit 2 */
  #define USB_OTG_GUSBCFG_TRDT_3    0x00002000	/* Bit 3 */
  #define USB_OTG_GUSBCFG_PHYLPCS   0x00008000	/* PHY Low-power clock select */
  #define USB_OTG_GUSBCFG_ULPIFSLS  0x00020000	/* ULPI FS/LS select */
  #define USB_OTG_GUSBCFG_ULPIAR    0x00040000	/* ULPI Auto-resume */
  #define USB_OTG_GUSBCFG_ULPICSM   0x00080000	/* ULPI Clock SuspendM */
  #define USB_OTG_GUSBCFG_ULPIEVBUSD 0x00100000	/* ULPI External VBUS Drive */
  #define USB_OTG_GUSBCFG_ULPIEVBUSI 0x00200000	/* ULPI external VBUS indicator */
  #define USB_OTG_GUSBCFG_TSDPS     0x00400000	/* TermSel DLine pulsing selection */
  #define USB_OTG_GUSBCFG_PCCI      0x00800000	/* Indicator complement */
  #define USB_OTG_GUSBCFG_PTCI      0x01000000	/* Indicator pass through */
  #define USB_OTG_GUSBCFG_ULPIIPD   0x02000000	/* ULPI interface protect disable */
  #define USB_OTG_GUSBCFG_FHMOD     0x20000000	/* Forced host mode */
  #define USB_OTG_GUSBCFG_FDMOD     0x40000000	/* Forced peripheral mode */
  #define USB_OTG_GUSBCFG_CTXPKT    0x80000000	/* Corrupt Tx packet */
#define TOFF_USBO_GRSTCTL    0x0010		/* (RW) Core Reset Register */
  #define USB_OTG_GRSTCTL_CSRST     0x00000001	/* Core soft reset */
  #define USB_OTG_GRSTCTL_HSRST     0x00000002	/* HCLK soft reset */
  #define USB_OTG_GRSTCTL_FCRST     0x00000004	/* Host frame counter reset */
  #define USB_OTG_GRSTCTL_RXFFLSH   0x00000010	/* RxFIFO flush */
  #define USB_OTG_GRSTCTL_TXFFLSH   0x00000020	/* TxFIFO flush */
  #define USB_OTG_GRSTCTL_TXFNUM    0x000007C0	/* TxFIFO number */
  #define USB_OTG_GRSTCTL_TXFNUM_0  0x00000040	/* Bit 0 */
  #define USB_OTG_GRSTCTL_TXFNUM_1  0x00000080	/* Bit 1 */
  #define USB_OTG_GRSTCTL_TXFNUM_2  0x00000100	/* Bit 2 */
  #define USB_OTG_GRSTCTL_TXFNUM_3  0x00000200	/* Bit 3 */
  #define USB_OTG_GRSTCTL_TXFNUM_4  0x00000400	/* Bit 4 */
  #define USB_OTG_GRSTCTL_DMAREQ    0x40000000	/* DMA request signal */
  #define USB_OTG_GRSTCTL_AHBIDL    0x80000000	/* AHB master idle */
#define TOFF_USBO_GINTSTS   0x0014		/* (RW)  Core Interrupt Register */
  #define USB_OTG_GINTSTS_CMOD      0x00000001	/* Current mode of operation */
  #define USB_OTG_GINTSTS_MMIS      0x00000002	/* Mode mismatch interrupt */
  #define USB_OTG_GINTSTS_OTGINT    0x00000004	/* OTG interrupt */
  #define USB_OTG_GINTSTS_SOF       0x00000008	/* Start of frame */
  #define USB_OTG_GINTSTS_RXFLVL    0x00000010	/* RxFIFO nonempty */
  #define USB_OTG_GINTSTS_NPTXFE    0x00000020	/* Nonperiodic TxFIFO empty */
  #define USB_OTG_GINTSTS_GINAKEFF  0x00000040	/* Global IN nonperiodic NAK effective */
  #define USB_OTG_GINTSTS_BOUTNAKEFF 0x00000080	/* Global OUT NAK effective */
  #define USB_OTG_GINTSTS_ESUSP     0x00000400	/* Early suspend */
  #define USB_OTG_GINTSTS_USBSUSP   0x00000800	/* USB suspend */
  #define USB_OTG_GINTSTS_USBRST    0x00001000	/* USB reset */
  #define USB_OTG_GINTSTS_ENUMDNE   0x00002000	/* Enumeration done */
  #define USB_OTG_GINTSTS_ISOODRP   0x00004000	/* Isochronous OUT packet dropped interrupt */
  #define USB_OTG_GINTSTS_EOPF      0x00008000	/* End of periodic frame interrupt */
  #define USB_OTG_GINTSTS_IEPINT    0x00040000	/* IN endpoint interrupt */
  #define USB_OTG_GINTSTS_OEPINT    0x00080000	/* OUT endpoint interrupt */
  #define USB_OTG_GINTSTS_IISOIXFR  0x00100000	/* Incomplete isochronous IN transfer */
  #define USB_OTG_GINTSTS_PXFR_INCOMPISOOUT 0x00200000	/* Incomplete periodic transfer */
  #define USB_OTG_GINTSTS_DATAFSUSP 0x00400000	/* Data fetch suspended */
  #define USB_OTG_GINTSTS_HPRTINT   0x01000000	/* Host port interrupt */
  #define USB_OTG_GINTSTS_HCINT     0x02000000	/* Host channels interrupt */
  #define USB_OTG_GINTSTS_PTXFE     0x04000000	/* Periodic TxFIFO empty */
#if defined(TOPPERS_STM32F446_NUCLEO64) || defined(TOPPERS_STM32F446_NUCLEO144)
  #define USB_OTG_GINTSTS_LPMINT    0x08000000	/* LPM interrupt                                  */
#endif
  #define USB_OTG_GINTSTS_CIDSCHG   0x10000000	/* Connector ID status change */
  #define USB_OTG_GINTSTS_DISCINT   0x20000000	/* Disconnect detected interrupt */
  #define USB_OTG_GINTSTS_SRQINT    0x40000000	/* Session request/new session detected interrupt */
  #define USB_OTG_GINTSTS_WKUINT    0x80000000	/* Resume/remote wakeup detected interrupt */
#define TOFF_USBO_GINTMSK   0x0018		/* (RW)  Core Interrupt Mask Register */
  #define USB_OTG_GINTMSK_MMISM     0x00000002	/* Mode mismatch interrupt mask */
  #define USB_OTG_GINTMSK_OTGINT    0x00000004	/* OTG interrupt mask */
  #define USB_OTG_GINTMSK_SOFM      0x00000008	/* Start of frame mask */
  #define USB_OTG_GINTMSK_RXFLVLM   0x00000010	/* Receive FIFO nonempty mask */
  #define USB_OTG_GINTMSK_NPTXFEM   0x00000020	/* Nonperiodic TxFIFO empty mask */
  #define USB_OTG_GINTMSK_GINAKEFFM 0x00000040	/* Global nonperiodic IN NAK effective mask */
  #define USB_OTG_GINTMSK_GONAKEFFM 0x00000080	/* Global OUT NAK effective mask */
  #define USB_OTG_GINTMSK_ESUSPM    0x00000400	/* Early suspend mask */
  #define USB_OTG_GINTMSK_USBSUSPM  0x00000800	/* USB suspend mask */
  #define USB_OTG_GINTMSK_USBRST    0x00001000	/* USB reset mask */
  #define USB_OTG_GINTMSK_ENUMDNEM  0x00002000	/* Enumeration done mask */
  #define USB_OTG_GINTMSK_ISOODRPM  0x00004000	/* Isochronous OUT packet dropped interrupt mask */
  #define USB_OTG_GINTMSK_EOPFM     0x00008000	/* End of periodic frame interrupt mask */
  #define USB_OTG_GINTMSK_EPMISM    0x00020000	/* Endpoint mismatch interrupt mask */
  #define USB_OTG_GINTMSK_IEPINT    0x00040000	/* IN endpoints interrupt mask */
  #define USB_OTG_GINTMSK_OEPINT    0x00080000	/* OUT endpoints interrupt mask */
  #define USB_OTG_GINTMSK_IISOIXFRM 0x00100000	/* Incomplete isochronous IN transfer mask */
  #define USB_OTG_GINTMSK_PXFRM_IISOOXFRM 0x00200000	/* Incomplete periodic transfer mask */
  #define USB_OTG_GINTMSK_FSUSPM    0x00400000	/* Data fetch suspended mask */
#if defined(TOPPERS_STM32F446_NUCLEO64) || defined(TOPPERS_STM32F446_NUCLEO144)
  #define USB_OTG_GINTMSK_RSTDEM    0x00800000	/* Reset detected interrupt mask */
#endif
  #define USB_OTG_GINTMSK_PRTIM     0x01000000	/* Host port interrupt mask */
  #define USB_OTG_GINTMSK_HCIM      0x02000000	/* Host channels interrupt mask */
  #define USB_OTG_GINTMSK_PTXFEM    0x04000000	/* Periodic TxFIFO empty mask */
#if defined(TOPPERS_STM32F446_NUCLEO64) || defined(TOPPERS_STM32F446_NUCLEO144)
  #define USB_OTG_GINTMSK_LPMINTM   0x08000000	/* LPM interrupt Mask */
#endif
  #define USB_OTG_GINTMSK_CIDSCHGM  0x10000000	/* Connector ID status change mask */
  #define USB_OTG_GINTMSK_DISCINT   0x20000000	/* Disconnect detected interrupt mask */
  #define USB_OTG_GINTMSK_SRQIM     0x40000000	/* Session request/new session detected interrupt mask */
  #define USB_OTG_GINTMSK_WUIM      0x80000000	/* Resume/remote wakeup detected interrupt mask */
#define TOFF_USBO_GRXSTSR   0x001C		/* (RW) Receive Sts Q Read Register */
#define TOFF_USBO_GRXSTSP   0x0020		/* (RW) Receive Sts Q Read & POP Register */
  #define USB_OTG_GRXSTSP_EPNUM     0x0000000F	/* IN EP interrupt mask bits */
  #define USB_OTG_GRXSTSP_BCNT      0x00007FF0	/* OUT EP interrupt mask bits */
  #define USB_OTG_GRXSTSP_DPID      0x00018000	/* OUT EP interrupt mask bits */
  #define USB_OTG_GRXSTSP_PKTSTS    0x001E0000	/* OUT EP interrupt mask bits */
#define TOFF_USBO_GRXFSIZ   0x0024		/* (RW) Receive FIFO Size Register */
  #define USB_OTG_GRXFSIZ_RXFD      0x0000FFFF	/* RxFIFO depth */
#define TOFF_USBO_DIEPTXF0_HNPTXFSIZ 0x0028	/* (RW) EP0 / Non Periodic Tx FIFO Size Register */
  #define USB_OTG_NPTXFSA           0x0000FFFF	/* Nonperiodic transmit RAM start address */
  #define USB_OTG_NPTXFD            0xFFFF0000	/* Nonperiodic TxFIFO depth */
  #define USB_OTG_TX0FSA            0x0000FFFF	/* Endpoint 0 transmit RAM start address */
  #define USB_OTG_TX0FD             0xFFFF0000	/* Endpoint 0 TxFIFO depth */
#define TOFF_USBO_HNPTXSTS  0x002C		/* (RW) Non Periodic Tx FIFO/Queue Sts Register */
#define TOFF_USBO_GCCFG     0x0038		/* (RW) General Purpose IO Register */
  #define USB_OTG_GCCFG_PWRDWN      0x00010000	/* Power down */
#if defined(TOPPERS_STM32F446_NUCLEO64) || defined(TOPPERS_STM32F446_NUCLEO144)
  #define USB_OTG_GCCFG_VBDEN       0x00200000	/* USB VBUS Detection Enable */
#else
  #define USB_OTG_GCCFG_I2CPADEN    0x00020000	/* Enable I2C bus connection for the external I2C PHY interface */
  #define USB_OTG_GCCFG_VBUSASEN    0x00040000	/* Enable the VBUS sensing device */
  #define USB_OTG_GCCFG_VBUSBSEN    0x00080000	/* Enable the VBUS sensing device */
  #define USB_OTG_GCCFG_SOFOUTEN    0x00100000	/* SOF output enable */
  #define USB_OTG_GCCFG_NOVBUSSENS  0x00200000	/* VBUS sensing disable option */
#endif
#define TOFF_USBO_CID       0x003C		/* (RW) User ID Register */
  #define USB_OTG_CID_PRODUCT_ID    0xFFFFFFFF	/* Product ID field */
#if defined(TOPPERS_STM32F446_NUCLEO64) || defined(TOPPERS_STM32F446_NUCLEO144)
#define TOFF_USBO_GHWCFG3   0x004C		/* (RW) User HW config3 */
#define TOFF_USBO_GLPMCFG   0x0054		/* (RW) LPM Register */
  #define USB_OTG_GLPMCFG_LPMEN     0x00000001	/* LPM support enable                                     */
  #define USB_OTG_GLPMCFG_LPMACK    0x00000002	/* LPM Token acknowledge enable                           */
  #define USB_OTG_GLPMCFG_BESL      0x0000003C	/* BESL value received with last ACKed LPM Token          */
  #define USB_OTG_GLPMCFG_REMWAKE   0x00000040	/* bRemoteWake value received with last ACKed LPM Token   */
  #define USB_OTG_GLPMCFG_L1SSEN    0x00000080	/* L1 shallow sleep enable                                */
  #define USB_OTG_GLPMCFG_BESLTHRS  0x00000F00	/* BESL threshold                                         */
  #define USB_OTG_GLPMCFG_L1DSEN    0x00001000	/* L1 deep sleep enable                                   */
  #define USB_OTG_GLPMCFG_LPMRSP    0x00006000	/* LPM response                                           */
  #define USB_OTG_GLPMCFG_SLPSTS    0x00008000	/* Port sleep status                                      */
  #define USB_OTG_GLPMCFG_L1RSMOK   0x00010000	/* Sleep State Resume OK                                  */
  #define USB_OTG_GLPMCFG_LPMCHIDX  0x001E0000	/* LPM Channel Index                                      */
  #define USB_OTG_GLPMCFG_LPMRCNT   0x00E00000	/* LPM retry count                                        */
  #define USB_OTG_GLPMCFG_SNDLPM    0x01000000	/* Send LPM transaction                                   */
  #define USB_OTG_GLPMCFG_LPMRCNTSTS 0x0E000000	/* LPM retry count status                                 */
  #define USB_OTG_GLPMCFG_ENBESL    0x10000000	/* Enable best effort service latency                     */
#define TOFF_USBO_GDFIFOCFG 0x005C		/* (RW) DFIFO Software Config Register */
#endif
#define TOFF_USBO_HPTXFSIZ  0x0100		/* (RW) Host Periodic Tx FIFO Size Reg */
  #define USB_OTG_HPTXFSIZ_PTXSA    0x0000FFFF	/* Host periodic TxFIFO start address */
  #define USB_OTG_HPTXFSIZ_PTXFD    0xFFFF0000	/* Host periodic TxFIFO depth */
#define TOFF_USBO_DIEPTXF   0x0104		/* (RW) dev Periodic Transmit FIFO x 15 */
  #define USB_OTG_DIEPTXF_INEPTXSA  0x0000FFFF	/* IN endpoint FIFOx transmit RAM start address */
  #define USB_OTG_DIEPTXF_INEPTXFD  0xFFFF0000	/* IN endpoint TxFIFO depth */

/*
 *  USB DEVICE(OTG)
 */
#define TADR_USB_DEVICE_BASE (USB_OTG_FS_PERIPH_BASE+USB_OTG_DEVICE_BASE)
#define TOFF_USBD_DCFG      0x0000		/* (RW) dev Configuration Register */
  #define USB_OTG_DCFG_DSPD         0x00000003	/* Device speed */
  #define USB_OTG_DCFG_DSPD_0       0x00000001	/* Bit 0 */
  #define USB_OTG_DCFG_DSPD_1       0x00000002	/* Bit 1 */
  #define USB_OTG_DCFG_NZLSOHSK     0x00000004	/* Nonzero-length status OUT handshake */
  #define USB_OTG_DCFG_DAD          0x000007F0	/* Device address */
  #define USB_OTG_DCFG_DAD_0        0x00000010	/* Bit 0 */
  #define USB_OTG_DCFG_DAD_1        0x00000020	/* Bit 1 */
  #define USB_OTG_DCFG_DAD_2        0x00000040	/* Bit 2 */
  #define USB_OTG_DCFG_DAD_3        0x00000080	/* Bit 3 */
  #define USB_OTG_DCFG_DAD_4        0x00000100	/* Bit 4 */
  #define USB_OTG_DCFG_DAD_5        0x00000200	/* Bit 5 */
  #define USB_OTG_DCFG_DAD_6        0x00000400	/* Bit 6 */
  #define USB_OTG_DCFG_PFIVL        0x00001800	/* Periodic (micro)frame interval */
  #define USB_OTG_DCFG_PFIVL_0      0x00000800	/* Bit 0 */
  #define USB_OTG_DCFG_PFIVL_1      0x00001000	/* Bit 1 */
  #define USB_OTG_DCFG_PERSCHIVL    0x03000000	/* Periodic scheduling interval */
  #define USB_OTG_DCFG_PERSCHIVL_0  0x01000000	/* Bit 0 */
  #define USB_OTG_DCFG_PERSCHIVL_1  0x02000000	/* Bit 1 */
#define TOFF_USBD_DCTL      0x0004		/* (RW) dev Control Register */
  #define USB_OTG_DCTL_RWUSIG       0x00000001	/* Remote wakeup signaling */
  #define USB_OTG_DCTL_SDIS         0x00000002	/* Soft disconnect */
  #define USB_OTG_DCTL_GINSTS       0x00000004	/* Global IN NAK status */
  #define USB_OTG_DCTL_GONSTS       0x00000008	/* Global OUT NAK status */
  #define USB_OTG_DCTL_TCTL         0x00000070	/* Test control */
  #define USB_OTG_DCTL_TCTL_0       0x00000010	/* Bit 0 */
  #define USB_OTG_DCTL_TCTL_1       0x00000020	/* Bit 1 */
  #define USB_OTG_DCTL_TCTL_2       0x00000040	/* Bit 2 */
  #define USB_OTG_DCTL_SGINAK       0x00000080	/* Set global IN NAK */
  #define USB_OTG_DCTL_CGINAK       0x00000100	/* Clear global IN NAK */
  #define USB_OTG_DCTL_SGONAK       0x00000200	/* Set global OUT NAK */
  #define USB_OTG_DCTL_CGONAK       0x00000400	/* Clear global OUT NAK */
  #define USB_OTG_DCTL_POPRGDNE     0x00000800	/* Power-on programming done */
#define TOFF_USBD_DSTS      0x0008		/* (RO) dev Status Register (RO) */
  #define USB_OTG_DSTS_SUSPSTS      0x00000001	/* Suspend status */
  #define USB_OTG_DSTS_ENUMSPD      0x00000006	/* Enumerated speed */
  #define USB_OTG_DSTS_ENUMSPD_0    0x00000002	/* Bit 0 */
  #define USB_OTG_DSTS_ENUMSPD_1    0x00000004	/* Bit 1 */
  #define USB_OTG_DSTS_EERR         0x00000008	/* Erratic error */
  #define USB_OTG_DSTS_FNSOF        0x003FFF00	/* Frame number of the received SOF */
#define TOFF_USBD_DIEPMSK   0x0010		/* (RW) dev IN Endpoint Mask */
  #define USB_OTG_DIEPMSK_XFRCM     0x00000001	/* Transfer completed interrupt mask */
  #define USB_OTG_DIEPMSK_EPDM      0x00000002	/* Endpoint disabled interrupt mask */
  #define USB_OTG_DIEPMSK_TOM       0x00000008	/* Timeout condition mask (nonisochronous endpoints) */
  #define USB_OTG_DIEPMSK_ITTXFEMSK 0x00000010	/* IN token received when TxFIFO empty mask */
  #define USB_OTG_DIEPMSK_INEPNMM   0x00000020	/* IN token received with EP mismatch mask */
  #define USB_OTG_DIEPMSK_INEPNEM   0x00000040	/* IN endpoint NAK effective mask */
  #define USB_OTG_DIEPMSK_TXFURM    0x00000100	/* FIFO underrun mask */
  #define USB_OTG_DIEPMSK_BIM       0x00000200	/* BNA interrupt mask */
#define TOFF_USBD_DOEPMSK   0x0014		/* (RW) dev OUT Endpoint Mask */
  #define USB_OTG_DOEPMSK_XFRCM     0x00000001	/* Transfer completed interrupt mask */
  #define USB_OTG_DOEPMSK_EPDM      0x00000002	/* Endpoint disabled interrupt mask */
  #define USB_OTG_DOEPMSK_STUPM     0x00000008	/* SETUP phase done mask */
  #define USB_OTG_DOEPMSK_OTEPDM    0x00000010	/* OUT token received when endpoint disabled mask */
  #define USB_OTG_DOEPMSK_B2BSTUP   0x00000040	/* Back-to-back SETUP packets received mask */
  #define USB_OTG_DOEPMSK_OPEM      0x00000100	/* OUT packet error mask */
  #define USB_OTG_DOEPMSK_BOIM      0x00000200	/* BNA interrupt mask */
#define TOFF_USBD_DAINT     0x0018		/* (RW) dev All Endpoints Itr Register */
  #define USB_OTG_DAINT_IEPINT      0x0000FFFF	/* IN endpoint interrupt bits */
  #define USB_OTG_DAINT_OEPINT      0xFFFF0000	/* OUT endpoint interrupt bits */
#define TOFF_USBD_DAINTMSK  0x001C		/* (RW) dev All Endpoints Itr Mask */
  #define USB_OTG_DAINTMSK_IEPM     0x0000FFFF	/* IN EP interrupt mask bits */
  #define USB_OTG_DAINTMSK_OEPM     0xFFFF0000	/* OUT EP interrupt mask bits */
#define TOFF_USBD_DVBUSDIS  0x0028		/* (RW) dev VBUS discharge Register */
  #define USB_OTG_DVBUSDIS_VBUSDT   0x0000FFFF	/* Device VBUS discharge time */
#define TOFF_USBD_DVBUSPULSE 0x002C		/* (RW) dev VBUS Pulse Register */
  #define USB_OTG_DVBUSPULSE_DVBUSP 0x00000FFF	/* Device VBUS pulsing time */
#define TOFF_USBD_DTHRCTL   0x0030		/* (RW) dev thr */
  #define USB_OTG_DTHRCTL_NONISOTHREN 0x00000001	/* Nonisochronous IN endpoints threshold enable */
  #define USB_OTG_DTHRCTL_ISOTHREN    0x00000002	/* ISO IN endpoint threshold enable */
  #define USB_OTG_DTHRCTL_TXTHRLEN    0x000007FC	/* Transmit threshold length */
  #define USB_OTG_DTHRCTL_TXTHRLEN_0  0x00000004	/* Bit 0 */
  #define USB_OTG_DTHRCTL_TXTHRLEN_1  0x00000008	/* Bit 1 */
  #define USB_OTG_DTHRCTL_TXTHRLEN_2  0x00000010	/* Bit 2 */
  #define USB_OTG_DTHRCTL_TXTHRLEN_3  0x00000020	/* Bit 3 */
  #define USB_OTG_DTHRCTL_TXTHRLEN_4  0x00000040	/* Bit 4 */
  #define USB_OTG_DTHRCTL_TXTHRLEN_5  0x00000080	/* Bit 5 */
  #define USB_OTG_DTHRCTL_TXTHRLEN_6  0x00000100	/* Bit 6 */
  #define USB_OTG_DTHRCTL_TXTHRLEN_7  0x00000200	/* Bit 7 */
  #define USB_OTG_DTHRCTL_TXTHRLEN_8  0x00000400	/* Bit 8 */
  #define USB_OTG_DTHRCTL_RXTHREN     0x00010000	/* Receive threshold enable */
  #define USB_OTG_DTHRCTL_RXTHRLEN    0x03FE0000	/* Receive threshold length */
  #define USB_OTG_DTHRCTL_RXTHRLEN_0  0x00020000	/* Bit 0 */
  #define USB_OTG_DTHRCTL_RXTHRLEN_1  0x00040000	/* Bit 1 */
  #define USB_OTG_DTHRCTL_RXTHRLEN_2  0x00080000	/* Bit 2 */
  #define USB_OTG_DTHRCTL_RXTHRLEN_3  0x00100000	/* Bit 3 */
  #define USB_OTG_DTHRCTL_RXTHRLEN_4  0x00200000	/* Bit 4 */
  #define USB_OTG_DTHRCTL_RXTHRLEN_5  0x00400000	/* Bit 5 */
  #define USB_OTG_DTHRCTL_RXTHRLEN_6  0x00800000	/* Bit 6 */
  #define USB_OTG_DTHRCTL_RXTHRLEN_7  0x01000000	/* Bit 7 */
  #define USB_OTG_DTHRCTL_RXTHRLEN_8  0x02000000	/* Bit 8 */
  #define USB_OTG_DTHRCTL_ARPEN       0x08000000	/* Arbiter parking enable */
#define TOFF_USBD_DIEPEMPMSK 0x0034		/* (RW) dev empty msk */
  #define USB_OTG_DIEPEMPMSK_INEPTXFEM 0x0000FFFF	/* IN EP Tx FIFO empty interrupt mask bits */
#define TOFF_USBD_DEACHINT  0x0038		/* (RW) dedicated EP interrupt */
  #define USB_OTG_DEACHINT_IEP1INT  0x00000002	/* IN endpoint 1interrupt bit */
  #define USB_OTG_DEACHINT_OEP1INT  0x00020000	/* OUT endpoint 1 interrupt bit */
#define TOFF_USBD_DEACHMSK  0x003C		/* (RW) dedicated EP msk */
#define TOFF_USBD_DINEP1MSK 0x0044		/* (RW) dedicated EP mask */
#define TOFF_USBD_DOUTEP1MSK 0x0084		/* (RW) dedicated EP msk */

/*
 *  USB OTG IN ENDPOINT
 */
#define TADR_USBO_INEP_BASE     (USB_OTG_FS_PERIPH_BASE+USB_OTG_IN_ENDPOINT_BASE)
#define USBO_EP_REG_SIZE         0x20
#define TOFF_USBEI_DIEPCTL  0x0000		/* (RW) dev IN Endpoint Control Register */
  #define USB_OTG_DIEPCTL_MPSIZ     0x000007FF	/* Maximum packet size */
  #define USB_OTG_DIEPCTL_USBAEP    0x00008000	/* USB active endpoint */
  #define USB_OTG_DIEPCTL_EONUM_DPID 0x00010000	/* Even/odd frame */
  #define USB_OTG_DIEPCTL_NAKSTS    0x00020000	/* NAK status */
  #define USB_OTG_DIEPCTL_EPTYP     0x000C0000	/* Endpoint type */
  #define USB_OTG_DIEPCTL_EPTYP_0   0x00040000	/* Bit 0 */
  #define USB_OTG_DIEPCTL_EPTYP_1   0x00080000	/* Bit 1 */
  #define USB_OTG_DIEPCTL_STALL     0x00200000	/* STALL handshake */
  #define USB_OTG_DIEPCTL_TXFNUM    0x03C00000	/* TxFIFO number */
  #define USB_OTG_DIEPCTL_TXFNUM_0  0x00400000	/* Bit 0 */
  #define USB_OTG_DIEPCTL_TXFNUM_1  0x00800000	/* Bit 1 */
  #define USB_OTG_DIEPCTL_TXFNUM_2  0x01000000	/* Bit 2 */
  #define USB_OTG_DIEPCTL_TXFNUM_3  0x02000000	/* Bit 3 */
  #define USB_OTG_DIEPCTL_CNAK      0x04000000	/* Clear NAK */
  #define USB_OTG_DIEPCTL_SNAK      0x08000000	/* Set NAK */
  #define USB_OTG_DIEPCTL_SD0PID_SEVNFRM 0x10000000	/* Set DATA0 PID */
  #define USB_OTG_DIEPCTL_SODDFRM   0x20000000	/* Set odd frame */
  #define USB_OTG_DIEPCTL_EPDIS     0x40000000	/* Endpoint disable */
  #define USB_OTG_DIEPCTL_EPENA     0x80000000	/* Endpoint enable */
#define TOFF_USBEI_DIEPINT  0x0008		/* (RW) dev IN Endpoint Itr Register */
  #define USB_OTG_DIEPINT_XFRC      0x00000001	/* Transfer completed interrupt */
  #define USB_OTG_DIEPINT_EPDISD    0x00000002	/* Endpoint disabled interrupt */
  #define USB_OTG_DIEPINT_TOC       0x00000008	/* Timeout condition */
  #define USB_OTG_DIEPINT_ITTXFE    0x00000010	/* IN token received when TxFIFO is empty */
  #define USB_OTG_DIEPINT_INEPNE    0x00000040	/* IN endpoint NAK effective */
  #define USB_OTG_DIEPINT_TXFE      0x00000080	/* Transmit FIFO empty */
  #define USB_OTG_DIEPINT_TXFIFOUDRN 0x00000100	/* Transmit Fifo Underrun */
  #define USB_OTG_DIEPINT_BNA       0x00000200	/* Buffer not available interrupt */
  #define USB_OTG_DIEPINT_PKTDRPSTS 0x00000800	/* Packet dropped status */
  #define USB_OTG_DIEPINT_BERR      0x00001000	/* Babble error interrupt */
  #define USB_OTG_DIEPINT_NAK       0x00002000	/* NAK interrupt */
#define TOFF_USBEI_DIEPTSIZ 0x0010		/* (RW) IN Endpoint Txfer Size */
  #define USB_OTG_DIEPTSIZ_XFRSIZ   0x0007FFFF	/* Transfer size */
  #define USB_OTG_DIEPTSIZ_PKTCNT   0x1FF80000	/* Packet count */
  #define USB_OTG_DIEPTSIZ_MULCNT   0x60000000	/* Packet count */
#define TOFF_USBEI_DIEPDMA  0x0014		/* (RW) IN Endpoint DMA Address Register */
  #define USB_OTG_DIEPDMA_DMAADDR   0xFFFFFFFF	/* DMA address */
#define TOFF_USBEI_DTXFSTS  0x0018		/* (RW) IN Endpoint Tx FIFO Status Register */
  #define USB_OTG_DTXFSTS_INEPTFSAV 0x0000FFFF	/* IN endpoint TxFIFO space avail */

/*
 *  USB OTG OUTPUT ENDPOINT
 */
#define TADR_USBO_OUTEP_BASE    (USB_OTG_FS_PERIPH_BASE+USB_OTG_OUT_ENDPOINT_BASE)
#define TOFF_USBEO_DOEPCTL  0x0000		/* (RW) dev OUT Endpoint Control Register */
  #define USB_OTG_DOEPCTL_MPSIZ     0x000007FF	/* Maximum packet size */
  #define USB_OTG_DOEPCTL_USBAEP    0x00008000	/* USB active endpoint */
  #define USB_OTG_DOEPCTL_NAKSTS    0x00020000	/* NAK status */
  #define USB_OTG_DOEPCTL_SD0PID_SEVNFRM  0x10000000	/* Set DATA0 PID */
  #define USB_OTG_DOEPCTL_SODDFRM   0x20000000	/* Set odd frame */
  #define USB_OTG_DOEPCTL_EPTYP     0x000C0000	/* Endpoint type */
  #define USB_OTG_DOEPCTL_EPTYP_0   0x00040000	/* Bit 0 */
  #define USB_OTG_DOEPCTL_EPTYP_1   0x00080000	/* Bit 1 */
  #define USB_OTG_DOEPCTL_SNPM      0x00100000	/* Snoop mode */
  #define USB_OTG_DOEPCTL_STALL     0x00200000	/* STALL handshake */
  #define USB_OTG_DOEPCTL_CNAK      0x04000000	/* Clear NAK */
  #define USB_OTG_DOEPCTL_SNAK      0x08000000	/* Set NAK */
  #define USB_OTG_DOEPCTL_EPDIS     0x40000000	/* Endpoint disable */
  #define USB_OTG_DOEPCTL_EPENA     0x80000000	/* Endpoint enable */
#define TOFF_USBEO_DOEPINT  0x0008		/* (RW) dev OUT Endpoint Itr Register */
  #define USB_OTG_DOEPINT_XFRC      0x00000001	/* Transfer completed interrupt */
  #define USB_OTG_DOEPINT_EPDISD    0x00000002	/* Endpoint disabled interrupt */
  #define USB_OTG_DOEPINT_STUP      0x00000008	/* SETUP phase done */
  #define USB_OTG_DOEPINT_OTEPDIS   0x00000010	/* OUT token received when endpoint disabled */
  #define USB_OTG_DOEPINT_B2BSTUP   0x00000040	/* Back-to-back SETUP packets received */
  #define USB_OTG_DOEPINT_NYET      0x00004000	/* NYET interrupt */
#define TOFF_USBEO_DOEPTSIZ 0x0010		/* (RW) dev OUT Endpoint Txfer Size */
  #define USB_OTG_DOEPTSIZ_XFRSIZ   0x0007FFFF	/* Transfer size */
  #define USB_OTG_DOEPTSIZ_PKTCNT   0x1FF80000	/* Packet count */
  #define USB_OTG_DOEPTSIZ_STUPCNT  0x60000000	/* SETUP packet count */
  #define USB_OTG_DOEPTSIZ_STUPCNT_0 0x20000000	/* Bit 0 */
  #define USB_OTG_DOEPTSIZ_STUPCNT_1 0x40000000	/* Bit 1 */
#define TOFF_USBEO_DOEPDMA  0x0014		/* (RW) dev OUT Endpoint DMA Address */

/*
 *  USB OTG HOST
 */
#define TADR_USBO_HOST_BASE     (USB_OTG_FS_PERIPH_BASE+USB_OTG_HOST_BASE)
#define TOFF_USBH_HCFG      0x0000		/* (RW) Host Configuration Register */
  #define USB_OTG_HCFG_FSLSPCS      0x00000003	/* FS/LS PHY clock select */
  #define USB_OTG_HCFG_FSLSPCS_0    0x00000001	/* Bit 0 */
  #define USB_OTG_HCFG_FSLSPCS_1    0x00000002	/* Bit 1 */
  #define USB_OTG_HCFG_FSLSS        0x00000004	/* FS- and LS-only support */
#define TOFF_USBH_HFIR      0x0004		/* (RW) Host Frame Interval Register */
  #define USB_OTG_HFIR_FRIVL        0x0000FFFF	/* Frame interval */
#define TOFF_USBH_HFNUM     0x0008		/* (RW) Host Frame Nbr/Frame Remaining */
  #define USB_OTG_HFNUM_FRNUM       0x0000FFFF	/* Frame number */
  #define USB_OTG_HFNUM_FTREM       0xFFFF0000	/* Frame time remaining */
#define TOFF_USBH_HPTXSTS   0x0010		/* (RW) Host Periodic Tx FIFO/ Queue Status */
  #define USB_OTG_HPTXSTS_PTXFSAVL  0x0000FFFF	/* Periodic transmit data FIFO space available */
  #define USB_OTG_HPTXSTS_PTXQSAV   0x00FF0000	/* Periodic transmit request queue space available */
  #define USB_OTG_HPTXSTS_PTXQSAV_0 0x00010000	/* Bit 0 */
  #define USB_OTG_HPTXSTS_PTXQSAV_1 0x00020000	/* Bit 1 */
  #define USB_OTG_HPTXSTS_PTXQSAV_2 0x00040000	/* Bit 2 */
  #define USB_OTG_HPTXSTS_PTXQSAV_3 0x00080000	/* Bit 3 */
  #define USB_OTG_HPTXSTS_PTXQSAV_4 0x00100000	/* Bit 4 */
  #define USB_OTG_HPTXSTS_PTXQSAV_5 0x00200000	/* Bit 5 */
  #define USB_OTG_HPTXSTS_PTXQSAV_6 0x00400000	/* Bit 6 */
  #define USB_OTG_HPTXSTS_PTXQSAV_7 0x00800000	/* Bit 7 */
  #define USB_OTG_HPTXSTS_PTXQTOP   0xFF000000	/* Top of the periodic transmit request queue */
  #define USB_OTG_HPTXSTS_PTXQTOP_0 0x01000000	/* Bit 0 */
  #define USB_OTG_HPTXSTS_PTXQTOP_1 0x02000000	/* Bit 1 */
  #define USB_OTG_HPTXSTS_PTXQTOP_2 0x04000000	/* Bit 2 */
  #define USB_OTG_HPTXSTS_PTXQTOP_3 0x08000000	/* Bit 3 */
  #define USB_OTG_HPTXSTS_PTXQTOP_4 0x10000000	/* Bit 4 */
  #define USB_OTG_HPTXSTS_PTXQTOP_5 0x20000000	/* Bit 5 */
  #define USB_OTG_HPTXSTS_PTXQTOP_6 0x40000000	/* Bit 6 */
  #define USB_OTG_HPTXSTS_PTXQTOP_7 0x80000000	/* Bit 7 */
#define TOFF_USBH_HAINT     0x0014		/* (RW) Host All Channels Interrupt Register */
  #define USB_OTG_HAINT_HAINT       0x0000FFFF	/* Channel interrupts */
#define TOFF_USBH_HAINTMSK  0x0018		/* (RW) Host All Channels Interrupt Mask */
  #define USB_OTG_HAINTMSK_HAINTM   0x0000FFFF	/* Channel interrupt mask */

/*
 *  USB HOST CHANNEL SPECIFIC
 */
#define TADR_USBH_HC_BASE        (USB_OTG_FS_PERIPH_BASE+USB_OTG_HOST_CHANNEL_BASE)
#define USBO_HOST_CHANNEL_REG_SIZE    0x20
#define TOFF_USBHC_HCCHAR   0x0000
  #define USB_OTG_HCCHAR_MPSIZ      0x000007FF	/* Maximum packet size */
  #define USB_OTG_HCCHAR_EPNUM      0x00007800	/* Endpoint number */
  #define USB_OTG_HCCHAR_EPNUM_0    0x00000800	/* Bit 0 */
  #define USB_OTG_HCCHAR_EPNUM_1    0x00001000	/* Bit 1 */
  #define USB_OTG_HCCHAR_EPNUM_2    0x00002000	/* Bit 2 */
  #define USB_OTG_HCCHAR_EPNUM_3    0x00004000	/* Bit 3 */
  #define USB_OTG_HCCHAR_EPDIR      0x00008000	/* Endpoint direction */
  #define USB_OTG_HCCHAR_LSDEV      0x00020000	/* Low-speed device */
  #define USB_OTG_HCCHAR_EPTYP      0x000C0000	/* Endpoint type */
  #define USB_OTG_HCCHAR_EPTYP_0    0x00040000	/* Bit 0 */
  #define USB_OTG_HCCHAR_EPTYP_1    0x00080000	/* Bit 1 */
  #define USB_OTG_HCCHAR_MC         0x00300000	/* Multi Count (MC) / Error Count (EC) */
  #define USB_OTG_HCCHAR_MC_0       0x00100000	/* Bit 0 */
  #define USB_OTG_HCCHAR_MC_1       0x00200000	/* Bit 1 */
  #define USB_OTG_HCCHAR_DAD        0x1FC00000	/* Device address */
  #define USB_OTG_HCCHAR_DAD_0      0x00400000	/* Bit 0 */
  #define USB_OTG_HCCHAR_DAD_1      0x00800000	/* Bit 1 */
  #define USB_OTG_HCCHAR_DAD_2      0x01000000	/* Bit 2 */
  #define USB_OTG_HCCHAR_DAD_3      0x02000000	/* Bit 3 */
  #define USB_OTG_HCCHAR_DAD_4      0x04000000	/* Bit 4 */
  #define USB_OTG_HCCHAR_DAD_5      0x08000000	/* Bit 5 */
  #define USB_OTG_HCCHAR_DAD_6      0x10000000	/* Bit 6 */
  #define USB_OTG_HCCHAR_ODDFRM     0x20000000	/* Odd frame */
  #define USB_OTG_HCCHAR_CHDIS      0x40000000	/* Channel disable */
  #define USB_OTG_HCCHAR_CHENA      0x80000000	/* Channel enable */
#define TOFF_USBHC_HCSPLT   0x0004
  #define USB_OTG_HCSPLT_PRTADDR    0x0000007F	/* Port address */
  #define USB_OTG_HCSPLT_PRTADDR_0  0x00000001	/* Bit 0 */
  #define USB_OTG_HCSPLT_PRTADDR_1  0x00000002	/* Bit 1 */
  #define USB_OTG_HCSPLT_PRTADDR_2  0x00000004	/* Bit 2 */
  #define USB_OTG_HCSPLT_PRTADDR_3  0x00000008	/* Bit 3 */
  #define USB_OTG_HCSPLT_PRTADDR_4  0x00000010	/* Bit 4 */
  #define USB_OTG_HCSPLT_PRTADDR_5  0x00000020	/* Bit 5 */
  #define USB_OTG_HCSPLT_PRTADDR_6  0x00000040	/* Bit 6 */
  #define USB_OTG_HCSPLT_HUBADDR    0x00003F80	/* Hub address */
  #define USB_OTG_HCSPLT_HUBADDR_0  0x00000080	/* Bit 0 */
  #define USB_OTG_HCSPLT_HUBADDR_1  0x00000100	/* Bit 1 */
  #define USB_OTG_HCSPLT_HUBADDR_2  0x00000200	/* Bit 2 */
  #define USB_OTG_HCSPLT_HUBADDR_3  0x00000400	/* Bit 3 */
  #define USB_OTG_HCSPLT_HUBADDR_4  0x00000800	/* Bit 4 */
  #define USB_OTG_HCSPLT_HUBADDR_5  0x00001000	/* Bit 5 */
  #define USB_OTG_HCSPLT_HUBADDR_6  0x00002000	/* Bit 6 */
  #define USB_OTG_HCSPLT_XACTPOS    0x0000C000	/* XACTPOS */
  #define USB_OTG_HCSPLT_XACTPOS_0  0x00004000	/* Bit 0 */
  #define USB_OTG_HCSPLT_XACTPOS_1  0x00008000	/* Bit 1 */
  #define USB_OTG_HCSPLT_COMPLSPLT  0x00010000	/* Do complete split */
  #define USB_OTG_HCSPLT_SPLITEN    0x80000000	/* Split enable */
#define TOFF_USBHC_HCINT    0x0008
  #define USB_OTG_HCINT_XFRC        0x00000001	/* Transfer completed */
  #define USB_OTG_HCINT_CHH         0x00000002	/* Channel halted */
  #define USB_OTG_HCINT_AHBERR      0x00000004	/* AHB error */
  #define USB_OTG_HCINT_STALL       0x00000008	/* STALL response received interrupt */
  #define USB_OTG_HCINT_NAK         0x00000010	/* NAK response received interrupt */
  #define USB_OTG_HCINT_ACK         0x00000020	/* ACK response received/transmitted interrupt */
  #define USB_OTG_HCINT_NYET        0x00000040	/* Response received interrupt */
  #define USB_OTG_HCINT_TXERR       0x00000080	/* Transaction error */
  #define USB_OTG_HCINT_BBERR       0x00000100	/* Babble error */
  #define USB_OTG_HCINT_FRMOR       0x00000200	/* Frame overrun */
  #define USB_OTG_HCINT_DTERR       0x00000400	/* Data toggle error */
#define TOFF_USBHC_HCINTMSK 0x000C
  #define USB_OTG_HCINTMSK_XFRCM    0x00000001	/* Transfer completed mask */
  #define USB_OTG_HCINTMSK_CHHM     0x00000002	/* Channel halted mask */
  #define USB_OTG_HCINTMSK_AHBERR   0x00000004	/* AHB error */
  #define USB_OTG_HCINTMSK_STALLM   0x00000008	/* STALL response received interrupt mask */
  #define USB_OTG_HCINTMSK_NAKM     0x00000010	/* NAK response received interrupt mask */
  #define USB_OTG_HCINTMSK_ACKM     0x00000020	/* ACK response received/transmitted interrupt mask */
  #define USB_OTG_HCINTMSK_NYET     0x00000040	/* response received interrupt mask */
  #define USB_OTG_HCINTMSK_TXERRM   0x00000080	/* Transaction error mask */
  #define USB_OTG_HCINTMSK_BBERRM   0x00000100	/* Babble error mask */
  #define USB_OTG_HCINTMSK_FRMORM   0x00000200	/* Frame overrun mask */
  #define USB_OTG_HCINTMSK_DTERRM   0x00000400	/* Data toggle error mask */
#define TOFF_USBHC_HCTSIZ   0x0010
  #define USB_OTG_HCTSIZ_XFRSIZ     0x0007FFFF	/* Transfer size */
  #define USB_OTG_HCTSIZ_PKTCNT     0x1FF80000	/* Packet count */
  #define USB_OTG_HCTSIZ_DOPING     0x80000000	/* Do PING */
  #define USB_OTG_HCTSIZ_DPID       0x60000000	/* Data PID */
  #define USB_OTG_HCTSIZ_DPID_0     0x20000000	/* Bit 0 */
  #define USB_OTG_HCTSIZ_DPID_1     0x40000000	/* Bit 1 */
#define TOFF_USBHC_HCDMA    0x0014
  #define USB_OTG_HCDMA_DMAADDR     0xFFFFFFFF	/* DMA address */

/*
 *  USB OTG HPRT
 */
#define TADR_USBO_HPRT0_BASE         (USB_OTG_FS_PERIPH_BASE+USB_OTG_HOST_PORT_BASE)
  #define USB_OTG_HPRT_PCSTS        0x00000001	/* Port connect status */
  #define USB_OTG_HPRT_PCDET        0x00000002	/* Port connect detected */
  #define USB_OTG_HPRT_PENA         0x00000004	/* Port enable */
  #define USB_OTG_HPRT_PENCHNG      0x00000008	/* Port enable/disable change */
  #define USB_OTG_HPRT_POCA         0x00000010	/* Port overcurrent active */
  #define USB_OTG_HPRT_POCCHNG      0x00000020	/* Port overcurrent change */
  #define USB_OTG_HPRT_PRES         0x00000040	/* Port resume */
  #define USB_OTG_HPRT_PSUSP        0x00000080	/* Port suspend */
  #define USB_OTG_HPRT_PRST         0x00000100	/* Port reset */
  #define USB_OTG_HPRT_PLSTS        0x00000C00	/* Port line status */
  #define USB_OTG_HPRT_PLSTS_0      0x00000400	/* Bit 0 */
  #define USB_OTG_HPRT_PLSTS_1      0x00000800	/* Bit 1 */
  #define USB_OTG_HPRT_PPWR         0x00001000	/* Port power */
  #define USB_OTG_HPRT_PTCTL        0x0001E000	/* Port test control */
  #define USB_OTG_HPRT_PTCTL_0      0x00002000	/* Bit 0 */
  #define USB_OTG_HPRT_PTCTL_1      0x00004000	/* Bit 1 */
  #define USB_OTG_HPRT_PTCTL_2      0x00008000	/* Bit 2 */
  #define USB_OTG_HPRT_PTCTL_3      0x00010000	/* Bit 3 */
  #define USB_OTG_HPRT_PSPD         0x00060000	/* Port speed */
  #define USB_OTG_HPRT_PSPD_0       0x00020000	/* Bit 0 */
  #define USB_OTG_HPRT_PSPD_1       0x00040000	/* Bit 1 */

/*
 *  PCGCCTL BIT DEFINITIONS
 */
#define USB_OTG_PCGCCTL_STOPCLK     0x00000001	/* SETUP packet count */
#define USB_OTG_PCGCCTL_GATECLK     0x00000002	/* Bit 0 */
#define USB_OTG_PCGCCTL_PHYSUSP     0x00000010	/* Bit 1 */

#endif  /* _STM32F4XX_H_ */

