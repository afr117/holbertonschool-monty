#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_MAX_SIZE 1026

extern size_t stack_size;
extern int data_stack[STACK_MAX_SIZE];

void push(char *value_str, int line_number);
void pall(void);

#endif /* MONTY_H */
