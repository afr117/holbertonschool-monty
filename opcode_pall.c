#include "monty.h"

void pall(void) {
    StackNode *current = stack;

    while (current != NULL)
    {
	printf("Stack value: %d\n", current->data);
	printf("%d\n", current->data);
	current = current->next;
    }
}

