// monty.c
#include "monty.h"
#include <string.h>
#include <ctype.h>

#define TOKEN_DELIMITERS " \t\n"

stack_t *stack;

/**
 * init_stack - Initialize the data stack.
 */
void init_stack(void)
{
    stack = NULL;
}

/**
 * is_numeric - Check if a string represents a numeric value.
 * @str: The string to check.
 * Return: 1 if numeric, 0 otherwise.
 */
int is_numeric(const char *str)
{
    if (!str || *str == '\0' || (*str == '-' && *(str + 1) == '\0'))
        return 0;

    while (*str)
    {
        if (!isdigit(*str) && *str != '-')
            return 0;
        str++;
    }

    return 1;
}

/**
 * process_line - Process a line of Monty bytecode.
 * @line: The line to process.
 */
void process_line(char *line)
{
    char *opcode, *value_str;
    unsigned int line_number = 0;

    opcode = strtok(line, TOKEN_DELIMITERS);
    if (!opcode || opcode[0] == '#')
        return;

    printf("Debug: Processing opcode '%s'\n", opcode);

    if (strcmp(opcode, "push") == 0)
    {
        line_number++;
        value_str = strtok(NULL, TOKEN_DELIMITERS);
        if (!value_str || !is_numeric(value_str))
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }

        printf("Debug: Pushing value %s to stack\n", value_str);
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
    unsigned int line_number = 0;

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

