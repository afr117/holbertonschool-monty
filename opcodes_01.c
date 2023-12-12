#include "monty.h"
#include <string.h>                                                    
#include <ctype.h>

/**
 * push - Push an element to the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the Monty bytecode file.
 */
void push(stack_t **stack, unsigned int line_number)
{
    char *arg = strtok(NULL, TOKEN_DELIMITERS);  /* Assuming TOKEN_DELIMITERS is defined in your shell.h */

    if (!arg || !is_numeric(arg))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    int value = atoi(arg);

    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack)
        (*stack)->prev = new_node;

    *stack = new_node;
}

/**
 * pall - Print all the values on the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the Monty bytecode file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void)line_number;  /* Unused parameter */

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

int is_numeric(const char *str)
{
    if (!str)
        return 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]) && str[i] != '-')
            return 0;
    }

    return 1;
}
