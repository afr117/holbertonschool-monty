#include "monty.h"

StackNode *stack = NULL;

void pint(int line_number) {
    if (stack == NULL) {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", stack->data);
}

