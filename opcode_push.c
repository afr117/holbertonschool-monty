#include "monty.h"

/* Implementation of push opcode */
void push(int value) {
    StackNode *new_node = malloc(sizeof(StackNode));
    if (new_node == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = value;
    new_node->next = stack;
    stack = new_node;
}

/* Implementation of pall opcode */
void pall(void) {
    StackNode *current = stack;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

