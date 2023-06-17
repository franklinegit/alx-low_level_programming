#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * array_range - creates an array of integers
 * @min: minimum value
 * @max: maximu value
 * Return: pointer to the newly created array
 */
int *array_range(int min, int max)
{
	int len = (max - min) + 1, i;
	int *ptr;

	if (min > max)
	{
		return (NULL);
	}
	ptr = malloc(len * sizeof(int));
	if (ptr == NULL)
	{
		return (NULL);
	}
	for (i = 0; min <= max; i++)
	{
		ptr[i] = min++;
	}
	return (ptr);
}
