#include "monty.h"
#include <stdio.h>

size_t stack_size = 0;


int main(int argc, char *argv[])
{
	init_stack();

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

    // Initialize your stack and any other necessary variables here
    init_stack();

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file)) != -1)
    {
        // Process the line, parse opcodes, and execute corresponding functions
        process_line(line);
    }

    // Free any allocated memory and close the file
    free(line);
    fclose(file);

    return EXIT_SUCCESS;
}

