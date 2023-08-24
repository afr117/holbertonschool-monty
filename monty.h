#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

/* Data structure for the stack */
typedef struct StackNode {
    int data;
    struct StackNode *next;
} StackNode;

/* Global variable for the stack */
extern StackNode *stack;

/* Function prototypes */
void push(int value);
void pall(void);

#endif /* MONTY_H */

