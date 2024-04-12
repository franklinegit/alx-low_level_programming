#include <stdio.h>

/**
 * main - function prints all arguments received
 * 
 * @argc: Number of arguments
 * @argv: Array of arguments
 * 
 * Return: 0 when sucessful
*/

int main(int argc, char *argv[])
{
    char **ptr = argv;
    while (*ptr != NULL)
    {
        printf("%s\n", *ptr);
        ptr++;
    }
    

    return (0);
}