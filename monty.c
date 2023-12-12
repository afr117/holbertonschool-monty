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
    char *opcode, *value_str;
    unsigned int line_number;

    opcode = strtok(line, TOKEN_DELIMITERS);
    if (!opcode || opcode[0] == '#')
        return;

    if (strcmp(opcode, "push") == 0)
    {
        value_str = strtok(NULL, TOKEN_DELIMITERS);
        if (!value_str || !is_numeric(value_str))
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }

        push(&stack, atoi(value_str));
    }
    else if (strcmp(opcode, "pall") == 0)
    {
        pall(&stack, line_number);
    }
    // Add more opcode handling as needed
}

/**
 * main - Entry point of the Monty interpreter.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    FILE *file;
    unsigned int line_number = 0; // Initialize line_number

    if (argc != 2)
    {
        fprintf(stderr, "Usage: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    init_stack();

    while ((read = getline(&line, &len, file)) != -1)
    {
        line_number++;
        process_line(line);
    }

    fclose(file);
    free(line);
    exit(EXIT_SUCCESS);
}

