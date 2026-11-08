#include <stdlib.h>
#include <stdbool.h>
#include <stm32f103xx.h>

#ifdef Debug
#include <stdio.h>
#endif //Debug

int main(void) {
#ifdef Debug
    printf("I`m was born\n");
    printf("SystemCoreClock: %lu\n", SystemCoreClock);
#endif //Debug

    SysTick_Config(SystemCoreClock/100);

    return EXIT_SUCCESS;
}

void SysTick_Handler(void) {
#ifdef Debug
    printf("SysTick_Handler\n");
#endif
}