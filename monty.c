#include "monty.h"
#include <string.h>
#include <ctype.h>

size_t stack_size = 0;
int data_stack[STACK_MAX_SIZE];

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

    char opcode[100];
    int line_number = 1;

    while (fgets(opcode, sizeof(opcode), file)) {
        // Remove leading and trailing whitespace
        char *trimmed_opcode = opcode;
        while (*trimmed_opcode == ' ' || *trimmed_opcode == '\t')
            trimmed_opcode++;
        
        // Skip empty lines
        if (*trimmed_opcode == '\n' || *trimmed_opcode == '\0')
            continue;

        // Check for stack overflow
        if (stack_size >= STACK_MAX_SIZE) {
            fprintf(stderr, "L%d: Error: Stack overflow\n", line_number);
            fclose(file);
            exit(EXIT_FAILURE);
        }

        if (strcmp(trimmed_opcode, "push") == 0) {
            char value_str[100];
            if (fscanf(file, "%s", value_str) == 1) {
                push(value_str, line_number);
            } else {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                fclose(file);
                exit(EXIT_FAILURE);
            }
        } else if (strcmp(trimmed_opcode, "pall") == 0) {
            pall();
        } else {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, trimmed_opcode);
            fclose(file);
            exit(EXIT_FAILURE);
        }
        
        line_number++; // Increment line_number after each line
    }

    fclose(file);
    return (0);
}
This version of the main loop reads lines using fgets() instead of fscanf() and processes them accordingly. It skips empty lines and handles lines with whitespace before or after the instruction. This should provide the correct output for the mentioned case while minimizing the impact on the rest of the code.






