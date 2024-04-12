#include <stdio.h>

/**
 * main - prints the number of arguments passed into it.
 * 
 * @argc: Number of arguments
 * @argv: Array of arguments
 * 
 * Return: 0 when sucessful
*/

int main(int argc, char *argv[])
{
    printf("%d\n", argc - 1);
    return (0);
}