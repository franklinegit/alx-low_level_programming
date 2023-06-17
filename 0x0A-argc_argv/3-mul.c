#include <stdio.h>
#include "main.h"

int _atoi(char *s);
/**
 * main - multiplies two numbers
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 (Success), 1 (Error)
 */
int main(int argc, char **argv)
{
	int product, no1, no2;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	no1 = _atoi(argv[1]);
	no2 = _atoi(argv[2]);
	product = no1 * no2;

	printf("%d\n", product);

	return (0);
}

/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 * Return: the int converted from the string
 */
int _atoi(char *s)
{
	int i = 0, j = 0, k = 0, len = 0, f = 0, digit = 0;

	while (s[len] != '\0')
		len++;
	while (i < len && f == 0)
	{
		if (s[i] == '-')
			++j;
		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';
			if (j % 2)
				digit = -digit;
			k = k * 10 + digit;
			f = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
			f = 0;
		}
		i++;
	}

	if (f == 0)
		return (0);

	return (k);
}

