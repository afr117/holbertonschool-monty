#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    stack_t *stack = NULL;
    unsigned int line_number = 0;
    char *opcode;
    int value;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (getline(&line, &len, file) != -1)
    {
        line_number++;

        /* Tokenize the line */
        opcode = strtok(line, " \t\n");

        if (opcode && strcmp(opcode, "push") == 0)
        {
            /* Execute push opcode */
            value = atoi(strtok(NULL, " \t\n"));

            if (value || (strcmp("0", strtok(NULL, " \t\n")) == 0))
                push(&stack, value);
            else
            {
                fprintf(stderr, "L%u: usage: push integer\n", line_number);
                free_stack(stack);
                fclose(file);
                free(line);
                exit(EXIT_FAILURE);
            }
        }
        else if (opcode && strcmp(opcode, "pall") == 0)
        {
            /* Execute pall opcode */
            pall(&stack, line_number);
        }
        else
        {
            fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
            free_stack(stack);
            fclose(file);
            free(line);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
    free(line);
    free_stack(stack);

    return EXIT_SUCCESS;
}

