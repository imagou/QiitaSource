/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2015-2016 by 3rd Designing Center
 *              Imageing System Development Division RICOH COMPANY, LTD.
 *  Copyright (C) 2017-2017 by TOPPERS PROJECT Educational Working Group.
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
 *  @(#) $Id: stm32l4xx.h,v 1.2 2018/11/05 20:31:08 roi Exp $
 */

#ifndef _STM32L4XX_H_
#define _STM32L4XX_H_

#include <sil.h>
#include "cmsis_l4.h"

/*
 *  割込み番号の最大値
 */
#if !defined(TOPPERS_STM32L476_DISCOVERY) && !defined(TOPPERS_STM32L476_NUCLEO64)
#define TMAX_INTNO          (16 + 95)
#else
#define TMAX_INTNO          (16 + 82)
#endif

/*
 *  割込み優先度のビット幅
 */
#define TBITW_IPRI          4

/*
 *  INTERRUPT NUMBER
 */
#define IRQ_VECTOR_WWDG             (16 + 0)	/* Window WatchDog Interrupt */
#define IRQ_PVD_PVM                 (16 + 1)	/* PVD/PVM1/PVM2/PVM3/PVM4 through EXTI Line detection Interrupts */
#define IRQ_TAMP_STAMP              (16 + 2)	/* Tamper and TimeStamp interrupts through the EXTI line */
#define IRQ_VECTOR_RTC_WKUP         (16 + 3)	/* RTC Wakeup interrupt through the EXTI line */
#define IRQ_VECTOR_FLASH            (16 + 4)	/* FLASH global Interrupt */
#define IRQ_VECTOR_RCC              (16 + 5)	/* RCC global Interrupt */
#define IRQ_VECTOR_EXTI0            (16 + 6)	/* EXTI Line0 Interrupt */
#define IRQ_VECTOR_EXTI1            (16 + 7)	/* EXTI Line1 Interrupt */
#define IRQ_VECTOR_EXTI2            (16 + 8)	/* EXTI Line2 Interrupt */
#define IRQ_VECTOR_EXTI3            (16 + 9)	/* EXTI Line3 Interrupt */
#define IRQ_VECTOR_EXTI4            (16 + 10)	/* EXTI Line4 Interrupt */
#define IRQ_VECTOR_DMA1_CH1         (16 + 11)	/* DMA1 Channel 1 global Interrupt */
#define IRQ_VECTOR_DMA1_CH2         (16 + 12)	/* DMA1 Channel 2 global Interrupt */
#define IRQ_VECTOR_DMA1_CH3         (16 + 13)	/* DMA1 Channel 3 global Interrupt */
#define IRQ_VECTOR_DMA1_CH4         (16 + 14)	/* DMA1 Channel 4 global Interrupt */
#define IRQ_VECTOR_DMA1_CH5         (16 + 15)	/* DMA1 Channel 5 global Interrupt */
#define IRQ_VECTOR_DMA1_CH6         (16 + 16)	/* DMA1 Channel 6 global Interrupt */
#define IRQ_VECTOR_DMA1_CH7         (16 + 17)	/* DMA1 Channel 7 global Interrupt */
#define IRQ_VECTOR_ADC1_2           (16 + 18)	/* ADC1, ADC2 SAR global Interrupts */
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
#define IRQ_VECTOR_DFSDM1_FLT3      (16 + 42)	/* DFSDM1 Filter 3 global Interrupt */
#define IRQ_VECTOR_TIM8_BRK         (16 + 43)	/* TIM8 Break Interrupt */
#define IRQ_VECTOR_TIM8_UP          (16 + 44)	/* TIM8 Update Interrupt */
#define IRQ_VECTOR_TIM8_TRG_COM     (16 + 45)	/* TIM8 Trigger and Commutation Interrupt */
#define IRQ_VECTOR_TIM8_CC          (16 + 46)	/* TIM8 Capture Compare Interrupt */
#define IRQ_VECTOR_ADC3             (16 + 47)	/* ADC3 global Interrupt */
#define IRQ_VECTOR_FMC              (16 + 48)	/* FMC global Interrupt */
#define IRQ_VECTOR_SDMMC1           (16 + 49)	/* SDMMC1 global Interrupt */
#define IRQ_VECTOR_TIM5             (16 + 50)	/* TIM5 global Interrupt */
#define IRQ_VECTOR_SPI3             (16 + 51)	/* SPI3 global Interrupt */
#define IRQ_VECTOR_UART4            (16 + 52)	/* UART4 global Interrupt */
#define IRQ_VECTOR_UART5            (16 + 53)	/* UART5 global Interrupt */
#define IRQ_VECTOR_TIM6_DAC         (16 + 54)	/* TIM6 global and DAC1&2 underrun error interrupts */
#define IRQ_VECTOR_TIM7             (16 + 55)	/* TIM7 global interrupt */
#define IRQ_VECTOR_DMA2_CH1         (16 + 56)	/* DMA2 Channel 1 global Interrupt */
#define IRQ_VECTOR_DMA2_CH2         (16 + 57)	/* DMA2 Channel 2 global Interrupt */
#define IRQ_VECTOR_DMA2_CH3         (16 + 58)	/* DMA2 Channel 3 global Interrupt */
#define IRQ_VECTOR_DMA2_CH4         (16 + 59)	/* DMA2 Channel 4 global Interrupt */
#define IRQ_VECTOR_DMA2_CH5         (16 + 60)	/* DMA2 Channel 5 global Interrupt */
#define IRQ_VECTOR_DFSDM1_FLT0      (16 + 61)	/* DFSDM1 Filter 0 global Interrupt */
#define IRQ_VECTOR_DFSDM1_FLT1      (16 + 62)	/* DFSDM1 Filter 1 global Interrupt */
#define IRQ_VECTOR_DFSDM1_FLT2      (16 + 63)	/* DFSDM1 Filter 2 global Interrupt */
#define IRQ_VECTOR_COMP             (16 + 64)	/* COMP1 and COMP2 Interrupts */
#define IRQ_VECTOR_LPTIM1           (16 + 65)	/* LP TIM1 interrupt */
#define IRQ_VECTOR_LPTIM2           (16 + 66)	/* LP TIM2 interrupt */
#define IRQ_VECTOR_OTG_FS           (16 + 67)	/* USB OTG FS global Interrupt */
#define IRQ_VECTOR_DMA2_CH6         (16 + 68)	/* DMA2 Channel 6 global interrupt */
#define IRQ_VECTOR_DMA2_CH7         (16 + 69)	/* DMA2 Channel 7 global interrupt */
#define IRQ_VECTOR_LPUART1          (16 + 70)	/* LP UART1 interrupt */
#define IRQ_VECTOR_QUADSPI          (16 + 71)	/* Quad SPI global interrupt */
#define IRQ_VECTOR_I2C3_EV          (16 + 72)	/* I2C3 event interrupt */
#define IRQ_VECTOR_I2C3_ER          (16 + 73)	/* I2C3 error interrupt */
#define IRQ_VECTOR_SAI1             (16 + 74)	/* Serial Audio Interface 1 global interrupt */
#define IRQ_VECTOR_SAI2             (16 + 75)	/* Serial Audio Interface 2 global interrupt */
#define IRQ_VECTOR_SWPMI1           (16 + 76)	/* Serial Wire Interface 1 global interrupt */
#define IRQ_VECTOR_TSC              (16 + 77)	/* Touch Sense Controller global interrupt */
#define IRQ_VECTOR_LCD              (16 + 78)	/* LCD global Interrupt */
#define IRQ_VECTOR_RNG              (16 + 80)	/* RNG global interrupt */
#define IRQ_VECTOR_FPU              (16 + 81)	/* FPU global interrupt */
#if !defined(TOPPERS_STM32L476_DISCOVERY) && !defined(TOPPERS_STM32L476_NUCLEO64)
#define IRQ_VECTOR_CRS              (16 + 82)	/* CRS global interrupt */
#define IRQ_VECTOR_I2C4_EV          (16 + 83)	/* I2C4 Event interrupt */
#define IRQ_VECTOR_I2C4_ER          (16 + 84)	/* I2C4 Error interrupt */
#define IRQ_VECTOR_DCMI             (16 + 85)	/* DCMI global interrupt */
#define IRQ_VECTOR_DMA2D            (16 + 90)	/* DMA2D global interrupt */
#define IRQ_VECTOR_DMAMUX1_OVR      (16 + 94)	/* DMAMUX1 overrun global interrupt */
#endif

/*
 *  PERIPHERAL MEMORY MAP
 */
#define FLASH_BASE          0x08000000	/* FLASH base address in the alias region */
#define SRAM_BASE           0x20000000	/* SRAM base address in the alias region */
#define PERIPH_BASE         0x40000000	/* Peripheral base address in the alias region */
#define FMC_BASE            0x60000000	/* FMC base address */
#if !defined(TOPPERS_STM32L476_DISCOVERY) && !defined(TOPPERS_STM32L476_NUCLEO64)
#define OCTOSPI1_BASE       0x90000000	/* OCTOSPI1 memories accessible over AHB base address */
#define OCTOSPI2_BASE       0x70000000	/* OCTOSPI2 memories accessible over AHB base address */
#else
#define QSPI_BASE           0x90000000	/* QUADSPI memories accessible over AHB base address */
#endif

#define FMC_R_BASE          0xA0000000	/* FMC  control registers base address */
#if !defined(TOPPERS_STM32L476_DISCOVERY) && !defined(TOPPERS_STM32L476_NUCLEO64)
#define OCTOSPI1_R_BASE     0xA0001000	/* OCTOSPI1 control registers base address */
#define OCTOSPI2_R_BASE     0xA0001400	/* OCTOSPI2 control registers base address */
#else
#define QSPI_R_BASE         0xA0001000	/* QUADSPI control registers base address */
#endif
#define PERIPH_BB_BASE      0x42000000	/* Peripheral base address in the bit-band region */

/* Peripheral memory map */
#define APB1PERIPH_BASE     PERIPH_BASE
#define APB2PERIPH_BASE     (PERIPH_BASE + 0x00010000)
#define AHB1PERIPH_BASE     (PERIPH_BASE + 0x00020000)
#define AHB2PERIPH_BASE     (PERIPH_BASE + 0x08000000)

/* USB registers base address */
#define USB_OTG_FS_PERIPH_BASE      0x50000000

#define USB_OTG_DEVICE_BASE         0x800
#define USB_OTG_IN_ENDPOINT_BASE    0x900
#define USB_OTG_OUT_ENDPOINT_BASE   0xB00
#define USB_OTG_HOST_BASE           0x400
#define USB_OTG_HOST_PORT_BASE      0x440
#define USB_OTG_HOST_CHANNEL_BASE   0x500
#define USB_OTG_PCGCCTL_BASE        0xE00
#define USB_OTG_FIFO_BASE           0x1000
#define USB_OTG_FIFO_SIZE           0x1000

/* Debug MCU registers base address */
#define DBGMCU_BASE         0xE0042000

/*
 *  TIMER
 */
#define TADR_TIM2_BASE      (APB1PERIPH_BASE + 0x0000)
#define TADR_TIM3_BASE      (APB1PERIPH_BASE + 0x0400)
#define TADR_TIM4_BASE      (APB1PERIPH_BASE + 0x0800)
#define TADR_TIM5_BASE      (APB1PERIPH_BASE + 0x0C00)
#define TADR_TIM6_BASE      (APB1PERIPH_BASE + 0x1000)
#define TADR_TIM7_BASE      (APB1PERIPH_BASE + 0x1400)
#define TADR_TIM1_BASE      (APB2PERIPH_BASE + 0x2C00)
#define TADR_TIM8_BASE      (APB2PERIPH_BASE + 0x3400)
#define TADR_TIM15_BASE     (APB2PERIPH_BASE + 0x4000)
#define TADR_TIM16_BASE     (APB2PERIPH_BASE + 0x4400)
#define TADR_TIM17_BASE     (APB2PERIPH_BASE + 0x4800)

#define TOFF_TIM_CR1        0x0000		/* (RW) TIM control register 1 */
  #define TIM_CR1_CEN        0x00000001	/* Counter enable */
  #define TIM_CR1_UDIS       0x00000002	/* Update disable */
  #define TIM_CR1_URS        0x00000004	/* Update request source */
  #define TIM_CR1_OPM        0x00000008	/* One pulse mode */
  #define TIM_CR1_DIR        0x00000010	/* Direction */
  #define TIM_CR1_CMS_0      0x00000020	/* CMS[1:0] bit 0 */
  #define TIM_CR1_CMS_1      0x00000040	/* CMS[1:0] bit 1 */
  #define TIM_CR1_ARPE       0x00000080	/* Auto-reload preload enable */
  #define TIM_CR1_CKD_0      0x00000100	/* CKD[1:0] bit 0 */
  #define TIM_CR1_CKD_1      0x00000200	/* CKD[1:0] bit 1 */
  #define TIM_CR1_UIFREMAP   0x00000800	/* Update interrupt flag remap */
#define TOFF_TIM_CR2        0x0004		/* (RW) TIM control register 2 */
  #define TIM_CR2_CCPC       0x00000001	/* Capture/Compare Preloaded Control */
  #define TIM_CR2_CCUS       0x00000004	/* Capture/Compare Control Update Selection */
  #define TIM_CR2_CCDS       0x00000008	/* Capture/Compare DMA Selection */
  #define TIM_CR2_MMS        0x00000070	/* MMS[2:0] bits (Master Mode Selection) */
  #define TIM_CR2_MMS_0      0x00000010
  #define TIM_CR2_MMS_1      0x00000020
  #define TIM_CR2_MMS_2      0x00000040
  #define TIM_CR2_TI1S       0x00000080	/* TI1 Selection */
  #define TIM_CR2_OIS1       0x00000100	/* Output Idle state 1 (OC1 output) */
  #define TIM_CR2_OIS1N      0x00000200	/* Output Idle state 1 (OC1N output) */
  #define TIM_CR2_OIS2       0x00000400	/* Output Idle state 2 (OC2 output) */
  #define TIM_CR2_OIS2N      0x00000800	/* Output Idle state 2 (OC2N output) */
  #define TIM_CR2_OIS3       0x00001000	/* Output Idle state 3 (OC3 output) */
  #define TIM_CR2_OIS3N      0x00002000	/* Output Idle state 3 (OC3N output) */
  #define TIM_CR2_OIS4       0x00004000	/* Output Idle state 4 (OC4 output) */
  #define TIM_CR2_OIS5       0x00010000	/* Output Idle state 5 (OC5 output) */
  #define TIM_CR2_OIS6       0x00040000	/* Output Idle state 6 (OC6 output) */
  #define TIM_CR2_MMS2       0x00F00000	/* MMS[2:0] bits (Master Mode Selection) */
  #define TIM_CR2_MMS2_0     0x00100000
  #define TIM_CR2_MMS2_1     0x00200000
  #define TIM_CR2_MMS2_2     0x00400000
  #define TIM_CR2_MMS2_3     0x00800000
#define TOFF_TIM_SMCR       0x0008		/* (RW) TIM slave mode control register */
  #define TIM_SMCR_SMS       0x00010007	/* SMS[2:0] bits (Slave mode selection) */
  #define TIM_SMCR_SMS_0     0x00000001
  #define TIM_SMCR_SMS_1     0x00000002
  #define TIM_SMCR_SMS_2     0x00000004
  #define TIM_SMCR_SMS_3     0x00010000
  #define TIM_SMCR_OCCS      0x00000008	/* OCREF clear selection */
  #define TIM_SMCR_TS        0x00000070	/* TS[2:0] bits (Trigger selection) */
  #define TIM_SMCR_TS_0      0x00000010
  #define TIM_SMCR_TS_1      0x00000020
  #define TIM_SMCR_TS_2      0x00000040
  #define TIM_SMCR_MSM       0x00000080	/* Master/slave mode */
  #define TIM_SMCR_ETF       0x00000F00	/* ETF[3:0] bits (External trigger filter) */
  #define TIM_SMCR_ETF_0     0x00000100
  #define TIM_SMCR_ETF_1     0x00000200
  #define TIM_SMCR_ETF_2     0x00000400
  #define TIM_SMCR_ETF_3     0x00000800
  #define TIM_SMCR_ETPS      0x00003000	/* ETPS[1:0] bits (External trigger prescaler) */
  #define TIM_SMCR_ETPS_0    0x00001000
  #define TIM_SMCR_ETPS_1    0x00002000
  #define TIM_SMCR_ECE       0x00004000	/* External clock enable */
  #define TIM_SMCR_ETP       0x00008000	/* External trigger polarity */
#define TOFF_TIM_DIER       0x000C		/* (RW) TIM DMA/interrupt enable register */
  #define TIM_DIER_UIE       0x00000001	/* Update interrupt enable */
  #define TIM_DIER_CC1IE     0x00000002	/* Capture/Compare 1 interrupt enable */
  #define TIM_DIER_CC2IE     0x00000004	/* Capture/Compare 2 interrupt enable */
  #define TIM_DIER_CC3IE     0x00000008	/* Capture/Compare 3 interrupt enable */
  #define TIM_DIER_CC4IE     0x00000010	/* Capture/Compare 4 interrupt enable */
  #define TIM_DIER_COMIE     0x00000020	/* COM interrupt enable */
  #define TIM_DIER_TIE       0x00000040	/* Trigger interrupt enable */
  #define TIM_DIER_BIE       0x00000080	/* Break interrupt enable */
  #define TIM_DIER_UDE       0x00000100	/* Update DMA request enable */
  #define TIM_DIER_CC1DE     0x00000200	/* Capture/Compare 1 DMA request enable */
  #define TIM_DIER_CC2DE     0x00000400	/* Capture/Compare 2 DMA request enable */
  #define TIM_DIER_CC3DE     0x00000800	/* Capture/Compare 3 DMA request enable */
  #define TIM_DIER_CC4DE     0x00001000	/* Capture/Compare 4 DMA request enable */
  #define TIM_DIER_COMDE     0x00002000	/* COM DMA request enable */
  #define TIM_DIER_TDE       0x00004000	/* Trigger DMA request enable */
#define TOFF_TIM_SR         0x0010		/* (RW) TIM status register */
  #define TIM_SR_UIF         0x00000001	/* Update interrupt Flag */
  #define TIM_SR_CC1IF       0x00000002	/* Capture/Compare 1 interrupt Flag */
  #define TIM_SR_CC2IF       0x00000004	/* Capture/Compare 2 interrupt Flag */
  #define TIM_SR_CC3IF       0x00000008	/* Capture/Compare 3 interrupt Flag */
  #define TIM_SR_CC4IF       0x00000010	/* Capture/Compare 4 interrupt Flag */
  #define TIM_SR_COMIF       0x00000020	/* COM interrupt Flag */
  #define TIM_SR_TIF         0x00000040	/* Trigger interrupt Flag */
  #define TIM_SR_BIF         0x00000080	/* Break interrupt Flag */
  #define TIM_SR_CC1OF       0x00000200	/* Capture/Compare 1 Overcapture Flag */
  #define TIM_SR_CC2OF       0x00000400	/* Capture/Compare 2 Overcapture Flag */
  #define TIM_SR_CC3OF       0x00000800	/* Capture/Compare 3 Overcapture Flag */
  #define TIM_SR_CC4OF       0x00001000	/* Capture/Compare 4 Overcapture Flag */
  #define TIM_SR_SBIF        0x00002000	/* System Break interrupt Flag */
  #define TIM_SR_CC5IF       0x00010000	/* Capture/Compare 5 interrupt Flag */
  #define TIM_SR_CC6IF       0x00020000	/* Capture/Compare 6 interrupt Flag */
#define TOFF_TIM_EGR        0x0014		/* (RW) TIM event generation register */
  #define TIM_EGR_UG         0x00000001	/* Update Generation */
  #define TIM_EGR_CC1G       0x00000002	/* Capture/Compare 1 Generation */
  #define TIM_EGR_CC2G       0x00000004	/* Capture/Compare 2 Generation */
  #define TIM_EGR_CC3G       0x00000008	/* Capture/Compare 3 Generation */
  #define TIM_EGR_CC4G       0x00000010	/* Capture/Compare 4 Generation */
  #define TIM_EGR_COMG       0x00000020	/* Capture/Compare Control Update Generation */
  #define TIM_EGR_TG         0x00000040	/* Trigger Generation */
  #define TIM_EGR_BG         0x00000080	/* Break Generation */
  #define TIM_EGR_B2G        0x00000100	/* Break 2 Generation */
#define TOFF_TIM_CCMR1      0x0018		/* (RW) TIM capture/compare mode register 1 */
  #define TIM_CCMR1_CC1S     0x00000003	/* CC1S[1:0] bits (Capture/Compare 1 Selection) */
  #define TIM_CCMR1_CC1S_0   0x00000001
  #define TIM_CCMR1_CC1S_1   0x00000002
  #define TIM_CCMR1_OC1FE    0x00000004	/* Output Compare 1 Fast enable */
  #define TIM_CCMR1_OC1PE    0x00000008	/* Output Compare 1 Preload enable */
  #define TIM_CCMR1_OC1M     0x00010070	/* OC1M[2:0] bits (Output Compare 1 Mode) */
  #define TIM_CCMR1_OC1M_0   0x00000010
  #define TIM_CCMR1_OC1M_1   0x00000020
  #define TIM_CCMR1_OC1M_2   0x00000040
  #define TIM_CCMR1_OC1M_3   0x00010000
  #define TIM_CCMR1_OC1CE    0x00000080	/* Output Compare 1 Clear Enable */
  #define TIM_CCMR1_CC2S     0x00000300	/* CC2S[1:0] bits (Capture/Compare 2 Selection) */
  #define TIM_CCMR1_CC2S_0   0x00000100
  #define TIM_CCMR1_CC2S_1   0x00000200
  #define TIM_CCMR1_OC2FE    0x00000400	/* Output Compare 2 Fast enable */
  #define TIM_CCMR1_OC2PE    0x00000800	/* Output Compare 2 Preload enable */
  #define TIM_CCMR1_OC2M     0x01007000	/* OC2M[2:0] bits (Output Compare 2 Mode) */
  #define TIM_CCMR1_OC2M_0   0x00001000
  #define TIM_CCMR1_OC2M_1   0x00002000
  #define TIM_CCMR1_OC2M_2   0x00004000
  #define TIM_CCMR1_OC2M_3   0x01000000
  #define TIM_CCMR1_OC2CE    0x00008000	/* Output Compare 2 Clear Enable */

  #define TIM_CCMR1_IC1PSC   0x0000000C	/* IC1PSC[1:0] bits (Input Capture 1 Prescaler) */
  #define TIM_CCMR1_IC1PSC_0 0x00000004
  #define TIM_CCMR1_IC1PSC_1 0x00000008
  #define TIM_CCMR1_IC1F     0x000000F0	/* IC1F[3:0] bits (Input Capture 1 Filter) */
  #define TIM_CCMR1_IC1F_0   0x00000010
  #define TIM_CCMR1_IC1F_1   0x00000020
  #define TIM_CCMR1_IC1F_2   0x00000040
  #define TIM_CCMR1_IC1F_3   0x00000080
  #define TIM_CCMR1_IC2PSC   0x00000C00	/* IC2PSC[1:0] bits (Input Capture 2 Prescaler) */
  #define TIM_CCMR1_IC2PSC_0 0x00000400
  #define TIM_CCMR1_IC2PSC_1 0x00000800
  #define TIM_CCMR1_IC2F     0x0000F000	/* IC2F[3:0] bits (Input Capture 2 Filter) */
  #define TIM_CCMR1_IC2F_0   0x00001000
  #define TIM_CCMR1_IC2F_1   0x00002000
  #define TIM_CCMR1_IC2F_2   0x00004000
  #define TIM_CCMR1_IC2F_3   0x00008000
#define TOFF_TIM_CCMR2      0x001C		/* (RW) TIM capture/compare mode register 2 */
  #define TIM_CCMR2_CC3S     0x00000003	/* CC3S[1:0] bits (Capture/Compare 3 Selection) */
  #define TIM_CCMR2_CC3S_0   0x00000001
  #define TIM_CCMR2_CC3S_1   0x00000002
  #define TIM_CCMR2_OC3FE    0x00000004	/* Output Compare 3 Fast enable */
  #define TIM_CCMR2_OC3PE    0x00000008	/* Output Compare 3 Preload enable */
  #define TIM_CCMR2_OC3M     0x00010070	/* OC3M[2:0] bits (Output Compare 3 Mode) */
  #define TIM_CCMR2_OC3M_0   0x00000010
  #define TIM_CCMR2_OC3M_1   0x00000020
  #define TIM_CCMR2_OC3M_2   0x00000040
  #define TIM_CCMR2_OC3M_3   0x00010000
  #define TIM_CCMR2_OC3CE    0x00000080	/* Output Compare 3 Clear Enable */
  #define TIM_CCMR2_CC4S     0x00000300	/* CC4S[1:0] bits (Capture/Compare 4 Selection) */
  #define TIM_CCMR2_CC4S_0   0x00000100
  #define TIM_CCMR2_CC4S_1   0x00000200
  #define TIM_CCMR2_OC4FE    0x00000400	/* Output Compare 4 Fast enable */
  #define TIM_CCMR2_OC4PE    0x00000800	/* Output Compare 4 Preload enable */
  #define TIM_CCMR2_OC4M     0x01007000	/* OC4M[2:0] bits (Output Compare 4 Mode) */
  #define TIM_CCMR2_OC4M_0   0x00001000
  #define TIM_CCMR2_OC4M_1   0x00002000
  #define TIM_CCMR2_OC4M_2   0x00004000
  #define TIM_CCMR2_OC4M_3   0x01000000
  #define TIM_CCMR2_OC4CE    0x00008000	/* Output Compare 4 Clear Enable */

  #define TIM_CCMR2_IC3PSC   0x0000000C	/* IC3PSC[1:0] bits (Input Capture 3 Prescaler) */
  #define TIM_CCMR2_IC3PSC_0 0x00000004
  #define TIM_CCMR2_IC3PSC_1 0x00000008
  #define TIM_CCMR2_IC3F     0x000000F0	/* IC3F[3:0] bits (Input Capture 3 Filter) */
  #define TIM_CCMR2_IC3F_0   0x00000010
  #define TIM_CCMR2_IC3F_1   0x00000020
  #define TIM_CCMR2_IC3F_2   0x00000040
  #define TIM_CCMR2_IC3F_3   0x00000080
  #define TIM_CCMR2_IC4PSC   0x00000C00	/* IC4PSC[1:0] bits (Input Capture 4 Prescaler) */
  #define TIM_CCMR2_IC4PSC_0 0x00000400
  #define TIM_CCMR2_IC4PSC_1 0x00000800
  #define TIM_CCMR2_IC4F     0x0000F000	/* IC4F[3:0] bits (Input Capture 4 Filter) */
  #define TIM_CCMR2_IC4F_0   0x00001000
  #define TIM_CCMR2_IC4F_1   0x00002000
  #define TIM_CCMR2_IC4F_2   0x00004000
  #define TIM_CCMR2_IC4F_3   0x00008000
#define TOFF_TIM_CCER       0x0020		/* (RW) TIM capture/compare enable register */
  #define TIM_CCER_CC1E      0x00000001	/* Capture/Compare 1 output enable */
  #define TIM_CCER_CC1P      0x00000002	/* Capture/Compare 1 output Polarity */
  #define TIM_CCER_CC1NE     0x00000004	/* Capture/Compare 1 Complementary output enable */
  #define TIM_CCER_CC1NP     0x00000008	/* Capture/Compare 1 Complementary output Polarity */
  #define TIM_CCER_CC2E      0x00000010	/* Capture/Compare 2 output enable */
  #define TIM_CCER_CC2P      0x00000020	/* Capture/Compare 2 output Polarity */
  #define TIM_CCER_CC2NE     0x00000040	/* Capture/Compare 2 Complementary output enable */
  #define TIM_CCER_CC2NP     0x00000080	/* Capture/Compare 2 Complementary output Polarity */
  #define TIM_CCER_CC3E      0x00000100	/* Capture/Compare 3 output enable */
  #define TIM_CCER_CC3P      0x00000200	/* Capture/Compare 3 output Polarity */
  #define TIM_CCER_CC3NE     0x00000400	/* Capture/Compare 3 Complementary output enable */
  #define TIM_CCER_CC3NP     0x00000800	/* Capture/Compare 3 Complementary output Polarity */
  #define TIM_CCER_CC4E      0x00001000	/* Capture/Compare 4 output enable */
  #define TIM_CCER_CC4P      0x00002000	/* Capture/Compare 4 output Polarity */
  #define TIM_CCER_CC4NP     0x00008000	/* Capture/Compare 4 Complementary output Polarity */
  #define TIM_CCER_CC5E      0x00010000	/* Capture/Compare 5 output enable */
  #define TIM_CCER_CC5P      0x00020000	/* Capture/Compare 5 output Polarity */
  #define TIM_CCER_CC6E      0x00100000	/* Capture/Compare 6 output enable */
  #define TIM_CCER_CC6P      0x00200000	/* Capture/Compare 6 output Polarity */
#define TOFF_TIM_CNT        0x0024		/* (RW) TIM counter register */
  #define TIM_CNT_CNT        0xFFFFFFFF	/* Counter Value */
  #define TIM_CNT_UIFCPY     0x80000000	/* Update interrupt flag copy (if UIFREMAP=1) */
#define TOFF_TIM_PSC        0x0028		/* (RW) TIM prescaler */
  #define TIM_PSC_PSC        0x0000FFFF	/* Prescaler Value */
#define TOFF_TIM_ARR        0x002C		/* (RW) TIM auto-reload register */
#define TOFF_TIM_RCR        0x0030		/* (RW) TIM repetition counter register */
  #define TIM_RCR_REP        0x0000FFFF	/* Repetition Counter Value */
#define TOFF_TIM_CCR1       0x0034		/* (RW) TIM capture/compare register 1 */
  #define TIM_CCR1_CCR1      0x0000FFFF	/* Capture/Compare 1 Value */
#define TOFF_TIM_CCR2       0x0038		/* (RW) TIM capture/compare register 2 */
  #define TIM_CCR2_CCR2      0x0000FFFF	/* Capture/Compare 2 Value */
#define TOFF_TIM_CCR3       0x003C		/* (RW) TIM capture/compare register 3 */
  #define TIM_CCR3_CCR3      0x0000FFFF	/* Capture/Compare 3 Value */
#define TOFF_TIM_CCR4       0x0040		/* (RW) TIM capture/compare register 4 */
  #define TIM_CCR4_CCR4      0x0000FFFF	/* Capture/Compare 4 Value */
#define TOFF_TIM_BDTR       0x0044		/* (RW) TIM break and dead-time register */
  #define TIM_BDTR_DTG       0x000000FF	/* DTG[0:7] bits (Dead-Time Generator set-up) */
  #define TIM_BDTR_DTG_0     0x00000001
  #define TIM_BDTR_DTG_1     0x00000002
  #define TIM_BDTR_DTG_2     0x00000004
  #define TIM_BDTR_DTG_3     0x00000008
  #define TIM_BDTR_DTG_4     0x00000010
  #define TIM_BDTR_DTG_5     0x00000020
  #define TIM_BDTR_DTG_6     0x00000040
  #define TIM_BDTR_DTG_7     0x00000080
  #define TIM_BDTR_LOCK      0x00000300	/* LOCK[1:0] bits (Lock Configuration) */
  #define TIM_BDTR_LOCK_0    0x00000100
  #define TIM_BDTR_LOCK_1    0x00000200
  #define TIM_BDTR_OSSI      0x00000400	/* Off-State Selection for Idle mode */
  #define TIM_BDTR_OSSR      0x00000800	/* Off-State Selection for Run mode */
  #define TIM_BDTR_BKE       0x00001000	/* Break enable for Break 1 */
  #define TIM_BDTR_BKP       0x00002000	/* Break Polarity for Break 1 */
  #define TIM_BDTR_AOE       0x00004000	/* Automatic Output enable */
  #define TIM_BDTR_MOE       0x00008000	/* Main Output enable */
  #define TIM_BDTR_BKF       0x000F0000	/* Break Filter for Break 1 */
  #define TIM_BDTR_BK2F      0x00F00000	/* Break Filter for Break 2 */
  #define TIM_BDTR_BK2E      0x01000000	/* Break enable for Break 2 */
  #define TIM_BDTR_BK2P      0x02000000	/* Break Polarity for Break 2 */
#define TOFF_TIM_DCR        0x0048		/* (RW) TIM DMA control register */
  #define TIM_DCR_DBA        0x0000001F	/* DBA[4:0] bits (DMA Base Address) */
  #define TIM_DCR_DBA_0      0x00000001
  #define TIM_DCR_DBA_1      0x00000002
  #define TIM_DCR_DBA_2      0x00000004
  #define TIM_DCR_DBA_3      0x00000008
  #define TIM_DCR_DBA_4      0x00000010
  #define TIM_DCR_DBL        0x00001F00	/* DBL[4:0] bits (DMA Burst Length) */
  #define TIM_DCR_DBL_0      0x00000100
  #define TIM_DCR_DBL_1      0x00000200
  #define TIM_DCR_DBL_2      0x00000400
  #define TIM_DCR_DBL_3      0x00000800
  #define TIM_DCR_DBL_4      0x00001000
#define TOFF_TIM_DMAR       0x004C		/* (RW) TIM DMA address for full transfer */
  #define TIM_DMAR_DMAB      0x0000FFFF	/* DMA register for burst accesses */
#define TOFF_TIM_OR1        0x0050		/* (RW) TIM option register 1 */
#define TOFF_TIM_CCMR3      0x0054		/* (RW) TIM capture/compare mode register 3 */
  #define TIM_CCMR3_OC5FE    0x00000004	/* Output Compare 5 Fast enable */
  #define TIM_CCMR3_OC5PE    0x00000008	/* Output Compare 5 Preload enable */
  #define TIM_CCMR3_OC5M     0x00010070	/* OC5M[3:0] bits (Output Compare 5 Mode) */
  #define TIM_CCMR3_OC5M_0   0x00000010
  #define TIM_CCMR3_OC5M_1   0x00000020
  #define TIM_CCMR3_OC5M_2   0x00000040
  #define TIM_CCMR3_OC5M_3   0x00010000
  #define TIM_CCMR3_OC5CE    0x00000080	/* Output Compare 5 Clear Enable */
  #define TIM_CCMR3_OC6FE    0x00000400	/* Output Compare 6 Fast enable */
  #define TIM_CCMR3_OC6PE    0x00000800	/* Output Compare 6 Preload enable */
  #define TIM_CCMR3_OC6M     0x01007000	/* OC6M[3:0] bits (Output Compare 6 Mode) */
  #define TIM_CCMR3_OC6M_0   0x00001000
  #define TIM_CCMR3_OC6M_1   0x00002000
  #define TIM_CCMR3_OC6M_2   0x00004000
  #define TIM_CCMR3_OC6M_3   0x01000000
  #define TIM_CCMR3_OC6CE    0x00008000	/* Output Compare 6 Clear Enable */
#define TOFF_TIM_CCR5       0x0058		/* (RW) TIM capture/compare register5 */
  #define TIM_CCR5_CCR5      0xFFFFFFFF	/* Capture/Compare 5 Value */
  #define TIM_CCR5_GC5C1     0x20000000	/* Group Channel 5 and Channel 1 */
  #define TIM_CCR5_GC5C2     0x40000000	/* Group Channel 5 and Channel 2 */
  #define TIM_CCR5_GC5C3     0x80000000	/* Group Channel 5 and Channel 3 */
#define TOFF_TIM_CCR6		0x005C		/* (RW) TIM capture/compare register6 */
  #define TIM_CCR6_CCR6      0x0000FFFF	/* Capture/Compare 6 Value */
#define TOFF_TIM_OR2        0x0060		/* (RW) TIM option register 2 */
#define TOFF_TIM_OR3        0x0064		/* (RW) TIM option register 3 */

/*
 *  LCD
 */
#define TADR_LCD_BASE       (APB1PERIPH_BASE + 0x2400)
#define TOFF_LCD_CR         0x0000		/* (RW) LCD control register */
  #define LCD_CR_LCDEN       0x00000001	/* LCD Enable Bit */
  #define LCD_CR_VSEL        0x00000002	/* Voltage source selector Bit */
  #define LCD_CR_DUTY        0x0000001C	/* DUTY[2:0] bits (Duty selector) */
  #define LCD_CR_DUTY_0      0x00000004
  #define LCD_CR_DUTY_1      0x00000008
  #define LCD_CR_DUTY_2      0x00000010
  #define LCD_CR_BIAS        0x00000060	/* BIAS[1:0] bits (Bias selector) */
  #define LCD_CR_BIAS_0      0x00000020
  #define LCD_CR_BIAS_1      0x00000040
  #define LCD_CR_MUX_SEG     0x00000080	/* Mux Segment Enable Bit */
  #define LCD_CR_BUFEN       0x00000100	/* Voltage output buffer enable Bit */
#define TOFF_LCD_FCR        0x0004		/* (RW) LCD frame control register */
  #define LCD_FCR_HD         0x00000001	/* High Drive Enable Bit */
  #define LCD_FCR_SOFIE      0x00000002	/* Start of Frame Interrupt Enable Bit */
  #define LCD_FCR_UDDIE      0x00000008	/* Update Display Done Interrupt Enable Bit */
  #define LCD_FCR_PON        0x00000070	/* PON[2:0] bits (Puls ON Duration) */
  #define LCD_FCR_PON_0      0x00000010
  #define LCD_FCR_PON_1      0x00000020
  #define LCD_FCR_PON_2      0x00000040
  #define LCD_FCR_DEAD       0x00000380	/* DEAD[2:0] bits (DEAD Time) */
  #define LCD_FCR_DEAD_0     0x00000080
  #define LCD_FCR_DEAD_1     0x00000100
  #define LCD_FCR_DEAD_2     0x00000200
  #define LCD_FCR_CC         0x00001C00	/* CC[2:0] bits (Contrast Control) */
  #define LCD_FCR_CC_0       0x00000400
  #define LCD_FCR_CC_1       0x00000800
  #define LCD_FCR_CC_2       0x00001000
  #define LCD_FCR_BLINKF     0x0000E000	/* BLINKF[2:0] bits (Blink Frequency) */
  #define LCD_FCR_BLINKF_0   0x00002000
  #define LCD_FCR_BLINKF_1   0x00004000
  #define LCD_FCR_BLINKF_2   0x00008000
  #define LCD_FCR_BLINK      0x00030000	/* BLINK[1:0] bits (Blink Enable) */
  #define LCD_FCR_BLINK_0    0x00010000
  #define LCD_FCR_BLINK_1    0x00020000
  #define LCD_FCR_DIV        0x003C0000	/* DIV[3:0] bits (Divider) */
  #define LCD_FCR_PS         0x03C00000	/* PS[3:0] bits (Prescaler) */
#define TOFF_LCD_SR         0x0008		/* (RW) LCD status register */
  #define LCD_SR_ENS         0x00000001	/* LCD Enabled Bit */
  #define LCD_SR_SOF         0x00000002	/* Start Of Frame Flag Bit */
  #define LCD_SR_UDR         0x00000004	/* Update Display Request Bit */
  #define LCD_SR_UDD         0x00000008	/* Update Display Done Flag Bit */
  #define LCD_SR_RDY         0x00000010	/* Ready Flag Bit */
  #define LCD_SR_FCRSR       0x00000020	/* LCD FCR Register Synchronization Flag Bit */
#define TOFF_LCD_CLR        0x000C		/* (RW) LCD clear register */
  #define LCD_CLR_SOFC       0x00000002	/* Start Of Frame Flag Clear Bit */
  #define LCD_CLR_UDDC       0x00000008	/* Update Display Done Flag Clear Bit */
#define TOFF_LCD_RAM        0x0014		/* (RW) LCD display memory  0x14-0x50 */

/*
 *  REAL-TIME CLOCK
 */
#define TADR_RTC_BASE       (APB1PERIPH_BASE + 0x2800)
#define TOFF_RTC_TR         0x0000		/* (RW) RTC time register */
  #define RTC_TR_SU                0x0000000F
  #define RTC_TR_SU_0              0x00000001
  #define RTC_TR_SU_1              0x00000002
  #define RTC_TR_SU_2              0x00000004
  #define RTC_TR_SU_3              0x00000008
  #define RTC_TR_ST                0x00000070
  #define RTC_TR_ST_0              0x00000010
  #define RTC_TR_ST_1              0x00000020
  #define RTC_TR_ST_2              0x00000040
  #define RTC_TR_MNU               0x00000F00
  #define RTC_TR_MNU_0             0x00000100
  #define RTC_TR_MNU_1             0x00000200
  #define RTC_TR_MNU_2             0x00000400
  #define RTC_TR_MNU_3             0x00000800
  #define RTC_TR_MNT               0x00007000
  #define RTC_TR_MNT_0             0x00001000
  #define RTC_TR_MNT_1             0x00002000
  #define RTC_TR_MNT_2             0x00004000
  #define RTC_TR_HU                0x000F0000
  #define RTC_TR_HU_0              0x00010000
  #define RTC_TR_HU_1              0x00020000
  #define RTC_TR_HU_2              0x00040000
  #define RTC_TR_HU_3              0x00080000
  #define RTC_TR_HT                0x00300000
  #define RTC_TR_HT_0              0x00100000
  #define RTC_TR_HT_1              0x00200000
  #define RTC_TR_PM                0x00400000
#define TOFF_RTC_DR         0x0004		/* (RW) RTC date register */
  #define RTC_DR_DU                0x0000000F
  #define RTC_DR_DU_0              0x00000001
  #define RTC_DR_DU_1              0x00000002
  #define RTC_DR_DU_2              0x00000004
  #define RTC_DR_DU_3              0x00000008
  #define RTC_DR_DT                0x00000030
  #define RTC_DR_DT_0              0x00000010
  #define RTC_DR_DT_1              0x00000020
  #define RTC_DR_MU                0x00000F00
  #define RTC_DR_MU_0              0x00000100
  #define RTC_DR_MU_1              0x00000200
  #define RTC_DR_MU_2              0x00000400
  #define RTC_DR_MU_3              0x00000800
  #define RTC_DR_WDU               0x0000E000
  #define RTC_DR_WDU_0             0x00002000
  #define RTC_DR_WDU_1             0x00004000
  #define RTC_DR_WDU_2             0x00008000
  #define RTC_DR_MT                0x00001000
  #define RTC_DR_YU                0x000F0000
  #define RTC_DR_YU_0              0x00010000
  #define RTC_DR_YU_1              0x00020000
  #define RTC_DR_YU_2              0x00040000
  #define RTC_DR_YU_3              0x00080000
  #define RTC_DR_YT                0x00F00000
  #define RTC_DR_YT_0              0x00100000
  #define RTC_DR_YT_1              0x00200000
  #define RTC_DR_YT_2              0x00400000
  #define RTC_DR_YT_3              0x00800000
#define TOFF_RTC_CR         0x0008		/* (RW) RTC control register */
  #define RTC_CR_WUCKSEL           0x00000007
  #define RTC_CR_WUCKSEL_0         0x00000001
  #define RTC_CR_WUCKSEL_1         0x00000002
  #define RTC_CR_WUCKSEL_2         0x00000004
  #define RTC_CR_TSEDGE            0x00000008
  #define RTC_CR_REFCKON           0x00000010
  #define RTC_CR_BYPSHAD           0x00000020
  #define RTC_CR_FMT               0x00000040
  #define RTC_CR_DCE               0x00000080
  #define RTC_CR_ALRAE             0x00000100
  #define RTC_CR_ALRBE             0x00000200
  #define RTC_CR_WUTE              0x00000400
  #define RTC_CR_TSE               0x00000800
  #define RTC_CR_ALRAIE            0x00001000
  #define RTC_CR_ALRBIE            0x00002000
  #define RTC_CR_WUTIE             0x00004000
  #define RTC_CR_TSIE              0x00008000
  #define RTC_CR_ADD1H             0x00010000
  #define RTC_CR_SUB1H             0x00020000
  #define RTC_CR_BCK               0x00040000
  #define RTC_CR_COSEL             0x00080000
  #define RTC_CR_POL               0x00100000
  #define RTC_CR_OSEL              0x00600000
  #define RTC_CR_OSEL_0            0x00200000
  #define RTC_CR_OSEL_1            0x00400000
  #define RTC_CR_COE               0x00800000
  #define RTC_CR_ITSE              0x01000000
#define TOFF_RTC_ISR        0x000C		/* (RW) RTC initialization and status register */
  #define RTC_ISR_ALRAWF           0x00000001
  #define RTC_ISR_ALRBWF           0x00000002
  #define RTC_ISR_WUTWF            0x00000004
  #define RTC_ISR_SHPF             0x00000008
  #define RTC_ISR_INITS            0x00000010
  #define RTC_ISR_RSF              0x00000020
  #define RTC_ISR_INITF            0x00000040
  #define RTC_ISR_INIT             0x00000080
  #define RTC_ISR_ALRAF            0x00000100
  #define RTC_ISR_ALRBF            0x00000200
  #define RTC_ISR_WUTF             0x00000400
  #define RTC_ISR_TSF              0x00000800
  #define RTC_ISR_TSOVF            0x00001000
  #define RTC_ISR_TAMP2F           0x00004000
  #define RTC_ISR_TAMP1F           0x00002000
  #define RTC_ISR_RECALPF          0x00010000
  #define RTC_ISR_ITSF             0x00020000
#define TOFF_RTC_PRER       0x0010		/* (RW) RTC prescaler register */
#define TOFF_RTC_WUTR       0x0014		/* (RW) RTC wakeup timer register */
#define TOFF_RTC_CALIBR     0x0018		/* (RW) RTC calibration register */
#define TOFF_RTC_ALRMAR     0x001C		/* (RW) RTC alarm A register */
  #define RTC_ALRMAR_SU            0x0000000F
  #define RTC_ALRMAR_SU_0          0x00000001
  #define RTC_ALRMAR_SU_1          0x00000002
  #define RTC_ALRMAR_SU_2          0x00000004
  #define RTC_ALRMAR_SU_3          0x00000008
  #define RTC_ALRMAR_ST            0x00000070
  #define RTC_ALRMAR_ST_0          0x00000010
  #define RTC_ALRMAR_ST_1          0x00000020
  #define RTC_ALRMAR_ST_2          0x00000040
  #define RTC_ALRMAR_MSK1          0x00000080
  #define RTC_ALRMAR_MNU           0x00000F00
  #define RTC_ALRMAR_MNU_0         0x00000100
  #define RTC_ALRMAR_MNU_1         0x00000200
  #define RTC_ALRMAR_MNU_2         0x00000400
  #define RTC_ALRMAR_MNU_3         0x00000800
  #define RTC_ALRMAR_MNT           0x00007000
  #define RTC_ALRMAR_MNT_0         0x00001000
  #define RTC_ALRMAR_MNT_1         0x00002000
  #define RTC_ALRMAR_MNT_2         0x00004000
  #define RTC_ALRMAR_MSK2          0x00008000
  #define RTC_ALRMAR_HU            0x000F0000
  #define RTC_ALRMAR_HU_0          0x00010000
  #define RTC_ALRMAR_HU_1          0x00020000
  #define RTC_ALRMAR_HU_2          0x00040000
  #define RTC_ALRMAR_HU_3          0x00080000
  #define RTC_ALRMAR_HT            0x00300000
  #define RTC_ALRMAR_HT_0          0x00100000
  #define RTC_ALRMAR_HT_1          0x00200000
  #define RTC_ALRMAR_PM            0x00400000
  #define RTC_ALRMAR_MSK3          0x00800000
  #define RTC_ALRMAR_DU            0x0F000000
  #define RTC_ALRMAR_DU_0          0x01000000
  #define RTC_ALRMAR_DU_1          0x02000000
  #define RTC_ALRMAR_DU_2          0x04000000
  #define RTC_ALRMAR_DU_3          0x08000000
  #define RTC_ALRMAR_DT            0x30000000
  #define RTC_ALRMAR_DT_0          0x10000000
  #define RTC_ALRMAR_DT_1          0x20000000
  #define RTC_ALRMAR_WDSEL         0x40000000
  #define RTC_ALRMAR_MSK4          0x80000000
#define TOFF_RTC_ALRMBR     0x0020		/* (RW) RTC alarm B register */
  #define RTC_ALRMBR_SU            0x0000000F
  #define RTC_ALRMBR_SU_0          0x00000001
  #define RTC_ALRMBR_SU_1          0x00000002
  #define RTC_ALRMBR_SU_2          0x00000004
  #define RTC_ALRMBR_SU_3          0x00000008
  #define RTC_ALRMBR_ST            0x00000070
  #define RTC_ALRMBR_ST_0          0x00000010
  #define RTC_ALRMBR_ST_1          0x00000020
  #define RTC_ALRMBR_ST_2          0x00000040
  #define RTC_ALRMBR_MSK1          0x00000080
  #define RTC_ALRMBR_MNU           0x00000F00
  #define RTC_ALRMBR_MNU_0         0x00000100
  #define RTC_ALRMBR_MNU_1         0x00000200
  #define RTC_ALRMBR_MNU_2         0x00000400
  #define RTC_ALRMBR_MNU_3         0x00000800
  #define RTC_ALRMBR_MNT           0x00007000
  #define RTC_ALRMBR_MNT_0         0x00001000
  #define RTC_ALRMBR_MNT_1         0x00002000
  #define RTC_ALRMBR_MNT_2         0x00004000
  #define RTC_ALRMBR_MSK2          0x00008000
  #define RTC_ALRMBR_HU            0x000F0000
  #define RTC_ALRMBR_HU_0          0x00010000
  #define RTC_ALRMBR_HU_1          0x00020000
  #define RTC_ALRMBR_HU_2          0x00040000
  #define RTC_ALRMBR_HU_3          0x00080000
  #define RTC_ALRMBR_HT            0x00300000
  #define RTC_ALRMBR_HT_0          0x00100000
  #define RTC_ALRMBR_HT_1          0x00200000
  #define RTC_ALRMBR_PM            0x00400000
  #define RTC_ALRMBR_MSK3          0x00800000
  #define RTC_ALRMBR_DU            0x0F000000
  #define RTC_ALRMBR_DU_0          0x01000000
  #define RTC_ALRMBR_DU_1          0x02000000
  #define RTC_ALRMBR_DU_2          0x04000000
  #define RTC_ALRMBR_DU_3          0x08000000
  #define RTC_ALRMBR_DT            0x30000000
  #define RTC_ALRMBR_DT_0          0x10000000
  #define RTC_ALRMBR_DT_1          0x20000000
  #define RTC_ALRMBR_WDSEL         0x40000000
  #define RTC_ALRMBR_MSK4          0x80000000
#define TOFF_RTC_WPR        0x0024		/* (RW) RTC write protection register */
  #define RTC_WPR_KEY              0x000000FF
#define TOFF_RTC_SSR        0x0028		/* (RW) RTC sub second register */
#define TOFF_RTC_SHIFTR     0x002C		/* (RW) RTC shift control register */
#define TOFF_RTC_TSTR       0x0030		/* (RW) RTC time stamp time register */
  #define RTC_TSTR_SU              0x0000000F
  #define RTC_TSTR_SU_0            0x00000001
  #define RTC_TSTR_SU_1            0x00000002
  #define RTC_TSTR_SU_2            0x00000004
  #define RTC_TSTR_SU_3            0x00000008
  #define RTC_TSTR_ST              0x00000070
  #define RTC_TSTR_ST_0            0x00000010
  #define RTC_TSTR_ST_1            0x00000020
  #define RTC_TSTR_ST_2            0x00000040
  #define RTC_TSTR_MNU             0x00000F00
  #define RTC_TSTR_MNU_0           0x00000100
  #define RTC_TSTR_MNU_1           0x00000200
  #define RTC_TSTR_MNU_2           0x00000400
  #define RTC_TSTR_MNU_3           0x00000800
  #define RTC_TSTR_MNT             0x00007000
  #define RTC_TSTR_MNT_0           0x00001000
  #define RTC_TSTR_MNT_1           0x00002000
  #define RTC_TSTR_MNT_2           0x00004000
  #define RTC_TSTR_HU              0x000F0000
  #define RTC_TSTR_HU_0            0x00010000
  #define RTC_TSTR_HU_1            0x00020000
  #define RTC_TSTR_HU_2            0x00040000
  #define RTC_TSTR_HU_3            0x00080000
  #define RTC_TSTR_HT              0x00300000
  #define RTC_TSTR_HT_0            0x00100000
  #define RTC_TSTR_HT_1            0x00200000
  #define RTC_TSTR_PM              0x00400000
#define TOFF_RTC_TSDR       0x0034		/* (RW) RTC time stamp date register */
  #define RTC_TSDR_DU              0x0000000F
  #define RTC_TSDR_DU_0            0x00000001
  #define RTC_TSDR_DU_1            0x00000002
  #define RTC_TSDR_DU_2            0x00000004
  #define RTC_TSDR_DU_3            0x00000008
  #define RTC_TSDR_DT              0x00000030
  #define RTC_TSDR_DT_0            0x00000010
  #define RTC_TSDR_DT_1            0x00000020
  #define RTC_TSDR_MU              0x00000F00
  #define RTC_TSDR_MU_0            0x00000100
  #define RTC_TSDR_MU_1            0x00000200
  #define RTC_TSDR_MU_2            0x00000400
  #define RTC_TSDR_MU_3            0x00000800
  #define RTC_TSDR_MT              0x00001000
  #define RTC_TSDR_WDU             0x0000E000
  #define RTC_TSDR_WDU_0           0x00002000
  #define RTC_TSDR_WDU_1           0x00004000
  #define RTC_TSDR_WDU_2           0x00008000
#define TOFF_RTC_TSSSR      0x0038		/* (RW) RTC time-stamp sub second register */
#define TOFF_RTC_CALR       0x003C		/* (RW) RTC calibration register */
  #define RTC_CALR_CALM            0x000001FF
  #define RTC_CALR_CALM_0          0x00000001
  #define RTC_CALR_CALM_1          0x00000002
  #define RTC_CALR_CALM_2          0x00000004
  #define RTC_CALR_CALM_3          0x00000008
  #define RTC_CALR_CALM_4          0x00000010
  #define RTC_CALR_CALM_5          0x00000020
  #define RTC_CALR_CALM_6          0x00000040
  #define RTC_CALR_CALM_7          0x00000080
  #define RTC_CALR_CALM_8          0x00000100
  #define RTC_CALR_CALW16          0x00002000
  #define RTC_CALR_CALW8           0x00004000
  #define RTC_CALR_CALP            0x00008000
#define TOFF_RTC_TAMPCR     0x0040		/* (RW) RTC tamper configuration register */
  #define RTC_TAMPCR_TAMP1E        0x00000001
  #define RTC_TAMPCR_TAMP1TRG      0x00000002
  #define RTC_TAMPCR_TAMPIE        0x00000004
  #define RTC_TAMPCR_TAMP2E        0x00000008
  #define RTC_TAMPCR_TAMP2TRG      0x00000010
  #define RTC_TAMPCR_TAMP3E        0x00000020
  #define RTC_TAMPCR_TAMP3TRG      0x00000040
  #define RTC_TAMPCR_TAMPTS        0x00000080
  #define RTC_TAMPCR_TAMPFREQ      0x00000700
  #define RTC_TAMPCR_TAMPFREQ_0    0x00000100
  #define RTC_TAMPCR_TAMPFREQ_1    0x00000200
  #define RTC_TAMPCR_TAMPFREQ_2    0x00000400
  #define RTC_TAMPCR_TAMPFLT       0x00001800
  #define RTC_TAMPCR_TAMPFLT_0     0x00000800
  #define RTC_TAMPCR_TAMPFLT_1     0x00001000
  #define RTC_TAMPCR_TAMPPRCH      0x00006000
  #define RTC_TAMPCR_TAMPPRCH_0    0x00002000
  #define RTC_TAMPCR_TAMPPRCH_1    0x00004000
  #define RTC_TAMPCR_TAMPPUDIS     0x00008000
  #define RTC_TAMPCR_TAMP1IE       0x00010000
  #define RTC_TAMPCR_TAMP1NOERASE  0x00020000
  #define RTC_TAMPCR_TAMP1MF       0x00040000
  #define RTC_TAMPCR_TAMP2IE       0x00080000
  #define RTC_TAMPCR_TAMP2NOERASE  0x00100000
  #define RTC_TAMPCR_TAMP2MF       0x00200000
  #define RTC_TAMPCR_TAMP3IE       0x00400000
  #define RTC_TAMPCR_TAMP3NOERASE  0x00800000
  #define RTC_TAMPCR_TAMP3MF       0x01000000
#define TOFF_RTC_ALRMASSR   0x0044		/* (RW) RTC alarm A sub second register */
  #define RTC_ALRMASSR_SS          0x00007FFF
  #define RTC_ALRMASSR_MASKSS      0x0F000000
  #define RTC_ALRMASSR_MASKSS_0    0x01000000
  #define RTC_ALRMASSR_MASKSS_1    0x02000000
  #define RTC_ALRMASSR_MASKSS_2    0x04000000
  #define RTC_ALRMASSR_MASKSS_3    0x08000000
#define TOFF_RTC_ALRMBSSR   0x0048		/* (RW) RTC alarm B sub second register */
  #define RTC_ALRMBSSR_SS          0x00007FFF
  #define RTC_ALRMBSSR_MASKSS      0x0F000000
  #define RTC_ALRMBSSR_MASKSS_0    0x01000000
  #define RTC_ALRMBSSR_MASKSS_1    0x02000000
  #define RTC_ALRMBSSR_MASKSS_2    0x04000000
  #define RTC_ALRMBSSR_MASKSS_3    0x08000000
#define TOFF_RTC_OR         0x004C		/* (RW) RTC option register */
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
#define TOFF_RTC_BKP20R     0x00A0		/* (RW) RTC backup register 20 */
#define TOFF_RTC_BKP21R     0x00A4		/* (RW) RTC backup register 21 */
#define TOFF_RTC_BKP22R     0x00A8		/* (RW) RTC backup register 22 */
#define TOFF_RTC_BKP23R     0x00AC		/* (RW) RTC backup register 23 */
#define TOFF_RTC_BKP24R     0x00B0		/* (RW) RTC backup register 24 */
#define TOFF_RTC_BKP25R     0x00B4		/* (RW) RTC backup register 25 */
#define TOFF_RTC_BKP26R     0x00B8		/* (RW) RTC backup register 26 */
#define TOFF_RTC_BKP27R     0x00BC		/* (RW) RTC backup register 27 */
#define TOFF_RTC_BKP28R     0x00C0		/* (RW) RTC backup register 28 */
#define TOFF_RTC_BKP29R     0x00C4		/* (RW) RTC backup register 29 */
#define TOFF_RTC_BKP30R     0x00C8		/* (RW) RTC backup register 30 */
#define TOFF_RTC_BKP31R     0x00CC		/* (RW) RTC backup register 31 */

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
#define TOFF_IWDG_WINR      0x0010		/* (RW) IWDG Window register */

/*
 *  SERIAL PERIPHERAL IINTERFACE
 */
#define TADR_SPI2_BASE      (APB1PERIPH_BASE + 0x3800)
#define TADR_SPI3_BASE      (APB1PERIPH_BASE + 0x3C00)
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
  #define SPI_CR2_NSSP             0x00000008	/* NSS pulse management Enable */
  #define SPI_CR2_FRF              0x00000010	/* Frame Format */
  #define SPI_CR2_ERRIE            0x00000020	/* Error Interrupt Enable */
  #define SPI_CR2_RXNEIE           0x00000040	/* RX buffer Not Empty Interrupt Enable */
  #define SPI_CR2_TXEIE            0x00000080	/* Tx buffer Empty Interrupt Enable */
  #define SPI_CR2_DS               0x00000F00	/* DS[3:0] Data Size */
  #define SPI_CR2_DS_0             0x00000100
  #define SPI_CR2_DS_1             0x00000200
  #define SPI_CR2_DS_2             0x00000400
  #define SPI_CR2_DS_3             0x00000800
  #define SPI_CR2_FRXTH            0x00001000	/* FIFO reception Threshold */
  #define SPI_CR2_LDMARX           0x00002000	/* Last DMA transfer for reception */
  #define SPI_CR2_LDMATX           0x00004000	/* Last DMA transfer for transmission */
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
  #define SPI_SR_FRLVL             0x00000600	/* FIFO Reception Level */
  #define SPI_SR_FRLVL_0           0x00000200
  #define SPI_SR_FRLVL_1           0x00000400
  #define SPI_SR_FTLVL             0x00001800	/* FIFO Transmission Level */
  #define SPI_SR_FTLVL_0           0x00000800
  #define SPI_SR_FTLVL_1           0x00001000
#define TOFF_SPI_DR         0x000C		/* (RW) SPI data register */
#define TOFF_SPI_CRCPR      0x0010		/* (RW) SPI CRC polynomial register (not used in I2S mode) */
#define TOFF_SPI_RXCRCR     0x0014		/* (RW) SPI RX CRC register (not used in I2S mode) */
#define TOFF_SPI_TXCRCR     0x0018		/* (RW) SPI TX CRC register (not used in I2S mode) */

/*
 *  UNIVERSAL SYNCHRONOUS ASYNCHORONOUS RECEIVER TRANSMITTER
 */
#define TADR_USART2_BASE    (APB1PERIPH_BASE + 0x4400)
#define TADR_USART3_BASE    (APB1PERIPH_BASE + 0x4800)
#define TADR_UART4_BASE     (APB1PERIPH_BASE + 0x4C00)
#define TADR_UART5_BASE     (APB1PERIPH_BASE + 0x5000)
#define TADR_LPUART1_BASE   (APB1PERIPH_BASE + 0x8000)
#define TADR_USART1_BASE    (APB2PERIPH_BASE + 0x3800)
#define TOFF_USART_CR1      0x0000		/* (RW-32) USART Control register 1 */
  #define USART_CR1_UE       0x00000001	/* USART Enable */
  #define USART_CR1_UESM     0x00000002	/* USART Enable in STOP Mode */
  #define USART_CR1_RE       0x00000004	/* Receiver Enable */
  #define USART_CR1_TE       0x00000008	/* Transmitter Enable */
  #define USART_CR1_IDLEIE   0x00000010	/* IDLE Interrupt Enable */
  #define USART_CR1_RXNEIE   0x00000020	/* RXNE Interrupt Enable */
  #define USART_CR1_TCIE     0x00000040	/* Transmission Complete Interrupt Enable */
  #define USART_CR1_TXEIE    0x00000080	/* PE Interrupt Enable */
  #define USART_CR1_PEIE     0x00000100	/* PE Interrupt Enable */
  #define USART_CR1_PS       0x00000200	/* Parity Selection */
  #define USART_CR1_PCE      0x00000400	/* Parity Control Enable */
  #define USART_CR1_WAKE     0x00000800	/* Wakeup method */
  #define USART_CR1_M0       0x00001000	/* Word length bit 0 */
  #define USART_CR1_MME      0x00002000	/* Mute Mode Enable */
  #define USART_CR1_CMIE     0x00004000	/* Character match interrupt enable */
  #define USART_CR1_OVER8    0x00008000	/* Oversampling by 8-bit or 16-bit mode */
  #define USART_CR1_DEDT     0x001F0000	/* DEDT[4:0] bits (Driver Enable Deassertion Time) */
  #define USART_CR1_DEDT_0   0x00010000
  #define USART_CR1_DEDT_1   0x00020000
  #define USART_CR1_DEDT_2   0x00040000
  #define USART_CR1_DEDT_3   0x00080000
  #define USART_CR1_DEDT_4   0x00100000
  #define USART_CR1_DEAT     0x03E00000	/* DEAT[4:0] bits (Driver Enable Assertion Time) */
  #define USART_CR1_DEAT_0   0x00200000
  #define USART_CR1_DEAT_1   0x00400000
  #define USART_CR1_DEAT_2   0x00800000
  #define USART_CR1_DEAT_3   0x01000000
  #define USART_CR1_DEAT_4   0x02000000
  #define USART_CR1_RTOIE    0x04000000	/* Receive Time Out interrupt enable */
  #define USART_CR1_EOBIE    0x08000000	/* End of Block interrupt enable */
  #define USART_CR1_M1       0x10000000	/* Word length bit 1 */
  #define USART_CR1_M        0x10001000	/* [M1:M0] Word length */
#define TOFF_USART_CR2      0x0004		/* (RW-32) USART Control register 2 */
  #define USART_CR2_ADDM7    0x00000010	/* 7-bit or 4-bit Address Detection */
  #define USART_CR2_LBDL     0x00000020	/* LIN Break Detection Length */
  #define USART_CR2_LBDIE    0x00000040	/* LIN Break Detection Interrupt Enable */
  #define USART_CR2_LBCL     0x00000100	/* Last Bit Clock pulse */
  #define USART_CR2_CPHA     0x00000200	/* Clock Phase */
  #define USART_CR2_CPOL     0x00000400	/* Clock Polarity */
  #define USART_CR2_CLKEN    0x00000800	/* Clock Enable */
  #define USART_CR2_STOP     0x00003000	/* STOP[1:0] bits (STOP bits) */
  #define USART_CR2_STOP_0   0x00001000	/* Bit 0 */
  #define USART_CR2_STOP_1   0x00002000	/* Bit 1 */
  #define USART_CR2_LINEN    0x00004000	/* LIN mode enable */
  #define USART_CR2_SWAP     0x00008000	/* SWAP TX/RX pins */
  #define USART_CR2_RXINV    0x00010000	/* RX pin active level inversion */
  #define USART_CR2_TXINV    0x00020000	/* TX pin active level inversion */
  #define USART_CR2_DATAINV  0x00040000	/* Binary data inversion */
  #define USART_CR2_MSBFIRST 0x00080000	/* Most Significant Bit First */
  #define USART_CR2_ABREN    0x00100000	/* Auto Baud-Rate Enable*/
  #define USART_CR2_ABRMODE  0x00600000	/* ABRMOD[1:0] bits (Auto Baud-Rate Mode) */
  #define USART_CR2_ABRMODE_0 0x00200000
  #define USART_CR2_ABRMODE_1 0x00400000
  #define USART_CR2_RTOEN    0x00800000	/* Receiver Time-Out enable */
  #define USART_CR2_ADD      0xFF000000	/* Address of the USART node */
#define TOFF_USART_CR3      0x0008		/* (RW-32) USART Control register 3 */
  #define USART_CR3_EIE      0x00000001	/* Error Interrupt Enable */
  #define USART_CR3_IREN     0x00000002	/* IrDA mode Enable */
  #define USART_CR3_IRLP     0x00000004	/* IrDA Low-Power */
  #define USART_CR3_HDSEL    0x00000008	/* Half-Duplex Selection */
  #define USART_CR3_NACK     0x00000010	/* Smartcard NACK enable */
  #define USART_CR3_SCEN     0x00000020	/* Smartcard mode enable */
  #define USART_CR3_DMAR     0x00000040	/* DMA Enable Receiver */
  #define USART_CR3_DMAT     0x00000080	/* DMA Enable Transmitter */
  #define USART_CR3_RTSE     0x00000100	/* RTS Enable */
  #define USART_CR3_CTSE     0x00000200	/* CTS Enable */
  #define USART_CR3_CTSIE    0x00000400	/* CTS Interrupt Enable */
  #define USART_CR3_ONEBIT   0x00000800	/* USART One bit method enable */
  #define USART_CR3_OVRDIS   0x00001000	/* Overrun Disable */
  #define USART_CR3_DDRE     0x00002000	/* DMA Disable on Reception Error */
  #define USART_CR3_DEM      0x00004000	/* Driver Enable Mode */
  #define USART_CR3_DEP      0x00008000	/* Driver Enable Polarity Selection */
  #define USART_CR3_SCARCNT  0x000E0000	/* SCARCNT[2:0] bits (SmartCard Auto-Retry Count) */
  #define USART_CR3_SCARCNT_0 0x00020000
  #define USART_CR3_SCARCNT_1 0x00040000
  #define USART_CR3_SCARCNT_2 0x00080000
  #define USART_CR3_WUS      0x00300000	/* WUS[1:0] bits (Wake UP Interrupt Flag Selection) */
  #define USART_CR3_WUS_0    0x00100000
  #define USART_CR3_WUS_1    0x00200000
  #define USART_CR3_WUFIE    0x00400000	/* Wake Up Interrupt Enable */
#define TOFF_USART_BRR      0x000C		/* (RW-32) USART Baud rate register */
#define TOFF_USART_GTPR     0x0010		/* (RW-32) USART Guard time and prescaler register */
  #define USART_GTPR_PSC     0x000000FF	/* PSC[7:0] bits (Prescaler value) */
  #define USART_GTPR_PSC_0   0x00000001	/* Bit 0 */
  #define USART_GTPR_PSC_1   0x00000002	/* Bit 1 */
  #define USART_GTPR_PSC_2   0x00000004	/* Bit 2 */
  #define USART_GTPR_PSC_3   0x00000008	/* Bit 3 */
  #define USART_GTPR_PSC_4   0x00000010	/* Bit 4 */
  #define USART_GTPR_PSC_5   0x00000020	/* Bit 5 */
  #define USART_GTPR_PSC_6   0x00000040	/* Bit 6 */
  #define USART_GTPR_PSC_7   0x00000080	/* Bit 7 */
  #define USART_GTPR_GT      0x0000FF00	/* Guard time value */
#define TOFF_USART_RTOR     0x0014		/* (RW) USART Receiver Time Out register */
  #define USART_RTOR_RTO     0x00FFFFFF	/* Receiver Time Out Value */
  #define USART_RTOR_BLEN    0xFF000000	/* Block Length */
#define TOFF_USART_RQR      0x0018		/* (RW) USART Request register */
  #define USART_RQR_ABRRQ    0x00000001	/* Auto-Baud Rate Request */
  #define USART_RQR_SBKRQ    0x00000002	/* Send Break Request */
  #define USART_RQR_MMRQ     0x00000004	/* Mute Mode Request */
  #define USART_RQR_RXFRQ    0x00000008	/* Receive Data flush Request */
  #define USART_RQR_TXFRQ    0x00000010	/* Transmit data flush Request */
#define TOFF_USART_ISR      0x001C		/* (RW) USART Interrupt and status register */
  #define USART_ISR_PE       0x00000001	/* Parity Error */
  #define USART_ISR_FE       0x00000002	/* Framing Error */
  #define USART_ISR_NE       0x00000004	/* Noise detected Flag */
  #define USART_ISR_ORE      0x00000008	/* OverRun Error */
  #define USART_ISR_IDLE     0x00000010	/* IDLE line detected */
  #define USART_ISR_RXNE     0x00000020	/* Read Data Register Not Empty */
  #define USART_ISR_TC       0x00000040	/* Transmission Complete */
  #define USART_ISR_TXE      0x00000080	/* Transmit Data Register Empty */
  #define USART_ISR_LBDF     0x00000100	/* LIN Break Detection Flag */
  #define USART_ISR_CTSIF    0x00000200	/* CTS interrupt flag */
  #define USART_ISR_CTS      0x00000400	/* CTS flag */
  #define USART_ISR_RTOF     0x00000800	/* Receiver Time Out */
  #define USART_ISR_EOBF     0x00001000	/* End Of Block Flag */
  #define USART_ISR_ABRE     0x00004000	/* Auto-Baud Rate Error */
  #define USART_ISR_ABRF     0x00008000	/* Auto-Baud Rate Flag */
  #define USART_ISR_BUSY     0x00010000	/* Busy Flag */
  #define USART_ISR_CMF      0x00020000	/* Character Match Flag */
  #define USART_ISR_SBKF     0x00040000	/* Send Break Flag */
  #define USART_ISR_RWU      0x00080000	/* Receive Wake Up from mute mode Flag */
  #define USART_ISR_WUF      0x00100000	/* Wake Up from stop mode Flag */
  #define USART_ISR_TEACK    0x00200000	/* Transmit Enable Acknowledge Flag */
  #define USART_ISR_REACK    0x00400000	/* Receive Enable Acknowledge Flag */
#define TOFF_USART_ICR      0x0020		/* (RW) USART Interrupt flag Clear register */
  #define USART_ICR_PECF     0x00000001	/* Parity Error Clear Flag */
  #define USART_ICR_FECF     0x00000002	/* Framing Error Clear Flag */
  #define USART_ICR_NCF      0x00000004	/* Noise detected Clear Flag */
  #define USART_ICR_ORECF    0x00000008	/* OverRun Error Clear Flag */
  #define USART_ICR_IDLECF   0x00000010	/* IDLE line detected Clear Flag */
  #define USART_ICR_TCCF     0x00000040	/* Transmission Complete Clear Flag */
  #define USART_ICR_LBDCF    0x00000100	/* LIN Break Detection Clear Flag */
  #define USART_ICR_CTSCF    0x00000200	/* CTS Interrupt Clear Flag */
  #define USART_ICR_RTOCF    0x00000800	/* Receiver Time Out Clear Flag */
  #define USART_ICR_EOBCF    0x00001000	/* End Of Block Clear Flag */
  #define USART_ICR_CMCF     0x00020000	/* Character Match Clear Flag */
  #define USART_ICR_WUCF     0x00100000	/* Wake Up from stop mode Clear Flag */
#define TOFF_USART_RDR      0x0024		/* (RW-16) USART Receive Data register */
  #define USART_RDR_RDR      0x01FF		/* RDR[8:0] bits (Receive Data value) */
#define TOFF_USART_TDR      0x0028		/* (RW-16) USART Transmit Data register */
  #define USART_TDR_TDR      0x01FF		/* TDR[8:0] bits (Transmit Data value) */
#if !defined(TOPPERS_STM32L476_DISCOVERY) && !defined(TOPPERS_STM32L476_NUCLEO64)
#define TOFF_USART_PRESC    0x002C		/* Prescaler register */
  #define USART_PRESC_PRESCALER   0x0000000F	/* PRESCALER[3:0] bits (Clock prescaler) */
  #define USART_PRESC_PRESCALER_0 0x00000001
  #define USART_PRESC_PRESCALER_1 0x00000002
  #define USART_PRESC_PRESCALER_2 0x00000004
  #define USART_PRESC_PRESCALER_3 0x00000008
#endif


/*
 *  INTER-INTERATED CIRCUIT IINTERFACE
 */
#define TADR_I2C1_BASE      (APB1PERIPH_BASE + 0x5400)
#define TADR_I2C2_BASE      (APB1PERIPH_BASE + 0x5800)
#define TADR_I2C3_BASE      (APB1PERIPH_BASE + 0x5C00)
#define TOFF_I2C_CR1        0x0000		/* (RW) I2C Control register 1 */
  #define I2C_CR1_PE         0x00000001	/* Peripheral Enable */
  #define I2C_CR1_TXIE       0x00000002	/* TX interrupt enable */
  #define I2C_CR1_RXIE       0x00000004	/* RX interrupt enable */
  #define I2C_CR1_ADDRIE     0x00000008	/* Address match interrupt enable */
  #define I2C_CR1_NACKIE     0x00000010	/* NACK received interrupt enable */
  #define I2C_CR1_STOPIE     0x00000020	/* STOP detection interrupt enable */
  #define I2C_CR1_TCIE       0x00000040	/* Transfer complete interrupt enable */
  #define I2C_CR1_ERRIE      0x00000080	/* Errors interrupt enable */
  #define I2C_CR1_DNF        0x00000F00	/* Digital noise filter */
  #define I2C_CR1_ANFOFF     0x00001000	/* Analog noise filter OFF */
  #define I2C_CR1_SWRST      0x00002000	/* Software reset */
  #define I2C_CR1_TXDMAEN    0x00004000	/* DMA transmission requests enable */
  #define I2C_CR1_RXDMAEN    0x00008000	/* DMA reception requests enable */
  #define I2C_CR1_SBC        0x00010000	/* Slave byte control */
  #define I2C_CR1_NOSTRETCH  0x00020000	/* Clock stretching disable */
  #define I2C_CR1_WUPEN      0x00040000	/* Wakeup from STOP enable */
  #define I2C_CR1_GCEN       0x00080000	/* General call enable */
  #define I2C_CR1_SMBHEN     0x00100000	/* SMBus host address enable */
  #define I2C_CR1_SMBDEN     0x00200000	/* SMBus device default address enable */
  #define I2C_CR1_ALERTEN    0x00400000	/* SMBus alert enable */
  #define I2C_CR1_PECEN      0x00800000	/* PEC enable */
#define TOFF_I2C_CR2        0x0004		/* (RW) I2C Control register 2 */
  #define I2C_CR2_SADD       0x000003FF	/* Slave address (master mode) */
  #define I2C_CR2_RD_WRN     0x00000400	/* Transfer direction (master mode) */
  #define I2C_CR2_ADD10      0x00000800	/* 10-bit addressing mode (master mode) */
  #define I2C_CR2_HEAD10R    0x00001000	/* 10-bit address header only read direction (master mode) */
  #define I2C_CR2_START      0x00002000	/* START generation */
  #define I2C_CR2_STOP       0x00004000	/* STOP generation (master mode) */
  #define I2C_CR2_NACK       0x00008000	/* NACK generation (slave mode) */
  #define I2C_CR2_NBYTES     0x00FF0000	/* Number of bytes */
  #define I2C_CR2_RELOAD     0x01000000	/* NBYTES reload mode */
  #define I2C_CR2_AUTOEND    0x02000000	/* Automatic end mode (master mode) */
  #define I2C_CR2_PECBYTE    0x04000000	/* Packet error checking byte */
#define TOFF_I2C_OAR1       0x0008		/* (RW) I2C Own address register 1 */
  #define I2C_OAR1_OA1      0x000003FF	/* Interface own address 1 */
  #define I2C_OAR1_OA1MODE  0x00000400	/* Own address 1 10-bit mode */
  #define I2C_OAR1_OA1EN    0x00008000	/* Own address 1 enable */
#define TOFF_I2C_OAR2       0x000C		/* (RW) I2C Own address register 2 */
  #define I2C_OAR2_OA2       0x000000FE	/* Interface own address 2 */
  #define I2C_OAR2_OA2MSK    0x00000700	/* Own address 2 masks */
  #define I2C_OAR2_OA2NOMASK 0x00000000	/* No mask */
  #define I2C_OAR2_OA2MASK01 0x00000100	/* OA2[1] is masked, Only OA2[7:2] are compared */
  #define I2C_OAR2_OA2MASK02 0x00000200	/* OA2[2:1] is masked, Only OA2[7:3] are compared */
  #define I2C_OAR2_OA2MASK03 0x00000300	/* OA2[3:1] is masked, Only OA2[7:4] are compared */
  #define I2C_OAR2_OA2MASK04 0x00000400	/* OA2[4:1] is masked, Only OA2[7:5] are compared */
  #define I2C_OAR2_OA2MASK05 0x00000500	/* OA2[5:1] is masked, Only OA2[7:6] are compared */
  #define I2C_OAR2_OA2MASK06 0x00000600	/* OA2[6:1] is masked, Only OA2[7] are compared */
  #define I2C_OAR2_OA2MASK07 0x00000700	/* OA2[7:1] is masked, No comparison is done */
  #define I2C_OAR2_OA2EN     0x00008000	/* Own address 2 enable */
#define TOFF_I2C_TIMINGR    0x0010		/* (RW) I2C Timing register */
  #define I2C_TIMINGR_SCLL   0x000000FF	/* SCL low period (master mode) */
  #define I2C_TIMINGR_SCLH   0x0000FF00	/* SCL high period (master mode) */
  #define I2C_TIMINGR_SDADEL 0x000F0000	/* Data hold time */
  #define I2C_TIMINGR_SCLDEL 0x00F00000	/* Data setup time */
  #define I2C_TIMINGR_PRESC  0xF0000000	/* Timings prescaler */
#define TOFF_I2C_TIMEOUTR   0x0014		/* (RW) I2C Timeout register */
  #define I2C_TIMEOUTR_TIMEOUTA 0x00000FFF	/* Bus timeout A */
  #define I2C_TIMEOUTR_TIDLE    0x00001000	/* Idle clock timeout detection */
  #define I2C_TIMEOUTR_TIMOUTEN 0x00008000	/* Clock timeout enable */
  #define I2C_TIMEOUTR_TIMEOUTB 0x0FFF0000	/* Bus timeout B*/
  #define I2C_TIMEOUTR_TEXTEN   0x80000000	/* Extended clock timeout enable */
#define TOFF_I2C_ISR        0x0018		/* (RW) I2C Interrupt and status register */
  #define I2C_ISR_TXE        0x00000001	/* Transmit data register empty */
  #define I2C_ISR_TXIS       0x00000002	/* Transmit interrupt status */
  #define I2C_ISR_RXNE       0x00000004	/* Receive data register not empty */
  #define I2C_ISR_ADDR       0x00000008	/* Address matched (slave mode)*/
  #define I2C_ISR_NACKF      0x00000010	/* NACK received flag */
  #define I2C_ISR_STOPF      0x00000020	/* STOP detection flag */
  #define I2C_ISR_TC         0x00000040	/* Transfer complete (master mode) */
  #define I2C_ISR_TCR        0x00000080	/* Transfer complete reload */
  #define I2C_ISR_BERR       0x00000100	/* Bus error */
  #define I2C_ISR_ARLO       0x00000200	/* Arbitration lost */
  #define I2C_ISR_OVR        0x00000400	/* Overrun/Underrun */
  #define I2C_ISR_PECERR     0x00000800	/* PEC error in reception */
  #define I2C_ISR_TIMEOUT    0x00001000	/* Timeout or Tlow detection flag */
  #define I2C_ISR_ALERT      0x00002000	/* SMBus alert */
  #define I2C_ISR_BUSY       0x00008000	/* Bus busy */
  #define I2C_ISR_DIR        0x00010000	/* Transfer direction (slave mode) */
  #define I2C_ISR_ADDCODE    0x00FE0000	/* Address match code (slave mode) */
#define TOFF_I2C_ICR        0x001C		/* (RW) I2C Interrupt clear register */
  #define I2C_ICR_ADDRCF     0x00000008	/* Address matched clear flag */
  #define I2C_ICR_NACKCF     0x00000010	/* NACK clear flag */
  #define I2C_ICR_STOPCF     0x00000020	/* STOP detection clear flag */
  #define I2C_ICR_BERRCF     0x00000100	/* Bus error clear flag */
  #define I2C_ICR_ARLOCF     0x00000200	/* Arbitration lost clear flag */
  #define I2C_ICR_OVRCF      0x00000400	/* Overrun/Underrun clear flag */
  #define I2C_ICR_PECCF      0x00000800	/* PAC error clear flag */
  #define I2C_ICR_TIMOUTCF   0x00001000	/* Timeout clear flag */
  #define I2C_ICR_ALERTCF    0x00002000	/* Alert clear flag */
#define TOFF_I2C_PECR       0x0020		/* (RW) I2C PEC register */
  #define I2C_PECR_PEC       0x000000FF	/* PEC register */
#define TOFF_I2C_RXDR       0x0024		/* (RW) I2C Receive data register */
  #define I2C_RXDR_RXDATA    0x000000FF	/* 8-bit receive data */
#define TOFF_I2C_TXDR       0x0028		/* (RW) I2C Transmit data register */
  #define I2C_TXDR_TXDATA    0x000000FF	/* 8-bit transmit data */

#if !defined(TOPPERS_STM32L476_DISCOVERY) && !defined(TOPPERS_STM32L476_NUCLEO64)
/*
 *  CLOCK RECOVERY SYSTEM
 */
#define TADR_CRS_BASE       (APB1PERIPH_BASE + 0x6000)
#define TOFF_CRS_CR         0x0000		/* (RW) CRS ccontrol register */
  #define CRS_CR_SYNCOKIE    0x00000001	/* SYNC event OK interrupt enable */
  #define CRS_CR_SYNCWARNIE  0x00000002	/* SYNC warning interrupt enable */
  #define CRS_CR_ERRIE       0x00000004	/* SYNC error or trimming error interrupt enable */
  #define CRS_CR_ESYNCIE     0x00000008	/* Expected SYNC interrupt enable */
  #define CRS_CR_CEN         0x00000020	/* Frequency error counter enable */
  #define CRS_CR_AUTOTRIMEN  0x00000040	/* Automatic trimming enable */
  #define CRS_CR_SWSYNC      0x00000080	/* Generate software SYNC event */
  #define CRS_CR_TRIM        0x00003F00	/* HSI48 oscillator smooth trimming */
#define TOFF_CRS_CFGR       0x0004		/* (RW) CRS configuration register */
  #define CRS_CFGR_RELOAD    0x0000FFFF	/* Counter reload value */
  #define CRS_CFGR_FELIM     0x00FF0000	/* Frequency error limit */
  #define CRS_CFGR_SYNCDIV   0x07000000	/* SYNC divider */
  #define CRS_CFGR_SYNCDIV_0 0x01000000
  #define CRS_CFGR_SYNCDIV_1 0x02000000
  #define CRS_CFGR_SYNCDIV_2 0x04000000
  #define CRS_CFGR_SYNCSRC   0x30000000	/* SYNC signal source selection */
  #define CRS_CFGR_SYNCSRC_0 0x10000000
  #define CRS_CFGR_SYNCSRC_1 0x20000000
  #define CRS_CFGR_SYNCPOL   0x80000000	/* SYNC polarity selection */
#define TOFF_CRS_ISR        0x0008		/* (RW) CRS interrupt and status register */
  #define CRS_ISR_SYNCOKF    0x00000001	/* SYNC event OK flag */
  #define CRS_ISR_SYNCWARNF  0x00000002	/* SYNC warning flag */
  #define CRS_ISR_ERRF       0x00000004	/* Error flag */
  #define CRS_ISR_ESYNCF     0x00000008	/* Expected SYNC flag */
  #define CRS_ISR_SYNCERR    0x00000100	/* SYNC error */
  #define CRS_ISR_SYNCMISS   0x00000200	/* SYNC missed */
  #define CRS_ISR_TRIMOVF    0x00000400	/* Trimming overflow or underflow */
  #define CRS_ISR_FEDIR      0x00008000	/* Frequency error direction */
  #define CRS_ISR_FECAP      0xFFFF0000	/* Frequency error capture */
#define TOFF_CRS_ICR        0x000C		/* (RW) CRS interrupt flag clear register */
  #define CRS_ICR_SYNCOKC    0x00000001	/* SYNC event OK clear flag */
  #define CRS_ICR_SYNCWARNC  0x00000002	/* SYNC warning clear flag */
  #define CRS_ICR_ERRC       0x00000004	/* Error clear flag */
  #define CRS_ICR_ESYNCC     0x00000008	/* Expected SYNC clear flag */
#endif


/*
 *  CONTROLLER AREA NETWORK
 */
#define TADR_CAN1_BASE      (APB1PERIPH_BASE + 0x6400)
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

#define TOFF_PWR_CR1        0x0000	/* (RW) PWR power control register 1 */
  #define PWR_CR1_LPMS          0x00000007	/* Low-power mode selection field */
  #define PWR_CR1_LPMS_STOP0    0x00000000	/* Stop 0 mode */
  #define PWR_CR1_LPMS_STOP1    0x00000001	/* Stop 1 mode */
  #define PWR_CR1_LPMS_STOP2    0x00000002	/* Stop 2 mode */
  #define PWR_CR1_LPMS_STANDBY  0x00000003	/* Stand-by mode */
  #define PWR_CR1_LPMS_SHUTDOWN 0x00000004	/* Shut-down mode */
  #define PWR_CR1_DBP           0x00000100	/* Disable Back-up domain Protection */
  #define PWR_CR1_VOS           0x00000600	/* VOS[1:0] bits (Regulator voltage scaling output selection) */
  #define PWR_CR1_VOS_0         0x00000200
  #define PWR_CR1_VOS_1         0x00000400
  #define PWR_CR1_LPR           0x00004000	/* Regulator low-power mode */
#define TOFF_PWR_CR2        0x0004	/* (RW) PWR power control register 2 */
  #define PWR_CR2_PVDE          0x00000001	/* Power Voltage Detector Enable */
  #define PWR_CR2_PLS           0x0000000E	/* PVD level selection */
  #define PWR_CR2_PLS_LEV0      0x00000000	/* PVD level 0 */
  #define PWR_CR2_PLS_LEV1      0x00000002	/* PVD level 1 */
  #define PWR_CR2_PLS_LEV2      0x00000004	/* PVD level 2 */
  #define PWR_CR2_PLS_LEV3      0x00000006	/* PVD level 3 */
  #define PWR_CR2_PLS_LEV4      0x00000008	/* PVD level 4 */
  #define PWR_CR2_PLS_LEV5      0x0000000A	/* PVD level 5 */
  #define PWR_CR2_PLS_LEV6      0x0000000C	/* PVD level 6 */
  #define PWR_CR2_PLS_LEV7      0x0000000E	/* PVD level 7 */
  #define PWR_CR2_PVME          0x000000F0	/* PVM bits field */
  #define PWR_CR2_PVME4         0x00000080	/* PVM 4 Enable */
  #define PWR_CR2_PVME3         0x00000040	/* PVM 3 Enable */
  #define PWR_CR2_PVME2         0x00000020	/* PVM 2 Enable */
  #define PWR_CR2_PVME1         0x00000010	/* PVM 1 Enable */
  #define PWR_CR2_IOSV          0x00000200	/* VDD IO2 independent I/Os Supply Valid */
  #define PWR_CR2_USV           0x00000400	/* VDD USB Supply Valid */
#define TOFF_PWR_CR3        0x0008	/* (RW) PWR power control register 3 */
  #define PWR_CR3_EWUP          0x0000001F	/* Enable Wake-Up Pins  */
  #define PWR_CR3_EWUP5         0x00000010	/* Enable Wake-Up Pin 5 */
  #define PWR_CR3_EWUP4         0x00000008	/* Enable Wake-Up Pin 4 */
  #define PWR_CR3_EWUP3         0x00000004	/* Enable Wake-Up Pin 3 */
  #define PWR_CR3_EWUP2         0x00000002	/* Enable Wake-Up Pin 2 */
  #define PWR_CR3_EWUP1         0x00000001	/* Enable Wake-Up Pin 1 */
  #define PWR_CR3_RRS           0x00000100	/* SRAM2 Retention in Stand-by mode */
  #define PWR_CR3_APC           0x00000400	/* Apply pull-up and pull-down configuration */
  #define PWR_CR3_EIWF          0x00008000	/* Enable Internal Wake-up line */
#define TOFF_PWR_CR4        0x000C	/* (RW) PWR power control register 4 */
  #define PWR_CR4_WP1           0x00000001	/* Wake-Up Pin 1 polarity */
  #define PWR_CR4_WP2           0x00000002	/* Wake-Up Pin 2 polarity */
  #define PWR_CR4_WP3           0x00000004	/* Wake-Up Pin 3 polarity */
  #define PWR_CR4_WP4           0x00000008	/* Wake-Up Pin 4 polarity */
  #define PWR_CR4_WP5           0x00000010	/* Wake-Up Pin 5 polarity */
  #define PWR_CR4_VBE           0x00000100	/* VBAT Battery charging Enable  */
  #define PWR_CR4_VBRS          0x00000200	/* VBAT Battery charging Resistor Selection */
#define TOFF_PWR_SR1        0x0010	/* (RW) PWR power status register 1 */
  #define PWR_SR1_WUF           0x0000001F	/* Wake-up Flags */
  #define PWR_SR1_WUF5          0x00000010	/* Wake-up Flag 5 */
  #define PWR_SR1_WUF4          0x00000008	/* Wake-up Flag 4 */
  #define PWR_SR1_WUF3          0x00000004	/* Wake-up Flag 3 */
  #define PWR_SR1_WUF2          0x00000002	/* Wake-up Flag 2 */
  #define PWR_SR1_WUF1          0x00000001	/* Wake-up Flag 1 */
  #define PWR_SR1_SBF           0x00000100	/* Stand-By Flag */
  #define PWR_SR1_WUFI          0x00008000	/* Wake-Up Flag Internal */
#define TOFF_PWR_SR2        0x0014	/* (RW) PWR power status register 2 */
  #define PWR_SR2_REGLPS        0x00000100	/* Low-power Regulator Started */
  #define PWR_SR2_REGLPF        0x00000200	/* Low-power Regulator Flag */
  #define PWR_SR2_VOSF          0x00000400	/* Voltage Scaling Flag */
  #define PWR_SR2_PVDO          0x00000800	/* Power Voltage Detector Output */
  #define PWR_SR2_PVMO1         0x00001000	/* Peripheral Voltage Monitoring Output 1 */
  #define PWR_SR2_PVMO2         0x00002000	/* Peripheral Voltage Monitoring Output 2 */
  #define PWR_SR2_PVMO3         0x00004000	/* Peripheral Voltage Monitoring Output 3 */
  #define PWR_SR2_PVMO4         0x00008000	/* Peripheral Voltage Monitoring Output 4 */
#define TOFF_PWR_SCR        0x0018	/* (RW) PWR power status reset register */
  #define PWR_SCR_CWUF          0x0000001F	/* Clear Wake-up Flags  */
  #define PWR_SCR_CWUF1         0x00000001	/* Clear Wake-up Flag 1 */
  #define PWR_SCR_CWUF2         0x00000002	/* Clear Wake-up Flag 2 */
  #define PWR_SCR_CWUF3         0x00000004	/* Clear Wake-up Flag 3 */
  #define PWR_SCR_CWUF4         0x00000008	/* Clear Wake-up Flag 4 */
  #define PWR_SCR_CWUF5         0x00000010	/* Clear Wake-up Flag 5 */
  #define PWR_SCR_CSBF          0x00000100	/* Clear Stand-By Flag */
#define TOFF_PWR_PUCRA      0x0020	/* (RW) Pull_up control register of portA */
#define TOFF_PWR_PDCRA      0x0024	/* (RW) Pull_Down control register of portA */
#define TOFF_PWR_PUCRB      0x0028	/* (RW) Pull_up control register of portB */
#define TOFF_PWR_PDCRB      0x002C	/* (RW) Pull_Down control register of portB */
#define TOFF_PWR_PUCRC      0x0030	/* (RW) Pull_up control register of portC */
#define TOFF_PWR_PDCRC      0x0034	/* (RW) Pull_Down control register of portC */
#define TOFF_PWR_PUCRD      0x0038	/* (RW) Pull_up control register of portD */
#define TOFF_PWR_PDCRD      0x003C	/* (RW) Pull_Down control register of portD */
#define TOFF_PWR_PUCRE      0x0040	/* (RW) Pull_up control register of portE */
#define TOFF_PWR_PDCRE      0x0044	/* (RW) Pull_Down control register of portE */
#define TOFF_PWR_PUCRF      0x0048	/* (RW) Pull_up control register of portF */
#define TOFF_PWR_PDCRF      0x004C	/* (RW) Pull_Down control register of portF */
#define TOFF_PWR_PUCRG      0x0050	/* (RW) Pull_up control register of portG */
#define TOFF_PWR_PDCRG      0x0054	/* (RW) Pull_Down control register of portG */
#define TOFF_PWR_PUCRH      0x0058	/* (RW) Pull_up control register of portH */
#define TOFF_PWR_PDCRH      0x005C	/* (RW) Pull_Down control register of portH */
#if !defined(TOPPERS_STM32L476_DISCOVERY) && !defined(TOPPERS_STM32L476_NUCLEO64)
#define TOFF_PWR_CR5        0x0080	/* (RW) PWR power control register 5 */
  #define PWR_CR5_R1MODE        0x00000100	/* Range 1 normal mode */
#endif


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
#define TOFF_DAC_CCR        0x0038		/* (RW) DAC calibration control register */
#define TOFF_DAC_MCR        0x003C		/* (RW) DAC mode control register */
#define TOFF_DAC_SHSR1      0x0040		/* (RW) DAC Sample and Hold sample time register 1 */
#define TOFF_DAC_SHSR2      0x0044		/* (RW) DAC Sample and Hold sample time register 2 */
#define TOFF_DAC_SHHR       0x0048		/* (RW) DAC Sample and Hold hold time register */
#define TOFF_DAC_SHRR       0x004C		/* (RW) DAC Sample and Hold refresh time register */


/*
 *  OPERATIONAL AMPLIFIER(OPAMP)
 */
#define TADR_OPAMP_BASE     (APB1PERIPH_BASE + 0x7800)
#define TADR_OPAMP1_BASE    (APB1PERIPH_BASE + 0x7800)
#define TADR_OPAMP2_BASE    (APB1PERIPH_BASE + 0x7810)
#define TOFF_OPAMP_CSR      0x0000		/* (RW) OPAMP control/status register */
#define TOFF_OPAMP_OTR      0x0004		/* (RW) OPAMP offset trimming register for normal mode */
#define TOFF_OPAMP_LPOTR    0x0008		/* (RW) OPAMP offset trimming register for low power mode */


/*
 *  LOW POWER TIMIMER
 */
#define TADR_LPTIM1_BASE    (APB1PERIPH_BASE + 0x7C00)
#define TADR_LPTIM2_BASE    (APB1PERIPH_BASE + 0x9400)
#define TOFF_LPTIM_ISR      0x0000		/* (RW) LPTIM Interrupt and Status register */
#define TOFF_LPTIM_ICR      0x0004		/* (RW) LPTIM Interrupt Clear register */
#define TOFF_LPTIM_IER      0x0008		/* (RW) LPTIM Interrupt Enable register */
#define TOFF_LPTIM_CFGR     0x000C		/* (RW) LPTIM Configuration register */
#define TOFF_LPTIM_CR       0x0010		/* (RW) LPTIM Control register */
#define TOFF_LPTIM_CMP      0x0014		/* (RW) LPTIM Compare register */
#define TOFF_LPTIM_ARR      0x0018		/* (RW) LPTIM Autoreload register */
#define TOFF_LPTIM_CNT      0x001C		/* (RW) LPTIM Counter register */
#define TOFF_LPTIM_OR       0x0020		/* (RW) LPTIM Option register */


/*
 *  SINGLE WIRE PROTOCOL MASTER INTERFACE (SPWMI)
  */
#define TADR_SWPMI1_BASE    (APB1PERIPH_BASE + 0x8800)
#define TOFF_SWPMI_CR       0x0000		/* (RW) SWPMI Configuration/Control register */
#define TOFF_SWPMI_BRR      0x0004		/* (RW) SWPMI bitrate register */
#define TOFF_SWPMI_ISR      0x000C		/* (RW) SWPMI Interrupt and Status register */
#define TOFF_SWPMI_ICR      0x0010		/* (RW) SWPMI Interrupt Flag Clear register */
#define TOFF_SWPMI_IER      0x0014		/* (RW) SWPMI Interrupt Enable register */
#define TOFF_SWPMI_RFL      0x0018		/* (RW) SWPMI Receive Frame Length register */
#define TOFF_SWPMI_TDR      0x001C		/* (RW) SWPMI Transmit data register */
#define TOFF_SWPMI_RDR      0x0020		/* (RW) SWPMI Receive data register */
#define TOFF_SWPMI_OR       0x0024		/* (RW) SWPMI Option register */


/*
 *  SYSTEM CONFIGURATION CONTROLLER
 */
#define TADR_SYSCFG_BASE    (APB2PERIPH_BASE + 0x0000)
#define TOFF_SYSCFG_MEMRMP  0x0000		/* (RW) SYSCFG memory remap register */
  #define SYSCFG_MEMRMP_MEM_MODE 0x00000007	/* SYSCFG_Memory Remap Config */
  #define SYSCFG_MEMRMP_MEM_MODE_0 0x00000001
  #define SYSCFG_MEMRMP_MEM_MODE_1 0x00000002
  #define SYSCFG_MEMRMP_MEM_MODE_2 0x00000004
  #define SYSCFG_MEMRMP_FB_MODE 0x00000100	/* Flash Bank mode selection */
#define TOFF_SYSCFG_CFGR1   0x0004		/* (RW) SYSCFG configuration register 1 */
  #define SYSCFG_CFGR1_FWDIS    0x00000001	/* FIREWALL access enable*/
  #define SYSCFG_CFGR1_BOOSTEN  0x00000100	/* I/O analog switch voltage booster enable */
  #define SYSCFG_CFGR1_I2C_PB6_FMP 0x00010000	/* I2C PB6 Fast mode plus */
  #define SYSCFG_CFGR1_I2C_PB7_FMP 0x00020000	/* I2C PB7 Fast mode plus */
  #define SYSCFG_CFGR1_I2C_PB8_FMP 0x00040000	/* I2C PB8 Fast mode plus */
  #define SYSCFG_CFGR1_I2C_PB9_FMP 0x00080000	/* I2C PB9 Fast mode plus */
  #define SYSCFG_CFGR1_I2C1_FMP 0x00100000	/* I2C1 Fast mode plus */
  #define SYSCFG_CFGR1_I2C2_FMP 0x00200000	/* I2C2 Fast mode plus */
  #define SYSCFG_CFGR1_I2C3_FMP 0x00400000	/* I2C3 Fast mode plus */
  #define SYSCFG_CFGR1_FPU_IE_0 0x04000000	/* Invalid operation Interrupt enable */
  #define SYSCFG_CFGR1_FPU_IE_1 0x08000000	/* Divide-by-zero Interrupt enable */
  #define SYSCFG_CFGR1_FPU_IE_2 0x10000000	/* Underflow Interrupt enable */
  #define SYSCFG_CFGR1_FPU_IE_3 0x20000000	/* Overflow Interrupt enable */
  #define SYSCFG_CFGR1_FPU_IE_4 0x40000000	/* Input denormal Interrupt enable */
  #define SYSCFG_CFGR1_FPU_IE_5 0x80000000	/* Inexact Interrupt enable (interrupt disabled at reset) */
#define TOFF_SYSCFG_EXTICR  0x0008		/* (RW) SYSCFG external interrupt configuration registers */
#define TOFF_SYSCFG_EXTICR1 0x0008		/* (RW) SYSCFG external interrupt configuration registers 1 */
  #define SYSCFG_EXTICR1_EXTI0  0x00000007	/* EXTI 0 configuration */
  #define SYSCFG_EXTICR1_EXTI1  0x00000070	/* EXTI 1 configuration */
  #define SYSCFG_EXTICR1_EXTI2  0x00000700	/* EXTI 2 configuration */
  #define SYSCFG_EXTICR1_EXTI3  0x00007000	/* EXTI 3 configuration */
  #define SYSCFG_EXTICR1_EXTI0_PA   0x00000000	/* PA[0] pin */
  #define SYSCFG_EXTICR1_EXTI0_PB   0x00000001	/* PB[0] pin */
  #define SYSCFG_EXTICR1_EXTI0_PC   0x00000002	/* PC[0] pin */
  #define SYSCFG_EXTICR1_EXTI0_PD   0x00000003	/* PD[0] pin */
  #define SYSCFG_EXTICR1_EXTI0_PE   0x00000004	/* PE[0] pin */
  #define SYSCFG_EXTICR1_EXTI0_PF   0x00000005	/* PF[0] pin */
  #define SYSCFG_EXTICR1_EXTI0_PG   0x00000006	/* PG[0] pin */
  #define SYSCFG_EXTICR1_EXTI0_PH   0x00000007	/* PH[0] pin */
  #define SYSCFG_EXTICR1_EXTI1_PA   0x00000000	/* PA[1] pin */
  #define SYSCFG_EXTICR1_EXTI1_PB   0x00000010	/* PB[1] pin */
  #define SYSCFG_EXTICR1_EXTI1_PC   0x00000020	/* PC[1] pin */
  #define SYSCFG_EXTICR1_EXTI1_PD   0x00000030	/* PD[1] pin */
  #define SYSCFG_EXTICR1_EXTI1_PE   0x00000040	/* PE[1] pin */
  #define SYSCFG_EXTICR1_EXTI1_PF   0x00000050	/* PF[1] pin */
  #define SYSCFG_EXTICR1_EXTI1_PG   0x00000060	/* PG[1] pin */
  #define SYSCFG_EXTICR1_EXTI1_PH   0x00000070	/* PH[1] pin */
  #define SYSCFG_EXTICR1_EXTI2_PA   0x00000000	/* PA[2] pin */
  #define SYSCFG_EXTICR1_EXTI2_PB   0x00000100	/* PB[2] pin */
  #define SYSCFG_EXTICR1_EXTI2_PC   0x00000200	/* PC[2] pin */
  #define SYSCFG_EXTICR1_EXTI2_PD   0x00000300	/* PD[2] pin */
  #define SYSCFG_EXTICR1_EXTI2_PE   0x00000400	/* PE[2] pin */
  #define SYSCFG_EXTICR1_EXTI2_PF   0x00000500	/* PF[2] pin */
  #define SYSCFG_EXTICR1_EXTI2_PG   0x00000600	/* PG[2] pin */
  #define SYSCFG_EXTICR1_EXTI3_PA   0x00000000	/* PA[3] pin */
  #define SYSCFG_EXTICR1_EXTI3_PB   0x00001000	/* PB[3] pin */
  #define SYSCFG_EXTICR1_EXTI3_PC   0x00002000	/* PC[3] pin */
  #define SYSCFG_EXTICR1_EXTI3_PD   0x00003000	/* PD[3] pin */
  #define SYSCFG_EXTICR1_EXTI3_PE   0x00004000	/* PE[3] pin */
  #define SYSCFG_EXTICR1_EXTI3_PF   0x00005000	/* PF[3] pin */
  #define SYSCFG_EXTICR1_EXTI3_PG   0x00006000	/* PG[3] pin */
#define TOFF_SYSCFG_EXTICR2 0x000C		/* (RW) SYSCFG external interrupt configuration registers 2 */
  #define SYSCFG_EXTICR2_EXTI4  0x00000007	/* EXTI 4 configuration */
  #define SYSCFG_EXTICR2_EXTI5  0x00000070	/* EXTI 5 configuration */
  #define SYSCFG_EXTICR2_EXTI6  0x00000700	/* EXTI 6 configuration */
  #define SYSCFG_EXTICR2_EXTI7  0x00007000	/* EXTI 7 configuration */
  #define SYSCFG_EXTICR2_EXTI4_PA   0x00000000	/* PA[4] pin */
  #define SYSCFG_EXTICR2_EXTI4_PB   0x00000001	/* PB[4] pin */
  #define SYSCFG_EXTICR2_EXTI4_PC   0x00000002	/* PC[4] pin */
  #define SYSCFG_EXTICR2_EXTI4_PD   0x00000003	/* PD[4] pin */
  #define SYSCFG_EXTICR2_EXTI4_PE   0x00000004	/* PE[4] pin */
  #define SYSCFG_EXTICR2_EXTI4_PF   0x00000005	/* PF[4] pin */
  #define SYSCFG_EXTICR2_EXTI4_PG   0x00000006	/* PG[4] pin */
  #define SYSCFG_EXTICR2_EXTI5_PA   0x00000000	/* PA[5] pin */
  #define SYSCFG_EXTICR2_EXTI5_PB   0x00000010	/* PB[5] pin */
  #define SYSCFG_EXTICR2_EXTI5_PC   0x00000020	/* PC[5] pin */
  #define SYSCFG_EXTICR2_EXTI5_PD   0x00000030	/* PD[5] pin */
  #define SYSCFG_EXTICR2_EXTI5_PE   0x00000040	/* PE[5] pin */
  #define SYSCFG_EXTICR2_EXTI5_PF   0x00000050	/* PF[5] pin */
  #define SYSCFG_EXTICR2_EXTI5_PG   0x00000060	/* PG[5] pin */
  #define SYSCFG_EXTICR2_EXTI6_PA   0x00000000	/* PA[6] pin */
  #define SYSCFG_EXTICR2_EXTI6_PB   0x00000100	/* PB[6] pin */
  #define SYSCFG_EXTICR2_EXTI6_PC   0x00000200	/* PC[6] pin */
  #define SYSCFG_EXTICR2_EXTI6_PD   0x00000300	/* PD[6] pin */
  #define SYSCFG_EXTICR2_EXTI6_PE   0x00000400	/* PE[6] pin */
  #define SYSCFG_EXTICR2_EXTI6_PF   0x00000500	/* PF[6] pin */
  #define SYSCFG_EXTICR2_EXTI6_PG   0x00000600	/* PG[6] pin */
  #define SYSCFG_EXTICR2_EXTI7_PA   0x00000000	/* PA[7] pin */
  #define SYSCFG_EXTICR2_EXTI7_PB   0x00001000	/* PB[7] pin */
  #define SYSCFG_EXTICR2_EXTI7_PC   0x00002000	/* PC[7] pin */
  #define SYSCFG_EXTICR2_EXTI7_PD   0x00003000	/* PD[7] pin */
  #define SYSCFG_EXTICR2_EXTI7_PE   0x00004000	/* PE[7] pin */
  #define SYSCFG_EXTICR2_EXTI7_PF   0x00005000	/* PF[7] pin */
  #define SYSCFG_EXTICR2_EXTI7_PG   0x00006000	/* PG[7] pin */
#define TOFF_SYSCFG_EXTICR3 0x0010		/* (RW) SYSCFG external interrupt configuration registers 3 */
  #define SYSCFG_EXTICR3_EXTI8  0x00000007	/* EXTI 8 configuration */
  #define SYSCFG_EXTICR3_EXTI9  0x00000070	/* EXTI 9 configuration */
  #define SYSCFG_EXTICR3_EXTI10 0x00000700	/* EXTI 10 configuration */
  #define SYSCFG_EXTICR3_EXTI11 0x00007000	/* EXTI 11 configuration */
  #define SYSCFG_EXTICR3_EXTI8_PA   0x00000000	/* PA[8] pin */
  #define SYSCFG_EXTICR3_EXTI8_PB   0x00000001	/* PB[8] pin */
  #define SYSCFG_EXTICR3_EXTI8_PC   0x00000002	/* PC[8] pin */
  #define SYSCFG_EXTICR3_EXTI8_PD   0x00000003	/* PD[8] pin */
  #define SYSCFG_EXTICR3_EXTI8_PE   0x00000004	/* PE[8] pin */
  #define SYSCFG_EXTICR3_EXTI8_PF   0x00000005	/* PF[8] pin */
  #define SYSCFG_EXTICR3_EXTI8_PG   0x00000006	/* PG[8] pin */
  #define SYSCFG_EXTICR3_EXTI9_PA   0x00000000	/* PA[9] pin */
  #define SYSCFG_EXTICR3_EXTI9_PB   0x00000010	/* PB[9] pin */
  #define SYSCFG_EXTICR3_EXTI9_PC   0x00000020	/* PC[9] pin */
  #define SYSCFG_EXTICR3_EXTI9_PD   0x00000030	/* PD[9] pin */
  #define SYSCFG_EXTICR3_EXTI9_PE   0x00000040	/* PE[9] pin */
  #define SYSCFG_EXTICR3_EXTI9_PF   0x00000050	/* PF[9] pin */
  #define SYSCFG_EXTICR3_EXTI9_PG   0x00000060	/* PG[9] pin */
  #define SYSCFG_EXTICR3_EXTI10_PA  0x00000000	/* PA[10] pin */
  #define SYSCFG_EXTICR3_EXTI10_PB  0x00000100	/* PB[10] pin */
  #define SYSCFG_EXTICR3_EXTI10_PC  0x00000200	/* PC[10] pin */
  #define SYSCFG_EXTICR3_EXTI10_PD  0x00000300	/* PD[10] pin */
  #define SYSCFG_EXTICR3_EXTI10_PE  0x00000400	/* PE[10] pin */
  #define SYSCFG_EXTICR3_EXTI10_PF  0x00000500	/* PF[10] pin */
  #define SYSCFG_EXTICR3_EXTI10_PG  0x00000600	/* PG[10] pin */
  #define SYSCFG_EXTICR3_EXTI11_PA  0x00000000	/* PA[11] pin */
  #define SYSCFG_EXTICR3_EXTI11_PB  0x00001000	/* PB[11] pin */
  #define SYSCFG_EXTICR3_EXTI11_PC  0x00002000	/* PC[11] pin */
  #define SYSCFG_EXTICR3_EXTI11_PD  0x00003000	/* PD[11] pin */
  #define SYSCFG_EXTICR3_EXTI11_PE  0x00004000	/* PE[11] pin */
  #define SYSCFG_EXTICR3_EXTI11_PF  0x00005000	/* PF[11] pin */
  #define SYSCFG_EXTICR3_EXTI11_PG  0x00006000	/* PG[11] pin */
#define TOFF_SYSCFG_EXTICR4 0x0018		/* (RW) SYSCFG external interrupt configuration registers 4 */
  #define SYSCFG_EXTICR4_EXTI12 0x00000007	/* EXTI 12 configuration */
  #define SYSCFG_EXTICR4_EXTI13 0x00000070	/* EXTI 13 configuration */
  #define SYSCFG_EXTICR4_EXTI14 0x00000700	/* EXTI 14 configuration */
  #define SYSCFG_EXTICR4_EXTI15 0x00007000	/* EXTI 15 configuration */
  #define SYSCFG_EXTICR4_EXTI12_PA  0x00000000	/* PA[12] pin */
  #define SYSCFG_EXTICR4_EXTI12_PB  0x00000001	/* PB[12] pin */
  #define SYSCFG_EXTICR4_EXTI12_PC  0x00000002	/* PC[12] pin */
  #define SYSCFG_EXTICR4_EXTI12_PD  0x00000003	/* PD[12] pin */
  #define SYSCFG_EXTICR4_EXTI12_PE  0x00000004	/* PE[12] pin */
  #define SYSCFG_EXTICR4_EXTI12_PF  0x00000005	/* PF[12] pin */
  #define SYSCFG_EXTICR4_EXTI12_PG  0x00000006	/* PG[12] pin */
  #define SYSCFG_EXTICR4_EXTI13_PA  0x00000000	/* PA[13] pin */
  #define SYSCFG_EXTICR4_EXTI13_PB  0x00000010	/* PB[13] pin */
  #define SYSCFG_EXTICR4_EXTI13_PC  0x00000020	/* PC[13] pin */
  #define SYSCFG_EXTICR4_EXTI13_PD  0x00000030	/* PD[13] pin */
  #define SYSCFG_EXTICR4_EXTI13_PE  0x00000040	/* PE[13] pin */
  #define SYSCFG_EXTICR4_EXTI13_PF  0x00000050	/* PF[13] pin */
  #define SYSCFG_EXTICR4_EXTI13_PG  0x00000060	/* PG[13] pin */
  #define SYSCFG_EXTICR4_EXTI14_PA  0x00000000	/* PA[14] pin */
  #define SYSCFG_EXTICR4_EXTI14_PB  0x00000100	/* PB[14] pin */
  #define SYSCFG_EXTICR4_EXTI14_PC  0x00000200	/* PC[14] pin */
  #define SYSCFG_EXTICR4_EXTI14_PD  0x00000300	/* PD[14] pin */
  #define SYSCFG_EXTICR4_EXTI14_PE  0x00000400	/* PE[14] pin */
  #define SYSCFG_EXTICR4_EXTI14_PF  0x00000500	/* PF[14] pin */
  #define SYSCFG_EXTICR4_EXTI14_PG  0x00000600	/* PG[14] pin */
  #define SYSCFG_EXTICR4_EXTI15_PA  0x00000000	/* PA[15] pin */
  #define SYSCFG_EXTICR4_EXTI15_PB  0x00001000	/* PB[15] pin */
  #define SYSCFG_EXTICR4_EXTI15_PC  0x00002000	/* PC[15] pin */
  #define SYSCFG_EXTICR4_EXTI15_PD  0x00003000	/* PD[15] pin */
  #define SYSCFG_EXTICR4_EXTI15_PE  0x00004000	/* PE[15] pin */
  #define SYSCFG_EXTICR4_EXTI15_PF  0x00005000	/* PF[15] pin */
  #define SYSCFG_EXTICR4_EXTI15_PG  0x00006000	/* PG[15] pin */
#define TOFF_SYSCFG_SCSR    0x0018		/* (RW) SYSCFG SRAM2 control and status register */
  #define SYSCFG_SCSR_SRAM2ER   0x00000001	/* SRAM2 Erase Request */
  #define SYSCFG_SCSR_SRAM2BSY  0x00000002	/* SRAM2 Erase Ongoing */
#define TOFF_SYSCFG_CFGR2   0x001C		/* (RW) SYSCFG configuration register 2 */
  #define SYSCFG_CFGR2_CLL   0x00000001	/* Core Lockup Lock */
  #define SYSCFG_CFGR2_SPL   0x00000002	/* SRAM Parity Lock*/
  #define SYSCFG_CFGR2_PVDL  0x00000004	/* PVD Lock */
  #define SYSCFG_CFGR2_ECCL  0x00000008	/* ECC Lock*/
  #define SYSCFG_CFGR2_SPF   0x00000100	/* SRAM Parity Flag */
#define TOFF_SYSCFG_SWPR    0x0020		/* (RW) SYSCFG SRAM2 write protection register */
  #define SYSCFG_SWPR_PAGE0  0x00000001	/* SRAM2 Write protection page 0 */
  #define SYSCFG_SWPR_PAGE1  0x00000002	/* SRAM2 Write protection page 1 */
  #define SYSCFG_SWPR_PAGE2  0x00000004	/* SRAM2 Write protection page 2 */
  #define SYSCFG_SWPR_PAGE3  0x00000008	/* SRAM2 Write protection page 3 */
  #define SYSCFG_SWPR_PAGE4  0x00000010	/* SRAM2 Write protection page 4 */
  #define SYSCFG_SWPR_PAGE5  0x00000020	/* SRAM2 Write protection page 5 */
  #define SYSCFG_SWPR_PAGE6  0x00000040	/* SRAM2 Write protection page 6 */
  #define SYSCFG_SWPR_PAGE7  0x00000080	/* SRAM2 Write protection page 7 */
  #define SYSCFG_SWPR_PAGE8  0x00000100	/* SRAM2 Write protection page 8 */
  #define SYSCFG_SWPR_PAGE9  0x00000200	/* SRAM2 Write protection page 9 */
  #define SYSCFG_SWPR_PAGE10 0x00000400	/* SRAM2 Write protection page 10*/
  #define SYSCFG_SWPR_PAGE11 0x00000800	/* SRAM2 Write protection page 11*/
  #define SYSCFG_SWPR_PAGE12 0x00001000	/* SRAM2 Write protection page 12*/
  #define SYSCFG_SWPR_PAGE13 0x00002000	/* SRAM2 Write protection page 13*/
  #define SYSCFG_SWPR_PAGE14 0x00004000	/* SRAM2 Write protection page 14*/
  #define SYSCFG_SWPR_PAGE15 0x00008000	/* SRAM2 Write protection page 15*/
  #define SYSCFG_SWPR_PAGE16 0x00010000	/* SRAM2 Write protection page 16*/
  #define SYSCFG_SWPR_PAGE17 0x00020000	/* SRAM2 Write protection page 17*/
  #define SYSCFG_SWPR_PAGE18 0x00040000	/* SRAM2 Write protection page 18*/
  #define SYSCFG_SWPR_PAGE19 0x00080000	/* SRAM2 Write protection page 19*/
  #define SYSCFG_SWPR_PAGE20 0x00100000	/* SRAM2 Write protection page 20*/
  #define SYSCFG_SWPR_PAGE21 0x00200000	/* SRAM2 Write protection page 21*/
  #define SYSCFG_SWPR_PAGE22 0x00400000	/* SRAM2 Write protection page 22*/
  #define SYSCFG_SWPR_PAGE23 0x00800000	/* SRAM2 Write protection page 23*/
  #define SYSCFG_SWPR_PAGE24 0x01000000	/* SRAM2 Write protection page 24*/
  #define SYSCFG_SWPR_PAGE25 0x02000000	/* SRAM2 Write protection page 25*/
  #define SYSCFG_SWPR_PAGE26 0x04000000	/* SRAM2 Write protection page 26*/
  #define SYSCFG_SWPR_PAGE27 0x08000000	/* SRAM2 Write protection page 27*/
  #define SYSCFG_SWPR_PAGE28 0x10000000	/* SRAM2 Write protection page 28*/
  #define SYSCFG_SWPR_PAGE29 0x20000000	/* SRAM2 Write protection page 29*/
  #define SYSCFG_SWPR_PAGE30 0x40000000	/* SRAM2 Write protection page 30*/
  #define SYSCFG_SWPR_PAGE31 0x80000000	/* SRAM2 Write protection page 31*/
#define TOFF_SYSCFG_SKR     0x0024		/* (RW) SYSCFG SRAM2 key register */
  #define SYSCFG_SKR_KEY     0x000000FF	/* SRAM2 write protection key for software erase  */


/*
 *  VREFBUF
 */
#define TADR_VREFBUF_BASE   (APB2PERIPH_BASE + 0x0030)
#define TOFF_VREFBUF_CSR    0x0000		/* (RW) VREFBUF control and status register */
  #define VREFBUF_CSR_ENVR   0x00000001	/* Voltage reference buffer enable */
  #define VREFBUF_CSR_HIZ    0x00000002	/* High impedance mode */
  #define VREFBUF_CSR_VRS    0x00000004	/* Voltage reference scale */
  #define VREFBUF_CSR_VRR    0x00000008	/* Voltage reference buffer ready  */
#define TOFF_VREFBUF_CCR    0x0004		/* (RW) VREFBUF calibration and control register */
  #define VREFBUF_CCR_TRIM   0x0000003F	/* TRIM[5:0] bits (Trimming code)  */


/*
 *  COMPARATOR
 */
#define TADR_COMP1_BASE     (APB2PERIPH_BASE + 0x0200)
#define TADR_COMP2_BASE     (APB2PERIPH_BASE + 0x0204)
#define TADR_COMP12_COMMON_BASE (TADR_COMP2_BASE)
#define TOFF_COMP_CSR       0x0000		/* (RW) COMP control and status register */
  #define COMP_CSR_EN        0x00000001	/* Comparator enable */
  #define COMP_CSR_PWRMODE   0x0000000C	/* Comparator power mode */
  #define COMP_CSR_PWRMODE_0 0x00000004
  #define COMP_CSR_PWRMODE_1 0x00000008
  #define COMP_CSR_INMSEL    0x00000070	/* Comparator input minus selection */
  #define COMP_CSR_INMSEL_0  0x00000010
  #define COMP_CSR_INMSEL_1  0x00000020
  #define COMP_CSR_INMSEL_2  0x00000040
  #define COMP_CSR_INPSEL    0x00000080	/* Comparator input plus selection */
  #define COMP_CSR_INPSEL_0  0x00000080
  #define COMP_CSR_WINMODE   0x00000200	/* Pair of comparators window mode. Bit intended to be used with COMP common instance (COMP_Common_TypeDef)  */
  #define COMP_CSR_POLARITY  0x00008000	/* Comparator output polarity */
  #define COMP_CSR_HYST      0x00030000	/* Comparator hysteresis */
  #define COMP_CSR_HYST_0    0x00010000
  #define COMP_CSR_HYST_1    0x00020000
  #define COMP_CSR_BLANKING  0x001C0000	/* Comparator blanking source */
  #define COMP_CSR_BLANKING_0 0x00040000
  #define COMP_CSR_BLANKING_1 0x00080000
  #define COMP_CSR_BLANKING_2 0x00100000
  #define COMP_CSR_BRGEN     0x00400000	/* Comparator voltage scaler enable */
  #define COMP_CSR_SCALEN    0x00800000	/* Comparator scaler bridge enable */
  #define COMP_CSR_VALUE     0x40000000	/* Comparator output level */
  #define COMP_CSR_LOCK      0x80000000	/* Comparator lock */


/*
 *  EXTERNAL INTERRUPT/EVENT CONTROLLER
 */
#define TADR_EXTI_BASE      (APB2PERIPH_BASE + 0x0400)
#define TOFF_EXTI_IMR1      0x0000		/* (RW) EXTI Interrupt mask register */
#define TOFF_EXTI_IMR       TOFF_EXTI_IMR1
  #define EXTI_IMR_MR0       0x00000001	/* Interrupt Mask on line 0 */
  #define EXTI_IMR_MR1       0x00000002	/* Interrupt Mask on line 1 */
  #define EXTI_IMR_MR2       0x00000004	/* Interrupt Mask on line 2 */
  #define EXTI_IMR_MR3       0x00000008	/* Interrupt Mask on line 3 */
  #define EXTI_IMR_MR4       0x00000010	/* Interrupt Mask on line 4 */
  #define EXTI_IMR_MR5       0x00000020	/* Interrupt Mask on line 5 */
  #define EXTI_IMR_MR6       0x00000040	/* Interrupt Mask on line 6 */
  #define EXTI_IMR_MR7       0x00000080	/* Interrupt Mask on line 7 */
  #define EXTI_IMR_MR8       0x00000100	/* Interrupt Mask on line 8 */
  #define EXTI_IMR_MR9       0x00000200	/* Interrupt Mask on line 9 */
  #define EXTI_IMR_MR10      0x00000400	/* Interrupt Mask on line 10 */
  #define EXTI_IMR_MR11      0x00000800	/* Interrupt Mask on line 11 */
  #define EXTI_IMR_MR12      0x00001000	/* Interrupt Mask on line 12 */
  #define EXTI_IMR_MR13      0x00002000	/* Interrupt Mask on line 13 */
  #define EXTI_IMR_MR14      0x00004000	/* Interrupt Mask on line 14 */
  #define EXTI_IMR_MR15      0x00008000	/* Interrupt Mask on line 15 */
  #define EXTI_IMR_MR16      0x00010000	/* Interrupt Mask on line 16 */
  #define EXTI_IMR_MR17      0x00020000	/* Interrupt Mask on line 17 */
  #define EXTI_IMR_MR18      0x00040000	/* Interrupt Mask on line 18 */
  #define EXTI_IMR_MR19      0x00080000	/* Interrupt Mask on line 19 */
  #define EXTI_IMR_MR20      0x00100000	/* Interrupt Mask on line 20 */
  #define EXTI_IMR_MR21      0x00200000	/* Interrupt Mask on line 21 */
  #define EXTI_IMR_MR22      0x00400000	/* Interrupt Mask on line 22 */
  #define EXTI_IMR_MR23      0x00800000	/* Interrupt Mask on line 23 */
  #define EXTI_IMR_MR25      0x02000000	/* Interrupt Mask on line 25 */
  #define EXTI_IMR_MR26      0x04000000	/* Interrupt Mask on line 26 */
  #define EXTI_IMR_MR27      0x08000000	/* Interrupt Mask on line 27 */
  #define EXTI_IMR_MR28      0x10000000	/* Interrupt Mask on line 28 */
  #define EXTI_IMR_MR31      0x80000000	/* Interrupt Mask on line 31 */
#define TOFF_EXTI_EMR1      0x0004		/* (RW) EXTI Event mask register */
  #define EXTI_EMR_MR0       0x00000001	/* Event Mask on line 0  */
  #define EXTI_EMR_MR1       0x00000002	/* Event Mask on line 1  */
  #define EXTI_EMR_MR2       0x00000004	/* Event Mask on line 2  */
  #define EXTI_EMR_MR3       0x00000008	/* Event Mask on line 3  */
  #define EXTI_EMR_MR4       0x00000010	/* Event Mask on line 4  */
  #define EXTI_EMR_MR5       0x00000020	/* Event Mask on line 5  */
  #define EXTI_EMR_MR6       0x00000040	/* Event Mask on line 6  */
  #define EXTI_EMR_MR7       0x00000080	/* Event Mask on line 7  */
  #define EXTI_EMR_MR8       0x00000100	/* Event Mask on line 8  */
  #define EXTI_EMR_MR9       0x00000200	/* Event Mask on line 9  */
  #define EXTI_EMR_MR10      0x00000400	/* Event Mask on line 10 */
  #define EXTI_EMR_MR11      0x00000800	/* Event Mask on line 11 */
  #define EXTI_EMR_MR12      0x00001000	/* Event Mask on line 12 */
  #define EXTI_EMR_MR13      0x00002000	/* Event Mask on line 13 */
  #define EXTI_EMR_MR14      0x00004000	/* Event Mask on line 14 */
  #define EXTI_EMR_MR15      0x00008000	/* Event Mask on line 15 */
  #define EXTI_EMR_MR16      0x00010000	/* Event Mask on line 16 */
  #define EXTI_EMR_MR17      0x00020000	/* Event Mask on line 17 */
  #define EXTI_EMR_MR18      0x00040000	/* Event Mask on line 18 */
  #define EXTI_EMR_MR19      0x00080000	/* Event Mask on line 19 */
  #define EXTI_EMR_MR20      0x00100000	/* Event Mask on line 20 */
  #define EXTI_EMR_MR21      0x00200000	/* Event Mask on line 21 */
  #define EXTI_EMR_MR22      0x00400000	/* Event Mask on line 22 */
  #define EXTI_EMR_MR23      0x00800000	/* Event Mask on line 23 */
  #define EXTI_EMR_MR25      0x02000000	/* Event Mask on line 25 */
  #define EXTI_EMR_MR26      0x04000000	/* Event Mask on line 26 */
  #define EXTI_EMR_MR27      0x08000000	/* Event Mask on line 27 */
  #define EXTI_EMR_MR28      0x10000000	/* Event Mask on line 28 */
  #define EXTI_EMR_MR31      0x80000000	/* Event Mask on line 31 */
#define TOFF_EXTI_RTSR1     0x0008		/* (RW) EXTI Rising trigger selection register */
#define TOFF_EXTI_RTSR      TOFF_EXTI_RTSR1
  #define EXTI_RTSR_TR0      0x00000001	/* Rising trigger event configuration bit of line 0 */
  #define EXTI_RTSR_TR1      0x00000002	/* Rising trigger event configuration bit of line 1 */
  #define EXTI_RTSR_TR2      0x00000004	/* Rising trigger event configuration bit of line 2 */
  #define EXTI_RTSR_TR3      0x00000008	/* Rising trigger event configuration bit of line 3 */
  #define EXTI_RTSR_TR4      0x00000010	/* Rising trigger event configuration bit of line 4 */
  #define EXTI_RTSR_TR5      0x00000020	/* Rising trigger event configuration bit of line 5 */
  #define EXTI_RTSR_TR6      0x00000040	/* Rising trigger event configuration bit of line 6 */
  #define EXTI_RTSR_TR7      0x00000080	/* Rising trigger event configuration bit of line 7 */
  #define EXTI_RTSR_TR8      0x00000100	/* Rising trigger event configuration bit of line 8 */
  #define EXTI_RTSR_TR9      0x00000200	/* Rising trigger event configuration bit of line 9 */
  #define EXTI_RTSR_TR10     0x00000400	/* Rising trigger event configuration bit of line 10 */
  #define EXTI_RTSR_TR11     0x00000800	/* Rising trigger event configuration bit of line 11 */
  #define EXTI_RTSR_TR12     0x00001000	/* Rising trigger event configuration bit of line 12 */
  #define EXTI_RTSR_TR13     0x00002000	/* Rising trigger event configuration bit of line 13 */
  #define EXTI_RTSR_TR14     0x00004000	/* Rising trigger event configuration bit of line 14 */
  #define EXTI_RTSR_TR15     0x00008000	/* Rising trigger event configuration bit of line 15 */
  #define EXTI_RTSR_TR16     0x00010000	/* Rising trigger event configuration bit of line 16 */
  #define EXTI_RTSR_TR17     0x00020000	/* Rising trigger event configuration bit of line 17 */
  #define EXTI_RTSR_TR18     0x00040000	/* Rising trigger event configuration bit of line 18 */
  #define EXTI_RTSR_TR19     0x00080000	/* Rising trigger event configuration bit of line 19 */
  #define EXTI_RTSR_TR20     0x00100000	/* Rising trigger event configuration bit of line 20 */
  #define EXTI_RTSR_TR21     0x00200000	/* Rising trigger event configuration bit of line 21 */
  #define EXTI_RTSR_TR22     0x00400000	/* Rising trigger event configuration bit of line 22 */
  #define EXTI_RTSR_TR31     0x80000000	/* Rising trigger event configuration bit of line 31 */
#define TOFF_EXTI_FTSR1     0x000C		/* (RW) EXTI Falling trigger selection register */
#define TOFF_EXTI_FTSR      TOFF_EXTI_FTSR1
  #define EXTI_FTSR_TR0      0x00000001	/* Falling trigger event configuration bit of line 0 */
  #define EXTI_FTSR_TR1      0x00000002	/* Falling trigger event configuration bit of line 1 */
  #define EXTI_FTSR_TR2      0x00000004	/* Falling trigger event configuration bit of line 2 */
  #define EXTI_FTSR_TR3      0x00000008	/* Falling trigger event configuration bit of line 3 */
  #define EXTI_FTSR_TR4      0x00000010	/* Falling trigger event configuration bit of line 4 */
  #define EXTI_FTSR_TR5      0x00000020	/* Falling trigger event configuration bit of line 5 */
  #define EXTI_FTSR_TR6      0x00000040	/* Falling trigger event configuration bit of line 6 */
  #define EXTI_FTSR_TR7      0x00000080	/* Falling trigger event configuration bit of line 7 */
  #define EXTI_FTSR_TR8      0x00000100	/* Falling trigger event configuration bit of line 8 */
  #define EXTI_FTSR_TR9      0x00000200	/* Falling trigger event configuration bit of line 9 */
  #define EXTI_FTSR_TR10     0x00000400	/* Falling trigger event configuration bit of line 10 */
  #define EXTI_FTSR_TR11     0x00000800	/* Falling trigger event configuration bit of line 11 */
  #define EXTI_FTSR_TR12     0x00001000	/* Falling trigger event configuration bit of line 12 */
  #define EXTI_FTSR_TR13     0x00002000	/* Falling trigger event configuration bit of line 13 */
  #define EXTI_FTSR_TR14     0x00004000	/* Falling trigger event configuration bit of line 14 */
  #define EXTI_FTSR_TR15     0x00008000	/* Falling trigger event configuration bit of line 15 */
  #define EXTI_FTSR_TR16     0x00010000	/* Falling trigger event configuration bit of line 16 */
  #define EXTI_FTSR_TR17     0x00020000	/* Falling trigger event configuration bit of line 17 */
  #define EXTI_FTSR_TR18     0x00040000	/* Falling trigger event configuration bit of line 18 */
  #define EXTI_FTSR_TR19     0x00080000	/* Falling trigger event configuration bit of line 19 */
  #define EXTI_FTSR_TR20     0x00100000	/* Falling trigger event configuration bit of line 20 */
  #define EXTI_FTSR_TR21     0x00200000	/* Falling trigger event configuration bit of line 21 */
  #define EXTI_FTSR_TR22     0x00400000	/* Falling trigger event configuration bit of line 22 */
  #define EXTI_FTSR_TR31     0x80000000	/* Falling trigger event configuration bit of line 31 */
#define TOFF_EXTI_SWIER1    0x0010		/* (RW) EXTI Software interrupt event register */
  #define EXTI_SWIER_SWIER0  0x00000000	/* Software Interrupt on line 0  */
  #define EXTI_SWIER_SWIER1  0x00000002	/* Software Interrupt on line 1  */
  #define EXTI_SWIER_SWIER2  0x00000004	/* Software Interrupt on line 2  */
  #define EXTI_SWIER_SWIER3  0x00000008	/* Software Interrupt on line 3  */
  #define EXTI_SWIER_SWIER4  0x00000010	/* Software Interrupt on line 4  */
  #define EXTI_SWIER_SWIER5  0x00000020	/* Software Interrupt on line 5  */
  #define EXTI_SWIER_SWIER6  0x00000040	/* Software Interrupt on line 6  */
  #define EXTI_SWIER_SWIER7  0x00000080	/* Software Interrupt on line 7  */
  #define EXTI_SWIER_SWIER8  0x00000100	/* Software Interrupt on line 8  */
  #define EXTI_SWIER_SWIER9  0x00000200	/* Software Interrupt on line 9  */
  #define EXTI_SWIER_SWIER10 0x00000400	/* Software Interrupt on line 10 */
  #define EXTI_SWIER_SWIER11 0x00000800	/* Software Interrupt on line 11 */
  #define EXTI_SWIER_SWIER12 0x00001000	/* Software Interrupt on line 12 */
  #define EXTI_SWIER_SWIER13 0x00002000	/* Software Interrupt on line 13 */
  #define EXTI_SWIER_SWIER14 0x00004000	/* Software Interrupt on line 14 */
  #define EXTI_SWIER_SWIER15 0x00008000	/* Software Interrupt on line 15 */
  #define EXTI_SWIER_SWIER16 0x00010000	/* Software Interrupt on line 16 */
  #define EXTI_SWIER_SWIER17 0x00020000	/* Software Interrupt on line 17 */
  #define EXTI_SWIER_SWIER19 0x00080000	/* Software Interrupt on line 19 */
  #define EXTI_SWIER_SWIER20 0x00100000	/* Software Interrupt on line 20 */
  #define EXTI_SWIER_SWIER21 0x00200000	/* Software Interrupt on line 21 */
  #define EXTI_SWIER_SWIER22 0x00400000	/* Software Interrupt on line 22 */
  #define EXTI_SWIER_SWIER31 0x80000000	/* Software Interrupt on line 31 */
#define TOFF_EXTI_PR1       0x0014		/* (RW) EXTI Pending register */
#define TOFF_EXTI_PR        TOFF_EXTI_PR1
  #define EXTI_PR_PR0        0x00000001	/* Pending bit for line 0 */
  #define EXTI_PR_PR1        0x00000002	/* Pending bit for line 1 */
  #define EXTI_PR_PR2        0x00000004	/* Pending bit for line 2 */
  #define EXTI_PR_PR3        0x00000008	/* Pending bit for line 3 */
  #define EXTI_PR_PR4        0x00000010	/* Pending bit for line 4 */
  #define EXTI_PR_PR5        0x00000020	/* Pending bit for line 5 */
  #define EXTI_PR_PR6        0x00000040	/* Pending bit for line 6 */
  #define EXTI_PR_PR7        0x00000080	/* Pending bit for line 7 */
  #define EXTI_PR_PR8        0x00000100	/* Pending bit for line 8 */
  #define EXTI_PR_PR9        0x00000200	/* Pending bit for line 9 */
  #define EXTI_PR_PR10       0x00000400	/* Pending bit for line 10 */
  #define EXTI_PR_PR11       0x00000800	/* Pending bit for line 11 */
  #define EXTI_PR_PR12       0x00001000	/* Pending bit for line 12 */
  #define EXTI_PR_PR13       0x00002000	/* Pending bit for line 13 */
  #define EXTI_PR_PR14       0x00004000	/* Pending bit for line 14 */
  #define EXTI_PR_PR15       0x00008000	/* Pending bit for line 15 */
  #define EXTI_PR_PR16       0x00010000	/* Pending bit for line 16 */
  #define EXTI_PR_PR17       0x00020000	/* Pending bit for line 17 */
  #define EXTI_PR_PR18       0x00040000	/* Pending bit for line 18 */
  #define EXTI_PR_PR19       0x00080000	/* Pending bit for line 19 */
  #define EXTI_PR_PR20       0x00100000	/* Pending bit for line 20 */
  #define EXTI_PR_PR21       0x00200000	/* Pending bit for line 21 */
  #define EXTI_PR_PR22       0x00400000	/* Pending bit for line 22 */
  #define EXTI_PR_PR31       0x80000000	/* Pending bit for line 31 */
#define TOFF_EXTI_IMR2      0x0020		/* (RW) EXTI Interrupt mask register 2 */
#define TOFF_EXTI_EMR2      0x0024		/* (RW) EXTI Event mask register 2 */
#define TOFF_EXTI_RTSR2     0x0028		/* (RW) EXTI Rising trigger selection register 2 */
#define TOFF_EXTI_FTSR2     0x002C		/* (RW) EXTI Falling trigger selection register 2 */
#define TOFF_EXTI_SWIER2    0x0030		/* (RW) EXTI Software interrupt event register 2 */
#define TOFF_EXTI_PR2       0x0034		/* (RW) EXTI Pending register 2 */


/*
 *  FIREWALL
 */
#define TADR_FIREWALL_BASE  (APB2PERIPH_BASE + 0x1C00)
#define TOFF_FW_CSSA        0x0000		/* (RW) Code Segment Start Address register */
  #define FW_CSSA_ADD        0x00FFFF00	/* Code Segment Start Address */
#define TOFF_FW_CSL         0x0004		/* (RW) Code Segment Length register */
  #define FW_CSL_LENG        0x003FFF00	/* Code Segment Length */
#define TOFF_FW_NVDSSA      0x0008		/* (RW) NON volatile data Segment Start Address register */
  #define FW_NVDSSA_ADD      0x00FFFF00	/* Non Volatile Dat Segment Start Address */ 
#define TOFF_FW_NVDSL       0x000C		/* (RW) NON volatile data Segment Length register */
  #define FW_NVDSL_LENG      0x003FFF00	/* Non Volatile Data Segment Length */
#define TOFF_FW_VDSSA       0x0010		/* (RW) Volatile data Segment Start Address register */
  #define FW_VDSSA_ADD       0x0000FFC0	/* Volatile Data Segment Start Address */ 
#define TOFF_FW_VDSL        0x0014		/* (RW) Volatile data Segment Length register */
  #define FW_VDSL_LENG       0x0000FFC0	/* Volatile Data Segment Length */ 
#define TOFF_FW_CR          0x0020		/* (RW) Configuration  register */
  #define FW_CR_FPA          0x00000001	/* Firewall Pre Arm*/
  #define FW_CR_VDS          0x00000002	/* Volatile Data Sharing*/
  #define FW_CR_VDE          0x00000004	/* Volatile Data Execution*/


/*
 *  SD HOST INTERFACE
 */
#if !defined(TOPPERS_STM32L476_DISCOVERY) && !defined(TOPPERS_STM32L476_NUCLEO64)
#define TADR_SDMMC1_BASE    (APB2PERIPH_BASE + 0x08062400)
#else
#define TADR_SDMMC1_BASE    (APB2PERIPH_BASE + 0x2800)
#endif
#define TOFF_SDIO_POWER     0x0000		/* (RW) SDIO power control register */
  #define SDMMC_POWER_PWRCTRL   0x00000003	/* PWRCTRL[1:0] bits (Power supply control bits) */
  #define SDMMC_POWER_PWRCTRL_0 0x00000001	/* Bit 0 */
  #define SDMMC_POWER_PWRCTRL_1 0x00000002	/* Bit 1 */
#define TOFF_SDIO_CLKCR     0x0004		/* (RW) SDI clock control register */
  #define SDMMC_CLKCR_CLKDIV    0x000000FF	/* Clock divide factor             */
  #define SDMMC_CLKCR_CLKEN     0x00000100	/* Clock enable bit                */
  #define SDMMC_CLKCR_PWRSAV    0x00000200	/* Power saving configuration bit  */
  #define SDMMC_CLKCR_BYPASS    0x00000400	/* Clock divider bypass enable bit */
  #define SDMMC_CLKCR_WIDBUS    0x00001800	/* WIDBUS[1:0] bits (Wide bus mode enable bit) */
  #define SDMMC_CLKCR_WIDBUS_0  0x00000800	/* Bit 0 */
  #define SDMMC_CLKCR_WIDBUS_1  0x00001000	/* Bit 1 */
  #define SDMMC_CLKCR_NEGEDGE   0x00002000	/* SDMMC_CK dephasing selection bit */
  #define SDMMC_CLKCR_HWFC_EN   0x00004000	/* HW Flow Control enable          */
#define TOFF_SDIO_ARG       0x0008		/* (RW) SDIO argument register */
#define TOFF_SDIO_CMD       0x000C		/* (RW) SDIO command register */
  #define SDMMC_CMD_CMDINDEX    0x0000003F	/* Command Index                               */
  #define SDMMC_CMD_WAITRESP    0x000000C0	/* WAITRESP[1:0] bits (Wait for response bits) */
  #define SDMMC_CMD_WAITRESP_0  0x00000040	/* Bit 0 */
  #define SDMMC_CMD_WAITRESP_1  0x00000080	/* Bit 1 */
  #define SDMMC_CMD_WAITINT     0x00000100	/* CPSM Waits for Interrupt Request */
  #define SDMMC_CMD_WAITPEND    0x00000200	/* CPSM Waits for ends of data transfer (CmdPend internal signal) */
  #define SDMMC_CMD_CPSMEN      0x00000400	/* Command path state machine (CPSM) Enable bit */
  #define SDMMC_CMD_SDIOSUSPEND 0x00000800	/* SD I/O suspend command */
#define TOFF_SDIO_RESPCMD   0x0010		/* (R)  SDIO command response register */
#define TOFF_SDIO_RESP      0x0014		/* (R)  SDIO response 1 register */
#define TOFF_SDIO_RESP2     0x0018		/* (R)  SDIO response 2 register */
#define TOFF_SDIO_RESP3     0x001C		/* (R)  SDIO response 3 register */
#define TOFF_SDIO_RESP4     0x0020		/* (R)  SDIO response 4 register */
#define TOFF_SDIO_DTIMER    0x0024		/* (RW) SDIO data timer register */
#define TOFF_SDIO_DLEN      0x0028		/* (RW) SDIO data length register */
#define TOFF_SDIO_DCTRL     0x002C		/* (RW) SDIO data control register */
  #define SDMMC_DCTRL_DTEN      0x00000001	/* Data transfer enabled bit */
  #define SDMMC_DCTRL_DTDIR     0x00000002	/* Data transfer direction selection */
  #define SDMMC_DCTRL_DTMODE    0x00000004	/* Data transfer mode selection      */
  #define SDMMC_DCTRL_DMAEN     0x00000008	/* DMA enabled bit                   */
  #define SDMMC_DCTRL_DBLOCKSIZE    0x00F0	/* DBLOCKSIZE[3:0] bits (Data block size) */
  #define SDMMC_DCTRL_DBLOCKSIZE_0  0x0010	/* Bit 0 */
  #define SDMMC_DCTRL_DBLOCKSIZE_1  0x0020	/* Bit 1 */
  #define SDMMC_DCTRL_DBLOCKSIZE_2  0x0040	/* Bit 2 */
  #define SDMMC_DCTRL_DBLOCKSIZE_3  0x0080	/* Bit 3 */
  #define SDMMC_DCTRL_RWSTART   0x00000100	/* Read wait start */
  #define SDMMC_DCTRL_RWSTOP    0x00000200	/* Read wait stop */
  #define SDMMC_DCTRL_RWMOD     0x00000400	/* Read wait mode */
  #define SDMMC_DCTRL_SDIOEN    0x00000800	/* SD I/O enable functions */
#define TOFF_SDIO_DCOUNT    0x0030		/* (R)  SDIO data counter register */
#define TOFF_SDIO_STA       0x0034		/* (R)  SDIO status register */
  #define SDMMC_STA_CCRCFAIL    0x00000001	/* Command response received (CRC check failed)  */
  #define SDMMC_STA_DCRCFAIL    0x00000002	/* Data block sent/received (CRC check failed)   */
  #define SDMMC_STA_CTIMEOUT    0x00000004	/* Command response timeout                      */
  #define SDMMC_STA_DTIMEOUT    0x00000008	/* Data timeout                                  */
  #define SDMMC_STA_TXUNDERR    0x00000010	/* Transmit FIFO underrun error                  */
  #define SDMMC_STA_RXOVERR     0x00000020	/* Received FIFO overrun error                   */
  #define SDMMC_STA_CMDREND     0x00000040	/* Command response received (CRC check passed)  */
  #define SDMMC_STA_CMDSENT     0x00000080	/* Command sent (no response required)           */
  #define SDMMC_STA_DATAEND     0x00000100	/* Data end (data counter, SDIDCOUNT, is zero)   */
  #define SDMMC_STA_STBITERR    0x00000200	/* Start bit not detected on all data signals in wide bus mode */
  #define SDMMC_STA_DBCKEND     0x00000400	/* Data block sent/received (CRC check passed)   */
  #define SDMMC_STA_CMDACT      0x00000800	/* Command transfer in progress                  */
  #define SDMMC_STA_TXACT       0x00001000	/* Data transmit in progress                     */
  #define SDMMC_STA_RXACT       0x00002000	/* Data receive in progress                      */
  #define SDMMC_STA_TXFIFOHE    0x00004000	/* Transmit FIFO Half Empty: at least 8 words can be written into the FIFO */
  #define SDMMC_STA_RXFIFOHF    0x00008000	/* Receive FIFO Half Full: there are at least 8 words in the FIFO */
  #define SDMMC_STA_TXFIFOF     0x00010000	/* Transmit FIFO full */
  #define SDMMC_STA_RXFIFOF     0x00020000	/* Receive FIFO full */
  #define SDMMC_STA_TXFIFOE     0x00040000	/* Transmit FIFO empty */
  #define SDMMC_STA_RXFIFOE     0x00080000	/* Receive FIFO empty */
  #define SDMMC_STA_TXDAVL      0x00100000	/* Data available in transmit FIFO */
  #define SDMMC_STA_RXDAVL      0x00200000	/* Data available in receive FIFO */
  #define SDMMC_STA_SDIOIT      0x00400000	/* SDMMC interrupt received */
#define TOFF_SDIO_ICR       0x0038		/* (RW) SDIO interrupt clear register */
  #define SDMMC_ICR_CCRCFAILC   0x00000001	/* CCRCFAIL flag clear bit */
  #define SDMMC_ICR_DCRCFAILC   0x00000002	/* DCRCFAIL flag clear bit */
  #define SDMMC_ICR_CTIMEOUTC   0x00000004	/* CTIMEOUT flag clear bit */
  #define SDMMC_ICR_DTIMEOUTC   0x00000008	/* DTIMEOUT flag clear bit */
  #define SDMMC_ICR_TXUNDERRC   0x00000010	/* TXUNDERR flag clear bit */
  #define SDMMC_ICR_RXOVERRC    0x00000020	/* RXOVERR flag clear bit  */
  #define SDMMC_ICR_CMDRENDC    0x00000040	/* CMDREND flag clear bit  */
  #define SDMMC_ICR_CMDSENTC    0x00000080	/* CMDSENT flag clear bit  */
  #define SDMMC_ICR_DATAENDC    0x00000100	/* DATAEND flag clear bit  */
  #define SDMMC_ICR_STBITERRC   0x00000200	/* STBITERR flag clear bit */
  #define SDMMC_ICR_DBCKENDC    0x00000400	/* DBCKEND flag clear bit  */
  #define SDMMC_ICR_SDIOITC     0x00400000	/* SDMMCIT flag clear bit   */
#define TOFF_SDIO_MASK      0x003C		/* (RW) SDIO mask register */
  #define SDMMC_MASK_CCRCFAILIE 0x00000001	/* Command CRC Fail Interrupt Enable */
  #define SDMMC_MASK_DCRCFAILIE 0x00000002	/* Data CRC Fail Interrupt Enable */
  #define SDMMC_MASK_CTIMEOUTIE 0x00000004	/* Command TimeOut Interrupt Enable */
  #define SDMMC_MASK_DTIMEOUTIE 0x00000008	/* Data TimeOut Interrupt Enable */
  #define SDMMC_MASK_TXUNDERRIE 0x00000010	/* Tx FIFO UnderRun Error Interrupt Enable */
  #define SDMMC_MASK_RXOVERRIE  0x00000020	/* Rx FIFO OverRun Error Interrupt Enable */
  #define SDMMC_MASK_CMDRENDIE  0x00000040	/* Command Response Received Interrupt Enable */
  #define SDMMC_MASK_CMDSENTIE  0x00000080	/* Command Sent Interrupt Enable */
  #define SDMMC_MASK_DATAENDIE  0x00000100	/* Data End Interrupt Enable */
  #define SDMMC_MASK_DBCKENDIE  0x00000400	/* Data Block End Interrupt Enable */
  #define SDMMC_MASK_CMDACTIE   0x00000800	/* CCommand Acting Interrupt Enable */
  #define SDMMC_MASK_TXACTIE    0x00001000	/* Data Transmit Acting Interrupt Enable */
  #define SDMMC_MASK_RXACTIE    0x00002000	/* Data receive acting interrupt enabled */
  #define SDMMC_MASK_TXFIFOHEIE 0x00004000	/* Tx FIFO Half Empty interrupt Enable */
  #define SDMMC_MASK_RXFIFOHFIE 0x00008000	/* Rx FIFO Half Full interrupt Enable */
  #define SDMMC_MASK_TXFIFOFIE  0x00010000	/* Tx FIFO Full interrupt Enable */
  #define SDMMC_MASK_RXFIFOFIE  0x00020000	/* Rx FIFO Full interrupt Enable */
  #define SDMMC_MASK_TXFIFOEIE  0x00040000	/* Tx FIFO Empty interrupt Enable */
  #define SDMMC_MASK_RXFIFOEIE  0x00080000	/* Rx FIFO Empty interrupt Enable */
  #define SDMMC_MASK_TXDAVLIE   0x00100000	/* Data available in Tx FIFO interrupt Enable */
  #define SDMMC_MASK_RXDAVLIE   0x00200000	/* Data available in Rx FIFO interrupt Enable */
  #define SDMMC_MASK_SDIOITIE   0x00400000	/* SDMMC Mode Interrupt Received interrupt Enable */
#define TOFF_SDIO_FIFOCNT   0x0048		/* (R)  SDIO FIFO counter register */
#define TOFF_SDIO_FIFO      0x0080		/* (RW) SDIO data FIFO register */


/*
 *  SERIAL AUDIO INTERFACE
 */
#define TADR_SAI1_BASE      (APB2PERIPH_BASE + 0x5400)
#define TADR_SAI2_BASE      (APB2PERIPH_BASE + 0x5800)
#define TOFF_SAI_GCR        0x0000		/* (RW) SAI global configuration register */
  #define SAI_GCR_SYNCIN      0x00000003	/* SYNCIN[1:0] bits (Synchronization Inputs)   */
  #define SAI_GCR_SYNCIN_0    0x00000001	/* Bit 0 */
  #define SAI_GCR_SYNCIN_1    0x00000002	/* Bit 1 */
  #define SAI_GCR_SYNCOUT     0x00000030	/* SYNCOUT[1:0] bits (Synchronization Outputs) */
  #define SAI_GCR_SYNCOUT_0   0x00000010	/* Bit 0 */
  #define SAI_GCR_SYNCOUT_1   0x00000020	/* Bit 1 */
#define SAI_WINDOW_SIZE     0x0020
#define TOFF_SAI_CR1        0x0000		/* (RW) SAI block x configuration register 1 */
  #define SAI_xCR1_MODE       0x00000003	/* MODE[1:0] bits (Audio Block Mode) */
  #define SAI_xCR1_MODE_0     0x00000001	/* Bit 0 */
  #define SAI_xCR1_MODE_1     0x00000002	/* Bit 1 */
  #define SAI_xCR1_PRTCFG     0x0000000C	/* PRTCFG[1:0] bits (Protocol Configuration)   */
  #define SAI_xCR1_PRTCFG_0   0x00000004	/* Bit 0 */
  #define SAI_xCR1_PRTCFG_1   0x00000008	/* Bit 1 */
  #define SAI_xCR1_DS         0x000000E0	/* DS[1:0] bits (Data Size) */
  #define SAI_xCR1_DS_0       0x00000020	/* Bit 0 */
  #define SAI_xCR1_DS_1       0x00000040	/* Bit 1 */
  #define SAI_xCR1_DS_2       0x00000080	/* Bit 2 */
  #define SAI_xCR1_LSBFIRST   0x00000100	/* LSB First Configuration  */
  #define SAI_xCR1_CKSTR      0x00000200	/* ClocK STRobing edge      */
  #define SAI_xCR1_SYNCEN     0x00000C00	/* SYNCEN[1:0](SYNChronization ENable) */
  #define SAI_xCR1_SYNCEN_0   0x00000400	/* Bit 0 */
  #define SAI_xCR1_SYNCEN_1   0x00000800	/* Bit 1 */
  #define SAI_xCR1_MONO       0x00001000	/* Mono mode */
  #define SAI_xCR1_OUTDRIV    0x00002000	/* Output Drive */
  #define SAI_xCR1_SAIEN      0x00010000	/* Audio Block enable */
  #define SAI_xCR1_DMAEN      0x00020000	/* DMA enable */
  #define SAI_xCR1_NODIV      0x00080000	/* No Divider Configuration */
  #define SAI_xCR1_MCKDIV     0x00F00000	/* MCKDIV[3:0] (Master ClocK Divider)  */
  #define SAI_xCR1_MCKDIV_0   0x00100000	/* Bit 0  */
  #define SAI_xCR1_MCKDIV_1   0x00200000	/* Bit 1  */
  #define SAI_xCR1_MCKDIV_2   0x00400000	/* Bit 2  */
  #define SAI_xCR1_MCKDIV_3   0x00800000	/* Bit 3  */
#define TOFF_SAI_CR2        0x0004		/* (RW) SAI block x configuration register 2 */
  #define SAI_xCR2_FTH        0x00000007	/* FTH[2:0](Fifo THreshold)  */
  #define SAI_xCR2_FTH_0      0x00000001	/* Bit 0 */
  #define SAI_xCR2_FTH_1      0x00000002	/* Bit 1 */
  #define SAI_xCR2_FTH_2      0x00000004	/* Bit 2 */
  #define SAI_xCR2_FFLUSH     0x00000008	/* Fifo FLUSH */
  #define SAI_xCR2_TRIS       0x00000010	/* TRIState Management on data line */
  #define SAI_xCR2_MUTE       0x00000020	/* Mute mode */
  #define SAI_xCR2_MUTEVAL    0x00000040	/* Mute value */
  #define SAI_xCR2_MUTECNT    0x00001F80	/* MUTECNT[5:0] (MUTE counter) */
  #define SAI_xCR2_MUTECNT_0  0x00000080	/* Bit 0 */
  #define SAI_xCR2_MUTECNT_1  0x00000100	/* Bit 1 */
  #define SAI_xCR2_MUTECNT_2  0x00000200	/* Bit 2 */
  #define SAI_xCR2_MUTECNT_3  0x00000400	/* Bit 3 */
  #define SAI_xCR2_MUTECNT_4  0x00000800	/* Bit 4 */
  #define SAI_xCR2_MUTECNT_5  0x00001000	/* Bit 5 */
  #define SAI_xCR2_CPL        0x00080000	/* Complement Bit */
  #define SAI_xCR2_COMP       0x0000C000	/* COMP[1:0] (Companding mode) */
  #define SAI_xCR2_COMP_0     0x00004000	/* Bit 0 */
  #define SAI_xCR2_COMP_1     0x00008000	/* Bit 1 */
#define TOFF_SAI_FRCR       0x0008		/* (RW) SAI block x frame configuration register */
  #define SAI_xFRCR_FRL       0x000000FF	/* FRL[1:0](Frame length)  */
  #define SAI_xFRCR_FRL_0     0x00000001	/* Bit 0 */
  #define SAI_xFRCR_FRL_1     0x00000002	/* Bit 1 */
  #define SAI_xFRCR_FRL_2     0x00000004	/* Bit 2 */
  #define SAI_xFRCR_FRL_3     0x00000008	/* Bit 3 */
  #define SAI_xFRCR_FRL_4     0x00000010	/* Bit 4 */
  #define SAI_xFRCR_FRL_5     0x00000020	/* Bit 5 */
  #define SAI_xFRCR_FRL_6     0x00000040	/* Bit 6 */
  #define SAI_xFRCR_FRL_7     0x00000080	/* Bit 7 */
  #define SAI_xFRCR_FSALL     0x00007F00	/* FRL[1:0] (Frame synchronization active level length)  */
  #define SAI_xFRCR_FSALL_0   0x00000100	/* Bit 0 */
  #define SAI_xFRCR_FSALL_1   0x00000200	/* Bit 1 */
  #define SAI_xFRCR_FSALL_2   0x00000400	/* Bit 2 */
  #define SAI_xFRCR_FSALL_3   0x00000800	/* Bit 3 */
  #define SAI_xFRCR_FSALL_4   0x00001000	/* Bit 4 */
  #define SAI_xFRCR_FSALL_5   0x00002000	/* Bit 5 */
  #define SAI_xFRCR_FSALL_6   0x00004000	/* Bit 6 */
  #define SAI_xFRCR_FSDEF     0x00010000	/* Frame Synchronization Definition */
  #define SAI_xFRCR_FSPO      0x00020000	/* Frame Synchronization POLarity */
  #define SAI_xFRCR_FSOFF     0x00040000	/* Frame Synchronization OFFset*/
#define TOFF_SAI_SLOTR      0x000C		/* (RW) SAI block x slot register */
  #define SAI_xSLOTR_FBOFF    0x0000001F	/* FRL[4:0](First Bit Offset)  */
  #define SAI_xSLOTR_FBOFF_0  0x00000001	/* Bit 0 */
  #define SAI_xSLOTR_FBOFF_1  0x00000002	/* Bit 1 */
  #define SAI_xSLOTR_FBOFF_2  0x00000004	/* Bit 2 */
  #define SAI_xSLOTR_FBOFF_3  0x00000008	/* Bit 3 */
  #define SAI_xSLOTR_FBOFF_4  0x00000010	/* Bit 4 */
  #define SAI_xSLOTR_SLOTSZ   0x000000C0	/* SLOTSZ[1:0] (Slot size)  */
  #define SAI_xSLOTR_SLOTSZ_0 0x00000040	/* Bit 0 */
  #define SAI_xSLOTR_SLOTSZ_1 0x00000080	/* Bit 1 */
  #define SAI_xSLOTR_NBSLOT   0x00000F00	/* NBSLOT[3:0] (Number of Slot in audio Frame)  */
  #define SAI_xSLOTR_NBSLOT_0 0x00000100	/* Bit 0 */
  #define SAI_xSLOTR_NBSLOT_1 0x00000200	/* Bit 1 */
  #define SAI_xSLOTR_NBSLOT_2 0x00000400	/* Bit 2 */
  #define SAI_xSLOTR_NBSLOT_3 0x00000800	/* Bit 3 */
  #define SAI_xSLOTR_SLOTEN   0xFFFF0000	/* SLOTEN[15:0] (Slot Enable)  */
#define TOFF_SAI_IMR        0x0010		/* (RW) SAI block x interrupt mask register */
  #define SAI_xIMR_OVRUDRIE   0x00000001	/* Overrun underrun interrupt enable                              */
  #define SAI_xIMR_MUTEDETIE  0x00000002	/* Mute detection interrupt enable                                */
  #define SAI_xIMR_WCKCFGIE   0x00000004	/* Wrong Clock Configuration interrupt enable                     */
  #define SAI_xIMR_FREQIE     0x00000008	/* FIFO request interrupt enable                                  */
  #define SAI_xIMR_CNRDYIE    0x00000010	/* Codec not ready interrupt enable                               */
  #define SAI_xIMR_AFSDETIE   0x00000020	/* Anticipated frame synchronization detection interrupt enable   */
  #define SAI_xIMR_LFSDETIE   0x00000040	/* Late frame synchronization detection interrupt enable          */
#define TOFF_SAI_SR         0x0014		/* (RW) SAI block x status register */
  #define SAI_xSR_OVRUDR      0x00000001	/* Overrun underrun */
  #define SAI_xSR_MUTEDET     0x00000002	/* Mute detection */
  #define SAI_xSR_WCKCFG      0x00000004	/* Wrong Clock Configuration */
  #define SAI_xSR_FREQ        0x00000008	/* FIFO request */
  #define SAI_xSR_CNRDY       0x00000010	/* Codec not ready */
  #define SAI_xSR_AFSDET      0x00000020	/* Anticipated frame synchronization detection */
  #define SAI_xSR_LFSDET      0x00000040	/* Late frame synchronization detection */
  #define SAI_xSR_FLVL        0x00070000	/* FLVL[2:0] (FIFO Level Threshold) */
  #define SAI_xSR_FLVL_0      0x00010000	/* Bit 0 */
  #define SAI_xSR_FLVL_1      0x00020000	/* Bit 1 */
  #define SAI_xSR_FLVL_2      0x00040000	/* Bit 2 */
#define TOFF_SAI_CLRFR      0x0018		/* (RW) SAI block x clear flag register */
  #define SAI_xCLRFR_COVRUDR  0x00000001	/* Clear Overrun underrun */
  #define SAI_xCLRFR_CMUTEDET 0x00000002	/* Clear Mute detection */
  #define SAI_xCLRFR_CWCKCFG  0x00000004	/* Clear Wrong Clock Configuration */
  #define SAI_xCLRFR_CFREQ    0x00000008	/* Clear FIFO request */
  #define SAI_xCLRFR_CCNRDY   0x00000010	/* Clear Codec not ready */
  #define SAI_xCLRFR_CAFSDET  0x00000020	/* Clear Anticipated frame synchronization detection */
  #define SAI_xCLRFR_CLFSDET  0x00000040	/* Clear Late frame synchronization detection */
#define TOFF_SAI_DR         0x001C		/* (RW) SAI block x data register */


/*
 *  DFSDM MODULE REGISTERS
 */
#define TADR_DFSDM1_BASE            (APB2PERIPH_BASE + 0x6000)
#define TADR_DFSDM1_CHANNEL0_BASE   (TADR_DFSDM1_BASE + 0x0000)
#define TADR_DFSDM1_CHANNEL1_BASE   (TADR_DFSDM1_BASE + 0x0020)
#define TADR_DFSDM1_CHANNEL2_BASE   (TADR_DFSDM1_BASE + 0x0040)
#define TADR_DFSDM1_CHANNEL3_BASE   (TADR_DFSDM1_BASE + 0x0060)
#define TADR_DFSDM1_CHANNEL4_BASE   (TADR_DFSDM1_BASE + 0x0080)
#define TADR_DFSDM1_CHANNEL5_BASE   (TADR_DFSDM1_BASE + 0x00A0)
#define TADR_DFSDM1_CHANNEL6_BASE   (TADR_DFSDM1_BASE + 0x00C0)
#define TADR_DFSDM1_CHANNEL7_BASE   (TADR_DFSDM1_BASE + 0x00E0)
#define TOFF_DFSDM_CHCFGR1 0x0000	/* (RW) DFSDM channel configuration register1 */
  #define DFSDM_CHCFGR1_SITP       0x00000003	/* SITP[1:0] Serial interface type for channel y */
  #define DFSDM_CHCFGR1_SITP_0     0x00000001	/* Serial interface type for channel y, Bit 0 */
  #define DFSDM_CHCFGR1_SITP_1     0x00000002	/* Serial interface type for channel y, Bit 1 */
  #define DFSDM_CHCFGR1_SPICKSEL   0x0000000C	/* SPICKSEL[1:0] SPI clock select for channel y */
  #define DFSDM_CHCFGR1_SPICKSEL_0 0x00000004	/* SPI clock select for channel y, Bit 0 */
  #define DFSDM_CHCFGR1_SPICKSEL_1 0x00000008	/* SPI clock select for channel y, Bit 1 */
  #define DFSDM_CHCFGR1_SCDEN      0x00000020	/* Short circuit detector enable on channel y */
  #define DFSDM_CHCFGR1_CKABEN     0x00000040	/* Clock absence detector enable on channel y */
  #define DFSDM_CHCFGR1_CHEN       0x00000080	/* Channel y enable */
  #define DFSDM_CHCFGR1_CHINSEL    0x00000100	/* Serial inputs selection for channel y */
  #define DFSDM_CHCFGR1_DATMPX     0x00003000	/* DATMPX[1:0] Input data multiplexer for channel y */
  #define DFSDM_CHCFGR1_DATMPX_0   0x00001000	/* Input data multiplexer for channel y, Bit 0 */
  #define DFSDM_CHCFGR1_DATMPX_1   0x00002000	/* Input data multiplexer for channel y, Bit 1 */
  #define DFSDM_CHCFGR1_DATPACK    0x0000C000	/* DATPACK[1:0] Data packing mode */
  #define DFSDM_CHCFGR1_DATPACK_0  0x00004000	/* Data packing mode, Bit 0 */
  #define DFSDM_CHCFGR1_DATPACK_1  0x00008000	/* Data packing mode, Bit 1 */
  #define DFSDM_CHCFGR1_CKOUTDIV   0x00FF0000	/* CKOUTDIV[7:0] output serial clock divider */
  #define DFSDM_CHCFGR1_CKOUTSRC   0x40000000	/* Output serial clock source selection */
  #define DFSDM_CHCFGR1_DFSDMEN    0x80000000	/* Global enable for DFSDM interface */
#define TOFF_DFSDM_CHCFGR2 0x0004	/* (RW) DFSDM channel configuration register2 */
  #define DFSDM_CHCFGR2_DTRBS      0x000000F8	/* DTRBS[4:0] Data right bit-shift for channel y */
  #define DFSDM_CHCFGR2_OFFSET     0xFFFFFF00	/* OFFSET[23:0] 24-bit calibration offset for channel y */
#define TOFF_DFSDM_CHAWSCDR 0x0008	/* (RW) DFSDM channel analog watchdog and short circuit detector register */
  #define DFSDM_CHAWSCDR_SCDT      0x000000FF	/* SCDT[7:0] Short circuit detector threshold for channel y */
  #define DFSDM_CHAWSCDR_BKSCD     0x0000F000	/* BKSCD[3:0] Break signal assignment for short circuit detector on channel y */
  #define DFSDM_CHAWSCDR_AWFOSR    0x001F0000	/* AWFOSR[4:0] Analog watchdog filter oversampling ratio on channel y */
  #define DFSDM_CHAWSCDR_AWFORD    0x00C00000	/* AWFORD[1:0] Analog watchdog Sinc filter order on channel y */
  #define DFSDM_CHAWSCDR_AWFORD_0  0x00400000	/* Analog watchdog Sinc filter order on channel y, Bit 0 */
  #define DFSDM_CHAWSCDR_AWFORD_1  0x00800000	/* Analog watchdog Sinc filter order on channel y, Bit 1 */
#define TOFF_DFSDM_CHWDATAR 0x000C	/* (RW) DFSDM channel watchdog filter data register */
  #define DFSDM_CHWDATR_WDATA      0x0000FFFF	/* WDATA[15:0] Input channel y watchdog data */
#define TOFF_DFSDM_CHDATINR 0x0010	/* (RW) DFSDM channel data input register */
  #define DFSDM_CHDATINR_INDAT0    0x0000FFFF	/* INDAT0[31:16] Input data for channel y or channel (y+1) */
  #define DFSDM_CHDATINR_INDAT1    0xFFFF0000	/* INDAT0[15:0] Input data for channel y */

#define TADR_DFSDM1_FILTER0_BASE    (TADR_DFSDM1_BASE + 0x0100)
#define TADR_DFSDM1_FILTER1_BASE    (TADR_DFSDM1_BASE + 0x0180)
#define TADR_DFSDM1_FILTER2_BASE    (TADR_DFSDM1_BASE + 0x0200)
#define TADR_DFSDM1_FILTER3_BASE    (TADR_DFSDM1_BASE + 0x0280)
#define TOFF_DFSDM_FLTCR1  0x0000	/* (RW) DFSDM control register1 */
  #define DFSDM_FLTCR1_DFEN      0x00000001	/* DFSDM enable */
  #define DFSDM_FLTCR1_JSWSTART  0x00000002	/* Start the conversion of the injected group of channels */
  #define DFSDM_FLTCR1_JSYNC     0x00000008	/* Launch an injected conversion synchronously with DFSDMx JSWSTART trigger */
  #define DFSDM_FLTCR1_JSCAN     0x00000010	/* Scanning conversion in continuous mode selection for injected conversions */
  #define DFSDM_FLTCR1_JDMAEN    0x00000020	/* DMA channel enabled to read data for the injected channel group */
  #define DFSDM_FLTCR1_JEXTSEL   0x00000700	/* JEXTSEL[2:0]Trigger signal selection for launching injected conversions */
  #define DFSDM_FLTCR1_JEXTSEL_0 0x00000100	/* Trigger signal selection for launching injected conversions, Bit 0 */
  #define DFSDM_FLTCR1_JEXTSEL_1 0x00000200	/* Trigger signal selection for launching injected conversions, Bit 1 */
  #define DFSDM_FLTCR1_JEXTSEL_2 0x00000400	/* Trigger signal selection for launching injected conversions, Bit 2 */
  #define DFSDM_FLTCR1_JEXTEN    0x00006000	/* JEXTEN[1:0] Trigger enable and trigger edge selection for injected conversions */
  #define DFSDM_FLTCR1_JEXTEN_1  0x00004000	/* Trigger enable and trigger edge selection for injected conversions, Bit 1 */
  #define DFSDM_FLTCR1_JEXTEN_0  0x00002000	/* Trigger enable and trigger edge selection for injected conversions, Bit 0 */
  #define DFSDM_FLTCR1_RSWSTART  0x00020000	/* Software start of a conversion on the regular channel */
  #define DFSDM_FLTCR1_RCONT     0x00040000	/* Continuous mode selection for regular conversions */
  #define DFSDM_FLTCR1_RSYNC     0x00080000	/* Launch regular conversion synchronously with DFSDMx */
  #define DFSDM_FLTCR1_RDMAEN    0x00200000	/* DMA channel enabled to read data for the regular conversion */
  #define DFSDM_FLTCR1_RCH       0x07000000	/* RCH[2:0] Regular channel selection */
  #define DFSDM_FLTCR1_FAST      0x20000000	/* Fast conversion mode selection */
  #define DFSDM_FLTCR1_AWFSEL    0x40000000	/* Analog watchdog fast mode select */
#define TOFF_DFSDM_FLTCR2  0x0004	/* (RW) DFSDM control register2 */
  #define DFSDM_FLTCR2_JEOCIE    0x00000001	/* Injected end of conversion interrupt enable */
  #define DFSDM_FLTCR2_REOCIE    0x00000002	/* Regular end of conversion interrupt enable */
  #define DFSDM_FLTCR2_JOVRIE    0x00000004	/* Injected data overrun interrupt enable */
  #define DFSDM_FLTCR2_ROVRIE    0x00000008	/* Regular data overrun interrupt enable */
  #define DFSDM_FLTCR2_AWDIE     0x00000010	/* Analog watchdog interrupt enable */
  #define DFSDM_FLTCR2_SCDIE     0x00000020	/* Short circuit detector interrupt enable */
  #define DFSDM_FLTCR2_CKABIE    0x00000040	/* Clock absence interrupt enable */
  #define DFSDM_FLTCR2_EXCH      0x0000FF00	/* EXCH[7:0] Extreme detector channel selection */
  #define DFSDM_FLTCR2_AWDCH     0x00FF0000	/* AWDCH[7:0] Analog watchdog channel selection */
#define TOFF_DFSDM_FLTISR  0x0008	/* (RW) DFSDM interrupt and status register */
  #define DFSDM_FLTISR_JEOCF     0x00000001	/* End of injected conversion flag */
  #define DFSDM_FLTISR_REOCF     0x00000002	/* End of regular conversion flag */
  #define DFSDM_FLTISR_JOVRF     0x00000004	/* Injected conversion overrun flag */
  #define DFSDM_FLTISR_ROVRF     0x00000008	/* Regular conversion overrun flag */
  #define DFSDM_FLTISR_AWDF      0x00000010	/* Analog watchdog */
  #define DFSDM_FLTISR_JCIP      0x00002000	/* Injected conversion in progress status */
  #define DFSDM_FLTISR_RCIP      0x00004000	/* Regular conversion in progress status */
  #define DFSDM_FLTISR_CKABF     0x00FF0000	/* CKABF[7:0] Clock absence flag */
  #define DFSDM_FLTISR_SCDF      0xFF000000	/* SCDF[7:0] Short circuit detector flag */
#define TOFF_DFSDM_FLTICR  0x000C	/* (RW) DFSDM interrupt flag clear register */
  #define DFSDM_FLTICR_CLRJOVRF  0x00000004	/* Clear the injected conversion overrun flag */
  #define DFSDM_FLTICR_CLRROVRF  0x00000008	/* Clear the regular conversion overrun flag */
  #define DFSDM_FLTICR_CLRCKABF  0x00FF0000	/* CLRCKABF[7:0] Clear the clock absence flag */
  #define DFSDM_FLTICR_CLRSCSDF  0xFF000000	/* CLRSCSDF[7:0] Clear the short circuit detector flag */
#define TOFF_DFSDM_FLTJCHGR 0x0010	/* (RW) DFSDM injected channel group selection register */
  #define DFSDM_FLTJCHGR_JCHG    0x000000FF	/* JCHG[7:0] Injected channel group selection */
#define TOFF_DFSDM_FLTFCR  0x0014	/* (RW) DFSDM filter control register */
  #define DFSDM_FLTFCR_IOSR      0x000000FF	/* IOSR[7:0] Integrator oversampling ratio (averaging length) */
  #define DFSDM_FLTFCR_FOSR      0x03FF0000	/* FOSR[9:0] Sinc filter oversampling ratio (decimation rate) */
  #define DFSDM_FLTFCR_FORD      0xE0000000	/* FORD[2:0] Sinc filter order */
  #define DFSDM_FLTFCR_FORD_2    0x80000000	/* Sinc filter order, Bit 2 */
  #define DFSDM_FLTFCR_FORD_1    0x40000000	/* Sinc filter order, Bit 1 */
  #define DFSDM_FLTFCR_FORD_0    0x20000000	/* Sinc filter order, Bit 0 */
#define TOFF_DFSDM_FLTJDATAR 0x0018	/* (RW) DFSDM data register for injected group */
  #define DFSDM_FLTJDATAR_JDATACH 0x00000007	/* JDATACH[2:0] Injected channel most recently converted */
  #define DFSDM_FLTJDATAR_JDATA   0xFFFFFF00	/* JDATA[23:0] Injected group conversion data */
#define TOFF_DFSDM_FLTRDATAR 0x001C	/* (RW) DFSDM data register for regular group */
  #define DFSDM_FLTRDATAR_RDATACH 0x00000007	/* RDATACH[2:0] Regular channel most recently converted */
  #define DFSDM_FLTRDATAR_RPEND   0x00000010	/* RPEND Regular channel pending data */
  #define DFSDM_FLTRDATAR_RDATA   0xFFFFFF00	/* RDATA[23:0] Regular channel conversion data */
#define TOFF_DFSDM_FLTAWHTR 0x0020	/* (RW) DFSDM analog watchdog high threshold register */
  #define DFSDM_FLTAWHTR_BKAWH   0x0000000F	/* BKAWH[3:0] Break signal assignment to analog watchdog high threshold event */
  #define DFSDM_FLTAWHTR_AWHT    0xFFFFFF00	/* AWHT[23:0] Analog watchdog high threshold */
#define TOFF_DFSDM_FLTAWLTR 0x0024	/* (RW) DFSDM analog watchdog low threshold register */
  #define DFSDM_FLTAWLTR_BKAWL   0x0000000F	/* BKAWL[3:0] Break signal assignment to analog watchdog low threshold event */
  #define DFSDM_FLTAWLTR_AWLT    0xFFFFFF00	/* AWLT[23:0] Analog watchdog low threshold */
#define TOFF_DFSDM_FLTAWSR  0x0028	/* (RW) DFSDM analog watchdog status register */
  #define DFSDM_FLTAWSR_AWLTF    0x000000FF	/* AWLTF[7:0] Analog watchdog low threshold error on given channels */
  #define DFSDM_FLTAWSR_AWHTF    0x0000FF00	/* AWHTF[15:8] Analog watchdog high threshold error on given channels */
#define TOFF_DFSDM_FLTAWCFR 0x002C	/* (RW) DFSDM analog watchdog clear flag register */
  #define DFSDM_FLTAWCFR_CLRAWLTF 0x000000FF	/* CLRAWLTF[7:0] Clear the Analog watchdog low threshold flag */
  #define DFSDM_FLTAWCFR_CLRAWHTF 0x0000FF00	/* CLRAWHTF[15:8] Clear the Analog watchdog high threshold flag */
#define TOFF_DFSDM_FLTEXMAX 0x0030	/* (RW) DFSDM extreme detector maximum register */
  #define DFSDM_FLTEXMAX_EXMAXCH 0x00000007	/* EXMAXCH[2:0] Extreme detector maximum data channel */
  #define DFSDM_FLTEXMAX_EXMAX   0xFFFFFF00	/* EXMAX[23:0] Extreme detector maximum value */
#define TOFF_DFSDM_FLTEXMIN 0x0034	/* (RW) DFSDM extreme detector minimum register */
  #define DFSDM_FLTEXMIN_EXMINCH 0x00000007	/* EXMINCH[2:0] Extreme detector minimum data channel */
  #define DFSDM_FLTEXMIN_EXMIN   0xFFFFFF00	/* EXMIN[23:0] Extreme detector minimum value */
#define TOFF_DFSDM_FLTCNVTIMR 0x0038/* (RW) DFSDM conversion timer */
  #define DFSDM_FLTCNVTIMR_CNVCNT 0xFFFFFFF0	/* CNVCNT[27:0]: 28-bit timer counting conversion time */


/* 
 *  DMA CONTROLLER
 */
#define TADR_DMA1_BASE      (AHB1PERIPH_BASE + 0x0000)
#define TADR_DMA2_BASE      (AHB1PERIPH_BASE + 0x0400)
#define TOFF_DMA_ISR        0x0000		/* (RW) DMA interrupt status register */
  #define DMA_ISR_GIF        0x1		/* Channel Global interrupt flag */
  #define DMA_ISR_TCIF       0x2		/* Channel Transfer Complete flag */
  #define DMA_ISR_HTIF       0x4		/* Channel Half Transfer flag */
  #define DMA_ISR_TEIF       0x8		/* Channel Transfer Error flag */
#define TOFF_DMA_IFCR       0x0004		/* (RW) DMA interrupt flag clear register */
  #define DMA_IFCR_CGIF      0x1		/* Channel Global interrupt clear    */
  #define DMA_IFCR_CTCIF     0x2		/* Channel Transfer Complete clear   */
  #define DMA_IFCR_CHTIF     0x4		/* Channel Half Transfer clear       */
  #define DMA_IFCR_CTEIF     0x8		/* Channel Transfer Error clear      */
#define TOFF_DMA_CSELR      0x00A8		/* (RW) Channel selection register */
  #define DMA_CSELR_C1S      0x0000000F	/* Channel 1 Selection */
  #define DMA_CSELR_C2S      0x000000F0	/* Channel 2 Selection */
  #define DMA_CSELR_C3S      0x00000F00	/* Channel 3 Selection */
  #define DMA_CSELR_C4S      0x0000F000	/* Channel 4 Selection */
  #define DMA_CSELR_C5S      0x000F0000	/* Channel 5 Selection */
  #define DMA_CSELR_C6S      0x00F00000	/* Channel 6 Selection */
  #define DMA_CSELR_C7S      0x0F000000	/* Channel 7 Selection */

#define TADR_DMA1_CH1_BASE  (TADR_DMA1_BASE + 0x008)
#define TADR_DMA1_CH2_BASE  (TADR_DMA1_BASE + 0x01C)
#define TADR_DMA1_CH3_BASE  (TADR_DMA1_BASE + 0x030)
#define TADR_DMA1_CH4_BASE  (TADR_DMA1_BASE + 0x044)
#define TADR_DMA1_CH5_BASE  (TADR_DMA1_BASE + 0x058)
#define TADR_DMA1_CH6_BASE  (TADR_DMA1_BASE + 0x06C)
#define TADR_DMA1_CH7_BASE  (TADR_DMA1_BASE + 0x080)
#define TADR_DMA2_CH1_BASE  (TADR_DMA2_BASE + 0x0008)
#define TADR_DMA2_CH2_BASE  (TADR_DMA2_BASE + 0x001C)
#define TADR_DMA2_CH3_BASE  (TADR_DMA2_BASE + 0x0030)
#define TADR_DMA2_CH4_BASE  (TADR_DMA2_BASE + 0x0044)
#define TADR_DMA2_CH5_BASE  (TADR_DMA2_BASE + 0x0058)
#define TADR_DMA2_CH6_BASE  (TADR_DMA2_BASE + 0x006C)
#define TADR_DMA2_CH7_BASE  (TADR_DMA2_BASE + 0x0080)
#define TOFF_DMACH_CCR      0x0000		/* (RW) DMA channel x configuration register */
  #define DMA_CCR_EN         0x00000001	/* Channel enable */
  #define DMA_CCR_TCIE       0x00000002	/* Transfer complete interrupt enable */
  #define DMA_CCR_HTIE       0x00000004	/* Half Transfer interrupt enable */
  #define DMA_CCR_TEIE       0x00000008	/* Transfer error interrupt enable */
  #define DMA_CCR_DIR        0x00000010	/* Data transfer direction */
  #define DMA_CCR_CIRC       0x00000020	/* Circular mode */
  #define DMA_CCR_PINC       0x00000040	/* Peripheral increment mode */
  #define DMA_CCR_MINC       0x00000080	/* Memory increment mode */
  #define DMA_CCR_PSIZE      0x00000300	/* PSIZE[1:0] bits (Peripheral size) */
  #define DMA_CCR_PSIZE_0    0x00000100
  #define DMA_CCR_PSIZE_1    0x00000200
  #define DMA_CCR_MSIZE      0x00000C00	/* MSIZE[1:0] bits (Memory size) */
  #define DMA_CCR_MSIZE_0    0x00000400
  #define DMA_CCR_MSIZE_1    0x00000800
  #define DMA_CCR_PL         0x00003000	/* PL[1:0] bits(Channel Priority level) */
  #define DMA_CCR_PL_0       0x00001000
  #define DMA_CCR_PL_1       0x00002000
  #define DMA_CCR_MEM2MEM    0x00004000	/* Memory to memory mode */
#define TOFF_DMACH_CNDTR    0x0004		/* (RW) DMA channel x number of data register */
  #define DMA_CNDTR_NDT      0x0000FFFF	/* Number of data to Transfer */
#define TOFF_DMACH_CPAR     0x0008		/* (RW) DMA channel x peripheral address register   */
#define TOFF_DMACH_CMAR     0x000C		/* (RW) DMA channel x memory address register */


#if !defined(TOPPERS_STM32L476_DISCOVERY) && !defined(TOPPERS_STM32L476_NUCLEO64)
/*
 *  DMAMUTEX
 */
#define TADR_DMAMUX1_BASE   (AHB1PERIPH_BASE + 0x0800)
#define TOFF_DMAMUX_CHANNEL_CR      0x0000
  #define DMAMUX_CxCR_DMAREQ_ID     0x000000FF
  #define DMAMUX_CxCR_DMAREQ_ID_0   0x00000001
  #define DMAMUX_CxCR_DMAREQ_ID_1   0x00000002
  #define DMAMUX_CxCR_DMAREQ_ID_2   0x00000004
  #define DMAMUX_CxCR_DMAREQ_ID_3   0x00000008
  #define DMAMUX_CxCR_DMAREQ_ID_4   0x00000010
  #define DMAMUX_CxCR_DMAREQ_ID_5   0x00000020
  #define DMAMUX_CxCR_DMAREQ_ID_6   0x00000040
  #define DMAMUX_CxCR_DMAREQ_ID_7   0x00000080
  #define DMAMUX_CxCR_SOIE          0x00000100
  #define DMAMUX_CxCR_EGE           0x00000200
  #define DMAMUX_CxCR_SE            0x00010000
  #define DMAMUX_CxCR_SPOL          0x00060000
  #define DMAMUX_CxCR_SPOL_0        0x00020000
  #define DMAMUX_CxCR_SPOL_1        0x00040000
  #define DMAMUX_CxCR_NBREQ         0x00F80000
  #define DMAMUX_CxCR_NBREQ_0       0x00080000
  #define DMAMUX_CxCR_NBREQ_1       0x00100000
  #define DMAMUX_CxCR_NBREQ_2       0x00200000
  #define DMAMUX_CxCR_NBREQ_3       0x00400000
  #define DMAMUX_CxCR_NBREQ_4       0x00800000
  #define DMAMUX_CxCR_SYNC_ID       0x1F000000
  #define DMAMUX_CxCR_SYNC_ID_0     0x01000000
  #define DMAMUX_CxCR_SYNC_ID_1     0x02000000
  #define DMAMUX_CxCR_SYNC_ID_2     0x04000000
  #define DMAMUX_CxCR_SYNC_ID_3     0x08000000
  #define DMAMUX_CxCR_SYNC_ID_4     0x10000000
#define TOFF_DMAMUX_REQUEST_GEN     0x0100
  #define DMAMUX_RGxCR_SIG_ID       0x0000001F
  #define DMAMUX_RGxCR_SIG_ID_0     0x00000001
  #define DMAMUX_RGxCR_SIG_ID_1     0x00000002
  #define DMAMUX_RGxCR_SIG_ID_2     0x00000004
  #define DMAMUX_RGxCR_SIG_ID_3     0x00000008
  #define DMAMUX_RGxCR_SIG_ID_4     0x00000010
  #define DMAMUX_RGxCR_OIE          0x00000100
  #define DMAMUX_RGxCR_GE           0x00010000
  #define DMAMUX_RGxCR_GPOL         0x00060000
  #define DMAMUX_RGxCR_GPOL_0       0x00020000
  #define DMAMUX_RGxCR_GPOL_1       0x00040000
  #define DMAMUX_RGxCR_GNBREQ       0x00F80000
  #define DMAMUX_RGxCR_GNBREQ_0     0x00080000
  #define DMAMUX_RGxCR_GNBREQ_1     0x00100000
  #define DMAMUX_RGxCR_GNBREQ_2     0x00200000
  #define DMAMUX_RGxCR_GNBREQ_3     0x00400000
  #define DMAMUX_RGxCR_GNBREQ_4     0x00800000
#define TOFF_DMAMUX_CHANNEL_STS     0x0080
#define TOFF_DMAMUX_CHANNEL_STS_CSR TOFF_DMAMUX_CHANNEL_STS
#define TOFF_DMAMUX_CHANNEL_STS_CFR (TOFF_DMAMUX_CHANNEL_STS+4)
#define TOFF_DMAMUX_REQUEST_GENSTS  0x1400
#define TOFF_DMAMUX_REQUEST_GENSTS_RGSR  TOFF_DMAMUX_REQUEST_GENSTS
#define TOFF_DMAMUX_REQUEST_GENSTS_RGCFR (TOFF_DMAMUX_REQUEST_GENSTS+4)


/*
 *  DMA2D CONTROLLER
 */
#define TADR_DMA2D_BASE     (AHB1PERIPH_BASE + 0xB000)
#define TOFF_DMA2D_CR       0x0000		/* (RW) DMA2D Control Register */
  #define DMA2D_CR_START     0x00000001	/* Start transfer */
  #define DMA2D_CR_SUSP      0x00000002	/* Suspend transfer */
  #define DMA2D_CR_ABORT     0x00000004	/* Abort transfer */
  #define DMA2D_CR_LOM       0x00000040	/* Line Offset Mode */
  #define DMA2D_CR_TEIE      0x00000100	/* Transfer Error Interrupt Enable */
  #define DMA2D_CR_TCIE      0x00000200	/* Transfer Complete Interrupt Enable */
  #define DMA2D_CR_TWIE      0x00000400	/* Transfer Watermark Interrupt Enable */
  #define DMA2D_CR_CAEIE     0x00000800	/* CLUT Access Error Interrupt Enable */
  #define DMA2D_CR_CTCIE     0x00001000	/* CLUT Transfer Complete Interrupt Enable */
  #define DMA2D_CR_CEIE      0x00002000	/* Configuration Error Interrupt Enable */
  #define DMA2D_CR_MODE      0x00070000	/* DMA2D Mode[2:0] */
  #define DMA2D_CR_MODE_0    0x00010000
  #define DMA2D_CR_MODE_1    0x00020000
  #define DMA2D_CR_MODE_2    0x00040000
#define TOFF_DMA2D_ISR      0x0004		/* (RW) DMA2D Interrupt Status Register */
  #define DMA2D_ISR_TEIF     0x00000001	/* Transfer Error Interrupt Flag */
  #define DMA2D_ISR_TCIF     0x00000002	/* Transfer Complete Interrupt Flag */
  #define DMA2D_ISR_TWIF     0x00000004	/* Transfer Watermark Interrupt Flag */
  #define DMA2D_ISR_CAEIF    0x00000008	/* CLUT Access Error Interrupt Flag */
  #define DMA2D_ISR_CTCIF    0x00000010	/* CLUT Transfer Complete Interrupt Flag */
  #define DMA2D_ISR_CEIF     0x00000020	/* Configuration Error Interrupt Flag */
#define TOFF_DMA2D_IFCR     0x0008		/* (RW) DMA2D Interrupt Flag Clear Register */
  #define DMA2D_IFCR_CTEIF   0x00000001	/* Clears Transfer Error Interrupt Flag */
  #define DMA2D_IFCR_CTCIF   0x00000002	/* Clears Transfer Complete Interrupt Flag */
  #define DMA2D_IFCR_CTWIF   0x00000004	/* Clears Transfer Watermark Interrupt Flag */
  #define DMA2D_IFCR_CAECIF  0x00000008	/* Clears CLUT Access Error Interrupt Flag */
  #define DMA2D_IFCR_CCTCIF  0x00000010	/* Clears CLUT Transfer Complete Interrupt Flag */
  #define DMA2D_IFCR_CCEIF   0x00000020	/* Clears Configuration Error Interrupt Flag */
#define TOFF_DMA2D_FGMAR    0x000C		/* (RW) DMA2D Foreground Memory Address Register */
#define TOFF_DMA2D_FGOR     0x0010		/* (RW) DMA2D Foreground Offset Register */
#define TOFF_DMA2D_BGMAR    0x0014		/* (RW) DMA2D Background Memory Address Register*/
#define TOFF_DMA2D_BGOR     0x0018		/* (RW) DMA2D Background Offset Register */
#define TOFF_DMA2D_FGPFCCR  0x001C		/* (RW) DMA2D Foreground PFC Control Register */
  #define DMA2D_FGPFCCR_CM   0x0000000F	/* Input color mode CM[3:0] */
  #define DMA2D_FGPFCCR_CM_0 0x00000001
  #define DMA2D_FGPFCCR_CM_1 0x00000002
  #define DMA2D_FGPFCCR_CM_2 0x00000004
  #define DMA2D_FGPFCCR_CM_3 0x00000008
  #define DMA2D_FGPFCCR_CCM  0x00000010	/* CLUT Color mode */
  #define DMA2D_FGPFCCR_START  0x00000020	/* Start */
  #define DMA2D_FGPFCCR_CS   0x0000FF00	/* CLUT size */
  #define DMA2D_FGPFCCR_AM   0x00030000	/* Alpha mode AM[1:0] */
  #define DMA2D_FGPFCCR_AM_0 0x00010000
  #define DMA2D_FGPFCCR_AM_1 0x00020000
  #define DMA2D_FGPFCCR_AI   0x00100000	/* Alpha Inverted */
  #define DMA2D_FGPFCCR_RBS  0x00200000	/* Red Blue Swap */
  #define DMA2D_FGPFCCR_ALPHA  0xFF000000	/* Alpha value */
#define TOFF_DMA2D_FGCOLR   0x0020		/* (RW) DMA2D Foreground Color Register */
  #define DMA2D_FGCOLR_BLUE  0x000000FF	/* Blue Value */
  #define DMA2D_FGCOLR_GREEN 0x0000FF00	/* Green Value */
  #define DMA2D_FGCOLR_RED   0x00FF0000	/* Red Value */
#define TOFF_DMA2D_BGPFCCR  0x0024		/* (RW) DMA2D Background PFC Control Register */
  #define DMA2D_BGPFCCR_CM   0x0000000F	/* Input color mode CM[3:0] */
  #define DMA2D_BGPFCCR_CM_0 0x00000001
  #define DMA2D_BGPFCCR_CM_1 0x00000002
  #define DMA2D_BGPFCCR_CM_2 0x00000004
  #define DMA2D_BGPFCCR_CM_3 0x00000008
  #define DMA2D_BGPFCCR_CCM  0x00000010	/* CLUT Color mode */
  #define DMA2D_BGPFCCR_START  0x00000020	/* Start */
  #define DMA2D_BGPFCCR_CS   0x0000FF00	/* CLUT size */
  #define DMA2D_BGPFCCR_AM   0x00030000	/* Alpha mode AM[1:0] */
  #define DMA2D_BGPFCCR_AM_0 0x00010000
  #define DMA2D_BGPFCCR_AM_1 0x00020000
  #define DMA2D_BGPFCCR_AI   0x00100000	/* Alpha Inverted */
  #define DMA2D_BGPFCCR_RBS  0x00200000	/* Red Blue Swap */
  #define DMA2D_BGPFCCR_ALPHA  0xFF000000	/* Alpha value */
#define TOFF_DMA2D_BGCOLR   0x0028		/* (RW) DMA2D Background Color Register */
  #define DMA2D_BGCOLR_BLUE  0x000000FF	/* Blue Value */
  #define DMA2D_BGCOLR_GREEN 0x0000FF00	/* Green Value */
  #define DMA2D_BGCOLR_RED   0x00FF0000	/* Red Value */
#define TOFF_DMA2D_FGCMAR   0x002C		/* (RW) DMA2D Foreground CLUT Memory Address Register */
#define TOFF_DMA2D_BGCMAR   0x0030		/* (RW) DMA2D Background CLUT Memory Address Register */
#define TOFF_DMA2D_OPFCCR   0x0034		/* (RW) DMA2D Output PFC Control Register */
  #define DMA2D_OPFCCR_CM    0x00000007	/* Color mode CM[2:0] */
  #define DMA2D_OPFCCR_CM_0  0x00000001
  #define DMA2D_OPFCCR_CM_1  0x00000002
  #define DMA2D_OPFCCR_CM_2  0x00000004
  #define DMA2D_OPFCCR_SB    0x00000100	/* Swap Bytes */
  #define DMA2D_OPFCCR_AI    0x00100000	/* Alpha Inverted */
  #define DMA2D_OPFCCR_RBS   0x00200000	/* Red Blue Swap */
#define TOFF_DMA2D_OCOLR    0x0038		/* (RW) DMA2D Output Color Register */
#define TOFF_DMA2D_OMAR     0x003C		/* (RW) DMA2D Output Memory Address Register */
#define TOFF_DMA2D_OOR      0x0040		/* (RW) DMA2D Output Offset Register */
#define TOFF_DMA2D_NLR      0x0044		/* (RW) DMA2D Number of Line Register */
#define TOFF_DMA2D_LWR      0x0048		/* (RW) DMA2D Line Watermark Register */
#define TOFF_DMA2D_AMTCR    0x004C		/* (RW) DMA2D AHB Master Timer Configuration Register */
  #define DMA2D_AMTCR_EN     0x00000001	/* Enable */
  #define DMA2D_AMTCR_DT     0x0000FF00	/* Dead Time */
#define TOFF_DMA2D_FGCLUT   0x0400		/* (RW) DMA2D Foreground CLUT[256] */
#define TOFF_DMA2D_BGCLUT   0x0800		/* (RW) DMA2D Background CLUT[256] */
#endif


/*
 *  RESET AND CLOCK CONTROL
 */
#define TADR_RCC_BASE       (AHB1PERIPH_BASE + 0x1000)
#define TOFF_RCC_CR         0x0000		/* (RW) RCC clock control register */
  #define RCC_CR_MSION          0x00000001	/* Internal Multi Speed oscillator (MSI) clock enable */
  #define RCC_CR_MSIRDY         0x00000002	/* Internal Multi Speed oscillator (MSI) clock ready flag */
  #define RCC_CR_MSIPLLEN       0x00000004	/* Internal Multi Speed oscillator (MSI) PLL enable */
  #define RCC_CR_MSIRGSEL       0x00000008	/* Internal Multi Speed oscillator (MSI) range selection */
  #define RCC_CR_MSIRANGE       0x000000F0	/* Internal Multi Speed oscillator (MSI) clock Range */
  #define RCC_CR_MSIRANGE_0     0x00000000
  #define RCC_CR_MSIRANGE_1     0x00000010
  #define RCC_CR_MSIRANGE_2     0x00000020
  #define RCC_CR_MSIRANGE_3     0x00000030
  #define RCC_CR_MSIRANGE_4     0x00000040
  #define RCC_CR_MSIRANGE_5     0x00000050
  #define RCC_CR_MSIRANGE_6     0x00000060
  #define RCC_CR_MSIRANGE_7     0x00000070
  #define RCC_CR_MSIRANGE_8     0x00000080
  #define RCC_CR_MSIRANGE_9     0x00000090
  #define RCC_CR_MSIRANGE_10    0x000000A0
  #define RCC_CR_MSIRANGE_11    0x000000B0
  #define RCC_CR_HSION          0x00000100	/* Internal High Speed oscillator (HSI16) clock enable */
  #define RCC_CR_HSIKERON       0x00000200	/* Internal High Speed oscillator (HSI16) clock enable for some IPs Kernel */
  #define RCC_CR_HSIRDY         0x00000400	/* Internal High Speed oscillator (HSI16) clock ready flag */
  #define RCC_CR_HSIASFS        0x00000800	/* HSI16 Automatic Start from Stop */
  #define RCC_CR_HSEON          0x00010000	/* External High Speed oscillator (HSE) clock enable */
  #define RCC_CR_HSERDY         0x00020000	/* External High Speed oscillator (HSE) clock ready */
  #define RCC_CR_HSEBYP         0x00040000	/* External High Speed oscillator (HSE) clock bypass */
  #define RCC_CR_CSSON          0x00080000	/* HSE Clock Security System enable */
  #define RCC_CR_PLLON          0x01000000	/* System PLL clock enable */
  #define RCC_CR_PLLRDY         0x02000000	/* System PLL clock ready */
  #define RCC_CR_PLLSAI1ON      0x04000000	/* SAI1 PLL enable */
  #define RCC_CR_PLLSAI1RDY     0x08000000	/* SAI1 PLL ready */
  #define RCC_CR_PLLSAI2ON      0x10000000	/* SAI2 PLL enable */
  #define RCC_CR_PLLSAI2RDY     0x20000000	/* SAI2 PLL ready */
#define TOFF_RCC_ICSCR      0x0004		/* (RW) RCC Internal clock sources calibration register */
  #define RCC_ICSCR_MSICAL      0x000000FF	/* MSICAL[7:0] bits */
  #define RCC_ICSCR_MSICAL_0    0x00000001
  #define RCC_ICSCR_MSICAL_1    0x00000002
  #define RCC_ICSCR_MSICAL_2    0x00000004
  #define RCC_ICSCR_MSICAL_3    0x00000008
  #define RCC_ICSCR_MSICAL_4    0x00000010
  #define RCC_ICSCR_MSICAL_5    0x00000020
  #define RCC_ICSCR_MSICAL_6    0x00000040
  #define RCC_ICSCR_MSICAL_7    0x00000080
  #define RCC_ICSCR_MSITRIM     0x0000FF00	/* MSITRIM[7:0] bits */
  #define RCC_ICSCR_MSITRIM_0   0x00000100
  #define RCC_ICSCR_MSITRIM_1   0x00000200
  #define RCC_ICSCR_MSITRIM_2   0x00000400
  #define RCC_ICSCR_MSITRIM_3   0x00000800
  #define RCC_ICSCR_MSITRIM_4   0x00001000
  #define RCC_ICSCR_MSITRIM_5   0x00002000
  #define RCC_ICSCR_MSITRIM_6   0x00004000
  #define RCC_ICSCR_MSITRIM_7   0x00008000
  #define RCC_ICSCR_HSICAL      0x00FF0000	/* HSICAL[7:0] bits */
  #define RCC_ICSCR_HSICAL_0    0x00010000
  #define RCC_ICSCR_HSICAL_1    0x00020000
  #define RCC_ICSCR_HSICAL_2    0x00040000
  #define RCC_ICSCR_HSICAL_3    0x00080000
  #define RCC_ICSCR_HSICAL_4    0x00100000
  #define RCC_ICSCR_HSICAL_5    0x00200000
  #define RCC_ICSCR_HSICAL_6    0x00400000
  #define RCC_ICSCR_HSICAL_7    0x00800000
  #define RCC_ICSCR_HSITRIM     0x1F000000	/* HSITRIM[4:0] bits */
  #define RCC_ICSCR_HSITRIM_0   0x01000000
  #define RCC_ICSCR_HSITRIM_1   0x02000000
  #define RCC_ICSCR_HSITRIM_2   0x04000000
  #define RCC_ICSCR_HSITRIM_3   0x08000000
  #define RCC_ICSCR_HSITRIM_4   0x10000000
#define TOFF_RCC_CFGR       0x0008		/* (RW) RCC clock configuration register */
  #define RCC_CFGR_SW           0x00000003	/* SW[1:0] bits (System clock Switch) */
  #define RCC_CFGR_SW_0         0x00000001
  #define RCC_CFGR_SW_1         0x00000002
  #define RCC_CFGR_SW_MSI       0x00000000	/* MSI oscillator selection as system clock */
  #define RCC_CFGR_SW_HSI       0x00000001	/* HSI16 oscillator selection as system clock */
  #define RCC_CFGR_SW_HSE       0x00000002	/* HSE oscillator selection as system clock */
  #define RCC_CFGR_SW_PLL       0x00000003	/* PLL selection as system clock */
  #define RCC_CFGR_SWS          0x0000000C	/* SWS[1:0] bits (System Clock Switch Status) */
  #define RCC_CFGR_SWS_0        0x00000004
  #define RCC_CFGR_SWS_1        0x00000008
  #define RCC_CFGR_SWS_MSI      0x00000000	/* MSI oscillator used as system clock */
  #define RCC_CFGR_SWS_HSI      0x00000004	/* HSI16 oscillator used as system clock */
  #define RCC_CFGR_SWS_HSE      0x00000008	/* HSE oscillator used as system clock */
  #define RCC_CFGR_SWS_PLL      0x0000000C	/* PLL used as system clock */
  #define RCC_CFGR_HPRE         0x000000F0	/* HPRE[3:0] bits (AHB prescaler) */
  #define RCC_CFGR_HPRE_0       0x00000010
  #define RCC_CFGR_HPRE_1       0x00000020
  #define RCC_CFGR_HPRE_2       0x00000040
  #define RCC_CFGR_HPRE_3       0x00000080
  #define RCC_CFGR_HPRE_DIV1    0x00000000	/* SYSCLK not divided */
  #define RCC_CFGR_HPRE_DIV2    0x00000080	/* SYSCLK divided by 2 */
  #define RCC_CFGR_HPRE_DIV4    0x00000090	/* SYSCLK divided by 4 */
  #define RCC_CFGR_HPRE_DIV8    0x000000A0	/* SYSCLK divided by 8 */
  #define RCC_CFGR_HPRE_DIV16   0x000000B0	/* SYSCLK divided by 16 */
  #define RCC_CFGR_HPRE_DIV64   0x000000C0	/* SYSCLK divided by 64 */
  #define RCC_CFGR_HPRE_DIV128  0x000000D0	/* SYSCLK divided by 128 */
  #define RCC_CFGR_HPRE_DIV256  0x000000E0	/* SYSCLK divided by 256 */
  #define RCC_CFGR_HPRE_DIV512  0x000000F0	/* SYSCLK divided by 512 */
  #define RCC_CFGR_PPRE1        0x00000700	/* PRE1[2:0] bits (APB2 prescaler) */
  #define RCC_CFGR_PPRE1_0      0x00000100
  #define RCC_CFGR_PPRE1_1      0x00000200
  #define RCC_CFGR_PPRE1_2      0x00000400
  #define RCC_CFGR_PPRE1_DIV1   0x00000000	/* HCLK not divided */
  #define RCC_CFGR_PPRE1_DIV2   0x00000400	/* HCLK divided by 2 */
  #define RCC_CFGR_PPRE1_DIV4   0x00000500	/* HCLK divided by 4 */
  #define RCC_CFGR_PPRE1_DIV8   0x00000600	/* HCLK divided by 8 */
  #define RCC_CFGR_PPRE1_DIV16  0x00000700	/* HCLK divided by 16 */
  #define RCC_CFGR_PPRE2        0x00003800	/* PRE2[2:0] bits (APB2 prescaler) */
  #define RCC_CFGR_PPRE2_0      0x00000800
  #define RCC_CFGR_PPRE2_1      0x00001000
  #define RCC_CFGR_PPRE2_2      0x00002000
  #define RCC_CFGR_PPRE2_DIV1   0x00000000	/* HCLK not divided */
  #define RCC_CFGR_PPRE2_DIV2   0x00002000	/* HCLK divided by 2 */
  #define RCC_CFGR_PPRE2_DIV4   0x00002800	/* HCLK divided by 4 */
  #define RCC_CFGR_PPRE2_DIV8   0x00003000	/* HCLK divided by 8 */
  #define RCC_CFGR_PPRE2_DIV16  0x00003800	/* HCLK divided by 16 */
  #define RCC_CFGR_STOPWUCK     0x00008000	/* Wake Up from stop and CSS backup clock selection */
  #define RCC_CFGR_MCOSEL       0x07000000	/* MCOSEL [2:0] bits (Clock output selection) */
  #define RCC_CFGR_MCOSEL_0     0x01000000
  #define RCC_CFGR_MCOSEL_1     0x02000000
  #define RCC_CFGR_MCOSEL_2     0x04000000
  #define RCC_CFGR_MCOPRE       0x70000000	/* MCO prescaler */
  #define RCC_CFGR_MCOPRE_0     0x10000000
  #define RCC_CFGR_MCOPRE_1     0x20000000
  #define RCC_CFGR_MCOPRE_2     0x40000000
  #define RCC_CFGR_MCOPRE_DIV1  0x00000000	/* MCO is divided by 1 */
  #define RCC_CFGR_MCOPRE_DIV2  0x10000000	/* MCO is divided by 2 */
  #define RCC_CFGR_MCOPRE_DIV4  0x20000000	/* MCO is divided by 4 */
  #define RCC_CFGR_MCOPRE_DIV8  0x30000000	/* MCO is divided by 8 */
  #define RCC_CFGR_MCOPRE_DIV16 0x40000000	/* MCO is divided by 16 */
  #define RCC_CFGR_MCO_PRE      RCC_CFGR_MCOPRE
  #define RCC_CFGR_MCO_PRE_1    RCC_CFGR_MCOPRE_DIV1
  #define RCC_CFGR_MCO_PRE_2    RCC_CFGR_MCOPRE_DIV2
  #define RCC_CFGR_MCO_PRE_4    RCC_CFGR_MCOPRE_DIV4
  #define RCC_CFGR_MCO_PRE_8    RCC_CFGR_MCOPRE_DIV8
  #define RCC_CFGR_MCO_PRE_16   RCC_CFGR_MCOPRE_DIV16
#define TOFF_RCC_PLLCFGR    0x000C		/* (RW) RCC system PLL configuration register */
  #define RCC_PLLCFGR_PLLSRC    0x00000003
  #define RCC_PLLCFGR_PLLSRC_MSI 0x00000001	/* MSI oscillator source clock selected */
  #define RCC_PLLCFGR_PLLSRC_HSI 0x00000002	/* HSI16 oscillator source clock selected */
  #define RCC_PLLCFGR_PLLSRC_HSE 0x00000003	/* HSE oscillator source clock selected */
  #define RCC_PLLCFGR_PLLM      0x00000070
  #define RCC_PLLCFGR_PLLM_0    0x00000010
  #define RCC_PLLCFGR_PLLM_1    0x00000020
  #define RCC_PLLCFGR_PLLM_2    0x00000040
  #define RCC_PLLCFGR_PLLN      0x00007F00
  #define RCC_PLLCFGR_PLLN_0    0x00000100
  #define RCC_PLLCFGR_PLLN_1    0x00000200
  #define RCC_PLLCFGR_PLLN_2    0x00000400
  #define RCC_PLLCFGR_PLLN_3    0x00000800
  #define RCC_PLLCFGR_PLLN_4    0x00001000
  #define RCC_PLLCFGR_PLLN_5    0x00002000
  #define RCC_PLLCFGR_PLLN_6    0x00004000
  #define RCC_PLLCFGR_PLLPEN    0x00010000
  #define RCC_PLLCFGR_PLLP      0x00020000
  #define RCC_PLLCFGR_PLLQEN    0x00100000
  #define RCC_PLLCFGR_PLLQ      0x00600000
  #define RCC_PLLCFGR_PLLQ_0    0x00200000
  #define RCC_PLLCFGR_PLLQ_1    0x00400000
  #define RCC_PLLCFGR_PLLREN    0x01000000
  #define RCC_PLLCFGR_PLLR      0x06000000
  #define RCC_PLLCFGR_PLLR_0    0x02000000
  #define RCC_PLLCFGR_PLLR_1    0x04000000
#define TOFF_RCC_PLLSAI1CFGR 0x0010		/* (RW) RCC PLL SAI1 configuration register */
  #define RCC_PLLSAI1CFGR_PLLSAI1N   0x00007F00
  #define RCC_PLLSAI1CFGR_PLLSAI1PEN 0x00010000
  #define RCC_PLLSAI1CFGR_PLLSAI1P   0x00020000
  #define RCC_PLLSAI1CFGR_PLLSAI1QEN 0x00100000
  #define RCC_PLLSAI1CFGR_PLLSAI1Q   0x00600000
  #define RCC_PLLSAI1CFGR_PLLSAI1REN 0x01000000
  #define RCC_PLLSAI1CFGR_PLLSAI1R   0x06000000
#define TOFF_RCC_PLLSAI2CFGR 0x0014		/* (RW) RCC PLL SAI2 configuration register */
  #define RCC_PLLSAI2CFGR_PLLSAI2N   0x00007F00
  #define RCC_PLLSAI2CFGR_PLLSAI2PEN 0x00010000
  #define RCC_PLLSAI2CFGR_PLLSAI2P   0x00020000
  #define RCC_PLLSAI2CFGR_PLLSAI2REN 0x01000000
  #define RCC_PLLSAI2CFGR_PLLSAI2R   0x06000000
#define TOFF_RCC_CIER       0x0018		/* (RW) RCC clock interrupt enable register */
  #define RCC_CIER_LSIRDYIE     0x00000001
  #define RCC_CIER_LSERDYIE     0x00000002
  #define RCC_CIER_MSIRDYIE     0x00000004
  #define RCC_CIER_HSIRDYIE     0x00000008
  #define RCC_CIER_HSERDYIE     0x00000010
  #define RCC_CIER_PLLRDYIE     0x00000020
  #define RCC_CIER_PLLSAI1RDYIE 0x00000040
  #define RCC_CIER_PLLSAI2RDYIE 0x00000080
  #define RCC_CIER_LSECSSIE     0x00000200
#define TOFF_RCC_CIFR       0x001C		/* (RW) RCC clock interrupt flag register */
  #define RCC_CIFR_LSIRDYF      0x00000001
  #define RCC_CIFR_LSERDYF      0x00000002
  #define RCC_CIFR_MSIRDYF      0x00000004
  #define RCC_CIFR_HSIRDYF      0x00000008
  #define RCC_CIFR_HSERDYF      0x00000010
  #define RCC_CIFR_PLLRDYF      0x00000020
  #define RCC_CIFR_PLLSAI1RDYF  0x00000040
  #define RCC_CIFR_PLLSAI2RDYF  0x00000080
  #define RCC_CIFR_CSSF         0x00000100
  #define RCC_CIFR_LSECSSF      0x00000200
#define TOFF_RCC_CICR       0x0020		/* (RW) RCC clock interrupt clear register */
  #define RCC_CICR_LSIRDYC      0x00000001
  #define RCC_CICR_LSERDYC      0x00000002
  #define RCC_CICR_MSIRDYC      0x00000004
  #define RCC_CICR_HSIRDYC      0x00000008
  #define RCC_CICR_HSERDYC      0x00000010
  #define RCC_CICR_PLLRDYC      0x00000020
  #define RCC_CICR_PLLSAI1RDYC  0x00000040
  #define RCC_CICR_PLLSAI2RDYC  0x00000080
  #define RCC_CICR_CSSC         0x00000100
  #define RCC_CICR_LSECSSC      0x00000200
#define TOFF_RCC_AHB1RSTR   0x0028		/* (RW) RCC AHB1 peripheral reset register */
  #define RCC_AHB1RSTR_DMA1RST  0x00000001	/* DMA1 reset */
  #define RCC_AHB1RSTR_DMA2RST  0x00000002	/* DMA2 reset */
  #define RCC_AHB1RSTR_FLASHRST 0x00000100	/* FLASH reset */
  #define RCC_AHB1RSTR_CRCRST   0x00001000	/* CRC reset */
  #define RCC_AHB1RSTR_TSCRST   0x00010000	/* TSC reset */
#define TOFF_RCC_AHB2RSTR   0x002C		/* (RW) RCC AHB2 peripheral reset register */
  #define RCC_AHB2RSTR_GPIOARST 0x00000001	/* GPIOA reset */
  #define RCC_AHB2RSTR_GPIOBRST 0x00000002	/* GPIOB reset */
  #define RCC_AHB2RSTR_GPIOCRST 0x00000004	/* GPIOC reset */
  #define RCC_AHB2RSTR_GPIODRST 0x00000008	/* GPIOD reset */
  #define RCC_AHB2RSTR_GPIOERST 0x00000010	/* GPIOE reset */
  #define RCC_AHB2RSTR_GPIOFRST 0x00000020	/* GPIOF reset */
  #define RCC_AHB2RSTR_GPIOGRST 0x00000040	/* GPIOG reset */
  #define RCC_AHB2RSTR_GPIOHRST 0x00000080	/* GPIOH reset */
  #define RCC_AHB2RSTR_OTGFSRST 0x00001000	/* USB_OTG FS reset */
  #define RCC_AHB2RSTR_ADCRST   0x00002000	/* ADC reset */
  #define RCC_AHB2RSTR_RNGRST   0x00040000	/* RNG reset */
#define TOFF_RCC_AHB3RSTR   0x0030		/* (RW) RCC AHB3 peripheral reset register */
  #define RCC_AHB3RSTR_FMCRST   0x00000001	/* FMC reset */
  #define RCC_AHB3RSTR_QSPIRST  0x00000100	/* QSPI reset */
#define TOFF_RCC_APB1RSTR1  0x0038		/* (RW) RCC APB1 peripheral reset register 1 */
  #define RCC_APB1RSTR1_TIM2RST   0x00000001	/* TIMER2 reset */
  #define RCC_APB1RSTR1_TIM3RST   0x00000002	/* TIMER3 reset */
  #define RCC_APB1RSTR1_TIM4RST   0x00000004	/* TIMER4 reset */
  #define RCC_APB1RSTR1_TIM5RST   0x00000008	/* TIMER5 reset */
  #define RCC_APB1RSTR1_TIM6RST   0x00000010	/* TIMER6 reset */
  #define RCC_APB1RSTR1_TIM7RST   0x00000020	/* TIMER7 reset */
  #define RCC_APB1RSTR1_LCDRST    0x00000200	/* LCD reset */
  #define RCC_APB1RSTR1_SPI2RST   0x00004000	/* SPI2 reset */
  #define RCC_APB1RSTR1_SPI3RST   0x00008000	/* SPI3 reset */
  #define RCC_APB1RSTR1_USART2RST 0x00020000	/* USART2 reset */
  #define RCC_APB1RSTR1_USART3RST 0x00040000	/* USART3 reset */
  #define RCC_APB1RSTR1_UART4RST  0x00080000	/* UART4 reset */
  #define RCC_APB1RSTR1_UART5RST  0x00100000	/* UART5 reset */
  #define RCC_APB1RSTR1_I2C1RST   0x00200000	/* I2C1 reset */
  #define RCC_APB1RSTR1_I2C2RST   0x00400000	/* I2C2 reset */
  #define RCC_APB1RSTR1_I2C3RST   0x00800000	/* I2C1 reset */
  #define RCC_APB1RSTR1_CAN1RST   0x02000000	/* CAN1 reset */
#if !defined(TOPPERS_STM32L476_DISCOVERY) && !defined(TOPPERS_STM32L476_NUCLEO64)
  #define RCC_APB1RSTR1_CRSRST    0x01000000
#endif
  #define RCC_APB1RSTR1_PWRRST    0x10000000	/* PWR reset */
  #define RCC_APB1RSTR1_DAC1RST   0x20000000	/* DAC1 reset */
  #define RCC_APB1RSTR1_OPAMPRST  0x40000000	/* OPRAM reset */
  #define RCC_APB1RSTR1_LPTIM1RST 0x80000000	/* LPTIM1 */
#define TOFF_RCC_APB1RSTR2  0x003C		/* (RW) RCC APB1 peripheral reset register 2 */
  #define RCC_APB1RSTR2_LPUART1RST 0x00000001	/* LPUART1 reset */
  #define RCC_APB1RSTR2_SWPMI1RST  0x00000004	/* SWPMI1 reset */
  #define RCC_APB1RSTR2_LPTIM2RST  0x00000020	/* LPTIMER2 reset */
#define TOFF_RCC_APB2RSTR   0x0040		/* (RW) RCC APB2 peripheral reset register */
  #define RCC_APB2RSTR_SYSCFGRST  0x00000001	/* SYSCFG reset */
  #define RCC_APB2RSTR_SDMMC1RST  0x00000400	/* SDMMAC reset */
  #define RCC_APB2RSTR_TIM1RST    0x00000800	/* TIMER1 reset */
  #define RCC_APB2RSTR_SPI1RST    0x00001000	/* SPI1 reset */
  #define RCC_APB2RSTR_TIM8RST    0x00002000	/* TIMER8 reset */
  #define RCC_APB2RSTR_USART1RST  0x00004000	/* USART1 reset */
  #define RCC_APB2RSTR_TIM15RST   0x00010000	/* TIMER15 reset */
  #define RCC_APB2RSTR_TIM16RST   0x00020000	/* TIMER16 reset */
  #define RCC_APB2RSTR_TIM17RST   0x00040000	/* TIMER17 reset */
  #define RCC_APB2RSTR_SAI1RST    0x00200000	/* SAI1 reset */
  #define RCC_APB2RSTR_SAI2RST    0x00400000	/* SAI2 reset */
  #define RCC_APB2RSTR_DFSDM1RST  0x01000000	/* DFSDM1 reset */
#define TOFF_RCC_AHB1ENR    0x0048		/* (RW) RCC AHB1 peripheral clocks enable register */
  #define RCC_AHB1ENR_DMA1EN    0x00000001	/* DMA1 clock clock enable */
  #define RCC_AHB1ENR_DMA2EN    0x00000002	/* DMA2 clock enable */
#if !defined(TOPPERS_STM32L476_DISCOVERY) && !defined(TOPPERS_STM32L476_NUCLEO64)
  #define RCC_AHB1ENR_DMAMUX1EN 0x00000004	/* DMAMUX clock enable */
#endif
  #define RCC_AHB1ENR_FLASHEN   0x00000100	/* FLASH clock enable */
  #define RCC_AHB1ENR_CRCEN     0x00001000	/* CRC clock enable */
  #define RCC_AHB1ENR_TSCEN     0x00010000	/* TSC clock enable */
#if !defined(TOPPERS_STM32L476_DISCOVERY) && !defined(TOPPERS_STM32L476_NUCLEO64)
  #define RCC_AHB1ENR_DMA2DEN   0x00020000	/* DMA2D clock enable */
#endif
#define TOFF_RCC_AHB2ENR    0x004C		/* (RW) RCC AHB2 peripheral clocks clock enable register */
  #define RCC_AHB2ENR_GPIOAEN   0x00000001	/* GPIOA clock enable */
  #define RCC_AHB2ENR_GPIOBEN   0x00000002	/* GPIOB clock enable */
  #define RCC_AHB2ENR_GPIOCEN   0x00000004	/* GPIOC clock enable */
  #define RCC_AHB2ENR_GPIODEN   0x00000008	/* GPIOD clock enable */
  #define RCC_AHB2ENR_GPIOEEN   0x00000010	/* GPIOE clock enable */
  #define RCC_AHB2ENR_GPIOFEN   0x00000020	/* GPIOF clock enable */
  #define RCC_AHB2ENR_GPIOGEN   0x00000040	/* GPIOG clock enable */
  #define RCC_AHB2ENR_GPIOHEN   0x00000080	/* GPIOH clock enable */
  #define RCC_AHB2ENR_OTGFSEN   0x00001000	/* USB_OTG FS clock enable */
  #define RCC_AHB2ENR_ADCEN     0x00002000	/* ADC clock enable */
  #define RCC_AHB2ENR_RNGEN     0x00040000	/* RNG clock enable */
#define TOFF_RCC_AHB3ENR    0x0050		/* (RW) RCC AHB3 peripheral clocks clock enable register */
  #define RCC_AHB3ENR_FMCEN     0x00000001	/* FMC clock enable */
  #define RCC_AHB3ENR_QSPIEN    0x00000100	/* QUADSPI clock enable */
#define TOFF_RCC_APB1ENR1   0x0058		/* (RW) RCC APB1 peripheral clocks clock enable register 1 */
  #define RCC_APB1ENR1_TIM2EN   0x00000001	/* TIMER2 clock enable */
  #define RCC_APB1ENR1_TIM3EN   0x00000002	/* TIMER3 clock enable */
  #define RCC_APB1ENR1_TIM4EN   0x00000004	/* TIMER4 clock enable */
  #define RCC_APB1ENR1_TIM5EN   0x00000008	/* TIMER5 clock enable */
  #define RCC_APB1ENR1_TIM6EN   0x00000010	/* TIMER6 clock enable	 */
  #define RCC_APB1ENR1_TIM7EN   0x00000020	/* TIMER7 clock enable */
  #define RCC_APB1ENR1_LCDEN    0x00000200	/* LCD clock enable */
  #define RCC_APB1ENR1_WWDGEN   0x00000800	/* WWDG clock enable */
  #define RCC_APB1ENR1_SPI2EN   0x00004000	/* SPI2 clock enable */
  #define RCC_APB1ENR1_SPI3EN   0x00008000	/* SPI3 clock enable */
  #define RCC_APB1ENR1_USART2EN 0x00020000	/* USART2 clock enable */
  #define RCC_APB1ENR1_USART3EN 0x00040000	/* USART3 clock enable */
  #define RCC_APB1ENR1_UART4EN  0x00080000	/* UART4 clock enable */
  #define RCC_APB1ENR1_UART5EN  0x00100000	/* UART5 clock enable */
  #define RCC_APB1ENR1_I2C1EN   0x00200000	/* I2C1 clock enable */
  #define RCC_APB1ENR1_I2C2EN   0x00400000	/* I2C2 clock enable */
  #define RCC_APB1ENR1_I2C3EN   0x00800000	/* I2C3 clock enable */
#if !defined(TOPPERS_STM32L476_DISCOVERY) && !defined(TOPPERS_STM32L476_NUCLEO64)
  #define RCC_APB1ENR1_CRSEN    0x01000000
#endif
  #define RCC_APB1ENR1_CAN1EN   0x02000000	/* CAN1 clock enable */
  #define RCC_APB1ENR1_PWREN    0x10000000	/* PWR clock enable */
  #define RCC_APB1ENR1_DAC1EN   0x20000000	/* DAC1 clock enable */
  #define RCC_APB1ENR1_OPAMPEN  0x40000000	/* OPAM clock enable */
  #define RCC_APB1ENR1_LPTIM1EN 0x80000000	/* LPTIMER1 clock enable */
#define TOFF_RCC_APB1ENR2   0x005C		/* (RW) RCC APB1 peripheral clocks enable register 2 */
  #define RCC_APB1ENR2_LPUART1EN 0x00000001	/* LPUART1 clock enable */
  #define RCC_APB1ENR2_SWPMI1EN 0x00000004	/* SWPMI clock enable */
  #define RCC_APB1ENR2_LPTIM2EN 0x00000020	/* LPTIMER2 clock enable */
#define TOFF_RCC_APB2ENR    0x0060		/* (RW) RCC APB2 peripheral clocks enable register */
  #define RCC_APB2ENR_SYSCFGEN  0x00000001	/* SYSCFG clock enable */
  #define RCC_APB2ENR_FWEN      0x00000080	/* FW clock enable */
  #define RCC_APB2ENR_SDMMC1EN  0x00000400	/* SDMMC clock enable */
  #define RCC_APB2ENR_TIM1EN    0x00000800	/* TIMER1 clock enable */
  #define RCC_APB2ENR_SPI1EN    0x00001000	/* SPI1 clock enable */
  #define RCC_APB2ENR_TIM8EN    0x00002000	/* TIMER8 clock enable */
  #define RCC_APB2ENR_USART1EN  0x00004000	/* USART1 clock enable */
  #define RCC_APB2ENR_TIM15EN   0x00010000	/* TIMER15 clock enable */
  #define RCC_APB2ENR_TIM16EN   0x00020000	/* TIMER16 clock enable */
  #define RCC_APB2ENR_TIM17EN   0x00040000	/* TIMER17 clock enable */
  #define RCC_APB2ENR_SAI1EN    0x00200000	/* SAI1 clock enable */
  #define RCC_APB2ENR_SAI2EN    0x00400000	/* SAI2 clock enable */
  #define RCC_APB2ENR_DFSDM1EN  0x01000000	/* DFSDM1 clock enable */
#define TOFF_RCC_AHB1SMENR  0x0068		/* (RW) RCC AHB1 peripheral clocks enable in sleep and stop modes register */
  #define RCC_AHB1SMENR_DMA1SMEN  0x00000001	/* DMA1 clock enabled in sleep mode */
  #define RCC_AHB1SMENR_DMA2SMEN  0x00000002	/* DMA2 clock enabled in sleep mode */
  #define RCC_AHB1SMENR_FLASHSMEN 0x00000100	/* FLASH clock enabled in sleep mode */
  #define RCC_AHB1SMENR_SRAM1SMEN 0x00000200	/* SRAM1 clock enabled in sleep mode */
  #define RCC_AHB1SMENR_CRCSMEN   0x00001000	/* CRC clock enabled in sleep mode */
  #define RCC_AHB1SMENR_TSCSMEN   0x00010000	/* TSC clock enabled in sleep mode */
#define TOFF_RCC_AHB2SMENR  0x006C		/* (RW) RCC AHB2 peripheral clocks enable in sleep and stop modes register */
  #define RCC_AHB2SMENR_GPIOASMEN 0x00000001	/* GPIOA clock enabled in sleep mode */
  #define RCC_AHB2SMENR_GPIOBSMEN 0x00000002	/* GPIOB clock enabled in sleep mode */
  #define RCC_AHB2SMENR_GPIOCSMEN 0x00000004	/* GPIOC clock enabled in sleep mode */
  #define RCC_AHB2SMENR_GPIODSMEN 0x00000008	/* GPIOD clock enabled in sleep mode */
  #define RCC_AHB2SMENR_GPIOESMEN 0x00000010	/* GPIOE clock enabled in sleep mode */
  #define RCC_AHB2SMENR_GPIOFSMEN 0x00000020	/* GPIOF clock enabled in sleep mode */
  #define RCC_AHB2SMENR_GPIOGSMEN 0x00000040	/* GPIOG clock enabled in sleep mode */
  #define RCC_AHB2SMENR_GPIOHSMEN 0x00000080	/* GPIOH clock enabled in sleep mode */
  #define RCC_AHB2SMENR_SRAM2SMEN 0x00000200	/* SRAM2 clock enabled in sleep mode */
  #define RCC_AHB2SMENR_OTGFSSMEN 0x00001000	/* USB_OTG FS clock enabled in sleep mode */
  #define RCC_AHB2SMENR_ADCSMEN   0x00002000	/* ADC clock enabled in sleep mode */
  #define RCC_AHB2SMENR_RNGSMEN   0x00040000	/* RNG clock enabled in sleep mode */
#define TOFF_RCC_AHB3SMENR  0x0070		/* (RW) RCC AHB3 peripheral clocks enable in sleep and stop modes register */
  #define RCC_AHB3SMENR_FMCSMEN   0x00000001	/* FMC clock enabled in sleep mode */
  #define RCC_AHB3SMENR_QSPISMEN  0x00000100	/* QUADSPI clock enabled in sleep mode */
#define TOFF_RCC_APB1SMENR1 0x0078		/* (RW) RCC APB1 peripheral clocks enable in sleep mode and stop modes register 1 */
  #define RCC_APB1SMENR1_TIM2SMEN 0x00000001	/* TIM2 clock enabled in sleep mode */
  #define RCC_APB1SMENR1_TIM3SMEN 0x00000002	/* TIM3 clock enabled in sleep mode */
  #define RCC_APB1SMENR1_TIM4SMEN 0x00000004	/* TIM4 clock enabled in sleep mode */
  #define RCC_APB1SMENR1_TIM5SMEN 0x00000008	/* TIM5 clock enabled in sleep mode */
  #define RCC_APB1SMENR1_TIM6SMEN 0x00000010	/* TIM6 clock enabled in sleep mode */
  #define RCC_APB1SMENR1_TIM7SMEN 0x00000020	/* TIM7 clock enabled in sleep mode */
  #define RCC_APB1SMENR1_LCDSMEN  0x00000200	/* LCD clock enabled in sleep mode */
  #define RCC_APB1SMENR1_WWDGSMEN 0x00000800	/* WWDG clock enabled in sleep mode */
  #define RCC_APB1SMENR1_SPI2SMEN 0x00004000	/* SPI2 clock enabled in sleep mode */
  #define RCC_APB1SMENR1_SPI3SMEN 0x00008000	/* SPI3 clock enabled in sleep mode */
  #define RCC_APB1SMENR1_USART2SMEN 0x00020000	/* USART2 clock enabled in sleep mode */
  #define RCC_APB1SMENR1_USART3SMEN 0x00040000	/* USART3 clock enabled in sleep mode */
  #define RCC_APB1SMENR1_UART4SMEN  0x00080000	/* UART4 clock enabled in sleep mode */
  #define RCC_APB1SMENR1_UART5SMEN  0x00100000	/* UART5 clock enabled in sleep mode */
  #define RCC_APB1SMENR1_I2C1SMEN 0x00200000	/* I2C1 clock enabled in sleep mode */
  #define RCC_APB1SMENR1_I2C2SMEN 0x00400000	/* I2C2 clock enabled in sleep mode */
  #define RCC_APB1SMENR1_I2C3SMEN 0x00800000	/* I2C3 clock enabled in sleep mode */
  #define RCC_APB1SMENR1_CAN1SMEN 0x02000000	/* CAN1 clock enabled in sleep mode */
  #define RCC_APB1SMENR1_PWRSMEN  0x10000000	/* PWR clock enabled in sleep mode */
  #define RCC_APB1SMENR1_DAC1SMEN 0x20000000	/* DAC1 clock enabled in sleep mode */
  #define RCC_APB1SMENR1_OPAMPSMEN  0x40000000	/* OPAMP clock enabled in sleep mode */
  #define RCC_APB1SMENR1_LPTIM1SMEN 0x80000000	/* LPTIM1 clock enabled in sleep mode */
#define TOFF_RCC_APB1SMENR2 0x007C		/* (RW) RCC APB1 peripheral clocks enable in sleep mode and stop modes register 2 */
  #define RCC_APB1SMENR2_LPUART1SMEN 0x00000001	/* LPUART1 clock enabled in sleep mode */
  #define RCC_APB1SMENR2_SWPMI1SMEN 0x00000004	/* SWPMI clock enabled in sleep mode */
  #define RCC_APB1SMENR2_LPTIM2SMEN 0x00000020	/* LPTIM2 clock enabled in sleep mode */
#define TOFF_RCC_APB2SMENR  0x0080		/* (RW) RCC APB2 peripheral clocks enable in sleep mode and stop modes register */
  #define RCC_APB2SMENR_SYSCFGSMEN  0x00000001	/* SYSCFG clock enabled in sleep mode */
  #define RCC_APB2SMENR_SDMMC1SMEN  0x00000400	/* SDMMC1 clock enabled in sleep mode */
  #define RCC_APB2SMENR_TIM1SMEN    0x00000800	/* TIM1 clock enabled in sleep mode */
  #define RCC_APB2SMENR_SPI1SMEN    0x00001000	/* SPI1 clock enabled in sleep mode */
  #define RCC_APB2SMENR_TIM8SMEN    0x00002000	/* TIM8 clock enabled in sleep mode */
  #define RCC_APB2SMENR_USART1SMEN  0x00004000	/* USART1 clock enabled in sleep mode */
  #define RCC_APB2SMENR_TIM15SMEN   0x00010000	/* TIM15 clock enabled in sleep mode */
  #define RCC_APB2SMENR_TIM16SMEN   0x00020000	/* TIM16 clock enabled in sleep mode */
  #define RCC_APB2SMENR_TIM17SMEN   0x00040000	/* TIM17 clock enabled in sleep mode */
  #define RCC_APB2SMENR_SAI1SMEN    0x00200000	/* SAI1 clock enabled in sleep mode */
  #define RCC_APB2SMENR_SAI2SMEN    0x00400000	/* SAI2 clock enabled in sleep mode */
  #define RCC_APB2SMENR_DFSDM1SMEN  0x01000000	/* DFSDM1 clock enabled in sleep mode */
#define TOFF_RCC_CCIPR      0x0088		/* (RW) RCC peripherals independent clock configuration register */
  #define RCC_CCIPR_USART1SEL   0x00000003	/* USART1SEL[1:0] bits */
  #define RCC_CCIPR_USART1SEL_0 0x00000001
  #define RCC_CCIPR_USART1SEL_1 0x00000002
  #define RCC_CCIPR_USART2SEL   0x0000000C	/* USART2SEL[1:0] bits */
  #define RCC_CCIPR_USART2SEL_0 0x00000004
  #define RCC_CCIPR_USART2SEL_1 0x00000008
  #define RCC_CCIPR_USART3SEL   0x00000030	/* USART3SEL[1:0] bits */
  #define RCC_CCIPR_USART3SEL_0 0x00000010
  #define RCC_CCIPR_USART3SEL_1 0x00000020
  #define RCC_CCIPR_UART4SEL    0x000000C0	/* UART4SEL[1:0] bits */
  #define RCC_CCIPR_UART4SEL_0  0x00000040
  #define RCC_CCIPR_UART4SEL_1  0x00000080
  #define RCC_CCIPR_UART5SEL    0x00000300	/* UART5SEL[1:0] bits */
  #define RCC_CCIPR_UART5SEL_0  0x00000100
  #define RCC_CCIPR_UART5SEL_1  0x00000200
  #define RCC_CCIPR_LPUART1SEL  0x00000C00	/* LPUART1SEL[1:0] bits */
  #define RCC_CCIPR_LPUART1SEL_0 0x00000400
  #define RCC_CCIPR_LPUART1SEL_1 0x00000800
  #define RCC_CCIPR_I2C1SEL     0x00003000	/* I2C1SEL[1:0] bits */
  #define RCC_CCIPR_I2C1SEL_0   0x00001000
  #define RCC_CCIPR_I2C1SEL_1   0x00002000
  #define RCC_CCIPR_I2C2SEL     0x0000C000	/* I2C2SEL[1:0] bits */
  #define RCC_CCIPR_I2C2SEL_0   0x00004000
  #define RCC_CCIPR_I2C2SEL_1   0x00008000
  #define RCC_CCIPR_I2C3SEL     0x00030000	/* I2C3SEL[1:0] bits */
  #define RCC_CCIPR_I2C3SEL_0   0x00010000
  #define RCC_CCIPR_I2C3SEL_1   0x00020000
  #define RCC_CCIPR_LPTIM1SEL   0x000C0000	/* LPTIM1SEL[1:0] bits */
  #define RCC_CCIPR_LPTIM1SEL_0 0x00040000
  #define RCC_CCIPR_LPTIM1SEL_1 0x00080000
  #define RCC_CCIPR_LPTIM2SEL   0x00300000	/* LPTIM2SEL[1:0] bits */
  #define RCC_CCIPR_LPTIM2SEL_0 0x00100000
  #define RCC_CCIPR_LPTIM2SEL_1 0x00200000
  #define RCC_CCIPR_SAI1SEL     0x00C00000	/* SAI1SEL[1:0] bits */
  #define RCC_CCIPR_SAI1SEL_0   0x00400000
  #define RCC_CCIPR_SAI1SEL_1   0x00800000
  #define RCC_CCIPR_SAI2SEL     0x03000000	/* SAI2SEL[1:0] bits */
  #define RCC_CCIPR_SAI2SEL_0   0x01000000
  #define RCC_CCIPR_SAI2SEL_1   0x02000000
  #define RCC_CCIPR_CLK48SEL    0x0C000000	/* CLK48SEL[1:0] bits */
  #define RCC_CCIPR_CLK48SEL_0  0x04000000
  #define RCC_CCIPR_CLK48SEL_1  0x08000000
  #define RCC_CCIPR_ADCSEL      0x30000000	/* ADCSEL[1:0] bits */
  #define RCC_CCIPR_ADCSEL_0    0x10000000
  #define RCC_CCIPR_ADCSEL_1    0x20000000
  #define RCC_CCIPR_SWPMI1SEL   0x40000000
  #define RCC_CCIPR_DFSDM1SEL   0x80000000
#define TOFF_RCC_BDCR       0x0090		/* (RW) RCC backup domain control register */
  #define RCC_BDCR_LSEON        0x00000001
  #define RCC_BDCR_LSERDY       0x00000002
  #define RCC_BDCR_LSEBYP       0x00000004
  #define RCC_BDCR_LSEDRV       0x00000018
  #define RCC_BDCR_LSEDRV_0     0x00000008
  #define RCC_BDCR_LSEDRV_1     0x00000010
  #define RCC_BDCR_LSECSSON     0x00000020
  #define RCC_BDCR_LSECSSD      0x00000040
  #define RCC_BDCR_RTCSEL       0x00000300
  #define RCC_BDCR_RTCSEL_0     0x00000100
  #define RCC_BDCR_RTCSEL_1     0x00000200
  #define RCC_BDCR_RTCEN        0x00008000
  #define RCC_BDCR_BDRST        0x00010000
  #define RCC_BDCR_LSCOEN       0x01000000
  #define RCC_BDCR_LSCOSEL      0x02000000
#define TOFF_RCC_CSR        0x0094		/* (RW) RCC clock control & status register */
  #define RCC_CSR_LSION         0x00000001	/* Internal Low Speed oscillator enable */
  #define RCC_CSR_LSIRDY        0x00000002	/* Internal Low Speed oscillator Ready */
  #define RCC_CSR_MSISRANGE     0x00000F00
  #define RCC_CSR_MSISRANGE_1   0x00000400
  #define RCC_CSR_MSISRANGE_2   0x00000500
  #define RCC_CSR_MSISRANGE_4   0x00000600
  #define RCC_CSR_MSISRANGE_8   0x00000700
  #define RCC_CSR_RMVF          0x00800000	/* Remove reset flag */
  #define RCC_CSR_FWRSTF        0x01000000	/* Mifare Firewall reset flag */
  #define RCC_CSR_OBLRSTF       0x02000000	/* OBL reset flag */
  #define RCC_CSR_PINRSTF       0x04000000	/* PIN reset flag */
  #define RCC_CSR_BORRSTF       0x08000000
  #define RCC_CSR_SFTRSTF       0x10000000	/* Software Reset flag */
  #define RCC_CSR_IWDGRSTF      0x20000000	/* Independent Watchdog reset flag */
  #define RCC_CSR_WWDGRSTF      0x40000000	/* Window watchdog reset flag */
  #define RCC_CSR_LPWRRSTF      0x80000000	/* Low-Power reset flag */
#if !defined(TOPPERS_STM32L476_DISCOVERY) && !defined(TOPPERS_STM32L476_NUCLEO64)
#define TOFF_RCC_CRRCR      0x0098		/* (RW) RCC clock recovery RC register */
  #define RCC_CRRCR_HSI48ON     0x00000001
  #define RCC_CRRCR_HSI48RDY    0x00000002
  #define RCC_CRRCR_HSI48CAL    0x0000FF80
  #define RCC_CRRCR_HSI48CAL_0  0x00000080
  #define RCC_CRRCR_HSI48CAL_1  0x00000100
  #define RCC_CRRCR_HSI48CAL_2  0x00000200
  #define RCC_CRRCR_HSI48CAL_3  0x00000400
  #define RCC_CRRCR_HSI48CAL_4  0x00000800
  #define RCC_CRRCR_HSI48CAL_5  0x00001000
  #define RCC_CRRCR_HSI48CAL_6  0x00002000
  #define RCC_CRRCR_HSI48CAL_7  0x00004000
  #define RCC_CRRCR_HSI48CAL_8  0x00008000
#define TOFF_RCC_CCIPR2     0x009C		/* (RW) RCC peripherals independent clock configuration register 2 */
  #define RCC_CCIPR2_I2C4SEL    0x00000003
  #define RCC_CCIPR2_I2C4SEL_0  0x00000001
  #define RCC_CCIPR2_I2C4SEL_1  0x00000002
  #define RCC_CCIPR2_DFSDM1SEL  0x00000004
  #define RCC_CCIPR2_ADFSDM1SEL 0x00000018
  #define RCC_CCIPR2_ADFSDM1SEL_0  0x00000008
  #define RCC_CCIPR2_ADFSDM1SEL_1  0x00000010
  #define RCC_CCIPR2_SAI1SEL    0x000000E0
  #define RCC_CCIPR2_SAI1SEL_0  0x00000020
  #define RCC_CCIPR2_SAI1SEL_1  0x00000040
  #define RCC_CCIPR2_SAI1SEL_2  0x00000080
  #define RCC_CCIPR2_SAI2SEL    0x00000700
  #define RCC_CCIPR2_SAI2SEL_0  0x00000100
  #define RCC_CCIPR2_SAI2SEL_1  0x00000200
  #define RCC_CCIPR2_SAI2SEL_2  0x00000400
  #define RCC_CCIPR2_SDMMCSEL   0x00004000
  #define RCC_CCIPR2_PLLSAI2DIVR   0x00030000
  #define RCC_CCIPR2_PLLSAI2DIVR_0 0x00010000
  #define RCC_CCIPR2_PLLSAI2DIVR_1 0x00020000
  #define RCC_CCIPR2_OSPISEL    0x00300000
  #define RCC_CCIPR2_OSPISEL_0  0x00100000
  #define RCC_CCIPR2_OSPISEL_1  0x00200000
#endif


/*
 *  FLASH REGISTERS
 */
#define TADR_FLASH_R_BASE   (AHB1PERIPH_BASE + 0x2000)
#define TOFF_FLASH_ACR      0x0000		/* (RW) FLASH access control register */
#if !defined(TOPPERS_STM32L476_DISCOVERY) && !defined(TOPPERS_STM32L476_NUCLEO64)
  #define FLASH_ACR_LATENCY  0x0000000F
#else
  #define FLASH_ACR_LATENCY  0x00000007
#endif
  #define FLASH_ACR_LATENCY_0WS  0x00000000
  #define FLASH_ACR_LATENCY_1WS  0x00000001
  #define FLASH_ACR_LATENCY_2WS  0x00000002
  #define FLASH_ACR_LATENCY_3WS  0x00000003
  #define FLASH_ACR_LATENCY_4WS  0x00000004
#if !defined(TOPPERS_STM32L476_DISCOVERY) && !defined(TOPPERS_STM32L476_NUCLEO64)
  #define FLASH_ACR_LATENCY_5WS  0x00000005
  #define FLASH_ACR_LATENCY_6WS  0x00000006
  #define FLASH_ACR_LATENCY_7WS  0x00000007
  #define FLASH_ACR_LATENCY_8WS  0x00000008
  #define FLASH_ACR_LATENCY_9WS  0x00000009
  #define FLASH_ACR_LATENCY_10WS 0x0000000A
  #define FLASH_ACR_LATENCY_11WS 0x0000000B
  #define FLASH_ACR_LATENCY_12WS 0x0000000C
  #define FLASH_ACR_LATENCY_13WS 0x0000000D
  #define FLASH_ACR_LATENCY_14WS 0x0000000E
  #define FLASH_ACR_LATENCY_15WS 0x0000000F
#endif

  #define FLASH_ACR_PRFTEN       0x00000100
  #define FLASH_ACR_ICEN     0x00000200
  #define FLASH_ACR_DCEN     0x00000400
  #define FLASH_ACR_ICRST    0x00000800
  #define FLASH_ACR_DCRST    0x00001000
  #define FLASH_ACR_RUN_PD   0x00002000	/* Flash power down mode during run */
  #define FLASH_ACR_SLEEP_PD 0x00004000	/* Flash power down mode during sleep */
#define TOFF_FLASH_PDKEYR   0x0004		/* (RW) Power down key register */
#define TOFF_FLASH_KEYR     0x0008		/* (RW) FLASH key register */
#define TOFF_FLASH_OPTKEYR  0x000C		/* (RW) Option byte key register */
#define TOFF_FLASH_SR       0x0010		/* (RW) Status register */
  #define FLASH_SR_EOP       0x00000001	/* End Of Programming*/
  #define FLASH_SR_OPERR     0x00000002
  #define FLASH_SR_PROGERR   0x00000008
  #define FLASH_SR_WRPERR    0x00000010	/* Write protection error */
  #define FLASH_SR_PGAERR    0x00000020	/* Programming Alignment Error */
  #define FLASH_SR_SIZERR    0x00000040	/* Size error */
  #define FLASH_SR_PGSERR    0x00000080
  #define FLASH_SR_MISERR    0x00000100
  #define FLASH_SR_FASTERR   0x00000200
  #define FLASH_SR_RDERR     0x00004000
  #define FLASH_SR_OPTVERR   0x00008000	/* Option Valid error */
  #define FLASH_SR_BSY       0x00010000	/* Busy */
#define TOFF_FLASH_CR       0x0014		/* (RW) FLASH control register */
  #define FLASH_CR_PG        0x00000001
  #define FLASH_CR_PER       0x00000002
  #define FLASH_CR_MER1      0x00000004
  #define FLASH_CR_PNB       0x000007F8
  #define FLASH_CR_BKER      0x00000800
  #define FLASH_CR_MER2      0x00008000
  #define FLASH_CR_STRT      0x00010000
  #define FLASH_CR_OPTSTRT   0x00020000
  #define FLASH_CR_FSTPG     0x00040000
  #define FLASH_CR_EOPIE     0x01000000
  #define FLASH_CR_ERRIE     0x02000000
  #define FLASH_CR_RDERRIE   0x04000000
  #define FLASH_CR_OBL_LAUNCH 0x08000000
  #define FLASH_CR_OPTLOCK   0x40000000
  #define FLASH_CR_LOCK      0x80000000
#define TOFF_FLASH_ECCR     0x0018		/* (RW) FLASH ECC register */
  #define FLASH_ECCR_ADDR_ECC 0x0007FFFF
  #define FLASH_ECCR_BK_ECC   0x00080000
  #define FLASH_ECCR_SYSF_ECC 0x00100000
  #define FLASH_ECCR_ECCIE    0x01000000
  #define FLASH_ECCR_ECCC     0x40000000
  #define FLASH_ECCR_ECCD     0x80000000
#define TOFF_FLASH_OPTR     0x0020		/* (RW) Option byte register */
  #define FLASH_OPTR_RDP        0x000000FF
  #define FLASH_OPTR_BOR_LEV    0x00000700	/* BOR_LEV[2:0] Brown Out Reset Threshold Level*/
  #define FLASH_OPTR_BOR_LEV_0  0x00000000
  #define FLASH_OPTR_BOR_LEV_1  0x00000100
  #define FLASH_OPTR_BOR_LEV_2  0x00000200
  #define FLASH_OPTR_BOR_LEV_3  0x00000300
  #define FLASH_OPTR_BOR_LEV_4  0x00000400
  #define FLASH_OPTR_nRST_STOP  0x00001000	/* nRST_STOP */
  #define FLASH_OPTR_nRST_STDBY 0x00002000	/* nRST_STDBY */
  #define FLASH_OPTR_nRST_SHDW  0x00004000	/* nRST_SHDW */
  #define FLASH_OPTR_IWDG_SW    0x00010000	/* IWDG_SW */
  #define FLASH_OPTR_IWDG_STOP  0x00020000	/* IWDG_STOP */
  #define FLASH_OPTR_IWDG_STDBY 0x00040000	/* IWDG_STDBY */
  #define FLASH_OPTR_WWDG_SW    0x00080000
  #define FLASH_OPTR_BFB2       0x00100000
  #define FLASH_OPTR_DUALBANK   0x00200000
  #define FLASH_OPTR_nBOOT1     0x00800000
  #define FLASH_OPTR_SRAM2_PE   0x01000000
  #define FLASH_OPTR_SRAM2_RST  0x02000000
#define TOFF_FLASH_PCROP1SR 0x0024		/* (RW) FLASH bank1 PCROP start address register */
  #define FLASH_PCROP1SR_PCROP1 0x0000FFFF
#define TOFF_FLASH_PCROP1ER 0x0028		/* (RW) FLASH bank1 PCROP end address register */
  #define FLASH_PCROP1ER_PCROP1_END 0x0000FFFF
  #define FLASH_PCROP1ER_PCROP_RDP  0x80000000
#define TOFF_FLASH_WRP1AR   0x002C		/* (RW) FLASH bank1 WRP area A address register */
  #define FLASH_WRP1AR_WRP1A_STRT   0x000000FF
  #define FLASH_WRP1AR_WRP1A_END    0x00FF0000
#define TOFF_FLASH_WRP1BR   0x0030		/* (RW) FLASH bank1 WRP area B address register */
  #define FLASH_WRP1BR_WRP1B_STRT   0x000000FF
  #define FLASH_WRP1BR_WRP1B_END    0x00FF0000
#define TOFF_FLASH_PCROP2SR 0x0044		/* (RW) FLASH bank2 PCROP start address register */
  #define FLASH_PCROP2SR_PCROP2_STRT 0x0000FFFF
#define TOFF_FLASH_PCROP2ER 0x0048		/* (RW) FLASH bank2 PCROP end address register */
  #define FLASH_PCROP2ER_PCROP2_END 0x0000FFFF
#define TOFF_FLASH_WRP2AR   0x004C		/* (RW) FLASH bank2 WRP area A address register */
  #define FLASH_WRP2AR_WRP2A_STRT   0x000000FF
  #define FLASH_WRP2AR_WRP2A_END    0x00FF0000
#define TOFF_FLASH_WRP2BR   0x0050		/* (RW) FLASH bank2 WRP area B address register */
  #define FLASH_WRP2BR_WRP2B_STRT   0x000000FF
  #define FLASH_WRP2BR_WRP2B_END    0x00FF0000

/*
 *  CRC CALCULATION UNIT
 */
#define TADR_CRC_BASE       (AHB1PERIPH_BASE + 0x3000)
#define TOFF_CRC_DR         0x0000		/* (RW) CRC Data register */
#define TOFF_CRC_IDR        0x0004		/* (RW-8) CRC Independent data register */
#define TOFF_CRC_CR         0x0008		/* (RW) CRC Control register */
#define TOFF_CRC_INIT       0x0010		/* (RW) Initial CRC value register */
#define TOFF_CRC_POL        0x0014		/* (RW) CRC polynomial register */


/*
 *  TOUCH SENSING CONTROLLER
 */
#define TADR_TSC_BASE       (AHB1PERIPH_BASE + 0x4000)
#define TOFF_TSC_CR         0x0000		/* (RW) TSC control register */
  #define TSC_CR_TSCE        0x00000001	/* Touch sensing controller enable */
  #define TSC_CR_START       0x00000002	/* Start acquisition */
  #define TSC_CR_AM          0x00000004	/* Acquisition mode */
  #define TSC_CR_SYNCPOL     0x00000008	/* Synchronization pin polarity */
  #define TSC_CR_IODEF       0x00000010	/* IO default mode */
  #define TSC_CR_MCV         0x000000E0	/* MCV[2:0] bits (Max Count Value) */
  #define TSC_CR_MCV_0       0x00000020
  #define TSC_CR_MCV_1       0x00000040
  #define TSC_CR_MCV_2       0x00000080
  #define TSC_CR_PGPSC       0x00007000	/* PGPSC[2:0] bits (Pulse Generator Prescaler) */
  #define TSC_CR_PGPSC_0     0x00001000
  #define TSC_CR_PGPSC_1     0x00002000
  #define TSC_CR_PGPSC_2     0x00004000
  #define TSC_CR_SSPSC       0x00008000	/* Spread Spectrum Prescaler */
  #define TSC_CR_SSE         0x00010000	/* Spread Spectrum Enable */
  #define TSC_CR_SSD         0x00FE0000	/* SSD[6:0] bits (Spread Spectrum Deviation) */
  #define TSC_CR_SSD_0       0x00020000
  #define TSC_CR_SSD_1       0x00040000
  #define TSC_CR_SSD_2       0x00080000
  #define TSC_CR_SSD_3       0x00100000
  #define TSC_CR_SSD_4       0x00200000
  #define TSC_CR_SSD_5       0x00400000
  #define TSC_CR_SSD_6       0x00800000
  #define TSC_CR_CTPL        0x0F000000	/* CTPL[3:0] bits (Charge Transfer pulse low) */
  #define TSC_CR_CTPL_0      0x01000000
  #define TSC_CR_CTPL_1      0x02000000
  #define TSC_CR_CTPL_2      0x04000000
  #define TSC_CR_CTPL_3      0x08000000
  #define TSC_CR_CTPH        0xF0000000	/* CTPH[3:0] bits (Charge Transfer pulse high) */
  #define TSC_CR_CTPH_0      0x10000000
  #define TSC_CR_CTPH_1      0x20000000
  #define TSC_CR_CTPH_2      0x40000000
  #define TSC_CR_CTPH_3      0x80000000
#define TOFF_TSC_IER        0x0004		/* (RW) TSC interrupt enable register */
  #define TSC_IER_EOAIE      0x00000001	/* End of acquisition interrupt enable */
  #define TSC_IER_MCEIE      0x00000002	/* Max count error interrupt enable */
#define TOFF_TSC_ICR        0x0008		/* (RW) TSC interrupt clear register */
  #define TSC_ICR_EOAIC      0x00000001	/* End of acquisition interrupt clear */
  #define TSC_ICR_MCEIC      0x00000002	/* Max count error interrupt clear */
#define TOFF_TSC_ISR        0x000C		/* (RW) TSC interrupt status register */
  #define TSC_ISR_EOAF       0x00000001	/* End of acquisition flag */
  #define TSC_ISR_MCEF       0x00000002	/* Max count error flag */
#define TOFF_TSC_IOHCR      0x0010		/* (RW) TSC I/O hysteresis control register */
  #define TSC_IOHCR_G1_IO1   0x00000001	/* GROUP1_IO1 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G1_IO2   0x00000002	/* GROUP1_IO2 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G1_IO3   0x00000004	/* GROUP1_IO3 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G1_IO4   0x00000008	/* GROUP1_IO4 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G2_IO1   0x00000010	/* GROUP2_IO1 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G2_IO2   0x00000020	/* GROUP2_IO2 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G2_IO3   0x00000040	/* GROUP2_IO3 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G2_IO4   0x00000080	/* GROUP2_IO4 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G3_IO1   0x00000100	/* GROUP3_IO1 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G3_IO2   0x00000200	/* GROUP3_IO2 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G3_IO3   0x00000400	/* GROUP3_IO3 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G3_IO4   0x00000800	/* GROUP3_IO4 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G4_IO1   0x00001000	/* GROUP4_IO1 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G4_IO2   0x00002000	/* GROUP4_IO2 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G4_IO3   0x00004000	/* GROUP4_IO3 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G4_IO4   0x00008000	/* GROUP4_IO4 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G5_IO1   0x00010000	/* GROUP5_IO1 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G5_IO2   0x00020000	/* GROUP5_IO2 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G5_IO3   0x00040000	/* GROUP5_IO3 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G5_IO4   0x00080000	/* GROUP5_IO4 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G6_IO1   0x00100000	/* GROUP6_IO1 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G6_IO2   0x00200000	/* GROUP6_IO2 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G6_IO3   0x00400000	/* GROUP6_IO3 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G6_IO4   0x00800000	/* GROUP6_IO4 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G7_IO1   0x01000000	/* GROUP7_IO1 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G7_IO2   0x02000000	/* GROUP7_IO2 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G7_IO3   0x04000000	/* GROUP7_IO3 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G7_IO4   0x08000000	/* GROUP7_IO4 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G8_IO1   0x10000000	/* GROUP8_IO1 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G8_IO2   0x20000000	/* GROUP8_IO2 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G8_IO3   0x40000000	/* GROUP8_IO3 schmitt trigger hysteresis mode */
  #define TSC_IOHCR_G8_IO4   0x80000000	/* GROUP8_IO4 schmitt trigger hysteresis mode */
#define TOFF_TSC_IOASCR     0x0018		/* (RW) TSC I/O analog switch control register */
  #define TSC_IOASCR_G1_IO1  0x00000001	/*GROUP1_IO1 analog switch enable */
  #define TSC_IOASCR_G1_IO2  0x00000002	/* GROUP1_IO2 analog switch enable */
  #define TSC_IOASCR_G1_IO3  0x00000004	/* GROUP1_IO3 analog switch enable */
  #define TSC_IOASCR_G1_IO4  0x00000008	/* GROUP1_IO4 analog switch enable */
  #define TSC_IOASCR_G2_IO1  0x00000010	/* GROUP2_IO1 analog switch enable */
  #define TSC_IOASCR_G2_IO2  0x00000020	/* GROUP2_IO2 analog switch enable */
  #define TSC_IOASCR_G2_IO3  0x00000040	/* GROUP2_IO3 analog switch enable */
  #define TSC_IOASCR_G2_IO4  0x00000080	/* GROUP2_IO4 analog switch enable */
  #define TSC_IOASCR_G3_IO1  0x00000100	/* GROUP3_IO1 analog switch enable */
  #define TSC_IOASCR_G3_IO2  0x00000200	/* GROUP3_IO2 analog switch enable */
  #define TSC_IOASCR_G3_IO3  0x00000400	/* GROUP3_IO3 analog switch enable */
  #define TSC_IOASCR_G3_IO4  0x00000800	/* GROUP3_IO4 analog switch enable */
  #define TSC_IOASCR_G4_IO1  0x00001000	/* GROUP4_IO1 analog switch enable */
  #define TSC_IOASCR_G4_IO2  0x00002000	/* GROUP4_IO2 analog switch enable */
  #define TSC_IOASCR_G4_IO3  0x00004000	/* GROUP4_IO3 analog switch enable */
  #define TSC_IOASCR_G4_IO4  0x00008000	/* GROUP4_IO4 analog switch enable */
  #define TSC_IOASCR_G5_IO1  0x00010000	/* GROUP5_IO1 analog switch enable */
  #define TSC_IOASCR_G5_IO2  0x00020000	/* GROUP5_IO2 analog switch enable */
  #define TSC_IOASCR_G5_IO3  0x00040000	/* GROUP5_IO3 analog switch enable */
  #define TSC_IOASCR_G5_IO4  0x00080000	/* GROUP5_IO4 analog switch enable */
  #define TSC_IOASCR_G6_IO1  0x00100000	/* GROUP6_IO1 analog switch enable */
  #define TSC_IOASCR_G6_IO2  0x00200000	/* GROUP6_IO2 analog switch enable */
  #define TSC_IOASCR_G6_IO3  0x00400000	/* GROUP6_IO3 analog switch enable */
  #define TSC_IOASCR_G6_IO4  0x00800000	/* GROUP6_IO4 analog switch enable */
  #define TSC_IOASCR_G7_IO1  0x01000000	/* GROUP7_IO1 analog switch enable */
  #define TSC_IOASCR_G7_IO2  0x02000000	/* GROUP7_IO2 analog switch enable */
  #define TSC_IOASCR_G7_IO3  0x04000000	/* GROUP7_IO3 analog switch enable */
  #define TSC_IOASCR_G7_IO4  0x08000000	/* GROUP7_IO4 analog switch enable */
  #define TSC_IOASCR_G8_IO   0x10000000	/* GROUP8_IO1 analog switch enable */
  #define TSC_IOASCR_G8_IO2  0x20000000	/* GROUP8_IO2 analog switch enable */
  #define TSC_IOASCR_G8_IO3  0x40000000	/* GROUP8_IO3 analog switch enable */
  #define TSC_IOASCR_G8_IO4  0x80000000	/* GROUP8_IO4 analog switch enable */
#define TOFF_TSC_IOSCR      0x0020		/* (RW) TSC I/O sampling control register */
  #define TSC_IOSCR_G1_IO1   0x00000001	/* GROUP1_IO1 sampling mode */
  #define TSC_IOSCR_G1_IO2   0x00000002	/* GROUP1_IO2 sampling mode */
  #define TSC_IOSCR_G1_IO3   0x00000004	/* GROUP1_IO3 sampling mode */
  #define TSC_IOSCR_G1_IO4   0x00000008	/* GROUP1_IO4 sampling mode */
  #define TSC_IOSCR_G2_IO1   0x00000010	/* GROUP2_IO1 sampling mode */
  #define TSC_IOSCR_G2_IO2   0x00000020	/* GROUP2_IO2 sampling mode */
  #define TSC_IOSCR_G2_IO3   0x00000040	/* GROUP2_IO3 sampling mode */
  #define TSC_IOSCR_G2_IO4   0x00000080	/* GROUP2_IO4 sampling mode */
  #define TSC_IOSCR_G3_IO1   0x00000100	/* GROUP3_IO1 sampling mode */
  #define TSC_IOSCR_G3_IO2   0x00000200	/* GROUP3_IO2 sampling mode */
  #define TSC_IOSCR_G3_IO3   0x00000400	/* GROUP3_IO3 sampling mode */
  #define TSC_IOSCR_G3_IO4   0x00000800	/* GROUP3_IO4 sampling mode */
  #define TSC_IOSCR_G4_IO1   0x00001000	/* GROUP4_IO1 sampling mode */
  #define TSC_IOSCR_G4_IO2   0x00002000	/* GROUP4_IO2 sampling mode */
  #define TSC_IOSCR_G4_IO3   0x00004000	/* GROUP4_IO3 sampling mode */
  #define TSC_IOSCR_G4_IO4   0x00008000	/* GROUP4_IO4 sampling mode */
  #define TSC_IOSCR_G5_IO1   0x00010000	/* GROUP5_IO1 sampling mode */
  #define TSC_IOSCR_G5_IO2   0x00020000	/* GROUP5_IO2 sampling mode */
  #define TSC_IOSCR_G5_IO3   0x00040000	/* GROUP5_IO3 sampling mode */
  #define TSC_IOSCR_G5_IO4   0x00080000	/* GROUP5_IO4 sampling mode */
  #define TSC_IOSCR_G6_IO1   0x00100000	/* GROUP6_IO1 sampling mode */
  #define TSC_IOSCR_G6_IO2   0x00200000	/* GROUP6_IO2 sampling mode */
  #define TSC_IOSCR_G6_IO3   0x00400000	/* GROUP6_IO3 sampling mode */
  #define TSC_IOSCR_G6_IO4   0x00800000	/* GROUP6_IO4 sampling mode */
  #define TSC_IOSCR_G7_IO1   0x01000000	/* GROUP7_IO1 sampling mode */
  #define TSC_IOSCR_G7_IO2   0x02000000	/* GROUP7_IO2 sampling mode */
  #define TSC_IOSCR_G7_IO3   0x04000000	/* GROUP7_IO3 sampling mode */
  #define TSC_IOSCR_G7_IO4   0x08000000	/* GROUP7_IO4 sampling mode */
  #define TSC_IOSCR_G8_IO1   0x10000000	/* GROUP8_IO1 sampling mode */
  #define TSC_IOSCR_G8_IO2   0x20000000	/* GROUP8_IO2 sampling mode */
  #define TSC_IOSCR_G8_IO3   0x40000000	/* GROUP8_IO3 sampling mode */
  #define TSC_IOSCR_G8_IO4   0x80000000	/* GROUP8_IO4 sampling mode */
#define TOFF_TSC_IOCCR      0x0028		/* (RW) TSC I/O channel control register */
  #define TSC_IOCCR_G1_IO1   0x00000001	/* GROUP1_IO1 channel mode */
  #define TSC_IOCCR_G1_IO2   0x00000002	/* GROUP1_IO2 channel mode */
  #define TSC_IOCCR_G1_IO3   0x00000004	/* GROUP1_IO3 channel mode */
  #define TSC_IOCCR_G1_IO4   0x00000008	/* GROUP1_IO4 channel mode */
  #define TSC_IOCCR_G2_IO1   0x00000010	/* GROUP2_IO1 channel mode */
  #define TSC_IOCCR_G2_IO2   0x00000020	/* GROUP2_IO2 channel mode */
  #define TSC_IOCCR_G2_IO3   0x00000040	/* GROUP2_IO3 channel mode */
  #define TSC_IOCCR_G2_IO4   0x00000080	/* GROUP2_IO4 channel mode */
  #define TSC_IOCCR_G3_IO1   0x00000100	/* GROUP3_IO1 channel mode */
  #define TSC_IOCCR_G3_IO2   0x00000200	/* GROUP3_IO2 channel mode */
  #define TSC_IOCCR_G3_IO3   0x00000400	/* GROUP3_IO3 channel mode */
  #define TSC_IOCCR_G3_IO4   0x00000800	/* GROUP3_IO4 channel mode */
  #define TSC_IOCCR_G4_IO1   0x00001000	/* GROUP4_IO1 channel mode */
  #define TSC_IOCCR_G4_IO2   0x00002000	/* GROUP4_IO2 channel mode */
  #define TSC_IOCCR_G4_IO3   0x00004000	/* GROUP4_IO3 channel mode */
  #define TSC_IOCCR_G4_IO4   0x00008000	/* GROUP4_IO4 channel mode */
  #define TSC_IOCCR_G5_IO1   0x00010000	/* GROUP5_IO1 channel mode */
  #define TSC_IOCCR_G5_IO2   0x00020000	/* GROUP5_IO2 channel mode */
  #define TSC_IOCCR_G5_IO3   0x00040000	/* GROUP5_IO3 channel mode */
  #define TSC_IOCCR_G5_IO4   0x00080000	/* GROUP5_IO4 channel mode */
  #define TSC_IOCCR_G6_IO1   0x00100000	/* GROUP6_IO1 channel mode */
  #define TSC_IOCCR_G6_IO2   0x00200000	/* GROUP6_IO2 channel mode */
  #define TSC_IOCCR_G6_IO3   0x00400000	/* GROUP6_IO3 channel mode */
  #define TSC_IOCCR_G6_IO4   0x00800000	/* GROUP6_IO4 channel mode */
  #define TSC_IOCCR_G7_IO1   0x01000000	/* GROUP7_IO1 channel mode */
  #define TSC_IOCCR_G7_IO2   0x02000000	/* GROUP7_IO2 channel mode */
  #define TSC_IOCCR_G7_IO3   0x04000000	/* GROUP7_IO3 channel mode */
  #define TSC_IOCCR_G7_IO4   0x08000000	/* GROUP7_IO4 channel mode */
  #define TSC_IOCCR_G8_IO1   0x10000000	/* GROUP8_IO1 channel mode */
  #define TSC_IOCCR_G8_IO2   0x20000000	/* GROUP8_IO2 channel mode */
  #define TSC_IOCCR_G8_IO3   0x40000000	/* GROUP8_IO3 channel mode */
  #define TSC_IOCCR_G8_IO4   0x80000000	/*GROUP8_IO4 channel mode */
#define TOFF_TSC_IOGCSR     0x0030		/* (RW) TSC I/O group control status register */
  #define TSC_IOGCSR_G1E     0x00000001	/* Analog IO GROUP1 enable */
  #define TSC_IOGCSR_G2E     0x00000002	/* Analog IO GROUP2 enable */
  #define TSC_IOGCSR_G3E     0x00000004	/* Analog IO GROUP3 enable */
  #define TSC_IOGCSR_G4E     0x00000008	/* Analog IO GROUP4 enable */
  #define TSC_IOGCSR_G5E     0x00000010	/* Analog IO GROUP5 enable */
  #define TSC_IOGCSR_G6E     0x00000020	/* Analog IO GROUP6 enable */
  #define TSC_IOGCSR_G7E     0x00000040	/* Analog IO GROUP7 enable */
  #define TSC_IOGCSR_G8E     0x00000080	/* Analog IO GROUP8 enable */
  #define TSC_IOGCSR_G1S     0x00010000	/* Analog IO GROUP1 status */
  #define TSC_IOGCSR_G2S     0x00020000	/* Analog IO GROUP2 status */
  #define TSC_IOGCSR_G3S     0x00040000	/* Analog IO GROUP3 status */
  #define TSC_IOGCSR_G4S     0x00080000	/* Analog IO GROUP4 status */
  #define TSC_IOGCSR_G5S     0x00100000	/* Analog IO GROUP5 status */
  #define TSC_IOGCSR_G6S     0x00200000	/* Analog IO GROUP6 status */
  #define TSC_IOGCSR_G7S     0x00400000	/* Analog IO GROUP7 status */
  #define TSC_IOGCSR_G8S     0x00800000	/* Analog IO GROUP8 status */
#define TOFF_TSC_IOGXCR     0x0034		/* (RW) TSC I/O group x counter register 0x34-50 */
  #define TSC_IOGXCR_CNT     0x00003FFF	/* CNT[13:0] bits (Counter value) */


/*
 *  GENERAL PURPOSE I/O
 */
#define TADR_GPIOA_BASE     (AHB2PERIPH_BASE + 0x0000)
#define TADR_GPIOB_BASE     (AHB2PERIPH_BASE + 0x0400)
#define TADR_GPIOC_BASE     (AHB2PERIPH_BASE + 0x0800)
#define TADR_GPIOD_BASE     (AHB2PERIPH_BASE + 0x0C00)
#define TADR_GPIOE_BASE     (AHB2PERIPH_BASE + 0x1000)
#define TADR_GPIOF_BASE     (AHB2PERIPH_BASE + 0x1400)
#define TADR_GPIOG_BASE     (AHB2PERIPH_BASE + 0x1800)
#define TADR_GPIOH_BASE     (AHB2PERIPH_BASE + 0x1C00)
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
#define TOFF_GPIO_BSRR      0x0018		/* (RW) GPIO port bit set/reset low register */
#define TOFF_GPIO_LCKR      0x001C		/* (RW) GPIO port configuration lock register */
#define TOFF_GPIO_AFR0      0x0020		/* (RW) GPIO alternate function registers */
#define TOFF_GPIO_AFR1      0x0024		/* (RW) GPIO alternate function registers */
#define TOFF_GPIO_BRR       0x0028		/* (RW) GPIO Bit Reset register */
#define TOFF_GPIO_ASCR      0x002C		/* (RW) GPIO analog switch control register */


/*
 *  ANALOG TO DIGITAL CONVERTER
 */
#define TADR_ADC1_BASE      (AHB2PERIPH_BASE + 0x08040000)
#define TADR_ADC2_BASE      (AHB2PERIPH_BASE + 0x08040100)
#define TADR_ADC3_BASE      (AHB2PERIPH_BASE + 0x08040200)
#define TOFF_ADC_ISR        0x0000		/* (RW) ADC interrupt and status register */
  #define ADC_ISR_ADRDY      0x00000001	/* ADC ready flag */
  #define ADC_ISR_EOSMP      0x00000002	/* ADC group regular end of sampling flag */
  #define ADC_ISR_EOC        0x00000004	/* ADC group regular end of unitary conversion flag */
  #define ADC_ISR_EOS        0x00000008	/* ADC End of Sequence flag */
  #define ADC_ISR_OVR        0x00000010	/* ADC group regular overrun flag */
  #define ADC_ISR_JEOC       0x00000020	/* ADC group injected end of unitary conversion flag */
  #define ADC_ISR_JEOS       0x00000040	/* ADC group injected end of sequence conversions flag */
  #define ADC_ISR_AWD1       0x00000080	/* ADC analog watchdog 1 flag */
  #define ADC_ISR_AWD2       0x00000100	/* ADC analog watchdog 2 flag */
  #define ADC_ISR_AWD3       0x00000200	/* ADC analog watchdog 3 flag */
  #define ADC_ISR_JQOVF      0x00000400	/* ADC group injected contexts queue overflow flag */
#define TOFF_ADC_IER        0x0004		/* (RW) ADC interrupt enable register */
  #define ADC_IER_ADRDYIE    0x00000001	/* ADC ready interrupt */
  #define ADC_IER_EOSMPIE    0x00000002	/* ADC group regular end of sampling interrupt */
  #define ADC_IER_EOCIE      0x00000004	/* ADC group regular end of unitary conversion interrupt */
  #define ADC_IER_EOSIE      0x00000008	/* ADC End of Sequence of conversion interrupt enable */
  #define ADC_IER_OVRIE      0x00000010	/* ADC group regular overrun interrupt */
  #define ADC_IER_JEOCIE     0x00000020	/* ADC group injected end of unitary conversion interrupt */
  #define ADC_IER_JEOSIE     0x00000040	/* ADC group injected end of sequence conversions interrupt */
  #define ADC_IER_AWD1IE     0x00000080	/* ADC analog watchdog 1 interrupt */
  #define ADC_IER_AWD2IE     0x00000100	/* ADC analog watchdog 2 interrupt */
  #define ADC_IER_AWD3IE     0x00000200	/* ADC analog watchdog 3 interrupt */
  #define ADC_IER_JQOVFIE    0x00000400	/* ADC group injected contexts queue overflow interrupt */
#define TOFF_ADC_CR         0x0008		/* (RW) ADC control register */
  #define ADC_CR_ADEN        0x00000001	/* ADC enable */
  #define ADC_CR_ADDIS       0x00000002	/* ADC disable */
  #define ADC_CR_ADSTART     0x00000004	/* ADC group regular conversion start */
  #define ADC_CR_JADSTART    0x00000008	/* ADC group injected conversion start */
  #define ADC_CR_ADSTP       0x00000010	/* ADC group regular conversion stop */
  #define ADC_CR_JADSTP      0x00000020	/* ADC group injected conversion stop */
  #define ADC_CR_ADVREGEN    0x10000000	/* ADC Voltage Regulator Enable */
  #define ADC_CR_DEEPPWD     0x20000000	/* ADC deep power down enable */
  #define ADC_CR_ADCALDIF    0x40000000	/* ADC differential mode for calibration */
  #define ADC_CR_ADCAL       0x80000000	/* ADC calibration */
#define TOFF_ADC_CFGR       0x000C		/* (RW) ADC configuration register 1 */
  #define ADC_CFGR_DMAEN     0x00000001	/* ADC DMA transfer enable */
  #define ADC_CFGR_DMACFG    0x00000002	/* ADC DMA transfer configuration */
  #define ADC_CFGR_SCANDIR   0x00000004	/* ADC group regular sequencer scan direction */
  #define ADC_CFGR_RES       0x00000018	/* ADC data resolution */
  #define ADC_CFGR_RES_0     0x00000008
  #define ADC_CFGR_RES_1     0x00000010
  #define ADC_CFGR_ALIGN     0x00000020	/* ADC data alignement */
  #define ADC_CFGR_EXTSEL    0x000003C0	/* ADC group regular external trigger source */
  #define ADC_CFGR_EXTSEL_0  0x00000040
  #define ADC_CFGR_EXTSEL_1  0x00000080
  #define ADC_CFGR_EXTSEL_2  0x00000100
  #define ADC_CFGR_EXTSEL_3  0x00000200
  #define ADC_CFGR_EXTEN     0x00000C00	/* ADC group regular external trigger polarity */
  #define ADC_CFGR_EXTEN_0   0x00000400
  #define ADC_CFGR_EXTEN_1   0x00000800
  #define ADC_CFGR_OVRMOD    0x00001000	/* ADC group regular overrun configuration */
  #define ADC_CFGR_CONT      0x00002000	/* ADC group regular continuous conversion mode */
  #define ADC_CFGR_AUTDLY    0x00004000	/* ADC low power auto wait */
  #define ADC_CFGR_DISCEN    0x00010000	/* ADC group regular sequencer discontinuous mode */
  #define ADC_CFGR_DISCNUM   0x000E0000	/* ADC group regular sequencer discontinuous number of ranks */
  #define ADC_CFGR_DISCNUM_0 0x00020000
  #define ADC_CFGR_DISCNUM_1 0x00040000
  #define ADC_CFGR_DISCNUM_2 0x00080000
  #define ADC_CFGR_JDISCEN   0x00100000	/* ADC group injected sequencer discontinuous mode */
  #define ADC_CFGR_JQM       0x00200000	/* ADC group injected contexts queue mode */
  #define ADC_CFGR_AWD1SGL   0x00400000	/* ADC analog watchdog 1 monitoring a single channel or all channels */
  #define ADC_CFGR_AWD1EN    0x00800000	/* ADC analog watchdog 1 enable on scope ADC group regular */
  #define ADC_CFGR_JAWD1EN   0x01000000	/* ADC analog watchdog 1 enable on scope ADC group injected */
  #define ADC_CFGR_JAUTO     0x02000000
  #define ADC_CFGR_AWD1CH    0x7C000000	/* ADC analog watchdog 1 monitored channel selection */
  #define ADC_CFGR_AWD1CH_0  0x04000000
  #define ADC_CFGR_AWD1CH_1  0x08000000
  #define ADC_CFGR_AWD1CH_2  0x10000000
  #define ADC_CFGR_AWD1CH_3  0x20000000
  #define ADC_CFGR_AWD1CH_4  0x40000000
  #define ADC_CFGR_JQDIS     0x80000000	/* ADC group injected contexts queue disable */
#define TOFF_ADC_CFGR2      0x0010	/* (RW) ADC configuration register 2 */
  #define ADC_CFGR2_ROVSE    0x00000001	/* ADC oversampler enable on scope ADC group regular */
  #define ADC_CFGR2_JOVSE    0x00000002	/* ADC oversampler enable on scope ADC group injected */
  #define ADC_CFGR2_OVSR     0x0000001C	/* ADC oversampling ratio */
  #define ADC_CFGR2_OVSR_0   0x00000004
  #define ADC_CFGR2_OVSR_1   0x00000008
  #define ADC_CFGR2_OVSR_2   0x00000010
  #define ADC_CFGR2_OVSS     0x000001E0	/* ADC oversampling shift */
  #define ADC_CFGR2_OVSS_0   0x00000020
  #define ADC_CFGR2_OVSS_1   0x00000040
  #define ADC_CFGR2_OVSS_2   0x00000080
  #define ADC_CFGR2_OVSS_3   0x00000100
  #define ADC_CFGR2_TROVS    0x00000200	/* ADC oversampling discontinuous mode (triggered mode) for ADC group regular */
  #define ADC_CFGR2_ROVSM    0x00000400	/* ADC oversampling mode managing interlaced conversions of ADC group regular and group injected */
#define TOFF_ADC_SMPR1      0x0014	/* (RW) ADC sampling time register 1 */
  #define ADC_SMPR1_SMP0     0x00000007	/* ADC channel 0 sampling time selection  */
  #define ADC_SMPR1_SMP0_0   0x00000001
  #define ADC_SMPR1_SMP0_1   0x00000002
  #define ADC_SMPR1_SMP0_2   0x00000004
  #define ADC_SMPR1_SMP1     0x00000038	/* ADC channel 1 sampling time selection  */
  #define ADC_SMPR1_SMP1_0   0x00000008
  #define ADC_SMPR1_SMP1_1   0x00000010
  #define ADC_SMPR1_SMP1_2   0x00000020
  #define ADC_SMPR1_SMP2     0x000001C0	/* ADC channel 2 sampling time selection  */
  #define ADC_SMPR1_SMP2_0   0x00000040
  #define ADC_SMPR1_SMP2_1   0x00000080
  #define ADC_SMPR1_SMP2_2   0x00000100
  #define ADC_SMPR1_SMP3     0x00000E00	/* ADC channel 3 sampling time selection  */
  #define ADC_SMPR1_SMP3_0   0x00000200
  #define ADC_SMPR1_SMP3_1   0x00000400
  #define ADC_SMPR1_SMP3_2   0x00000800
  #define ADC_SMPR1_SMP4     0x00007000	/* ADC channel 4 sampling time selection  */
  #define ADC_SMPR1_SMP4_0   0x00001000
  #define ADC_SMPR1_SMP4_1   0x00002000
  #define ADC_SMPR1_SMP4_2   0x00004000
  #define ADC_SMPR1_SMP5     0x00038000	/* ADC channel 5 sampling time selection  */
  #define ADC_SMPR1_SMP5_0   0x00008000
  #define ADC_SMPR1_SMP5_1   0x00010000
  #define ADC_SMPR1_SMP5_2   0x00020000
  #define ADC_SMPR1_SMP6     0x001C0000	/* ADC channel 6 sampling time selection  */
  #define ADC_SMPR1_SMP6_0   0x00040000
  #define ADC_SMPR1_SMP6_1   0x00080000
  #define ADC_SMPR1_SMP6_2   0x00100000
  #define ADC_SMPR1_SMP7     0x00E00000	/* ADC channel 7 sampling time selection  */
  #define ADC_SMPR1_SMP7_0   0x00200000
  #define ADC_SMPR1_SMP7_1   0x00400000
  #define ADC_SMPR1_SMP7_2   0x00800000
  #define ADC_SMPR1_SMP8     0x07000000	/* ADC channel 8 sampling time selection  */
  #define ADC_SMPR1_SMP8_0   0x01000000
  #define ADC_SMPR1_SMP8_1   0x02000000
  #define ADC_SMPR1_SMP8_2   0x04000000
  #define ADC_SMPR1_SMP9     0x38000000	/* ADC channel 9 sampling time selection  */
  #define ADC_SMPR1_SMP9_0   0x08000000
  #define ADC_SMPR1_SMP9_1   0x10000000
  #define ADC_SMPR1_SMP9_2   0x20000000
#define TOFF_ADC_SMPR2      0x0018	/* (RW) ADC sampling time register 2 */
  #define ADC_SMPR2_SMP10    0x00000007	/* ADC channel 10 sampling time selection  */
  #define ADC_SMPR2_SMP10_0  0x00000001
  #define ADC_SMPR2_SMP10_1  0x00000002
  #define ADC_SMPR2_SMP10_2  0x00000004
  #define ADC_SMPR2_SMP11    0x00000038	/* ADC channel 11 sampling time selection  */
  #define ADC_SMPR2_SMP11_0  0x00000008
  #define ADC_SMPR2_SMP11_1  0x00000010
  #define ADC_SMPR2_SMP11_2  0x00000020
  #define ADC_SMPR2_SMP12    0x000001C0	/* ADC channel 12 sampling time selection  */
  #define ADC_SMPR2_SMP12_0  0x00000040
  #define ADC_SMPR2_SMP12_1  0x00000080
  #define ADC_SMPR2_SMP12_2  0x00000100
  #define ADC_SMPR2_SMP13    0x00000E00	/* ADC channel 13 sampling time selection  */
  #define ADC_SMPR2_SMP13_0  0x00000200
  #define ADC_SMPR2_SMP13_1  0x00000400
  #define ADC_SMPR2_SMP13_2  0x00000800
  #define ADC_SMPR2_SMP14    0x00007000	/* ADC channel 14 sampling time selection  */
  #define ADC_SMPR2_SMP14_0  0x00001000
  #define ADC_SMPR2_SMP14_1  0x00002000
  #define ADC_SMPR2_SMP14_2  0x00004000
  #define ADC_SMPR2_SMP15    0x00038000	/* ADC channel 15 sampling time selection  */
  #define ADC_SMPR2_SMP15_0  0x00008000
  #define ADC_SMPR2_SMP15_1  0x00010000
  #define ADC_SMPR2_SMP15_2  0x00020000
  #define ADC_SMPR2_SMP16    0x001C0000	/* ADC channel 16 sampling time selection  */
  #define ADC_SMPR2_SMP16_0  0x00040000
  #define ADC_SMPR2_SMP16_1  0x00080000
  #define ADC_SMPR2_SMP16_2  0x00100000
  #define ADC_SMPR2_SMP17    0x00E00000	/* ADC channel 17 sampling time selection  */
  #define ADC_SMPR2_SMP17_0  0x00200000
  #define ADC_SMPR2_SMP17_1  0x00400000
  #define ADC_SMPR2_SMP17_2  0x00800000
  #define ADC_SMPR2_SMP18s   0x07000000	/* ADC channel 18 sampling time selection  */
  #define ADC_SMPR2_SMP18_0  0x01000000
  #define ADC_SMPR2_SMP18_1  0x02000000
  #define ADC_SMPR2_SMP18_2  0x04000000
#define TOFF_ADC_TR1        0x0020	/* (RW) ADC analog watchdog 1 threshold register */
  #define ADC_TR1_LT1        0x00000FFF	/* ADC analog watchdog 1 threshold low */
  #define ADC_TR1_LT1_0      0x00000001
  #define ADC_TR1_LT1_1      0x00000002
  #define ADC_TR1_LT1_2      0x00000004
  #define ADC_TR1_LT1_3      0x00000008
  #define ADC_TR1_LT1_4      0x00000010
  #define ADC_TR1_LT1_5      0x00000020
  #define ADC_TR1_LT1_6      0x00000040
  #define ADC_TR1_LT1_7      0x00000080
  #define ADC_TR1_LT1_8      0x00000100
  #define ADC_TR1_LT1_9      0x00000200
  #define ADC_TR1_LT1_10     0x00000400
  #define ADC_TR1_LT1_11     0x00000800
  #define ADC_TR1_HT1        0x0FFF0000	/* ADC Analog watchdog 1 threshold high */
  #define ADC_TR1_HT1_0      0x00010000
  #define ADC_TR1_HT1_1      0x00020000
  #define ADC_TR1_HT1_2      0x00040000
  #define ADC_TR1_HT1_3      0x00080000
  #define ADC_TR1_HT1_4      0x00100000
  #define ADC_TR1_HT1_5      0x00200000
  #define ADC_TR1_HT1_6      0x00400000
  #define ADC_TR1_HT1_7      0x00800000
  #define ADC_TR1_HT1_8      0x01000000
  #define ADC_TR1_HT1_9      0x02000000
  #define ADC_TR1_HT1_10     0x04000000
  #define ADC_TR1_HT1_11     0x08000000
#define TOFF_ADC_TR2        0x0024	/* (RW) ADC analog watchdog 2 threshold register */
  #define ADC_TR2_LT2        0x000000FF	/* ADC analog watchdog 2 threshold low */
  #define ADC_TR2_LT2_0      0x00000001
  #define ADC_TR2_LT2_1      0x00000002
  #define ADC_TR2_LT2_2      0x00000004
  #define ADC_TR2_LT2_3      0x00000008
  #define ADC_TR2_LT2_4      0x00000010
  #define ADC_TR2_LT2_5      0x00000020
  #define ADC_TR2_LT2_6      0x00000040
  #define ADC_TR2_LT2_7      0x00000080
  #define ADC_TR2_HT2        0x00FF0000	/* ADC analog watchdog 2 threshold high */
  #define ADC_TR2_HT2_0      0x00010000
  #define ADC_TR2_HT2_1      0x00020000
  #define ADC_TR2_HT2_2      0x00040000
  #define ADC_TR2_HT2_3      0x00080000
  #define ADC_TR2_HT2_4      0x00100000
  #define ADC_TR2_HT2_5      0x00200000
  #define ADC_TR2_HT2_6      0x00400000
  #define ADC_TR2_HT2_7      0x00800000
#define TOFF_ADC_TR3        0x0028	/* (RW) ADC analog watchdog 3 threshold register */
  #define ADC_TR3_LT3        0x000000FF	/* ADC analog watchdog 3 threshold low */
  #define ADC_TR3_LT3_0      0x00000001
  #define ADC_TR3_LT3_1      0x00000002
  #define ADC_TR3_LT3_2      0x00000004
  #define ADC_TR3_LT3_3      0x00000008
  #define ADC_TR3_LT3_4      0x00000010
  #define ADC_TR3_LT3_5      0x00000020
  #define ADC_TR3_LT3_6      0x00000040
  #define ADC_TR3_LT3_7      0x00000080
  #define ADC_TR3_HT3        0x00FF0000	/* ADC analog watchdog 3 threshold high */
  #define ADC_TR3_HT3_0      0x00010000
  #define ADC_TR3_HT3_1      0x00020000
  #define ADC_TR3_HT3_2      0x00040000
  #define ADC_TR3_HT3_3      0x00080000
  #define ADC_TR3_HT3_4      0x00100000
  #define ADC_TR3_HT3_5      0x00200000
  #define ADC_TR3_HT3_6      0x00400000
  #define ADC_TR3_HT3_7      0x00800000
#define TOFF_ADC_SQR1       0x0030	/* (RW) ADC group regular sequencer register 1 */
  #define ADC_SQR1_L         0x0000000F	/* ADC group regular sequencer scan length */
  #define ADC_SQR1_L_0       0x00000001
  #define ADC_SQR1_L_1       0x00000002
  #define ADC_SQR1_L_2       0x00000004
  #define ADC_SQR1_L_3       0x00000008
  #define ADC_SQR1_SQ1       0x000007C0	/* ADC group regular sequencer rank 1 */
  #define ADC_SQR1_SQ1_0     0x00000040
  #define ADC_SQR1_SQ1_1     0x00000080
  #define ADC_SQR1_SQ1_2     0x00000100
  #define ADC_SQR1_SQ1_3     0x00000200
  #define ADC_SQR1_SQ1_4     0x00000400
  #define ADC_SQR1_SQ2       0x0001F000	/* ADC group regular sequencer rank 2 */
  #define ADC_SQR1_SQ2_0     0x00001000
  #define ADC_SQR1_SQ2_1     0x00002000
  #define ADC_SQR1_SQ2_2     0x00004000
  #define ADC_SQR1_SQ2_3     0x00008000
  #define ADC_SQR1_SQ2_4     0x00010000
  #define ADC_SQR1_SQ3       0x007C0000	/* ADC group regular sequencer rank 3 */
  #define ADC_SQR1_SQ3_0     0x00040000
  #define ADC_SQR1_SQ3_1     0x00080000
  #define ADC_SQR1_SQ3_2     0x00100000
  #define ADC_SQR1_SQ3_3     0x00200000
  #define ADC_SQR1_SQ3_4     0x00400000
  #define ADC_SQR1_SQ4       0x1F000000	/* ADC group regular sequencer rank 4 */
  #define ADC_SQR1_SQ4_0     0x01000000
  #define ADC_SQR1_SQ4_1     0x02000000
  #define ADC_SQR1_SQ4_2     0x04000000
  #define ADC_SQR1_SQ4_3     0x08000000
  #define ADC_SQR1_SQ4_4     0x10000000
#define TOFF_ADC_SQR2       0x0034	/* (RW) ADC group regular sequencer register 2 */
  #define ADC_SQR2_SQ5       0x0000001F	/* ADC group regular sequencer rank 5 */
  #define ADC_SQR2_SQ5_0     0x00000001
  #define ADC_SQR2_SQ5_1     0x00000002
  #define ADC_SQR2_SQ5_2     0x00000004
  #define ADC_SQR2_SQ5_3     0x00000008
  #define ADC_SQR2_SQ5_4     0x00000010
  #define ADC_SQR2_SQ6       0x000007C0	/* ADC group regular sequencer rank 6 */
  #define ADC_SQR2_SQ6_0     0x00000040
  #define ADC_SQR2_SQ6_1     0x00000080
  #define ADC_SQR2_SQ6_2     0x00000100
  #define ADC_SQR2_SQ6_3     0x00000200
  #define ADC_SQR2_SQ6_4     0x00000400
  #define ADC_SQR2_SQ7       0x0001F000	/* ADC group regular sequencer rank 7 */
  #define ADC_SQR2_SQ7_0     0x00001000
  #define ADC_SQR2_SQ7_1     0x00002000
  #define ADC_SQR2_SQ7_2     0x00004000
  #define ADC_SQR2_SQ7_3     0x00008000
  #define ADC_SQR2_SQ7_4     0x00010000
  #define ADC_SQR2_SQ8       0x007C0000	/* ADC group regular sequencer rank 8 */
  #define ADC_SQR2_SQ8_0     0x00040000
  #define ADC_SQR2_SQ8_1     0x00080000
  #define ADC_SQR2_SQ8_2     0x00100000
  #define ADC_SQR2_SQ8_3     0x00200000
  #define ADC_SQR2_SQ8_4     0x00400000
  #define ADC_SQR2_SQ9       0x1F000000	/* ADC group regular sequencer rank 9 */
  #define ADC_SQR2_SQ9_0     0x01000000
  #define ADC_SQR2_SQ9_1     0x02000000
  #define ADC_SQR2_SQ9_2     0x04000000
  #define ADC_SQR2_SQ9_3     0x08000000
  #define ADC_SQR2_SQ9_4     0x10000000
#define TOFF_ADC_SQR3       0x0038	/* (RW) ADC group regular sequencer register 3 */
  #define ADC_SQR3_SQ10      0x0000001F	/* ADC group regular sequencer rank 10 */
  #define ADC_SQR3_SQ10_0    0x00000001
  #define ADC_SQR3_SQ10_1    0x00000002
  #define ADC_SQR3_SQ10_2    0x00000004
  #define ADC_SQR3_SQ10_3    0x00000008
  #define ADC_SQR3_SQ10_4    0x00000010
  #define ADC_SQR3_SQ11      0x000007C0	/* ADC group regular sequencer rank 11 */
  #define ADC_SQR3_SQ11_0    0x00000040
  #define ADC_SQR3_SQ11_1    0x00000080
  #define ADC_SQR3_SQ11_2    0x00000100
  #define ADC_SQR3_SQ11_3    0x00000200
  #define ADC_SQR3_SQ11_4    0x00000400
  #define ADC_SQR3_SQ12      0x0001F000	/* ADC group regular sequencer rank 12 */
  #define ADC_SQR3_SQ12_0    0x00001000
  #define ADC_SQR3_SQ12_1    0x00002000
  #define ADC_SQR3_SQ12_2    0x00004000
  #define ADC_SQR3_SQ12_3    0x00008000
  #define ADC_SQR3_SQ12_4    0x00010000
  #define ADC_SQR3_SQ13      0x007C0000	/* ADC group regular sequencer rank 13 */
  #define ADC_SQR3_SQ13_0    0x00040000
  #define ADC_SQR3_SQ13_1    0x00080000
  #define ADC_SQR3_SQ13_2    0x00100000
  #define ADC_SQR3_SQ13_3    0x00200000
  #define ADC_SQR3_SQ13_4    0x00400000
  #define ADC_SQR3_SQ14      0x1F000000	/* ADC group regular sequencer rank 14 */
  #define ADC_SQR3_SQ14_0    0x01000000
  #define ADC_SQR3_SQ14_1    0x02000000
  #define ADC_SQR3_SQ14_2    0x04000000
  #define ADC_SQR3_SQ14_3    0x08000000
  #define ADC_SQR3_SQ14_4    0x10000000
#define TOFF_ADC_SQR4       0x003C	/* (RW) ADC group regular sequencer register 4 */
  #define ADC_SQR4_SQ15      0x0000001F	/* ADC group regular sequencer rank 15 */
  #define ADC_SQR4_SQ15_0    0x00000001
  #define ADC_SQR4_SQ15_1    0x00000002
  #define ADC_SQR4_SQ15_2    0x00000004
  #define ADC_SQR4_SQ15_3    0x00000008
  #define ADC_SQR4_SQ15_4    0x00000010
  #define ADC_SQR4_SQ16      0x000007C0	/* ADC group regular sequencer rank 16 */
  #define ADC_SQR4_SQ16_0    0x00000040
  #define ADC_SQR4_SQ16_1    0x00000080
  #define ADC_SQR4_SQ16_2    0x00000100
  #define ADC_SQR4_SQ16_3    0x00000200
  #define ADC_SQR4_SQ16_4    0x00000400
#define TOFF_ADC_DR         0x0040		/* (RW) ADC group regular data register */
  #define ADC_DR_DATA        0x0000FFFF	/* ADC group regular conversion data */
#define TOFF_ADC_JSQR       0x004C	/* (RW) ADC group injected sequencer register */
  #define ADC_JSQR_JL        0x00000003	/* ADC group injected sequencer scan length */
  #define ADC_JSQR_JL_0      0x00000001
  #define ADC_JSQR_JL_1      0x00000002
  #define ADC_JSQR_JEXTSEL   0x0000003C	/* ADC group injected external trigger source */
  #define ADC_JSQR_JEXTSEL_0 0x00000004
  #define ADC_JSQR_JEXTSEL_1 0x00000008
  #define ADC_JSQR_JEXTSEL_2 0x00000010
  #define ADC_JSQR_JEXTSEL_3 0x00000020
  #define ADC_JSQR_JEXTEN    0x000000C0	/* ADC group injected external trigger polarity */
  #define ADC_JSQR_JEXTEN_0  0x00000040
  #define ADC_JSQR_JEXTEN_1  0x00000080
  #define ADC_JSQR_JSQ1      0x00001F00	/* ADC group injected sequencer rank 1 */
  #define ADC_JSQR_JSQ1_0    0x00000100
  #define ADC_JSQR_JSQ1_1    0x00000200
  #define ADC_JSQR_JSQ1_2    0x00000400
  #define ADC_JSQR_JSQ1_3    0x00000800
  #define ADC_JSQR_JSQ1_4    0x00001000
  #define ADC_JSQR_JSQ2      0x0007C000	/* ADC group injected sequencer rank 2 */
  #define ADC_JSQR_JSQ2_0    0x00004000
  #define ADC_JSQR_JSQ2_1    0x00008000
  #define ADC_JSQR_JSQ2_2    0x00010000
  #define ADC_JSQR_JSQ2_3    0x00020000
  #define ADC_JSQR_JSQ2_4    0x00040000
  #define ADC_JSQR_JSQ3      0x01F00000	/* ADC group injected sequencer rank 3 */
  #define ADC_JSQR_JSQ3_0    0x00100000
  #define ADC_JSQR_JSQ3_1    0x00200000
  #define ADC_JSQR_JSQ3_2    0x00400000
  #define ADC_JSQR_JSQ3_3    0x00800000
  #define ADC_JSQR_JSQ3_4    0x01000000
  #define ADC_JSQR_JSQ4      0x7C000000	/* ADC group injected sequencer rank 4 */
  #define ADC_JSQR_JSQ4_0    0x04000000
  #define ADC_JSQR_JSQ4_1    0x08000000
  #define ADC_JSQR_JSQ4_2    0x10000000
  #define ADC_JSQR_JSQ4_3    0x20000000
  #define ADC_JSQR_JSQ4_4    0x40000000
#define TOFF_ADC_OFR1       0x0060	/* (RW) ADC offset register 1 */
  #define ADC_OFR1_OFFSET1    0x00000FFF	/* ADC offset number 1 offset level */
  #define ADC_OFR1_OFFSET1_CH 0x7C000000	/* ADC offset number 1 channel selection */
  #define ADC_OFR1_OFFSET1_EN 0x80000000	/* ADC offset number 1 enable */
#define TOFF_ADC_OFR2       0x0064	/* (RW) ADC offset register 2 */
  #define ADC_OFR2_OFFSET2    0x00000FFF	/* ADC offset number 2 offset level */
  #define ADC_OFR2_OFFSET2_CH 0x7C000000	/* ADC offset number 2 channel selection */
  #define ADC_OFR2_OFFSET2_EN 0x80000000	/* ADC offset number 2 enable */
#define TOFF_ADC_OFR3       0x0068	/* (RW) ADC offset register 3 */
  #define ADC_OFR3_OFFSET3    0x00000FFF	/* ADC offset number 3 offset level */
  #define ADC_OFR3_OFFSET3_CH 0x7C000000	/* ADC offset number 3 channel selection */
  #define ADC_OFR3_OFFSET3_EN 0x80000000	/* ADC offset number 3 enable */
#define TOFF_ADC_OFR4       0x006C	/* (RW) ADC offset register 4 */
  #define ADC_OFR4_OFFSET4    0x00000FFF	/* ADC offset number 4 offset level */
  #define ADC_OFR4_OFFSET4_CH 0x7C000000	/* ADC offset number 4 channel selection */
  #define ADC_OFR4_OFFSET4_EN 0x80000000	/* ADC offset number 4 enable */
#define TOFF_ADC_JDR1       0x0080	/* (RW) ADC group injected rank 1 data register */
  #define ADC_JDR1_JDATA     0x0000FFFF	/* ADC group injected sequencer rank 1 conversion data */
#define TOFF_ADC_JDR2       0x0084	/* (RW) ADC group injected rank 2 data register */
  #define ADC_JDR2_JDATA     0x0000FFFF	/* ADC group injected sequencer rank 2 conversion data */
#define TOFF_ADC_JDR3       0x0088	/* (RW) ADC group injected rank 3 data register */
  #define ADC_JDR3_JDATA     0x0000FFFF	/* ADC group injected sequencer rank 3 conversion data */
#define TOFF_ADC_JDR4       0x008C	/* (RW) ADC group injected rank 4 data register */
  #define ADC_JDR4_JDATA     0x0000FFFF	/* ADC group injected sequencer rank 4 conversion data */
#define TOFF_ADC_AWD2CR     0x00A0	/* (RW) ADC analog watchdog 1 configuration register */
  #define ADC_AWD2CR_AWD2CH  0x0007FFFF	/* ADC analog watchdog 2 monitored channel selection */
#define TOFF_ADC_AWD3CR     0x00A4	/* (RW) ADC analog watchdog 3 Configuration Register */
  #define ADC_AWD3CR_AWD3CH  0x0007FFFF	/* ADC analog watchdog 3 monitored channel selection */
#define TOFF_ADC_DIFSEL     0x00B0	/* (RW) ADC differential mode selection register */
  #define ADC_DIFSEL_DIFSEL  0x0007FFFF	/* ADC channel differential or single-ended mode */
#define TOFF_ADC_CALFACT    0x00B4		/* ADC data register */
  #define ADC_CALFACT_CALFACT_S 0x0000007F	/* Calibration factor */
  #define ADC_CALFACT_CALFACT_D 0x007F0000	/* Calibration factor */

#define TADR_ADC_BASE       (AHB2PERIPH_BASE + 0x08040300)
#define TOFF_ADC_CSR        0x0000		/* (RW) ADC common status register */
  #define ADC_CSR_ADRDY_MST  0x00000001	/* ADC multimode master ready flag */
  #define ADC_CSR_EOSMP_MST  0x00000002	/* ADC multimode master group regular end of sampling flag */
  #define ADC_CSR_EOC_MST    0x00000004	/* ADC multimode master group regular end of unitary conversion flag */
  #define ADC_CSR_EOS_MST    0x00000008	/* ADC multimode master group regular end of sequence conversions flag */
  #define ADC_CSR_OVR_MST    0x00000010	/* ADC multimode master group regular overrun flag */
  #define ADC_CSR_JEOC_MST   0x00000020	/* ADC multimode master group injected end of unitary conversion flag */
  #define ADC_CSR_JEOS_MST   0x00000040	/* ADC multimode master group injected end of sequence conversions flag */
  #define ADC_CSR_AWD1_MST   0x00000080	/* ADC multimode master analog watchdog 1 flag */
  #define ADC_CSR_AWD2_MST   0x00000100	/* ADC multimode master analog watchdog 2 flag */
  #define ADC_CSR_AWD3_MST   0x00000200	/* ADC multimode master analog watchdog 3 flag */
  #define ADC_CSR_JQOVF_MST  0x00000400	/* ADC multimode master group injected contexts queue overflow flag */
  #define ADC_CSR_ADRDY_SLV  0x00010000	/* ADC multimode slave ready flag */
  #define ADC_CSR_EOSMP_SLV  0x00020000	/* ADC multimode slave group regular end of sampling flag */
  #define ADC_CSR_EOC_SLV    0x00040000	/* ADC multimode slave group regular end of unitary conversion flag */
  #define ADC_CSR_EOS_SLV    0x00080000	/* ADC multimode slave group regular end of sequence conversions flag */
  #define ADC_CSR_OVR_SLV    0x00100000	/* ADC multimode slave group regular overrun flag */
  #define ADC_CSR_JEOC_SLV   0x00200000	/* ADC multimode slave group injected end of unitary conversion flag */
  #define ADC_CSR_JEOS_SLV   0x00400000	/* ADC multimode slave group injected end of sequence conversions flag */
  #define ADC_CSR_AWD1_SLV   0x00800000	/* ADC multimode slave analog watchdog 1 flag */
  #define ADC_CSR_AWD2_SLV   0x01000000	/* ADC multimode slave analog watchdog 2 flag */
  #define ADC_CSR_AWD3_SLV   0x02000000	/* ADC multimode slave analog watchdog 3 flag */
  #define ADC_CSR_JQOVF_SLV  0x04000000	/* ADC multimode slave group injected contexts queue overflow flag */
#define TOFF_ADC_CCR        0x0008		/* (RW) ADC common configuration register */
  #define ADC_CCR_DUAL       0x0000001F	/* ADC multimode mode selection */
  #define ADC_CCR_DUAL_0     0x00000001
  #define ADC_CCR_DUAL_1     0x00000002
  #define ADC_CCR_DUAL_2     0x00000004
  #define ADC_CCR_DUAL_3     0x00000008
  #define ADC_CCR_DUAL_4     0x00000010
  #define ADC_CCR_DELAY      0x00000F00	/* ADC multimode delay between 2 sampling phases */
  #define ADC_CCR_DELAY_0    0x00000100
  #define ADC_CCR_DELAY_1    0x00000200
  #define ADC_CCR_DELAY_2    0x00000400
  #define ADC_CCR_DELAY_3    0x00000800
  #define ADC_CCR_DMACFG     0x00002000	/* ADC multimode DMA transfer configuration */
  #define ADC_CCR_MDMA       0x0000C000	/* ADC multimode DMA transfer enable */
  #define ADC_CCR_MDMA_0     0x00004000
  #define ADC_CCR_MDMA_1     0x00008000
  #define ADC_CCR_CKMODE     0x00030000	/* ADC common clock source and prescaler (prescaler only for clock source synchronous) */
  #define ADC_CCR_CKMODE_0   0x00010000
  #define ADC_CCR_CKMODE_1   0x00020000
  #define ADC_CCR_PRESC      0x003C0000	/* ADC common clock prescaler, only for clock source asynchronous */
  #define ADC_CCR_PRESC_0    0x00040000
  #define ADC_CCR_PRESC_1    0x00080000
  #define ADC_CCR_PRESC_2    0x00100000
  #define ADC_CCR_PRESC_3    0x00200000
  #define ADC_CCR_VREFEN     0x00400000	/* ADC internal path to VrefInt enable */
  #define ADC_CCR_TSEN       0x00800000	/* ADC internal path to temperature sensor enable */
  #define ADC_CCR_VBATEN     0x01000000	/* ADC internal path to battery voltage enable */
#define TOFF_ADC_CDR        0x000C		/* (RW) ADC common group regular data register */
  #define ADC_CDR_RDATA_MST  0x0000FFFF	/* ADC multimode master group regular conversion data */
  #define ADC_CDR_RDATA_SLV  0xFFFF0000	/* ADC multimode slave group regular conversion data */


/*
 *  RANDOM NUMBER GENERATOR
 */
#define TADR_RNG_BASE       (AHB2PERIPH_BASE + 0x08060800)
#define TOFF_RNG_CR         0x0000		/* (RW) RNG control register */
  #define RNG_CR_RNGEN       0x00000004
  #define RNG_CR_IE          0x00000008
#define TOFF_RNG_SR         0x0004		/* (RW) RNG status register */
  #define RNG_SR_DRDY        0x00000001
  #define RNG_SR_CECS        0x00000002
  #define RNG_SR_SECS        0x00000004
  #define RNG_SR_CEIS        0x00000020
  #define RNG_SR_SEIS        0x00000040
#define TOFF_RNG_DR         0x0008		/* (RW) RNG data register */



/*
 *  USB OTG
 */
#define TADR_USB_OTGFS_BASE (USB_OTG_FS_PERIPH_BASE)
#define TOFF_USBO_GOTGCTL   0x0000		/* (RW) USB_OTG Control and Status Register */
  #define USB_OTG_GOTGCTL_SRQSCS    0x00000001	/* Session request success */
  #define USB_OTG_GOTGCTL_SRQ       0x00000002	/* Session request */
  #define USB_OTG_GOTGCTL_VBVALOEN  0x00000004	/* VBUS valid override enable */
  #define USB_OTG_GOTGCTL_VBVALOVAL 0x00000008	/* VBUS valid override value */
  #define USB_OTG_GOTGCTL_AVALOEN   0x00000010	/* A-peripheral session valid override enable */
  #define USB_OTG_GOTGCTL_AVALOVAL  0x00000020	/* A-peripheral session valid override value */
  #define USB_OTG_GOTGCTL_BVALOEN   0x00000040	/* B-peripheral session valid override enable */
  #define USB_OTG_GOTGCTL_BVALOVAL  0x00000080	/* B-peripheral session valid override value  */
  #define USB_OTG_GOTGCTL_BSVLD     0x00080000	/* B-session valid */
#define TOFF_USBO_GOTGINT   0x0004		/* (RW) USB_OTG Interrupt Register */
  #define USB_OTG_GOTGINT_SEDET     0x00000004	/* Session end detected */
  #define USB_OTG_GOTGINT_SRSSCHG   0x00000100	/* Session request success status change */
  #define USB_OTG_GOTGINT_HNSSCHG   0x00000200	/* Host negotiation success status change */
  #define USB_OTG_GOTGINT_HNGDET    0x00020000	/* Host negotiation detected */
  #define USB_OTG_GOTGINT_ADTOCHG   0x00040000	/* A-device timeout change */
  #define USB_OTG_GOTGINT_DBCDNE    0x00080000	/* Debounce done */
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
  #define USB_OTG_GINTSTS_LPMINT    0x08000000	/* LPM interrupt */
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
  #define USB_OTG_GINTMSK_PRTIM     0x01000000	/* Host port interrupt mask */
  #define USB_OTG_GINTMSK_HCIM      0x02000000	/* Host channels interrupt mask */
  #define USB_OTG_GINTMSK_PTXFEM    0x04000000	/* Periodic TxFIFO empty mask */
  #define USB_OTG_GINTMSK_LPMINTM   0x08000000	/* LPM interrupt Mask */
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
  #define USB_OTG_GCCFG_DCDET       0x00000001	/* Data contact detection (DCD) status */
  #define USB_OTG_GCCFG_PDET        0x00000002	/* Primary detection (PD) status */
  #define USB_OTG_GCCFG_SDET        0x00000004	/* Secondary detection (SD) status */
  #define USB_OTG_GCCFG_PS2DET      0x00000008	/* DM pull-up detection status */
  #define USB_OTG_GCCFG_PWRDWN      0x00010000	/* Power down */
  #define USB_OTG_GCCFG_BCDEN       0x00020000	/* Battery charging detector (BCD) enable */
  #define USB_OTG_GCCFG_DCDEN       0x00040000	/* Data contact detection (DCD) mode enable*/
  #define USB_OTG_GCCFG_PDEN        0x00080000	/* Primary detection (PD) mode enable*/
  #define USB_OTG_GCCFG_SDEN        0x00100000	/* Secondary detection (SD) mode enable */
  #define USB_OTG_GCCFG_VBDEN       0x00200000	/* USB VBUS Detection Enable */
#define TOFF_USBO_CID       0x003C		/* (RW) User ID Register */
  #define USB_OTG_CID_PRODUCT_ID    0xFFFFFFFF	/* Product ID field */
#define TOFF_USBO_GSNPSID   0x0040		/* (RW) USB_OTG core ID */
#define TOFF_USBO_GHWCFG1   0x0044		/* (R)  User HW config1 */
#define TOFF_USBO_GHWCFG2   0x0048		/* (R)  User HW config2 */
#define TOFF_USBO_GHWCFG3   0x004C		/* (R)  User HW config3 */
  #define USB_OTG_GHWCFG3_LPMMode   0x00004000	/* LPM mode specified for Mode of Operation */ 
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
#define TOFF_USBO_GPWRDN    0x0058		/* (RW) Power Down Register */
  #define USB_OTG_GPWRDN_DISABLEVBUS 0x00000040	/* Power down */
#define TOFF_USBO_GDFIFOCFG 0x005C		/* (RW) DFIFO Software Config Register */
#define TOFF_USBO_GADPCTL   0x0060		/* (RW) ADP Timer, Control and Status Register */
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
 *  FLEXIBLE STATIC MEMORY
 */
#define TADR_FMC_R_BASE    (FMC_R_BASE + 0x0000)

/*
 *  FLEXIBLE MEMORY CONTROLLER
 */
#define TOFF_FMC_R_BTCR0    0x0000		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 0 */
#define TOFF_FMC_R_BTCR1    0x0004		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 1 */
#define TOFF_FMC_R_BTCR2    0x0008		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 2 */
#define TOFF_FMC_R_BTCR3    0x000C		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 3 */
#define TOFF_FMC_R_BTCR4    0x0010		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 4 */
#define TOFF_FMC_R_BTCR5    0x0014		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 5 */
#define TOFF_FMC_R_BTCR6    0x0018		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 6 */
#define TOFF_FMC_R_BTCR7    0x001C		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 7 */

/*
 *  FLEXIBLE MEMORY CONTROLLER BANK1E
 */
#define TOFF_FMC_R_BWTR0    0x0104		/* (RW) NOR/PSRAM write timing registers 0 */
#define TOFF_FMC_R_BWTR1    0x0108		/* (RW) NOR/PSRAM write timing registers 1 */
#define TOFF_FMC_R_BWTR2    0x010C		/* (RW) NOR/PSRAM write timing registers 2 */
#define TOFF_FMC_R_BWTR3    0x0110		/* (RW) NOR/PSRAM write timing registers 3 */
#define TOFF_FMC_R_BWTR4    0x0114		/* (RW) NOR/PSRAM write timing registers 4 */
#define TOFF_FMC_R_BWTR5    0x0118		/* (RW) NOR/PSRAM write timing registers 5 */
#define TOFF_FMC_R_BWTR6    0x011C		/* (RW) NOR/PSRAM write timing registers 6 */

/*
 *  FLEXIBLE MEMORY CONTROLLER BANK3
 */
#define TOFF_FMC_R_PCR      0x0080		/* (RW) NAND Flash control register */
#define TOFF_FMC_R_SR       0x0084		/* (RW) NAND Flash FIFO status and interrupt register */
#define TOFF_FMC_R_PMEM     0x0088		/* (RW) NAND Flash Common memory space timing register */
#define TOFF_FMC_R_PATT     0x008C		/* (RW) NAND Flash Attribute memory space timing register */
#define TOFF_FMC_R_ECCR     0x0090		/* (RW) NAND Flash ECC result registers */


#if !defined(TOPPERS_STM32L476_DISCOVERY) && !defined(TOPPERS_STM32L476_NUCLEO64)
/*
 *  DCMI
 */
#define TADR_DCMI_BASE      (AHB2PERIPH_BASE + 0x08050000)
#define TOFF_DCMI_CR        0x0000		/* (RW) DCMI control register */
  #define DCMI_CR_CAPTURE    0x00000001	/* DCMI Capture enable */
  #define DCMI_CR_CM         0x00000002	/* DCMI Capture mode */
  #define DCMI_CR_CROP       0x00000004	/* DCMI Crop feature */
  #define DCMI_CR_JPEG       0x00000008	/* DCMI JPEG format */
  #define DCMI_CR_ESS        0x00000010	/* DCMI Embedded synchronization select */
  #define DCMI_CR_PCKPOL     0x00000020	/* DCMI Pixel clock polarity */
  #define DCMI_CR_HSPOL      0x00000040	/* DCMI Horizontal synchronization polarity */
  #define DCMI_CR_VSPOL      0x00000080	/* DCMI Vertical synchronization polarity */
  #define DCMI_CR_FCRC       0x00000300	/* DCMI Frame capture rate control FCRC[1:0] */
  #define DCMI_CR_FCRC_0     0x00000100
  #define DCMI_CR_FCRC_1     0x00000200
  #define DCMI_CR_EDM        0x00000C00	/* DCMI Extended data mode EDM[1:0] */
  #define DCMI_CR_EDM_0      0x00000400
  #define DCMI_CR_EDM_1      0x00000800
  #define DCMI_CR_ENABLE     0x00004000	/* DCMI DCMI enable */
  #define DCMI_CR_BSM        0x00030000	/* DCMI Byte Select mode BSM[1:0] */
  #define DCMI_CR_BSM_0      0x00010000
  #define DCMI_CR_BSM_1      0x00020000
  #define DCMI_CR_OEBS       0x00040000	/* DCMI Odd/Even Byte Select (Byte Select Start) */
  #define DCMI_CR_LSM        0x00080000	/* DCMI Line Select mode */
  #define DCMI_CR_OELS       0x00100000	/* DCMI Odd/Even Line Select (Line Select Start) */
#define TOFF_DCMI_SR        0x0004		/* (RW) DCMI status register */
  #define DCMI_SR_HSYNC      0x00000001
  #define DCMI_SR_VSYNC      0x00000002
  #define DCMI_SR_FNE        0x00000004	/* DCMI FIFO not empty */
#define TOFF_DCMI_RISR      0x0008		/* (RW) DCMI raw interrupt status register */
  #define DCMI_RIS_FRAME_RIS 0x00000001	/* DCMI Capture complete raw interrupt status */
  #define DCMI_RIS_OVR_RIS   0x00000002	/* DCMI Overrun raw interrupt status */
  #define DCMI_RIS_ERR_RIS   0x00000004	/* DCMI Synchronization error raw interrupt status */
  #define DCMI_RIS_VSYNC_RIS 0x00000008	/* DCMI VSYNC raw interrupt status */
  #define DCMI_RIS_LINE_RIS  0x00000010	/* DCMI Line raw interrupt status */
#define TOFF_DCMI_IER       0x000C		/* (RW) DCMI interrupt enable register */
  #define DCMI_IER_FRAME_IE  0x00000001	/* DCMI Capture complete interrupt enable */
  #define DCMI_IER_OVR_IE    0x00000002	/* DCMI Overrun interrupt enable */
  #define DCMI_IER_ERR_IE    0x00000004	/* DCMI Synchronization error interrupt enable */
  #define DCMI_IER_VSYNC_IE  0x00000008	/* DCMI VSYNC interrupt enable */
  #define DCMI_IER_LINE_IE   0x00000010	/* DCMI Line interrupt enable */
  #define DCMI_IER_INT_IE    0x0000001F
#define TOFF_DCMI_MISR      0x0010		/* (RW) DCMI masked interrupt status register */
  #define DCMI_MIS_FRAME_MIS 0x00000001	/* DCMI Capture complete masked interrupt status */
  #define DCMI_MIS_OVR_MIS   0x00000002	/* DCMI Overrun masked interrupt status */
  #define DCMI_MIS_ERR_MIS   0x00000004	/* DCMI Synchronization error masked interrupt status */
  #define DCMI_MIS_VSYNC_MIS 0x00000008	/* DCMI VSYNC masked interrupt status */
  #define DCMI_MIS_LINE_MIS  0x00000010	/* DCMI Line masked interrupt status */
#define TOFF_DCMI_ICR       0x0014		/* (RW) DCMI interrupt clear register */
  #define DCMI_ICR_FRAME     0x00000001	/* DCMI Capture complete interrupt status clear */
  #define DCMI_ICR_OVR_ISC   0x00000002	/* DCMI Overrun interrupt status clear */
  #define DCMI_ICR_ERR_ISC   0x00000004	/* DCMI Synchronization error interrupt status clear */
  #define DCMI_ICR_VSYNC_ISC 0x00000008	/* DCMI Vertical synch interrupt status clear */
  #define DCMI_ICR_LINE_ISC  0x00000010	/* DCMI line interrupt status clear */
#define TOFF_DCMI_ESCR      0x0018		/* (RW) DCMI embedded synchronization code register */
  #define DCMI_ESCR_FSC      0x000000FF	/* DCMI Frame start delimiter code FSC[7:0] */
  #define DCMI_ESCR_FSC_0    0x00000001
  #define DCMI_ESCR_FSC_1    0x00000002
  #define DCMI_ESCR_FSC_2    0x00000004
  #define DCMI_ESCR_FSC_3    0x00000008
  #define DCMI_ESCR_FSC_4    0x00000010
  #define DCMI_ESCR_FSC_5    0x00000020
  #define DCMI_ESCR_FSC_6    0x00000040
  #define DCMI_ESCR_FSC_7    0x00000080
  #define DCMI_ESCR_LSC      0x0000FF00	/* DCMI Line start delimiter code LSC[7:0] */
  #define DCMI_ESCR_LSC_0    0x00000100
  #define DCMI_ESCR_LSC_1    0x00000200
  #define DCMI_ESCR_LSC_2    0x00000400
  #define DCMI_ESCR_LSC_3    0x00000800
  #define DCMI_ESCR_LSC_4    0x00001000
  #define DCMI_ESCR_LSC_5    0x00002000
  #define DCMI_ESCR_LSC_6    0x00004000
  #define DCMI_ESCR_LSC_7    0x00008000
  #define DCMI_ESCR_LEC      0x00FF0000	/* DCMI Line end delimiter code LEC[7:0] */
  #define DCMI_ESCR_LEC_0    0x00010000
  #define DCMI_ESCR_LEC_1    0x00020000
  #define DCMI_ESCR_LEC_2    0x00040000
  #define DCMI_ESCR_LEC_3    0x00080000
  #define DCMI_ESCR_LEC_4    0x00100000
  #define DCMI_ESCR_LEC_5    0x00200000
  #define DCMI_ESCR_LEC_6    0x00400000
  #define DCMI_ESCR_LEC_7    0x00800000
  #define DCMI_ESCR_FEC      0xFF000000	/* DCMI Frame end delimiter code FEC[7:0] */
  #define DCMI_ESCR_FEC_0    0x01000000
  #define DCMI_ESCR_FEC_1    0x02000000
  #define DCMI_ESCR_FEC_2    0x04000000
  #define DCMI_ESCR_FEC_3    0x08000000
  #define DCMI_ESCR_FEC_4    0x10000000
  #define DCMI_ESCR_FEC_5    0x20000000
  #define DCMI_ESCR_FEC_6    0x40000000
  #define DCMI_ESCR_FEC_7    0x80000000
#define TOFF_DCMI_ESUR      0x001C		/* (RW) DCMI embedded synchronization unmask register */
  #define DCMI_ESUR_FSU      0x000000FF	/* DCMI Frame start delimiter unmask FSU[7:0] */
  #define DCMI_ESUR_FSU_0    0x00000001
  #define DCMI_ESUR_FSU_1    0x00000002
  #define DCMI_ESUR_FSU_2    0x00000004
  #define DCMI_ESUR_FSU_3    0x00000008
  #define DCMI_ESUR_FSU_4    0x00000010
  #define DCMI_ESUR_FSU_5    0x00000020
  #define DCMI_ESUR_FSU_6    0x00000040
  #define DCMI_ESUR_FSU_7    0x00000080
  #define DCMI_ESUR_LSU      0x0000FF00	/* DCMI Line start delimiter unmask LSU[7:0] */
  #define DCMI_ESUR_LSU_0    0x00000100
  #define DCMI_ESUR_LSU_1    0x00000200
  #define DCMI_ESUR_LSU_2    0x00000400
  #define DCMI_ESUR_LSU_3    0x00000800
  #define DCMI_ESUR_LSU_4    0x00001000
  #define DCMI_ESUR_LSU_5    0x00002000
  #define DCMI_ESUR_LSU_6    0x00004000
  #define DCMI_ESUR_LSU_7    0x00008000
  #define DCMI_ESUR_LEU      0x00FF0000	/* DCMI Line end delimiter unmask LEU[7:0] */
  #define DCMI_ESUR_LEU_0    0x00010000
  #define DCMI_ESUR_LEU_1    0x00020000
  #define DCMI_ESUR_LEU_2    0x00040000
  #define DCMI_ESUR_LEU_3    0x00080000
  #define DCMI_ESUR_LEU_4    0x00100000
  #define DCMI_ESUR_LEU_5    0x00200000
  #define DCMI_ESUR_LEU_6    0x00400000
  #define DCMI_ESUR_LEU_7    0x00800000
  #define DCMI_ESUR_FEU      0xFF000000	/* DCMI Frame end delimiter unmask FEU[7:0] */
  #define DCMI_ESUR_FEU_0    0x01000000
  #define DCMI_ESUR_FEU_1    0x02000000
  #define DCMI_ESUR_FEU_2    0x04000000
  #define DCMI_ESUR_FEU_3    0x08000000
  #define DCMI_ESUR_FEU_4    0x10000000
  #define DCMI_ESUR_FEU_5    0x20000000
  #define DCMI_ESUR_FEU_6    0x40000000
  #define DCMI_ESUR_FEU_7    0x80000000
#define TOFF_DCMI_CWSTRTR   0x0020		/* (RW) DCMI crop window start */
  #define DCMI_CWSTRT_HOFFCNT   0x00003FFF	/* DCMI Horizontal offset count HOFFCNT[13:0] */
  #define DCMI_CWSTRT_HOFFCNT_0 0x00000001
  #define DCMI_CWSTRT_HOFFCNT_1 0x00000002
  #define DCMI_CWSTRT_HOFFCNT_2 0x00000004
  #define DCMI_CWSTRT_HOFFCNT_3 0x00000008
  #define DCMI_CWSTRT_HOFFCNT_4 0x00000010
  #define DCMI_CWSTRT_HOFFCNT_5 0x00000020
  #define DCMI_CWSTRT_HOFFCNT_6 0x00000040
  #define DCMI_CWSTRT_HOFFCNT_7 0x00000080
  #define DCMI_CWSTRT_HOFFCNT_8 0x00000100
  #define DCMI_CWSTRT_HOFFCNT_9 0x00000200
  #define DCMI_CWSTRT_HOFFCNT_10 0x00000400
  #define DCMI_CWSTRT_HOFFCNT_11 0x00000800
  #define DCMI_CWSTRT_HOFFCNT_12 0x00001000
  #define DCMI_CWSTRT_HOFFCNT_13 0x00002000
  #define DCMI_CWSTRT_VST   0x1FFF0000	/* DCMI Vertical start line count VST[12:0] */
  #define DCMI_CWSTRT_VST_0 0x00010000
  #define DCMI_CWSTRT_VST_1 0x00020000
  #define DCMI_CWSTRT_VST_2 0x00040000
  #define DCMI_CWSTRT_VST_3 0x00080000
  #define DCMI_CWSTRT_VST_4 0x00100000
  #define DCMI_CWSTRT_VST_5 0x00200000
  #define DCMI_CWSTRT_VST_6 0x00400000
  #define DCMI_CWSTRT_VST_7 0x00800000
  #define DCMI_CWSTRT_VST_8 0x01000000
  #define DCMI_CWSTRT_VST_9 0x02000000
  #define DCMI_CWSTRT_VST_10 0x04000000
  #define DCMI_CWSTRT_VST_11 0x08000000
  #define DCMI_CWSTRT_VST_12 0x10000000
#define TOFF_DCMI_CWSIZER   0x0024		/* (RW) DCMI crop window size */
  #define DCMI_CWSIZE_CAPCNT    0x00003FFF	/* DCMI Capture count CAPCNT[13:0] */
  #define DCMI_CWSIZE_CAPCNT_0  0x00000001
  #define DCMI_CWSIZE_CAPCNT_1  0x00000002
  #define DCMI_CWSIZE_CAPCNT_2  0x00000004
  #define DCMI_CWSIZE_CAPCNT_3  0x00000008
  #define DCMI_CWSIZE_CAPCNT_4  0x00000010
  #define DCMI_CWSIZE_CAPCNT_5  0x00000020
  #define DCMI_CWSIZE_CAPCNT_6  0x00000040
  #define DCMI_CWSIZE_CAPCNT_7  0x00000080
  #define DCMI_CWSIZE_CAPCNT_8  0x00000100
  #define DCMI_CWSIZE_CAPCNT_9  0x00000200
  #define DCMI_CWSIZE_CAPCNT_10 0x00000400
  #define DCMI_CWSIZE_CAPCNT_11 0x00000800
  #define DCMI_CWSIZE_CAPCNT_12 0x00001000
  #define DCMI_CWSIZE_CAPCNT_13 0x00002000
  #define DCMI_CWSIZE_VLINE  0x3FFF0000	/* DCMI Vertical line count VLINE[13:0] */
  #define DCMI_CWSIZE_VLINE_0   0x00010000
  #define DCMI_CWSIZE_VLINE_1   0x00020000
  #define DCMI_CWSIZE_VLINE_2   0x00040000
  #define DCMI_CWSIZE_VLINE_3   0x00080000
  #define DCMI_CWSIZE_VLINE_4   0x00100000
  #define DCMI_CWSIZE_VLINE_5   0x00200000
  #define DCMI_CWSIZE_VLINE_6   0x00400000
  #define DCMI_CWSIZE_VLINE_7   0x00800000
  #define DCMI_CWSIZE_VLINE_8   0x01000000
  #define DCMI_CWSIZE_VLINE_9   0x02000000
  #define DCMI_CWSIZE_VLINE_10  0x04000000
  #define DCMI_CWSIZE_VLINE_11  0x08000000
  #define DCMI_CWSIZE_VLINE_12  0x10000000
  #define DCMI_CWSIZE_VLINE_13  0x20000000
#define TOFF_DCMI_DR        0x0028		/* (RW) DCMI data register */
  #define DCMI_DR_BYTE0      0x000000FF	/* DCMI Data byte 0 Byte0[7:0] */
  #define DCMI_DR_BYTE0_0    0x00000001
  #define DCMI_DR_BYTE0_1    0x00000002
  #define DCMI_DR_BYTE0_2    0x00000004
  #define DCMI_DR_BYTE0_3    0x00000008
  #define DCMI_DR_BYTE0_4    0x00000010
  #define DCMI_DR_BYTE0_5    0x00000020
  #define DCMI_DR_BYTE0_6    0x00000040
  #define DCMI_DR_BYTE0_7    0x00000080
  #define DCMI_DR_BYTE1      0x0000FF00	/* DCMI Data byte 1 Byte1[7:0] */
  #define DCMI_DR_BYTE1_0    0x00000100
  #define DCMI_DR_BYTE1_1    0x00000200
  #define DCMI_DR_BYTE1_2    0x00000400
  #define DCMI_DR_BYTE1_3    0x00000800
  #define DCMI_DR_BYTE1_4    0x00001000
  #define DCMI_DR_BYTE1_5    0x00002000
  #define DCMI_DR_BYTE1_6    0x00004000
  #define DCMI_DR_BYTE1_7    0x00008000
  #define DCMI_DR_BYTE2      0x00FF0000	/* DCMI Data byte 2 Byte2[7:0] */
  #define DCMI_DR_BYTE2_0    0x00010000
  #define DCMI_DR_BYTE2_1    0x00020000
  #define DCMI_DR_BYTE2_2    0x00040000
  #define DCMI_DR_BYTE2_3    0x00080000
  #define DCMI_DR_BYTE2_4    0x00100000
  #define DCMI_DR_BYTE2_5    0x00200000
  #define DCMI_DR_BYTE2_6    0x00400000
  #define DCMI_DR_BYTE2_7    0x00800000
  #define DCMI_DR_BYTE3      0xFF000000	/* DCMI Data byte 3 Byte3[7:0] */
  #define DCMI_DR_BYTE3_0    0x01000000
  #define DCMI_DR_BYTE3_1    0x02000000
  #define DCMI_DR_BYTE3_2    0x04000000
  #define DCMI_DR_BYTE3_3    0x08000000
  #define DCMI_DR_BYTE3_4    0x10000000
  #define DCMI_DR_BYTE3_5    0x20000000
  #define DCMI_DR_BYTE3_6    0x40000000
  #define DCMI_DR_BYTE3_7    0x80000000


/*
 *  OCTO SERIAL PERIPHERAL INTERFACE
 */
#define TADR_OCTOSPI1_BASE  (OCTOSPI1_R_BASE)
#define TADR_OCTOSPI2_BASE  (OCTOSPI2_R_BASE)
#define TADR_OCTOSPIM_BASE  (AHB2PERIPH_BASE + 0x08061C00)
#define TOFF_OCTOSPI_CR     0x0000		/* (RW) OCTOSPI Control register */
  #define OCTOSPI_CR_EN      0x00000001	/* Enable */
  #define OCTOSPI_CR_ABORT   0x00000002	/* Abort request */
  #define OCTOSPI_CR_DMAEN   0x00000004	/* DMA Enable */
  #define OCTOSPI_CR_TCEN    0x00000008	/* Timeout Counter Enable */
  #define OCTOSPI_CR_DQM     0x00000040	/* Dual-Quad Mode */
  #define OCTOSPI_CR_FSEL    0x00000080	/* Flash Select */
  #define OCTOSPI_CR_FTHRES  0x00001F00	/* FIFO Threshold Level */
  #define OCTOSPI_CR_TEIE    0x00010000	/* Transfer Error Interrupt Enable */
  #define OCTOSPI_CR_TCIE    0x00020000	/* Transfer Complete Interrupt Enable */
  #define OCTOSPI_CR_FTIE    0x00040000	/* FIFO Threshold Interrupt Enable */
  #define OCTOSPI_CR_SMIE    0x00080000	/* Status Match Interrupt Enable */
  #define OCTOSPI_CR_TOIE    0x00100000	/* TimeOut Interrupt Enable */
  #define OCTOSPI_CR_APMS    0x00400000	/* Automatic Poll Mode Stop */
  #define OCTOSPI_CR_PMM     0x00800000	/* Polling Match Mode */
  #define OCTOSPI_CR_FMODE   0x30000000	/* Functional Mode */
  #define OCTOSPI_CR_FMODE_0 0x10000000
  #define OCTOSPI_CR_FMODE_1 0x20000000
#define TOFF_OCTOSPI_DCR1   0x0004		/* (RW) OCTOSPI Device Configuration register 1 */
  #define OCTOSPI_DCR1_CKMODE  0x00000001	/* Mode 0 / Mode 3 */
  #define OCTOSPI_DCR1_FRCK    0x00000002	/* Free Running Clock */
  #define OCTOSPI_DCR1_CSHT    0x00000700	/* Chip Select High Time */
  #define OCTOSPI_DCR1_DEVSIZE 0x001F0000	/* Device Size */
  #define OCTOSPI_DCR1_MTYPs   0x07000000	/* Memory Type */
  #define OCTOSPI_DCR1_MTYP_0  0x01000000
  #define OCTOSPI_DCR1_MTYP_1  0x02000000
  #define OCTOSPI_DCR1_MTYP_2  0x04000000
#define TOFF_OCTOSPI_DCR2   0x000C		/* (RW) OCTOSPI Device Configuration register 2 */
  #define OCTOSPI_DCR2_PRESCALER  0x000000FF	/* Clock prescaler */
  #define OCTOSPI_DCR2_WRAPSIZE   0x00070000	/* Wrap Size */
  #define OCTOSPI_DCR2_WRAPSIZE_0 0x00010000
  #define OCTOSPI_DCR2_WRAPSIZE_1 0x00020000
  #define OCTOSPI_DCR2_WRAPSIZE_2 0x00040000
#define TOFF_OCTOSPI_DCR3   0x0010		/* (RW) OCTOSPI Device Configuration register 3 */
  #define OCTOSPI_DCR3_CSBOUND 0x001F0000	/* CS Boundary */
#define TOFF_OCTOSPI_SR     0x0020		/* (RW) OCTOSPI Status register */
  #define OCTOSPI_SR_TEF     0x00000001	/* Transfer Error Flag */
  #define OCTOSPI_SR_TCF     0x00000002	/* Transfer Complete Flag */
  #define OCTOSPI_SR_FTF     0x00000004	/* FIFO Threshold Flag */
  #define OCTOSPI_SR_SMF     0x00000008	/* Status Match Flag */
  #define OCTOSPI_SR_TOF     0x00000010	/* Timeout Flag */
  #define OCTOSPI_SR_BUSY    0x00000020	/* Busy */
  #define OCTOSPI_SR_FLEVEL  0x00003F00	/* FIFO Level */
#define TOFF_OCTOSPI_FCR    0x0024		/* (RW) OCTOSPI Flag Clear register */
  #define OCTOSPI_FCR_CTEF   0x00000001	/* Clear Transfer Error Flag */
  #define OCTOSPI_FCR_CTCF   0x00000002	/* Clear Transfer Complete Flag */
  #define OCTOSPI_FCR_CSMF   0x00000008	/* Clear Status Match Flag */
  #define OCTOSPI_FCR_TOF    0x00000100	/* Clear Timeout Flag */
#define TOFF_OCTOSPI_DLR    0x0040		/* (RW) OCTOSPI Data Length register */
#define TOFF_OCTOSPI_AR     0x0048		/* (RW) OCTOSPI Address register */
#define TOFF_OCTOSPI_DR     0x0050		/* (RW) OCTOPSI Data register */
#define TOFF_OCTOSPI_PSMKR  0x0080		/* (RW) OCTOSPI Polling Status Mask register */
#define TOFF_OCTOSPI_PSMAR  0x0084		/* (RW) OCTOSPI Polling Status Match register */
#define TOFF_OCTOSPI_PIR    0x0090		/* (RW) OCTOSPI Polling Interval register */
#define TOFF_OCTOSPI_CCR    0x0100		/* (RW) OCTOSPI Communication Configuration register */
  #define OCTOSPI_CCR_IMODE  0x00000007	/* Instruction Mode */
  #define OCTOSPI_CCR_IMODE_0  0x00000001
  #define OCTOSPI_CCR_IMODE_1  0x00000002
  #define OCTOSPI_CCR_IMODE_2  0x00000004
  #define OCTOSPI_CCR_IDTR   0x00000008	/* Instruction Double Transfer Rate */
  #define OCTOSPI_CCR_ISIZE  0x00000030	/* Instruction Size */
  #define OCTOSPI_CCR_ISIZE_0  0x00000010
  #define OCTOSPI_CCR_ISIZE_1  0x00000020
  #define OCTOSPI_CCR_ADMODE 0x00000700	/* Address Mode */
  #define OCTOSPI_CCR_ADMODE_0 0x00000100
  #define OCTOSPI_CCR_ADMODE_1 0x00000200
  #define OCTOSPI_CCR_ADMODE_2 0x00000400
  #define OCTOSPI_CCR_ADDTR  0x00000800	/* Address Double Transfer Rate */
  #define OCTOSPI_CCR_ADSIZE 0x00003000	/* Address Size */
  #define OCTOSPI_CCR_ADSIZE_0 0x00001000
  #define OCTOSPI_CCR_ADSIZE_1 0x00002000
  #define OCTOSPI_CCR_ABMODE 0x00070000	/* Alternate Bytes Mode */
  #define OCTOSPI_CCR_ABMODE_0 0x00010000
  #define OCTOSPI_CCR_ABMODE_1 0x00020000
  #define OCTOSPI_CCR_ABMODE_2 0x00040000
  #define OCTOSPI_CCR_ABDTR  0x00080000	/* Alternate Bytes Double Transfer Rate */
  #define OCTOSPI_CCR_ABSIZE 0x00300000	/* Alternate Bytes Size */
  #define OCTOSPI_CCR_ABSIZE_0 0x00100000
  #define OCTOSPI_CCR_ABSIZE_1 0x00200000
  #define OCTOSPI_CCR_DMODE  0x07000000	/* Data Mode */
  #define OCTOSPI_CCR_DMODE_0  0x01000000
  #define OCTOSPI_CCR_DMODE_1  0x02000000
  #define OCTOSPI_CCR_DMODE_2  0x04000000
  #define OCTOSPI_CCR_DDTR   0x08000000	/* Data Double Transfer Rate */
  #define OCTOSPI_CCR_DQSE   0x20000000	/* DQS Enable */
  #define OCTOSPI_CCR_SIOO   0x80000000	/* Send Instruction Only Once Mode */
#define TOFF_OCTOSPI_TCR    0x0108		/* (RW) OCTOSPI Timing Configuration register */
  #define OCTOSPI_TCR_DCYC   0x0000001F	/* Number of Dummy Cycles */
  #define OCTOSPI_TCR_DHQC   0x10000000	/* Delay Hold Quarter Cycle */
  #define OCTOSPI_TCR_SSHIFT 0x40000000	/* Sample Shift */
#define TOFF_OCTOSPI_IR     0x0110		/* (RW) OCTOSPI Instruction register */
#define TOFF_OCTOSPI_ABR    0x0120		/* (RW) OCTOSPI Alternate Bytes register */
#define TOFF_OCTOSPI_LPTR   0x0130		/* (RW) OCTOSPI Low Power Timeout register */
#define TOFF_OCTOSPI_WCCR   0x0180		/* (RW) OCTOSPI Write Communication Configuration register */
  #define OCTOSPI_WCCR_IMODE 0x00000007	/* Instruction Mode */
  #define OCTOSPI_WCCR_IMODE_0  0x00000001
  #define OCTOSPI_WCCR_IMODE_1  0x00000002
  #define OCTOSPI_WCCR_IMODE_2  0x00000004
  #define OCTOSPI_WCCR_IDTR  0x00000008	/* Instruction Double Transfer Rate */
  #define OCTOSPI_WCCR_ISIZE 0x00000030	/* Instruction Size */
  #define OCTOSPI_WCCR_ISIZE_0  0x00000010
  #define OCTOSPI_WCCR_ISIZE_1  0x00000020
  #define OCTOSPI_WCCR_ADMODE 0x00000700	/* Address Mode */
  #define OCTOSPI_WCCR_ADMODE_0 0x00000100
  #define OCTOSPI_WCCR_ADMODE_1 0x00000200
  #define OCTOSPI_WCCR_ADMODE_2 0x00000400
  #define OCTOSPI_WCCR_ADDTR 0x00000800	/* Address Double Transfer Rate */
  #define OCTOSPI_WCCR_ADSIZE 0x00003000	/* Address Size */
  #define OCTOSPI_WCCR_ADSIZE_0 0x00001000
  #define OCTOSPI_WCCR_ADSIZE_1 0x00002000
  #define OCTOSPI_WCCR_ABMODE 0x00070000	/* Alternate Bytes Mode */
  #define OCTOSPI_WCCR_ABMODE_0 0x00010000
  #define OCTOSPI_WCCR_ABMODE_1 0x00020000
  #define OCTOSPI_WCCR_ABMODE_2 0x00040000
  #define OCTOSPI_WCCR_ABDTR 0x00080000	/* Alternate Bytes Double Transfer Rate */
  #define OCTOSPI_WCCR_ABSIZE 0x00300000	/* Alternate Bytes Size */
  #define OCTOSPI_WCCR_ABSIZE_0 0x00100000
  #define OCTOSPI_WCCR_ABSIZE_1 0x00200000
  #define OCTOSPI_WCCR_DMODE 0x07000000	/* Data Mode */
  #define OCTOSPI_WCCR_DMODE_0  0x01000000
  #define OCTOSPI_WCCR_DMODE_1  0x02000000
  #define OCTOSPI_WCCR_DMODE_2  0x04000000
  #define OCTOSPI_WCCR_DDTR  0x08000000	/* Data Double Transfer Rate */
  #define OCTOSPI_WCCR_DQSE  0x20000000	/* DQS Enable */
  #define OCTOSPI_WCCR_SIOO  0x80000000	/* Send Instruction Only Once Mode */
#define TOFF_OCTOSPI_WTCR   0x0188		/* (RW) OCTOSPI Write Timing Configuration register */
  #define OCTOSPI_WTCR_DCYC  0x0000001F	/* Number of Dummy Cycles */
#define TOFF_OCTOSPI_WIR    0x0190		/* (RW) OCTOSPI Write Instruction register */
#define TOFF_OCTOSPI_WABR   0x01A0		/* (RW) OCTOSPI Write Alternate Bytes register */
#define TOFF_OCTOSPI_HLCR   0x0200		/* (RW) OCTOSPI Hyperbus Latency Configuration register */
  #define OCTOSPI_HLCR_LM    0x00000001	/* Latency Mode */
  #define OCTOSPI_HLCR_WZL   0x00000002	/* Write Zero Latency */
  #define OCTOSPI_HLCR_TACC  0x0000FF00	/* Access Time */
  #define OCTOSPI_HLCR_TRWR  0x00FF0000	/* Read Write Recovery Time */


#define TOFF_OCTOSPIM_PCR1  0x0004		/* (RW) OCTOSPI IO Manager Port[1] Configuration register */
  #define OCTOSPIM_PCR_CLKEN  0x00000001	/* CLK/CLKn Enable for Port n */
  #define OCTOSPIM_PCR_CLKSRC 0x00000002	/* CLK/CLKn Source for Port n */
  #define OCTOSPIM_PCR_DQSEN  0x00000010	/* DQS Enable for Port n */
  #define OCTOSPIM_PCR_DQSSRC 0x00000020	/* DQS Source for Port n */
  #define OCTOSPIM_PCR_NCSEN  0x00000100	/* nCS Enable for Port n */
  #define OCTOSPIM_PCR_NCSSRC 0x00000200	/* nCS Source for Port n */
  #define OCTOSPIM_PCR_IOLEN  0x00010000	/* IO[3:0] Enable for Port n */
  #define OCTOSPIM_PCR_IOLSRC 0x00060000	/* IO[3:0] Source for Port n */
  #define OCTOSPIM_PCR_IOLSRC_0  0x00020000
  #define OCTOSPIM_PCR_IOLSRC_1  0x00040000
  #define OCTOSPIM_PCR_IOHEN  0x01000000	/* IO[7:4] Enable for Port n */
  #define OCTOSPIM_PCR_IOHSRC 0x06000000	/* IO[7:4] Source for Port n */
  #define OCTOSPIM_PCR_IOHSRC_0  0x02000000
  #define OCTOSPIM_PCR_IOHSRC_1  0x04000000
#define TOFF_OCTOSPIM_PCR2  0x0008		/* (RW) OCTOSPI IO Manager Port[2] Configuration register */
#else
/*
 * QUAD SERIAL PERIPHERAL INTERFACE
 */
#define TADR_QSPI_R_BASE    (QSPI_R_BASE)
#define TOFF_QUADSPI_CR     0x0000		/* (RW) QUADSPI Control register */
  #define QUADSPI_CR_EN         0x00000001	/* Enable */
  #define QUADSPI_CR_ABORT      0x00000002	/* Abort request */
  #define QUADSPI_CR_DMAEN      0x00000004	/* DMA Enable */
  #define QUADSPI_CR_TCEN       0x00000008	/* Timeout Counter Enable */
  #define QUADSPI_CR_SSHIFT     0x00000010	/* Sample Shift */
  #define QUADSPI_CR_FTHRES     0x00000F00	/* FTHRES[3:0] FIFO Level */
  #define QUADSPI_CR_TEIE       0x00010000	/* Transfer Error Interrupt Enable */
  #define QUADSPI_CR_TCIE       0x00020000	/* Transfer Complete Interrupt Enable */
  #define QUADSPI_CR_FTIE       0x00040000	/* FIFO Threshold Interrupt Enable */
  #define QUADSPI_CR_SMIE       0x00080000	/* Status Match Interrupt Enable */
  #define QUADSPI_CR_TOIE       0x00100000	/* TimeOut Interrupt Enable */
  #define QUADSPI_CR_APMS       0x00400000	/* Automatic Polling Mode Stop */
  #define QUADSPI_CR_PMM        0x00800000	/* Polling Match Mode */
  #define QUADSPI_CR_PRESCALER  0xFF000000	/* PRESCALER[7:0] Clock prescaler */
#define TOFF_QUADSPI_DCR    0x0004		/* (RW) QUADSPI Device Configuration register */
  #define QUADSPI_DCR_CKMODE    0x00000001	/* Mode 0 / Mode 3 */
  #define QUADSPI_DCR_CSHT      0x00000700	/* CSHT[2:0]: ChipSelect High Time */
  #define QUADSPI_DCR_CSHT_0    0x00000100
  #define QUADSPI_DCR_CSHT_1    0x00000200
  #define QUADSPI_DCR_CSHT_2    0x00000400
  #define QUADSPI_DCR_FSIZE     0x001F0000	/* FSIZE[4:0]: Flash Size */
#define TOFF_QUADSPI_SR     0x0008		/* (RW) QUADSPI Status register */
  #define QUADSPI_SR_TEF        0x00000001	/* Transfer Error Flag */
  #define QUADSPI_SR_TCF        0x00000002	/* Transfer Complete Flag */
  #define QUADSPI_SR_FTF        0x00000004	/* FIFO Threshlod Flag */
  #define QUADSPI_SR_SMF        0x00000008	/* Status Match Flag */
  #define QUADSPI_SR_TOF        0x00000010	/* Timeout Flag */
  #define QUADSPI_SR_BUSY       0x00000020	/* Busy */
  #define QUADSPI_SR_FLEVEL     0x00001F00	/* FIFO Threshlod Flag */
#define TOFF_QUADSPI_FCR    0x000C		/* (W)  QUADSPI Flag Clear register */
  #define QUADSPI_FCR_CTEF      0x00000001	/* Clear Transfer Error Flag */
  #define QUADSPI_FCR_CTCF      0x00000002	/* Clear Transfer Complete Flag */
  #define QUADSPI_FCR_CSMF      0x00000008	/* Clear Status Match Flag */
  #define QUADSPI_FCR_CTOF      0x00000010	/* Clear Timeout Flag */
#define TOFF_QUADSPI_DLR    0x0010		/* (RW) QUADSPI Data Length register */
#define TOFF_QUADSPI_CCR    0x0014		/* (RW) QUADSPI Communication Configuration register */
  #define QUADSPI_CCR_INSTRUCTION 0x000000FF	/* INSTRUCTION[7:0]: Instruction */
  #define QUADSPI_CCR_IMODE     0x00000300	/* IMODE[1:0]: Instruction Mode */
  #define QUADSPI_CCR_IMODE_0   0x00000100
  #define QUADSPI_CCR_IMODE_1   0x00000200
  #define QUADSPI_CCR_ADMODE    0x00000C00	/* ADMODE[1:0]: Address Mode */
  #define QUADSPI_CCR_ADMODE_0  0x00000400
  #define QUADSPI_CCR_ADMODE_1  0x00000800
  #define QUADSPI_CCR_ADSIZE    0x00003000	/* ADSIZE[1:0]: Address Size */
  #define QUADSPI_CCR_ADSIZE_0  0x00001000
  #define QUADSPI_CCR_ADSIZE_1  0x00002000
  #define QUADSPI_CCR_ABMODE    0x0000C000	/* ABMODE[1:0]: Alternate Bytes Mode */
  #define QUADSPI_CCR_ABMODE_0  0x00004000
  #define QUADSPI_CCR_ABMODE_1  0x00008000
  #define QUADSPI_CCR_ABSIZE    0x00030000	/* ABSIZE[1:0]: Instruction Mode */
  #define QUADSPI_CCR_ABSIZE_0  0x00010000
  #define QUADSPI_CCR_ABSIZE_1  0x00020000
  #define QUADSPI_CCR_DCYC      0x007C0000	/* DCYC[4:0]: Dummy Cycles */
  #define QUADSPI_CCR_DMODE     0x03000000	/* DMODE[1:0]: Data Mode */
  #define QUADSPI_CCR_DMODE_0   0x01000000
  #define QUADSPI_CCR_DMODE_1   0x02000000
  #define QUADSPI_CCR_FMODE     0x0C000000	/* FMODE[1:0]: Functional Mode */
  #define QUADSPI_CCR_FMODE_0   0x04000000
  #define QUADSPI_CCR_FMODE_1   0x08000000
  #define QUADSPI_CCR_SIOO      0x10000000	/* SIOO: Send Instruction Only Once Mode */
  #define QUADSPI_CCR_DDRM      0x80000000	/* DDRM: Double Data Rate Mode */
#define TOFF_QUADSPI_AR     0x0018		/* (RW) QUADSPI Address register */
#define TOFF_QUADSPI_ABR    0x001C		/* (RW) QUADSPI Alternate Bytes register */
#define TOFF_QUADSPI_DR     0x0020		/* (RW) QUADSPI Data register */
#define TOFF_QUADSPI_PSMKR  0x0024		/* (RW) QUADSPI Polling Status Mask register */
#define TOFF_QUADSPI_PSMAR  0x0028		/* (RW) QUADSPI Polling Status Match register */
#define TOFF_QUADSPI_PIR    0x002C		/* (RW) QUADSPI Polling Interval register */
  #define QUADSPI_PIR_INTERVAL  0x0000FFFF	/* INTERVAL[15:0]: Polling Interval */
#define TOFF_QUADSPI_LPTR   0x0030		/* (RW) QUADSPI Low Power Timeout register */
  #define QUADSPI_LPTR_TIMEOUT  0x0000FFFF	/* TIMEOUT[15:0]: Timeout period */
#endif


/*
 *  PCGCCTL BIT DEFINITIONS
 */
#define USB_OTG_PCGCCTL_STOPCLK     0x00000001	/* SETUP packet count */
#define USB_OTG_PCGCCTL_GATECLK     0x00000002	/* Bit 0 */
#define USB_OTG_PCGCCTL_PHYSUSP     0x00000010	/* Bit 1 */

/*
 *  DEBUG MCU
 */
#define TADR_DBGMCU_BASE    (DBGMCU_BASE)
#define TOFF_DBGMCU_IDCODE  0x0000		/* (RW) MCU device ID code */
#define TOFF_DBGMCU_CR      0x0004		/* (RW) Debug MCU configuration register */
#define TOFF_DBGMCU_APB1FZR1 0x0008		/* (RW) Debug MCU APB1 freeze register */
#define TOFF_DBGMCU_APB1FZR2 0x000C		/* (RW) Debug MCU APB1 freeze register 2 */
#define TOFF_DBGMCU_APB2FZ  0x000C		/* (RW) Debug MCU APB2 freeze register */


#endif  /* _STM32L4XX_H_ */

