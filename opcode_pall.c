#include "monty.h"

/**
 * pall - Prints all values on the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty byte code file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
    (void)line_number; /* Unused parameter */

    while (*stack)
    {
        printf("%d\n", (*stack)->n);
        *stack = (*stack)->next;
    }
}

