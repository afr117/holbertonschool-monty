#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX_SIZE 1024

extern int data_stack[STACK_MAX_SIZE];
extern size_t stack_size;

void push(int value);
void pall(void);

#endif /* MONTY_H */

