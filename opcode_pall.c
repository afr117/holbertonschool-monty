#include "monty.h"

void pall(void)
{
    StackNode *current = stack;
    while (current != NULL)
    {
        printf("%d", current->data); // Print the value without newline
        current = current->next;

        if (current != NULL)
            printf("\n"); // Add newline after each value except the last one
    }
    printf("\n"); // Add a final newline after printing all values
}

