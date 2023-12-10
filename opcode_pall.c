#include "monty.h"
#include <stdio.h>

void pall(void)
{
    for (size_t i = 0; i < stack_size; i++)
    {
        printf("%d\n", data_stack[i]);
    }
}

