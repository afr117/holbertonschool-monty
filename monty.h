#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct StackNode - singly linked list representation of a stack
 * @n: integer
 * @next: points to the next node
 *
 * Description: stack node structure
 */
typedef struct StackNode {
    int n;
    struct StackNode *next;
} StackNode;

/**
 * struct Monty - struct to hold Monty interpreter data
 * @stack: pointer to the top of the stack
 */
typedef struct {
    StackNode *stack;
} Monty;

/* Function prototypes */
void push(Monty *monty, int value);
void pall(const Monty *monty);

#endif /* MONTY_H */
