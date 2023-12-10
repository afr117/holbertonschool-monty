#include "monty.h"
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: monty file\n");
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    Monty monty;
    monty.stack = NULL;  // Initialize the stack

    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 1;

    while ((read = getline(&line, &len, file)) != -1)
    {
        // Process the line, parse opcodes, and execute corresponding functions
        // For simplicity, assume that each line only contains "push" or "pall"
        if (strncmp(line, "push", 4) == 0)
        {
            int value = atoi(line + 5);
            push(&monty, value);
        }
        else if (strncmp(line, "pall", 4) == 0)
        {
            pall(&monty);
        }
        else
        {
            fprintf(stderr, "L%d: unknown instruction\n", line_number);
            exit(EXIT_FAILURE);
        }

        line_number++;
    }

    free(line);
    fclose(file);

    return EXIT_SUCCESS;
}
