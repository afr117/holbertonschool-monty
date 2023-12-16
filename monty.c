#include "monty.h"
#include <string.h>

int data_stack[STACK_MAX_SIZE];
stack_t *stack;

/**
 * init_stack - Initialize the data stack.
 */
void init_stack(void)
{
    stack = NULL;
}

/**
 * process_line - Process a line of Monty bytecode.
 * @line: The line to process.
 */
void process_line(char *line)
{
    char *opcode;
    unsigned int line_number = 0;

    opcode = strtok(line, TOKEN_DELIMITERS);
    if (!opcode || opcode[0] == '#')
        return;

    if (strcmp(opcode, "push") == 0)
    {
        push(&stack, line_number);
    }
    else if (strcmp(opcode, "pall") == 0)
    {
        pall(&stack, line_number);
    }
    // Add more opcode handling as needed
}

