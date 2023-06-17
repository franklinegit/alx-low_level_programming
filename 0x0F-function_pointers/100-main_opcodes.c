#include <stdlib.h>
#include <stdio.h>
/**
 * main - prints opcodes
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	int mem, i;
	char *array;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	mem = atoi(argv[1]);

	if (mem < 0)
	{
		printf("Error\n");
		exit(2);
	}

	array = (char *)main;

	for (i = 0; i < mem; i++)
	{
		if (i == mem - 1)
		{
			printf("%02hhx\n", array[i]);
			break;
		}
		printf("%02hhx ", array[i]);
	}
	return (0);
}

