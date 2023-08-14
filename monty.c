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

    char line[100];
    int line_number = 1;

    while (fgets(line, sizeof(line), file) != NULL) {
        // Trim leading and trailing spaces from the line
        char *trimmed_line = line;
        while (*trimmed_line == ' ')
            trimmed_line++;
        char *end = trimmed_line + strlen(trimmed_line) - 1;
        while (*end == ' ' || *end == '\n')
            *end-- = '\0';

        // Skip empty lines
        if (*trimmed_line == '\0') {
            line_number++;
            continue;
        }

        char opcode[100];
        char value_str[100];
        if (sscanf(trimmed_line, "%s %s", opcode, value_str) == 1) {
            // Handle opcode without value
            if (strcmp(opcode, "pall") == 0) {
                pall();
            } else {
                fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
                fclose(file);
                exit(EXIT_FAILURE);
            }
        } else if (strcmp(opcode, "push") == 0) {
            push(value_str, line_number);
        } else {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            fclose(file);
            exit(EXIT_FAILURE);
        }

        line_number++; // Increment line_number after each line
    }

    fclose(file);
    return (0);
}

