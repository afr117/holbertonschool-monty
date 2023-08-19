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

    char line[1000];  // Adjust the size as needed
    int line_number = 1;

    while (fgets(line, sizeof(line), file)) {
        char opcode[100];
        int value;
        
        if (sscanf(line, "%99s %d", opcode, &value) == 2) {
            if (strcmp(opcode, "push") == 0) {
                char *rest_of_line = strchr(line, ' ') + 1;
                push(rest_of_line, line_number);
            }
        } else if (strcmp(opcode, "pall") == 0) {
            pall();
        } else {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
            fclose(file);
            exit(EXIT_FAILURE);
        }
        
        line_number++;
    }

    fclose(file);
    return (0);
}

