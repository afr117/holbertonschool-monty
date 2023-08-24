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

extern size_t stack_size;
extern int data_stack[STACK_MAX_SIZE];
extern StackNode *stack;

void push(char *value_str, int line_number);
void pint(int line_number);
void pop(int line_number);
void pall(void);

#endif /* MONTY_H */

