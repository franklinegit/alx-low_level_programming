#include <stdio.h>
#include <stdlib.h>

/**
 * main - multiplies two numbers.
 * 
 * @argc: Number of arguments
 * @argv: Array of arguments
 * 
 * Return: 0 when sucessful
*/

int main(int argc, char *argv[])
{
    int no1, no2;

    if (argc != 3)
    {
        fprintf(stderr, "Error\n");
        return (1);
    }

    no1 = atoi(argv[1]);
    no2 = atoi(argv[2]);
    printf("%d\n", no1 * no2);

    return (0);
}