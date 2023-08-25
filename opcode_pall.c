#include "monty.h"
#include <stdio.h>

void pall(void)
{
    StackNode *current = stack;
    while (current != NULL)
    {
        printf("Stack value: %d\n", current->data); // Add this line for debugging
        printf("%d\n", current->data);
        current = current->next;
    }
}

