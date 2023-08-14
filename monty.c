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

    while (fscanf(file, "%s", opcode) != EOF) {
        if (strcmp(opcode, "push") == 0) {
            char value_str[100];
            if (fscanf(file, "%s", value_str) == 1) {
                push(value_str, line_number);
            } else {
                fprintf(stderr, "L%d: usage: push integer\n", line_number + 1);
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
        while (fgetc(file) != '\n'); // Read until end of line
        line_number++; // Increment line_number after each line
    }

    fclose(file);

    // Added instruction "3000 push"
    push("3000", line_number);

    // Added instruction "pall"
    pall();

    return (0);
}

