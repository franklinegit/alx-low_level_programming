#include "main.h"

/**
 * @brief function that prints a string, followed by a new line.
 * 
 * @param s pointer to string
 */
void _puts_recursion1(char *s)
{
    if (*s == '\0')
    {
        _putchar('\n');
        return;
    }
    _putchar(*s);
    _puts_recursion1(s + 1);
}

