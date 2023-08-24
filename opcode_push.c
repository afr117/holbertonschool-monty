#include "monty.h"
#include <ctype.h>

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

    /* Check for extra spaces before/after the value string */
    char *trimmed_value_str = value_str;

    while (*trimmed_value_str == '\t')
        trimmed_value_str++;
    if (*trimmed_value_str == '\0') {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; trimmed_value_str[i]; i++) {
        if (!isdigit(trimmed_value_str[i]) &&
            trimmed_value_str[i] != '-' &&
            trimmed_value_str[i] != '+') {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }
    }
    value = atoi(trimmed_value_str);

    if (stack_size >= STACK_MAX_SIZE) {
        fprintf(stderr, "Error: Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    data_stack[stack_size] = value;
    stack_size++;

    pint(line_number);
}

/**
 * pint - Prints the value at the top of the stack
 * @line_number: Line number of the pint instruction in the file
 */
void pint(int line_number) {
    if (stack_size > 0) {
        printf("%d\n", data_stack[stack_size - 1]);
    } else {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
      fflush(stdout);
}

/**
 * pall - Prints all elements in the stack
 */
void pall(void) {
    for (size_t i = stack_size; i > 0; i--) {
        printf("%d\n", data_stack[i - 1]);
    }
}

