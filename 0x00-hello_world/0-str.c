#include <stdio.h>

int main(void)
{
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

    return (0);
}