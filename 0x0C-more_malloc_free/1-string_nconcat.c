#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
*string_nconcat - returns pointer to space in mem
*@s1: input string
*@s2: input string
*@n: number of characters
*Return: pointer to memory
*/
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int i, j, k, l;
	char *ptr;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	i = 0;
	while (s1[i] != '\0')
		i++;
	j = 0;
	while (s2[j] != '\0')
		j++;
	ptr = (char *)malloc(i + n + 1);
	if (ptr == NULL)
		return (NULL);
	if (n < j)
	{
		for (k = 0; s1[k] != '\0'; k++)
			ptr[k] = s1[k];
		for (l = 0; s2[l] != '\0' && l < n; l++)
		{
			 ptr[k] = s2[l];
			 k++;
		}
		ptr[k] = '\0';
	}
	if (n >= j)
	{
		for (k = 0; s1[k] != '\0'; k++)
			ptr[k] = s1[k];
		for (l = 0; s2[l] != '\0'; l++)
		{
			ptr[k] = s2[l];
			k++;
		}
		ptr[k] = '\0';
	}
	return (ptr);
}
