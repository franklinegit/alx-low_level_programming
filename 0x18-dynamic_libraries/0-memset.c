#include "main.h"
/**
 * _memset - function that fills a block of memory with given value
 * @s: address of memory to be filled
 * @b: desired value
 * @n: number of bytes to be changed
 *
 * Return: changed array with new value for n bytes
 */
char *_memset(char *s, char b, unsigned int n)
{
	int i;

	for (i = 0; n > 0; i++)
	{
		s[i] = b;
		n--;
	}
	return (s);
}
