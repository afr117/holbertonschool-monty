#include "monty.h"

void push(int value) {
    if (stack_size >= STACK_MAX_SIZE) {
        fprintf(stderr, "Error: Stack overflow\n");
        exit(EXIT_FAILURE);
    }

    data_stack[stack_size] = value;
    stack_size++;
}

void pall(void) {
    for (int i = stack_size - 1; i >= 0; i--) {
        printf("%d\n", data_stack[i]);
    }
}

/* Other opcode functions here */

