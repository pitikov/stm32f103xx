#include <stdlib.h>
#include <stdbool.h>
#include <stm32f103xx.h>

#ifdef Debug
#include <stdio.h>
#endif //Debug

int main(void) {
#ifdef Debug
    printf("I`m was born\n");
#endif //Debug

    SysTick_Config(SystemCoreClock/100);

    while (true)
        __WFI();
    return EXIT_SUCCESS;
}

void SysTick_Handler(void) {
    printf("SysTick_Handler\n");
}