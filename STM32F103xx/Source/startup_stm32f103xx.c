/******************************************************************************
 * @file     startup_stm32f103xx.c
 * @brief    CMSIS-Core(M) Device Startup File for
 *           Device STM32F103xx
 * @version  V1.0.0
 * @date     20. January 2021
 ******************************************************************************/
/*
 * Copyright (c) 2009-2021 Arm Limited. All rights reserved.
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

#include "stm32f103xx.h"

/*---------------------------------------------------------------------------
  External References
 *---------------------------------------------------------------------------*/
extern uint32_t __INITIAL_SP;
extern uint32_t __STACK_LIMIT;
#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
extern uint64_t __STACK_SEAL;
#endif

extern __NO_RETURN void __PROGRAM_START(void);

/*---------------------------------------------------------------------------
  Internal References
 *---------------------------------------------------------------------------*/
__NO_RETURN void Reset_Handler  (void);
__NO_RETURN void Default_Handler(void);

/* ToDo: Add Cortex exception handler according the used Cortex-Core */
/*---------------------------------------------------------------------------
  Exception / Interrupt Handler
 *---------------------------------------------------------------------------*/
/* Exceptions */
void NMI_Handler            (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void HardFault_Handler      (void) __attribute__ ((weak, noreturn));
void MemManage_Handler      (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void BusFault_Handler       (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void UsageFault_Handler     (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void SecureFault_Handler    (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void SVC_Handler            (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void DebugMon_Handler       (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void PendSV_Handler         (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void SysTick_Handler        (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));

/* STM32F103C8 specific interrupt handler */

void WWDG_IRQHandler          (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void PVD_IRQHandler           (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void TAMPER_IRQHandler        (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void RTC_IRQHandler           (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void FLASH_IRQHandler         (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void RCC_IRQHandler           (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void EXTI0_IRQHandler         (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void EXTI1_IRQHandler         (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void EXTI2_IRQHandler         (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void EXTI3_IRQHandler         (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void EXTI4_IRQHandler         (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void DMA1_Channel1_IRQHandler (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void DMA1_Channel2_IRQHandler (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void DMA1_Channel3_IRQHandler (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void DMA1_Channel4_IRQHandler (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void DMA1_Channel5_IRQHandler (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void DMA1_Channel6_IRQHandler (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void DMA1_Channel7_IRQHandler (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void ADC1_2_IRQHandler        (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void USB_HP_CAN_TX_IRQHandler (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void USB_LP_CAN_RX0_IRQHandler(void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void CAN_RX1_IRQHandler       (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void CAN_SCE_IRQHandler       (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void EXTI9_5_IRQHandler       (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void TIM1_BRK_IRQHandler      (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void TIM1_UP_IRQHandler       (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void TIM1_TRG_COM_IRQHandler  (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void TIM1_CC_IRQHandler       (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void TIM2_IRQHandler          (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void TIM3_IRQHandler          (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void TIM4_IRQHandler          (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void I2C1_EV_IRQHandler       (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void I2C1_ER_IRQHandler       (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void I2C2_EV_IRQHandler       (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void I2C2_ER_IRQHandler       (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void SPI1_IRQHandler          (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void SPI2_IRQHandler          (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void USART1_IRQHandler        (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void USART2_IRQHandler        (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void USART3_IRQHandler        (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void EXTI15_10_IRQHandler     (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void RTCAlarm_IRQHandler      (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));
void USBWakeup_IRQHandler     (void) __attribute__ ((weak, noreturn, alias("Default_Handler")));


/*----------------------------------------------------------------------------
  Exception / Interrupt Vector table
 *----------------------------------------------------------------------------*/

#if defined ( __GNUC__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif

#define  __VTABLE_SIZE 76

extern const VECTOR_TABLE_Type __VECTOR_TABLE[__VTABLE_SIZE];
       const VECTOR_TABLE_Type __VECTOR_TABLE[__VTABLE_SIZE] __VECTOR_TABLE_ATTRIBUTE = {
  (VECTOR_TABLE_Type)(&__INITIAL_SP),  /*     Initial Stack Pointer */
  Reset_Handler,                       /*     Reset Handler */
  NMI_Handler,                         /* -14 NMI Handler */
  HardFault_Handler,                   /* -13 Hard Fault Handler */
  MemManage_Handler,                   /* -12 MPU Fault Handler */
  BusFault_Handler,                    /* -11 Bus Fault Handler */
  UsageFault_Handler,                  /* -10 Usage Fault Handler */
  SecureFault_Handler,                 /*  -9 Secure Fault Handler */
  0,                                   /*     Reserved */
  0,                                   /*     Reserved */
  0,                                   /*     Reserved */
  SVC_Handler,                         /*  -5 SVCall Handler */
  DebugMon_Handler,                    /*  -4 Debug Monitor Handler */
  0,                                   /*     Reserved */
  PendSV_Handler,                      /*  -2 PendSV Handler */
  SysTick_Handler,                     /*  -1 SysTick Handler */

  WWDG_IRQHandler,                      /* Window watchdog interrupt Handler */
  PVD_IRQHandler,                       /* PVD through EXTI Line detection interrupt Handler */
  TAMPER_IRQHandler,                    /* Tamper interrupt Handler */
  RTC_IRQHandler,                       /* RTC global interrupt Handler */
  FLASH_IRQHandler,                     /* Flash global interrupt Handler */
  RCC_IRQHandler,                       /* RCC global interrupt Handler */
  EXTI0_IRQHandler,                     /* EXTI Line0 interrupt Handler */
  EXTI1_IRQHandler,                     /* EXTI Line1 interrupt Handler */
  EXTI2_IRQHandler,                     /* EXTI Line2 interrupt Handler */
  EXTI3_IRQHandler,                     /* EXTI Line3 interrupt Handler */
  EXTI4_IRQHandler,                     /* EXTI Line4 interrupt Handler */
  DMA1_Channel1_IRQHandler,             /* DMA1 Channel1 global interrupt Handler */
  DMA1_Channel2_IRQHandler,             /* DMA1 Channel2 global interrupt Handler */
  DMA1_Channel3_IRQHandler,             /* DMA1 Channel3 global interrupt Handler */
  DMA1_Channel4_IRQHandler,             /* DMA1 Channel4 global interrupt Handler */
  DMA1_Channel5_IRQHandler,             /* DMA1 Channel5 global interrupt Handler */
  DMA1_Channel6_IRQHandler,             /* DMA1 Channel6 global interrupt Handler */
  DMA1_Channel7_IRQHandler,             /* DMA1 Channel7 global interrupt Handler */
  ADC1_2_IRQHandler,                    /* ADC1 and ADC2 global interrupt Handler */
  USB_HP_CAN_TX_IRQHandler,             /* USB High Priority or CAN TX interrupts Handler */
  USB_LP_CAN_RX0_IRQHandler,            /* USB Low Priority or CAN RX0 interrupts Handler */
  CAN_RX1_IRQHandler,                   /* CAN RX1 interrupt Handler */
  CAN_SCE_IRQHandler,                   /* CAN SCE interrupt Handler */
  EXTI9_5_IRQHandler,                   /* EXTI Line[9:5] interrupts Handler */
  TIM1_BRK_IRQHandler,                  /* TIM1 Break interrupt Handler */
  TIM1_UP_IRQHandler,                   /* TIM1 Update interrupt Handler */
  TIM1_TRG_COM_IRQHandler,              /* TIM1 Trigger and Commutation interrupts Handler */
  TIM1_CC_IRQHandler,                   /* TIM1 Capture Compare interrupt Handler */
  TIM2_IRQHandler,                      /* TIM2 global interrupt Handler */
  TIM3_IRQHandler,                      /* TIM3 global interrupt Handler */
  TIM4_IRQHandler,                      /* TIM4 global interrupt Handler */
  I2C1_EV_IRQHandler,                   /* I2C1 event interrupt Handler */
  I2C1_ER_IRQHandler,                   /* I2C1 error interrupt Handler */
  I2C2_EV_IRQHandler,                   /* I2C2 event interrupt Handler */
  I2C2_ER_IRQHandler,                   /* I2C2 error interrupt Handler */
  SPI1_IRQHandler,                      /* SPI1 global interrupt Handler */
  SPI2_IRQHandler,                      /* SPI2 global interrupt Handler */
  USART1_IRQHandler,                    /* USART1 global interrupt Handler */
  USART2_IRQHandler,                    /* USART2 global interrupt Handler */
  USART3_IRQHandler,                    /* USART3 global interrupt Handler */
  EXTI15_10_IRQHandler,                 /* EXTI Line[15:10] interrupts Handler */
  RTCAlarm_IRQHandler,                  /* RTC alarm through EXTI line interrupt Handler */
  USBWakeup_IRQHandler,                 /* USB wakeup from suspend through EXTI line interrupt Handler */
  0,                                    /*     Reserved */
  0,                                    /*     Reserved */
  0,                                    /*     Reserved */
  0,                                    /*     Reserved */
  0,                                    /*     Reserved */
  0,                                    /*     Reserved */
  0,                                    /*     Reserved */
  0,                                    /*     Reserved */
  0,                                    /*     Reserved */
  0,                                    /*     Reserved */
  0,                                    /*     Reserved */
  0,                                    /*     Reserved */
  0,                                    /*     Reserved */
  0,                                    /*     Reserved */
  0,                                    /*     Reserved */
  0,                                    /*     Reserved */
  0,                                    /*     Reserved */
};

#if defined ( __GNUC__ )
#pragma GCC diagnostic pop
#endif

/*---------------------------------------------------------------------------
  Reset Handler called on controller reset
 *---------------------------------------------------------------------------*/
__NO_RETURN void Reset_Handler(void)
{
  __set_PSP((uint32_t)(&__INITIAL_SP));

  SystemInit();                    /* CMSIS System Initialization */
  __PROGRAM_START();               /* Enter PreMain (C library entry point) */
}


#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wmissing-noreturn"
#endif

/*---------------------------------------------------------------------------
  Hard Fault Handler
 *---------------------------------------------------------------------------*/
void HardFault_Handler(void)
{
  while(1);
}

/*---------------------------------------------------------------------------
  Default Handler for Exceptions / Interrupts
 *---------------------------------------------------------------------------*/
void Default_Handler(void)
{
  while(1);
}

#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic pop
#endif
