#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

size_t stack_size = 0;
int data_stack[STACK_MAX_SIZE];
StackNode *stack;

void init_stack(void) {
    stack = NULL;
}

void process_line(char *line) {
    char *opcode;
    char *value_str;
    int line_number = 0;

    // Remove trailing newline character
    size_t len = strlen(line);
    if (len > 0 && line[len - 1] == '\n') {
        line[len - 1] = '\0';
    }

    // Parse the opcode and value_str from the line
    opcode = strtok(line, " ");
    if (opcode == NULL) {
        return;  // Ignore empty lines
    }

    value_str = strtok(NULL, " ");
    line_number++;  // Increment line number for error reporting

    // Call the corresponding function based on the opcode
    if (strcmp(opcode, "push") == 0) {
        push(value_str, line_number);
    } else if (strcmp(opcode, "pall") == 0) {
        pall();
    }
}

int main(int argc, char *argv[]) {
    init_stack();

    if (argc != 2) {
        fprintf(stderr, "Usage: monty file\n");
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file)) != -1) {
        process_line(line);
    }

    free(line);
    fclose(file);

    return EXIT_SUCCESS;
}

