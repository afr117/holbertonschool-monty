// monty.h
#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

/* Structure for a stack node */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/* Structure for an instruction */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function prototypes */
void push(stack_t **stack, int value);
void pall(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);

/* Declare stack as an external variable */
extern stack_t *stack;

/* Check if a string is numeric */
int is_numeric(const char *str);

#endif /* MONTY_H */

