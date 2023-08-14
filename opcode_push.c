#include "monty.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void push(char *value_str, int line_number) {
    int value;

    char trimmed_value_str[100]; // Make sure the size is appropriate

    // Trim leading and trailing spaces from value_str
    size_t start = 0;
    while (isspace(value_str[start])) {
        start++;
    }

    size_t end = strlen(value_str);
    while (end > 0 && isspace(value_str[end - 1])) {
        end--;
    }

    strncpy(trimmed_value_str, value_str + start, end - start);
    trimmed_value_str[end - start] = '\0';

    if (trimmed_value_str[0] == '\0') {
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
