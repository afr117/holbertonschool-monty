#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>

#define STACK_MAX_SIZE 3000

extern size_t stack_size;

/* Data structure for the stack */
typedef struct StackNode {
    int data;
    struct StackNode *next;
} StackNode;

extern StackNode *stack;
extern int data_stack[STACK_MAX_SIZE];

void init_stack(void);
void process_line(char *line);
/* Function prototypes */
void push(char *value_str, int line_number);
void pint(int line_number); /* Prints the value at the top of the stack */
void pop(int line_number);
void pall(void);

#endif /* MONTY_H */
