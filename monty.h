// monty.h

#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>

#define TOKEN_DELIMITERS " \t\n\r"
#define STACK_MAX_SIZE 1024

/* Data structure for a stack node */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/* Monty opcode functions */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);

/* Utility functions */
int is_numeric(const char *str);

#endif /* MONTY_H */

