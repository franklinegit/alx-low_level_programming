#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * _memset - fills memory with constant 0
 * @str: memory area
 * @o: constant
 * @n: times to fill
 * Return: pointer to str
 */
char *_memset(char *str, char o, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		str[i] = o;
	}
	return (str);
}

/**
*_calloc - allocates memory for an array of nmemb elements of size bytes
*@nmemb: number of elements
*@size: size of each element
*Return: NULL if nmemb or size is 0 or malloc fails
*/
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
	{
		return (NULL);
	}
	_memset(ptr, 0, nmemb * size);
	return (ptr);
}
