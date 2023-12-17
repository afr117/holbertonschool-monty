#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>

#define STACK_MAX_SIZE 1024
#define TOKEN_DELIMITERS " \t\n"

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: Integer value stored in the node
 * @prev: Pointer to the previous element of the stack
 * @next: Pointer to the next element of the stack
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
int is_numeric(const char *str);

#endif /* MONTY_H */

