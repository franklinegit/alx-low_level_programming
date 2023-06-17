#include "main.h"

/**
 * char *_strcpy - copies string pointed to by src
 * @dest: destination to copy to
 * @src: source to copy from
 * Return: string
 */
char *_strcpy(char *dest, char *src)
{
	int i;
	int j;

	for (i = 0; *(src + i) != '\0'; i++);
	for (j = 0; j < j ;j++)
	{
		dest[j] = src[j];
	}
	dest[i] = '\0';
	return (dest);
}
