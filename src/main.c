#include <stdlib.h>
#include <stdbool.h>
#include <stm32f103xx.h>

#include <stdio.h>

int main(void) {
    printf("I`m was born\n");
    printf("SystemCoreClock: %lu\n", SystemCoreClock);

    SysTick_Config(SystemCoreClock/100);

    return EXIT_SUCCESS;
}

void SysTick_Handler(void) {
    printf("SysTick_Handler\n");
}