#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int check_num(char *str);
/**
 * main - adds two integers
 * @argc: number of arguments
 * @argv: Arguments
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	int len, sum = 0, strCon;

	len = 1;
	while (len < argc)
	{
		if (check_num(argv[len]))

		{
			strCon = atoi(argv[len]);
			sum += strCon;
		}
		else
		{
			printf("Error\n");
			return (1);
		}
		len++;
	}
	printf("%d\n", sum);
	return (0);
}

/**
 * check_num - check if it's digit
 * @str: array str
 * Return: Always 0 (Success)
 */
int check_num(char *str)
{
	unsigned int len;

	len = 0;
	while (len < strlen(str))
	{
		if (!isdigit(str[len]))
		{
			return (0);
		}
		len++;
	}
	return (1);
}

