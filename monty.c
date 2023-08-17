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

    char line[100]; // Buffer to hold each line from the file
    int line_number = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        line_number++;
        
        // Remove leading and trailing whitespace from the line
        char *trimmed_line = line;
        while (*trimmed_line == ' ' || *trimmed_line == '\t')
            trimmed_line++;

        // Skip empty lines
        if (*trimmed_line == '\0' || *trimmed_line == '\n')
            continue;

        // Parse the opcode and value from the trimmed line
        char opcode[100];
        char value_str[100];
        if (sscanf(trimmed_line, "%s %s", opcode, value_str) >= 1) {
            if (strcmp(opcode, "push") == 0) {
                if (*value_str != '\0' && isdigit(*value_str)) {
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
        } else {
            fprintf(stderr, "L%d: invalid instruction format\n", line_number);
            fclose(file);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
    return (0);
}
