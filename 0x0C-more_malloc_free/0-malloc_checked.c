#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
/**
 *malloc_checked - Returns a pointer to the allocated memory
 *@b: size of mem
 *Return: pointer to the allocated memory
 */
void *malloc_checked(unsigned int b)
{
	void *ptr;

	ptr = malloc(b);
	if (ptr == NULL)
	{
		exit(98);
	}
	return (ptr);
}
