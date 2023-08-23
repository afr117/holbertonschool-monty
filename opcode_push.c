#include "monty.h"
#include <ctype.h>


void push(char *value_str, int line_number) {
    int value;

    if (!value_str) {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    // Check for extra spaces before/after the value string
    char *trimmed_value_str = value_str;
    while (*trimmed_value_str == ' ')
        trimmed_value_str++;

    if (*trimmed_value_str == '\0') {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; trimmed_value_str[i]; i++) {
        if (!isdigit(trimmed_value_str[i]) && trimmed_value_str[i] != '-' && trimmed_value_str[i] != '+') {
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
}

void pall(void) {
    for (size_t i = stack_size; i > 0; i--) {
        printf("%d\n", data_stack[i - 1]);
    }
}

