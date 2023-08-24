#include "monty.h"
#include <ctype.h>


/**
 * pall - Prints all elements in the stack
 */

void pall(void)
{
	for (size_t i = stack_size; i > 0; i--)
{
	printf("%d\n", data_stack[i - 1]);
}
}
