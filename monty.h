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

/* Token delimiters */
#define TOKEN_DELIMITERS " \t\n"

/* Function prototype for is_numeric */
int is_numeric(const char *str);

/* Declaration for the stack variable */
extern stack_t *stack;

#endif /* MONTY_H */

