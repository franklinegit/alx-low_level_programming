#include "function_pointers.h"
#include <stdio.h>

/**
 * int_index - searches for integer
 * @array: input array
 * @size: size of array
 * @cmp: pointer to function
 * Return: index that doesn't return 0
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (size <= 0)
		return (-1);
	if (array == NULL || cmp == NULL)
		return (-1);
	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]) != 0)
			return (i);
	}
	return (-1);
}
