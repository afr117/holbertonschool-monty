#include "monty.h"

void push(char *value_str, int line_number)
{
    int value;
    char *endptr;

    if (!value_str)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    value = strtol(value_str, &endptr, 10);

    if (*endptr != '\0' && !isspace(*endptr))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    if (stack_size >= STACK_MAX_SIZE)
    {
        fprintf(stderr, "Error: Stack overflow\n");
        exit(EXIT_FAILURE);
    }

    data_stack[stack_size] = value;
    stack_size++;
}

