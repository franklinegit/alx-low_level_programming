#include "main.h"

/**
 * @brief function that returns the length of a string
 * 
 * @param s pointer to string
 * @return int The length of the string
 */
int _strlen_recursion1(char *s)
{
    if (*s == '\0')
        return (0);
    return (1 + _strlen_recursion1(s + 1));
}