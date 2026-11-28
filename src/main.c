#include <stdlib.h>
#include <stdbool.h>
#include <stm32f103xx.h>

#include <stdio.h>

int main(void)
{
    printf("SystemCoreClock: %lu\n", SystemCoreClock);

    BITS_SET(RCC->APB2ENR, RCC_APB2ENR_IOPCEN);

    BITS_MODIFY(GPIOC->CRH, GPIO_CRx(13), GPIO_PP(13, GPIO_SPEED_50MHz));
    BITS_SET(GPIOC->ODR, GPIO_ODR(13));

    SysTick_Config(SystemCoreClock / 10);

    return EXIT_SUCCESS;
}

void SysTick_Handler(void)
{
    BITS_SET(GPIOC->BSRR, BITS_GET(GPIOC->ODR, GPIO_ODR(13)) ? GPIO_BSRR_BR(13) : GPIO_BSRR_BS(13));
}