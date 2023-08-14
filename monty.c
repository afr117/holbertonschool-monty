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

        // Rest of your code for opcode parsing

        line_number++; // Increment line_number after each line
    }

    fclose(file);
    return (0);
}

