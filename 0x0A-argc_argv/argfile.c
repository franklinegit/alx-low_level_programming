#include <stdio.h>
#include <errno.h>
#include <string.h>

/**
 * main - Entry point
 * 
 * Return: 0 if successful, otherwise 1.
*/
int main(int argc, char *argv[])
{
    /* The function takes filename as argument, opens the file and counts the lines */

    /* Take command line arguments and validate if they are two */
    if (argc != 2)
    {
        printf("Error: Wrong count of arguments\n");
        printf("Usage: %s <filename>\n", argv[0]);
        return (1);
    }

    /* Open the file, and handle any file opening errors */
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error opening the file: %s\n", strerror(errno));
        return (1);
    }

    /* Count the number of lines */
    int no_of_lines = 0;
    char buffer[500];
    
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        no_of_lines++;
    }

    /* Close the file */
    fclose(file);

    /* Print number of lines */
    printf("Number of lines in %s: %d\n", argv[1], no_of_lines);

    return (0);
}