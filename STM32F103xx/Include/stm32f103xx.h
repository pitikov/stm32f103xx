/**************************************************************************//**
 * @file     stm32f103xx.h
 * @brief    CMSIS-Core(M) Device Header File for Device STM32F103xx
 *
 * @version  V1.0.0
 * @date     18. July 2023
 ******************************************************************************/
/*
 * Copyright (c) 2009-2023 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef STM32F103XX_H
#define STM32F103XX_H

#ifdef __cplusplus
extern "C" {
#endif


/* ========================================================================= */
/* ============           Interrupt Number Definition           ============ */
/* ========================================================================= */

typedef enum IRQn
{
/* ================     Cortex-M Core Exception Numbers     ================ */

/* ToDo: add Cortex exception numbers according the used Cortex-Core */
  Reset_IRQn             = -15,  /*  1 Reset Vector
                                       invoked on Power up and warm reset */
  NonMaskableInt_IRQn    = -14,  /*  2 Non maskable Interrupt
                                       cannot be stopped or preempted */
  HardFault_IRQn         = -13,  /*  3 Hard Fault
                                       all classes of Fault */
  MemoryManagement_IRQn  = -12,  /*  4 Memory Management
                                       MPU mismatch, including Access Violation and No Match */
  BusFault_IRQn          = -11,  /*  5 Bus Fault
                                       Pre-Fetch-, Memory Access, other address/memory Fault */
  UsageFault_IRQn        = -10,  /*  6 Usage Fault
                                       i.e. Undef Instruction, Illegal State Transition */
  SecureFault_IRQn       =  -9,  /*  7 Secure Fault Interrupt */
  SVCall_IRQn            =  -5,  /* 11 System Service Call via SVC instruction */
  DebugMonitor_IRQn      =  -4,  /* 12 Debug Monitor */
  PendSV_IRQn            =  -2,  /* 14 Pendable request for system service */
  SysTick_IRQn           =  -1,  /* 15 System Tick Timer */

/* ================        STM32F103xx Interrupt Numbers       ================ */
/* ToDo: Add here your device specific interrupt numbers
         according the interrupt handlers defined in startup_Device.s
         eg.: Interrupt for Timer#1       TIM1_IRQHandler   ->   TIM1_IRQn */
  // <DeviceInterrupt first>_IRQn = 0,    /* first Device Interrupt*/
  // ...
  // <DeviceInterrupt last>_IRQn  = n     /* last Device Interrupt */
} IRQn_Type;


/* ========================================================================= */
/* ============      Processor and Core Peripheral Section      ============ */
/* ========================================================================= */

/* ================ Start of section using anonymous unions ================ */
#if   defined (__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined (__ICCARM__)
  #pragma language=extended
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wc11-extensions"
  #pragma clang diagnostic ignored "-Wreserved-id-macro"
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning 586
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif


/* --------  Configuration of Core Peripherals  ----------------------------------- */

#define __CM3_REV               0x0201U  /* Core Revision r2p1 */
#define __Vendor_SysTickConfig  0U       /* Set to 1 if different SysTick Config is used */
#define __NVIC_PRIO_BITS        4U       /* Number of Bits used for Priority Levels */
#define __VTOR_PRESENT          1U       /* Set to 1 if VTOR is present */
#define __MPU_PRESENT           1U       /* Set to 1 if MPU is present */
#define __FPU_PRESENT           0U       /* Set to 1 if FPU is present */
#define __FPU_DP                0U       /* Set to 1 if FPU is double precision FPU (default is single precision FPU) */
#define __DSP_PRESENT           0U       /* Set to 1 if DSP extension are present */
#define __SAUREGION_PRESENT     0U       /* Set to 1 if SAU regions are present */
#define __PMU_PRESENT           0U       /* Set to 1 if PMU is present */
#define __PMU_NUM_EVENTCNT      0U       /* Set number of PMU Event Counters */
#define __ICACHE_PRESENT        0U       /* Set to 1 if I-Cache is present */
#define __DCACHE_PRESENT        0U       /* Set to 1 if D-Cache is present */
#define __DTCM_PRESENT          0U       /* Set to 1 if DTCM is present */


#include <core_cm3.h>                           /* Processor and core peripherals */
#include "system_stm32f103xx.h"                    /* System Header */



/* ========================================================================= */
/* ============       Device Specific Peripheral Section        ============ */
/* ========================================================================= */


/* ToDo: add here your device specific peripheral access structure typedefs
         including bit definitions for Pos/Msk macros
         following is an example for a timer */

/* ========================================================================= */
/* ============                       TMR                       ============ */
/* ========================================================================= */

// typedef struct
// {
//   __IOM uint32_t  LOAD;                 /* Offset: 0x000 (R/W) Load Register */
//   __IM  uint32_t  VALUE;                /* Offset: 0x004 (R/ ) Value Register */
//   __IOM uint32_t  CONTROL;              /* Offset: 0x008 (R/W) Control Register */
//   __OM  uint32_t  INTCLR;               /* Offset: 0x00C ( /W) Clear Interrupt Register */
//   __IM  uint32_t  RIS;                  /* Offset: 0x010 (R/ ) Raw Interrupt Status Register */
//   __IM  uint32_t  MIS;                  /* Offset: 0x014 (R/ ) Interrupt Status Register */
//   __IOM uint32_t  BGLOAD;               /* Offset: 0x018 (R/W) Background Load Register */
// } <DeviceAbbreviation>_TMR_TypeDef;

// /* <DeviceAbbreviation>_TMR LOAD Register Definitions */
// #define <DeviceAbbreviation>_TMR_LOAD_Pos              0
// #define <DeviceAbbreviation>_TMR_LOAD_Msk             (0xFFFFFFFFUL /*<< <DeviceAbbreviation>_TMR_LOAD_Pos*/)

// /* <DeviceAbbreviation>_TMR VALUE Register Definitions */
// #define <DeviceAbbreviation>_TMR_VALUE_Pos             0
// #define <DeviceAbbreviation>_TMR_VALUE_Msk            (0xFFFFFFFFUL /*<< <DeviceAbbreviation>_TMR_VALUE_Pos*/)

// /* <DeviceAbbreviation>_TMR CONTROL Register Definitions */
// #define <DeviceAbbreviation>_TMR_CONTROL_SIZE_Pos      1
// #define <DeviceAbbreviation>_TMR_CONTROL_SIZE_Msk     (1UL << <DeviceAbbreviation>_TMR_CONTROL_SIZE_Pos)

// #define <DeviceAbbreviation>_TMR_CONTROL_ONESHOT_Pos   0
// #define <DeviceAbbreviation>_TMR_CONTROL_ONESHOT_Msk  (1UL /*<< <DeviceAbbreviation>_TMR_CONTROL_ONESHOT_Pos*/)



/* --------  End of section using anonymous unions and disabling warnings  -------- */
#if   defined (__CC_ARM)
  #pragma pop
#elif defined (__ICCARM__)
  /* leave anonymous unions enabled */
#elif (defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050))
  #pragma clang diagnostic pop
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning restore
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif


/* ========================================================================= */
/* ============     Device Specific Peripheral Address Map      ============ */
/* ========================================================================= */

#define FLASH_MEMORY_BASE                         (0x08000000UL)                            /* FLASH (ROM) Memory base address */
#define SYSTEM_MEMORY_BASE                        (0x1FFFF000UL)                            /* System memory base address */
#define OPTION_BASE                               (0x1FFFF800UL)                            /* Options base */

#define TIM2_BASE                                 (0x40000000UL)                            /* TIM2 Timer base address */
#define TIM3_BASE                                 (0x40000400UL)                            /* TIM3 Timer base address */
#define TIM4_BASE                                 (0x40000800UL)                            /* TIM4 Timer base address */
#define RTC_BASE                                  (0x40002800UL)                            /* RTC Timer base address */
#define WWDG_BASE                                 (0x40002C00UL)                            /* WWDGT Timer base address */
#define IWDG_BASE                                 (0x40003000UL)                            /* IWDGT Timer base address */
#define SPI2_ABSE                                 (0x40003800UL)                            /* SPI2 base address */
#define USART2_BASE                               (0x40004400UL)                            /* USART2 base address */
#define USART3_BASE                               (0x40004800UL)                            /* USART2 base address */
#define I2C1_BASE                                 (0x40005400UL)                            /* I2C1 base address */
#define I2C2_BASE                                 (0x40005800UL)                            /* I2C2 base address */
#define USB_BASE                                  (0x40005C00UL)                            /* USB registers base address */
#define bxCAN_BASE                                (0x40006400UL)                            /* bxCAN base address */
#define BKP_BASE                                  (0x40006C00UL)                            /* BKP base address */
#define PWR_BASE                                  (0x40007000UL)                            /* PWR base address */
#define AFIO_BASE                                 (0x40010000UL)                            /* AFIO base address */
#define EXTI_BASE                                 (0x40010400UL)                            /* EXTI base address */
#define GPIOA_BASE                                (0x40010800UL)                            /* GPIO port A base address */
#define GPIOB_BASE                                (0x40010C00UL)                            /* GPIO port B base address */
#define GPIOC_BASE                                (0x40011000UL)                            /* GPIO port C base address */
#define GPIOD_BASE                                (0x40011400UL)                            /* GPIO port D base address */
#define GPIOE_BASE                                (0x40011800UL)                            /* GPIO port E base address */
#define ADC1_BASE                                 (0x40012400UL)                            /* ADC1 base address */
#define ADC2_BASE                                 (0x40012800UL)                            /* ADC1 base address */
#define TIM1_BASE                                 (0x40012C00UL)                            /* TIM1 Timer base address */
#define SPI1_BASE                                 (0x40013000UL)                            /* SPI1 base address */
#define USART1_BASE                               (0x40013800UL)                            /* USART1 base address */
#define DMA_BASE                                  (0x40020000UL)                            /* DMA base address */
#define RCC_BASE                                  (0x40021000UL)                            /* RCC base address */
#define FLASH_BASE                                (0x40022000UL)                            /* FLASH base address */
#define CRC_BASE                                  (0x40023000UL)                            /* CRC base address */


/*---------------------------------------------------------------------------
Flash memory allocation for STM32F103xx medium density perfomance line devices
-----------------------------------------------------------------------------*/
#define __FLASH_MEMORY_PAGE_COUNT                 128
#define __FLASH_MEMORY_PAGE_SIZE                  0x400
#define __FLASH_MEMORY_PAGE_VALID(n)              ((uint8_t)(n) < __FLASH_MEMORY_PAGE_COUNT)

#define FLASH_MEMORY_PAGE(n)                      (PAGE_VALID(n) ? \
                                                      (volatile uint32_t*)(FLASH_MEMORY_BASE + n * __FLASH_MEMORY_PAGE_SIZE)) : \
                                                      (volatile uint32_t*)0

/* ========================================================================= */
/* ============             Peripheral declaration              ============ */
/* ========================================================================= */


/* ToDo: Add here your device peripherals pointer definitions
         following is an example for timer */

// #define <DeviceAbbreviation>_TIM0        ((<DeviceAbbreviation>_TMR_TypeDef *) <DeviceAbbreviation>TIM0_BASE)
// #define <DeviceAbbreviation>_TIM1        ((<DeviceAbbreviation>_TMR_TypeDef *) <DeviceAbbreviation>TIM0_BASE)
// #define <DeviceAbbreviation>_TIM2        ((<DeviceAbbreviation>_TMR_TypeDef *) <DeviceAbbreviation>TIM0_BASE)

#ifdef __cplusplus
}
#endif

#endif  /* STM32F103XX_H */
