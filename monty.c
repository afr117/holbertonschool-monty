#include "monty.h"

/**
 * main - Entry point for Monty interpreter.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * This function reads and interprets Monty bytecode from file.
 * Parses Monty instructions and executes accordingly.
 *
 * Return: 0 on success, EXIT_FAILURE on failure.
 */

size_t stack_size = 0;
int data_stack[STACK_MAX_SIZE] = { -1 };

StackNode *stack = NULL;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");

    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char line[100];
    int line_number = 1;

    while (fgets(line, sizeof(line), file))
    {
        char opcode[100];
        char arg[100];
        int num_args = sscanf(line, " %s %s", opcode, arg);

        if (num_args >= 1)
        {
            if (strcmp(opcode, "push") == 0)
            {
                if (num_args == 2)
                {
                    push(arg, line_number);
                }
                else
                {
                    fprintf(stderr, "L%d: usage: push integer\n", line_number);
                    fclose(file);
                    exit(EXIT_FAILURE);
                }
            }
            else if (strcmp(opcode, "pint") == 0)
            {
                pint(line_number); // Call the pint function
            }
            else if (strcmp(opcode, "pall") == 0)
            {
                pall();
            }
            else
            {
                fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
                fclose(file);
                exit(EXIT_FAILURE);
            }
        }

        line_number++;
    }

    fclose(file);
    return 0;
}

void pint(int line_number)
{
    if (stack_size > 0)
    {
        printf("%d\n", data_stack[stack_size - 1]);
    }
    else
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
}
void pop(int line_number)
{
    if (stack_size > 0)
    {
        stack_size--;
    }
    else
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }
}

/**
 * pop - Removes the top element of the stack
 * @line_number: Line number of the pop instruction in the file
 */
void pop(int line_number)
{
    if (stack_size > 0)
    {
        stack_size--;
        data_stack[stack_size] = 0; // Clear the element at the top of the stack
    }
    else
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }
}
