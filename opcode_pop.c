#include "monty.h"

StackNode *stack = NULL;

void pop(int line_number) {
    if (stack == NULL) {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    StackNode *temp = stack;
    stack = stack->next;
    free(temp);
    stack_size--;
}

