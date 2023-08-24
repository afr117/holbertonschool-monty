#include "monty.h"

size_t stack_size = 0;
int data_stack[STACK_MAX_SIZE] = { -1 };
StackNode *stack = NULL;

void execute_instruction(FILE *file, int line_number, char *opcode, char *arg);

void push_or_exit(FILE *file, int line_number, char *arg, int num_args) {
    if (num_args == 2) {
        push(arg, line_number);
    } else {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        fclose(file);
        exit(EXIT_FAILURE);
    }
}

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
        char arg[100];
        int num_args = sscanf(line, " %s %s", opcode, arg);

        if (num_args >= 1) {
            execute_instruction(file, line_number, opcode, arg);
        }

        line_number++;
    }

    fclose(file);
    return 0;
}

void execute_instruction(FILE *file, int line_number, char *opcode, char *arg) {
    if (strcmp(opcode, "push") == 0) {
        push_or_exit(file, line_number, arg, num_args);
    } else if (strcmp(opcode, "pall") == 0) {
        pall();
    } else {
        fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
        fclose(file);
        exit(EXIT_FAILURE);
    }
}

