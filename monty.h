#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_MAX_SIZE 1024

typedef struct StackNode
{
    int n;
    struct StackNode *next;
} StackNode;

typedef struct opcode_s
{
    char *opcode;
    void (*f)(StackNode **stack, unsigned int line_number); // Change the function signature
} opcode_t;

void push(StackNode **stack, unsigned int line_number);
void pall(StackNode **stack, unsigned int line_number);
void pint(StackNode **stack, unsigned int line_number);
void pop(StackNode **stack, unsigned int line_number);
void swap(StackNode **stack, unsigned int line_number);

extern size_t stack_size;
extern int data_stack[STACK_MAX_SIZE];
extern StackNode *stack;

#endif /* MONTY_H */
