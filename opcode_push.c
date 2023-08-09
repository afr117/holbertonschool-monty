#include "monty.h"
#include <stdio.h>

void pall(void) {
    int i;

    for (i = stack_size - 1; i >= 0; i--) {
        printf("%d\n", data_stack[i]);
    }
}

