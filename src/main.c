#include <stdlib.h>

#ifdef Debug
#include <stdio.h>
#endif //Debug

int main(void) {
#ifdef Debug
    printf("I`m was born\n");
#endif //Debug

    return EXIT_SUCCESS;
}