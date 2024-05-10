#include "main.h"

/**
 * @brief function that prints a string in reverse.
 * 
 * @param s pointer to string
 */
void _print_rev_recursion1(char *s)
{
    if (*s == '\0')
        return;
    _print_rev_recursion1(s + 1);
    _putchar(*s);
}