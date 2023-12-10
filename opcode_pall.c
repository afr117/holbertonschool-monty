#include <stdio.h>
#include "monty.h"


void pall(void)
{
    StackNode *current = stack;
    while (current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}
