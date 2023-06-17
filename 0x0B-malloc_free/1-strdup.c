#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a new duplicate string
 * @str: input string
 * Return: a pointer to the duplicated string
 */

char *_strdup(char *str)
{
	char *ptr;
	int i, len;

	if (str == NULL)
	{
		return (NULL);
	}
	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
	{
		return (NULL);
	}
	for (i = 0; str[i]; i++)
	{
		ptr[i] = str[i];
	}
	return (ptr);
}
