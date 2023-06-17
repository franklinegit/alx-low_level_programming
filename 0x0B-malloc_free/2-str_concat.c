#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings
 * @s1: input string
 * @s2: input string
 * Return: pointer or NULL on failure
 */

char *str_concat(char *s1, char *s2)
{
	char *ptr;
	int i, j, k, l;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}
	i = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		j++;
	}
	ptr = malloc(sizeof(char) * (i + j + 1));
	if (ptr == NULL)
	{
		return (NULL);
	}
	for (k = 0; s1[k] != '\0'; k++)
	{
		ptr[k] = s1[k];
	}
	for (l = 0; s2[l] != '\0'; l++)
	{
		ptr[k] = s2[l];
		k++;
	}
	ptr[k] = '\0';
	return (ptr);
}
