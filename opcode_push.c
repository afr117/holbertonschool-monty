#include "monty.h"

int data_stack[STACK_MAX_SIZE];


/**
 * push - Pushes an element onto the stack
 * @value_str: String representation of the value to be pushed
 * @line_number: Line number of the push instruction in the file
 */
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

