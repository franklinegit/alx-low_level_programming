#include "function_pointers.h"
#include <stdio.h>

/**
 * array_iterator - execute on each array element
 * @array: array
 * @size: size of array
 * @action: pointer to array
 * Return: nothing
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	if (array == NULL || action == NULL)
		return;
	for (i = 0; i < size; i++)
		action(array[i]);
}
