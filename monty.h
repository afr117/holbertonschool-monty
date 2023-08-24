#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>


#define STACK_MAX_SIZE 3000

/* Data structure for the stack */
typedef struct StackNode {
    int data;
    struct StackNode *next;
} StackNode;

extern size_t stack_size;
extern int data_stack[STACK_MAX_SIZE];
extern StackNode *stack;

/* Function prototypes */
void push(char *value_str, int line_number);
void pint(int line_number);
void pall(void);

#endif /* MONTY_H */

