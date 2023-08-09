#include "monty.h"
#include <string.h>

// Define the stack_size and data_stack here
size_t stack_size = 0;
int data_stack[STACK_MAX_SIZE]; // Use the constant here

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Read lines from the file and process opcodes
    char opcode[100];
    int value;
    int line_number = 1; // Initialize line_number

    while (fscanf(file, "%s", opcode) != EOF) {
        if (strcmp(opcode, "push") == 0) {
            if (fscanf(file, "%d", &value) == 1) {
                push(value);
            } else {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }
        } else if (strcmp(opcode, "pall") == 0) {
            pall();
        } else {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }
        line_number++; // Increment line_number after each line
    }

    fclose(file);
    return (0);
}

/* Other function implementations here */

