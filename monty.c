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
        char *trimmed_line = line;
        while (*trimmed_line == ' ' || *trimmed_line == '\t')
            trimmed_line++;

        if (*trimmed_line == '\n' || *trimmed_line == '\0')
            continue;

        // Remove newline character from the end of the line
        size_t len = strlen(trimmed_line);
        if (len > 0 && trimmed_line[len - 1] == '\n')
            trimmed_line[len - 1] = '\0';

        // Parse the opcode and arguments
        char *opcode = strtok(trimmed_line, " \t\n");
        if (opcode == NULL) {
            fprintf(stderr, "L%d: unknown instruction\n", line_number);
            fclose(file);
            exit(EXIT_FAILURE);
        }

        if (strcmp(opcode, "push") == 0) {
            char *value_str = strtok(NULL, " \t\n");
            if (value_str == NULL || !is_integer(value_str)) {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                fclose(file);
                exit(EXIT_FAILURE);
            }
            push(value_str, line_number);
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

// Function to check if a string represents a valid integer
bool is_integer(const char *str) {
    if (*str == '\0') {
        return false;
    }
    for (const char *p = str; *p != '\0'; p++) {
        if (!isdigit(*p) && (*p != '-' && p == str)) {
            return false;
        }
    }
    return true;
}

