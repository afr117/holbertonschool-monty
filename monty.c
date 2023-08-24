#include "monty.h"

/**
 * main - Entry point for the Monty interpreter.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * This function reads and interprets Monty bytecode from a file.
 * It parses Monty instructions and executes them accordingly.
 *
 * Return: 0 on success, EXIT_FAILURE on failure.
 */

size_t stack_size = 0;
int data_stack[STACK_MAX_SIZE] = { -1 };
StackNode *stack = NULL; // You need to initialize stack to NULL

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char line[100];
    int line_number = 1;

    while (fgets(line, sizeof(line), file)) {
        char opcode[100];
        char arg[100];
        int num_args = sscanf(line, " %s %s", opcode, arg);

        if (num_args >= 1) {
            if (strcmp(opcode, "push") == 0) {
                if (num_args == 2) {
                    push(arg, line_number);
                } else {
                    fprintf(stderr, "L%d: usage: push integer\n", line_number);
                    fclose(file);
                    exit(EXIT_FAILURE);
                }
            } else if (strcmp(opcode, "pall") == 0) {
                pall();
            } else {
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

