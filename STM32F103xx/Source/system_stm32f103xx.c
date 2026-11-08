/*************************************************************************//**
 * @file     system_stm32f103xx.c
 * @brief    CMSIS-Core(M) Device Peripheral Access Layer Source File for
 *           Device STM32F103xx
 * @version  V1.0.0
 * @date     20. January 2021
 *****************************************************************************/
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


#include <stdint.h>
#include "stm32f103xx.h"

/*---------------------------------------------------------------------------
  Define clocks
 *---------------------------------------------------------------------------*/
#ifndef __HSE_VALUE
#warning __HSE_VALUE not defined
#else
#define HSE_VALUE __HSE_VALUE
#endif //__HSE_VALUE

#ifndef __LSE_VALUE
#waring __LSE_VALUE not defined
#else
#define LSE_VALUE __LSE_VALUE
#endif //__LSE_VALUE

#define LSI_VALUE 40000
#define HSI_VALUE 8000000

#ifndef __HSE_VALUE
#define SYSTEM_CLOCK    HSI_VALUE
#else 
#if HSE_VALUE == 8000000
#define SYSTEM_CLOCK   72000000
#else
#error Set your-self SYSTEM_CLOCK value
#endif 
#endif //__HSE_VALUE


/*---------------------------------------------------------------------------
  Exception / Interrupt Vector table
 *---------------------------------------------------------------------------*/
extern const VECTOR_TABLE_Type __VECTOR_TABLE[496];


/*---------------------------------------------------------------------------
  System Core Clock Variable
 *---------------------------------------------------------------------------*/
/* ToDo: Initialize SystemCoreClock with the system core clock frequency value
         achieved after system intitialization.
         This means system core clock frequency after call to SystemInit() */
uint32_t SystemCoreClock = SYSTEM_CLOCK;  /* System Clock Frequency (Core Clock)*/


/*---------------------------------------------------------------------------
  System Core Clock function
 *---------------------------------------------------------------------------*/
void SystemCoreClockUpdate (void)
{
/* ToDo: Add code to calculate the system frequency based upon the current
         register settings.
         This function can be used to retrieve the system core clock frequeny
         after user changed register sittings. */
  SystemCoreClock = SYSTEM_CLOCK;
}


/*---------------------------------------------------------------------------
  System initialization function
 *---------------------------------------------------------------------------*/
void SystemInit (void)
{
/* ToDo: Add code to initialize the system.
         Do not use global variables because this function is called before
         reaching pre-main. RW section maybe overwritten afterwards. */

/* ToDo: Initialize VTOR if available */
#if defined (__VTOR_PRESENT) && (__VTOR_PRESENT == 1U)
  SCB->VTOR = (uint32_t)(&__VECTOR_TABLE[0]);
#endif

  SystemCoreClock = SYSTEM_CLOCK;
}
