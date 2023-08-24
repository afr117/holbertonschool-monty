#include "monty.h"

StackNode *stack = NULL;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s file\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        // Parse line and execute opcode
        // Example: sscanf(line, "push %d", &value);
        // Example: if (strcmp(opcode, "push") == 0) push(value);
    }

    fclose(file);
    return EXIT_SUCCESS;
}

