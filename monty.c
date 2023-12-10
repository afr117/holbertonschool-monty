#include "monty.h"

/**
 * push - pushes an element onto the stack
 * @monty: pointer to the Monty interpreter
 * @value: integer value to push onto the stack
 */
void push(Monty *monty, int value)
{
    StackNode *new_node = malloc(sizeof(StackNode));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->next = monty->stack;
    monty->stack = new_node;
}

/**
 * pall - prints all values on the stack
 * @monty: pointer to the Monty interpreter
 */
void pall(const Monty *monty)
{
    StackNode *current = monty->stack;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
