#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
    char *current = *ptr;
    int sum = 0;

    if (argc < 2)
    {
        printf("0\n");
        return (1);
    }

    else
    {
        while (*ptr != NULL)
        {
            if (*current == 0 && *(current + 1) == '\0')
            {
                sum += 0;
            }

            while (*current != '\0')
            {
                if (isdigit(*current))
                {
                    continue;
                }
                else
                {
                    fprintf(stderr, "Error\n");
                    return (1);
                }
                current++;
            }
                        
            sum += atoi(*ptr);
            ptr++;
        }
    }

    printf("%d\n", sum);

    return (0);
}