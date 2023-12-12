#include "monty.h"
#include <string.h>
#include <ctype.h>

/**
 * is_numeric - Check if a string is a numeric value.
 * @str: String to check.
 * Return: 1 if numeric, 0 otherwise.
 */
int is_numeric(const char *str)
{
    if (!str)
        return 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]) && str[i] != '-')
            return 0;
    }

    return 1;
}

