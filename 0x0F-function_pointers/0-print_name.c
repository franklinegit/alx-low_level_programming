#include "function_pointers.h"
#include <stdio.h>

/**
 * print_name - uses function pointer to print name
 * @name: name to print
 * @f: pointer to function
 * Return: nothing
 */

void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;
	f(name);
}
