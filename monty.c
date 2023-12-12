#include "monty.h"
#include <string.h>

int main(int argc, char *argv[])
{
    /* Check if the correct number of arguments is provided */
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    /* Open and read the Monty bytecode file */
    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);       
        exit(EXIT_FAILURE);
    }

    /* Read and process each line from the file */
    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;
    while (getline(&line, &len, file) != -1)
    {
        line_number++;

        /* Remove trailing newline or carriage return characters */    
        size_t length = strlen(line);
        if (line[length - 1] == '\n' || line[length - 1] == '\r')      
        {
            line[length - 1] = '\0';
        }

        /* Parse and execute the opcode */
        /* You need to implement this part */
    }

    /* Free allocated memory and close the file */
    free(line);
    fclose(file);

    /* Free the stack */
    /* You need to implement this part */

    return 0;
}

