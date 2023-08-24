#include "monty.h"
#include <ctype.h>

/**
 * find_opcode - Finds the corresponding function for an opcode.
 * @opcode: The opcode to find.
 *
 * Return: A pointer to the corresponding function, or NULL if not found.
 */
void (*find_opcode(char *opcode))(StackNode **, unsigned int)
{
    opcode_t opcodes[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {"swap", swap},
        {NULL, NULL}
    };

    int i = 0;
    while (opcodes[i].opcode != NULL)
    {
        if (strcmp(opcodes[i].opcode, opcode) == 0)
            return opcodes[i].f;
        i++;
    }
    return NULL;
}


void push(StackNode **stack, unsigned int line_number);

void pint(StackNode **stack, unsigned int line_number);

void pop(StackNode **stack, unsigned int line_number);

void pall(StackNode **stack, unsigned int line_number);

void swap(StackNode **stack, unsigned int line_number);
