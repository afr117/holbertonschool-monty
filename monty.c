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
        char value_str[100];
        if (opcode[0] == '\n' || opcode[0] == ' ') {
            line_number++;
            continue;
        }
        
        if (sscanf(opcode, "push %s", value_str) == 1) {
            push(value_str, line_number);
        } else if (strcmp(opcode, "pall\n") == 0) {
            pall();
        } else {
            fprintf(stderr, "L%d: unknown instruction %s", line_number, opcode);
            fclose(file);
            exit(EXIT_FAILURE);
        }
        
        line_number++;
    }

    fclose(file);
    return (0);
}

