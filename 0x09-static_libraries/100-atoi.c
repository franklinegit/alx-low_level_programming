#include "main.h"

/**
 * _atoi - converts string into integer.
 *
 * @s: the string to be converted.
 *
 * Return: integer.
 */

int _atoi(char *s)
{
	int j = 1, i = 0;
	unsigned int n = 0;

	while (!(s[i] <= '9' && s[i] >= '0') && s[i] != '\0')
	{
		if (s[i] == '-')
			j *= -1;
		i++;
	}
	while (s[i] <= '9' && (s[i] >= '0' && s[i] != '\0'))
	{
		n = (n * 10) + (s[i] - '0');
		i++;
	}
	n *= j;
	return (n);
}
