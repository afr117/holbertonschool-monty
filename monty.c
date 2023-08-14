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

    while (fgets(opcode, sizeof(opcode), file) != NULL) {
        // Trim leading and trailing spaces from opcode
        char *trimmed_opcode = opcode;
        while (*trimmed_opcode == ' ')
            trimmed_opcode++;

        // Skip empty lines
        if (*trimmed_opcode == '\0' || *trimmed_opcode == '\n') {
            line_number++;
            continue;
        }

        // Find the first space or newline to separate opcode from value
        char *value_str = strchr(trimmed_opcode, ' ');
        if (value_str != NULL)
            *value_str++ = '\0'; // Separate opcode and value

        // Trim leading and trailing spaces from value_str
        if (value_str != NULL) {
            while (*value_str == ' ')
                value_str++;
            char *end = value_str + strlen(value_str) - 1;
            while (*end == ' ' || *end == '\n')
                *end-- = '\0';
        }

        if (strcmp(trimmed_opcode, "push") == 0) {
            if (value_str != NULL) {
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

