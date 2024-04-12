#include <stdio.h>
#include <stdlib.h>

/**
 * main - adds positive numbers.
 * 
 * @argc: Number of arguments
 * @argv: Array of arguments
 * 
 * Return: 0 when sucessful
*/

int main(int argc, char *argv[])
{
    char **ptr = argv + 1;
    int sum = 0;

    if (argc < 2)
    {
        fprintf(stderr, "0\n");
        return (1);
    }

    // valzero(argv);

    while (*ptr != NULL)
    {
        if (atoi(*ptr) == 0)
        {
            sum += atoi(*ptr);
        }
        else
        {
            fprintf(stderr, "Error\n");
            return (1);
        }

        ptr++;
    }
    printf("%d\n", sum);

    return (0);
}


/**
 * valzero - Function that validates if string is just zero.
 * 
 * @args: Array of argumrnts
 * 
 * Return: 0, otherwise 1
*/


// int valzero(char *args[])
// {
//     /* Function that checks if string is just zero. If so, return 0, otherwise 1*/
//     char **ptr = args;
//     char *current = *ptr;

//     if (*current == '0' && *(current + 1) == '\0');

// }
