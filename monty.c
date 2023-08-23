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

    while (fgets(line, sizeof(line), file)) {
        char opcode[100];
        char value_str[100]; // New variable to store the value
        int num_args = sscanf(line, " %s %s", opcode, value_str); // Read both opcode and value

        if (num_args >= 1) {
            if (strcmp(opcode, "push") == 0) {
                // Check if value_str is not empty
                if (num_args == 2 && strlen(value_str) > 0) {
                    push(value_str, line_number);
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
        line_number++; // Increment line_number after each line
    }

    fclose(file);
    return (0);
}

