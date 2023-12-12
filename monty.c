#include "monty.h"
<<<<<<< HEAD
#include <string.h>

int main(int argc, char *argv[])
{
    /* Check if the correct number of arguments is provided */
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
=======
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
>>>>>>> 956a2aff36631009045e85e03ae2d1fcfbf26ddf
        exit(EXIT_FAILURE);
    }

    /* Open and read the Monty bytecode file */
    FILE *file = fopen(argv[1], "r");
<<<<<<< HEAD
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
=======
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

>>>>>>> 956a2aff36631009045e85e03ae2d1fcfbf26ddf
    free(line);
    fclose(file);

    /* Free the stack */
    /* You need to implement this part */

    return 0;
}

