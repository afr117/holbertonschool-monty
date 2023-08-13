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
    for (size_t i = 0; i < stack_size; i++) {
        printf("%d\n", data_stack[i]);
    }
}

