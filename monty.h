
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_MAX_SIZE 3000
/* Data structure for the stack */
typedef struct StackNode {
    int data;
    struct StackNode *next;
} StackNode;

extern size_t stack_size;
extern int data_stack[STACK_MAX_SIZE];
/* Global variable for the stack */
extern StackNode *stack;

void push(char *value_str, int line_number);
/* Function prototypes */
void push(int value);
void pall(void);
void pint(int line_number);

#endif /* MONTY_H */
