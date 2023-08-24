#include "monty.h"
#include <string.h>
#include <ctype.h>

size_t stack_size = 0;
int data_stack[STACK_MAX_SIZE] = { -1 } ;

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
        char *token = strtok(line, " \t\n"); // Tokenize the line

        while (token != NULL) {
            char opcode[100];
            char arg[100];
            strcpy(opcode, token);

            token = strtok(NULL, " \t\n"); // Get the next token
            if (token != NULL) {
                strcpy(arg, token);
            } else {
                arg[0] = '\0';
            }

            if (strcmp(opcode, "push") == 0) {
                if (strlen(arg) > 0) {
                    push(arg, line_number);
                } else {
                    fprintf(stderr, "L%d: usage: push integer\n", line_number);
                    fclose(file);
                    exit(EXIT_FAILURE);
                }
            } else if (strcmp(opcode, "pint") == 0) {
                pint(line_number);
            } else if (strcmp(opcode, "pall") == 0) {
                pall();
            } else {
                fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
                fclose(file);
                exit(EXIT_FAILURE);
            }

            token = strtok(NULL, " \t\n"); // Get the next token
        }

        line_number++;
    }

    fclose(file);
    return 0;
}
