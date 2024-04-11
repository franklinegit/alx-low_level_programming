#include <stdio.h>

int print_arrstr();
/**
 * main - Entry point
 * 
 * Return: Returns 0
*/
int main(void)
{
    /**
     * The function uses various string output functions eg. putchar, puts, printf 
     * Function also tests use of arrays, pointers, and pointers to array of strings
     */
    char str1[] = "Hello, World";
    char *str2 = "Hello, World";
    int i = 0;

    /* Printing the string from str1 array using a for loop and putchar function */
    puts("Printing the string from str1 array using a for loop and putchar function");
    for(i = 0; str1[i] != '\0'; i++)
    {
        putchar(str1[i]);
    }

    putchar('\n');

    /* Printing the second character in the str2 string */
    puts("Printing the second character in the str2 string");
    putchar(str2[1]);

    putchar('\n');

    print_arrstr();

    return (0);
}


/**
 * print_arrstr - Function that prints array of strings
 * 
 * Return: 0 in success, otherwise, 1.
*/
int print_arrstr()
{
    char *strings[] = {
        "str1",
        "str2",
        "str3",
        "str4",
        NULL /* Null pointer marks the end of the array */
    };

    int i = 0;
    char **ptr = strings;

    /* Iterate through the array of pointers and print the strings */
    puts("Printing items from an array of strings");
    while (*ptr != NULL)
    {
        printf("String %d: %s\n", i + 1, *ptr);
        i++;
        ptr++;
    }

    return (0);
}