#include "monty.h"
#include <string.h>
#include <ctype.h>

size_t stack_size = 0;
int data_stack[STACK_MAX_SIZE];

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "USAGE: %s file\n", argv[0]);
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
            int value;
            if (fscanf(file, "%d", &value) == 1) {
                push(value);
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
        line_number++; // Increment line_number after each line
    }

    fclose(file);
    return (0);
}

