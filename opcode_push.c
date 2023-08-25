#include "monty.h"



void push(char *value_str, int line_number) {
    int value;

    if (!value_str) {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; value_str[i]; i++) {
        if (!isdigit(value_str[i]) && value_str[i] != '-' && value_str[i] != '+') {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }
    }

    value = atoi(value_str);

    StackNode *new_node = malloc(sizeof(StackNode));
    if (!new_node) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = value;
    new_node->next = stack;
    stack = new_node;

    stack_size++;
}

