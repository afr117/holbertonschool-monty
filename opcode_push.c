#include "monty.h"

/**
 * push - Pushes an element onto the stack
 * @value_str: String representation of the value to be pushed
 * @line_number: Line number of the push instruction in the file
 */
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

    if (stack_size >= STACK_MAX_SIZE) {
        fprintf(stderr, "Error: Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    data_stack[stack_size] = value;
    stack_size++;
}

/**
 * pall - Prints all elements in the stack
 */
void pall(void) {
    for (size_t i = stack_size; i > 0; i--) {
        printf("%d\n", data_stack[i - 1]);
    }
}

