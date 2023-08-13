#include "monty.h"

void push(char *value_str) {
    if (stack_size >= STACK_MAX_SIZE) {
        fprintf(stderr, "Error: Stack overflow\n");
        exit(EXIT_FAILURE);
    }

    int value;
    if (isdigit(value_str[0]) || (value_str[0] == '-' && isdigit(value_str[1]))) {
        value = atoi(value_str);
        data_stack[stack_size] = value;
        stack_size++;
    } else {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        fclose(file);
        exit(EXIT_FAILURE);
    }
}

