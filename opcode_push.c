#include "monty.h"

void pall(void) {
    // Implementation of the pall function
}

void push(int value) {
    if (stack_size >= STACK_MAX_SIZE) {
        fprintf(stderr, "Error: Stack overflow\n");
        exit(EXIT_FAILURE);
    }

    data_stack[stack_size] = value;
    stack_size++;
}

/* Other opcode functions here */

