#include <stdio.h>

/**
 * @brief Function that prints string in an array
 * 
 * @param str pointer to pointer to char
 * @param num_str number of strings to be printed from the array
 * @return int 
 */
int printStr(char **str, int num_str)
{
    int len =0, i = 0;

    for (i = 0; i < num_str; i++)
    {
        printf("%s\n", str[i]);
        len++;
    }

    return (len);
}

/**
 * @brief Function that prints a specific string from an array of arrays
 * 
 * @param str pointer to pointer to char
 * @param index index of string to be peinted
 * @return int 
 */
int printSpecificStr(char **str, int index)
{
    int len = 0;

    if (str[index] != NULL)
    {
        printf("%s\n", str[index]);
    }
    while (str[index][len] != '\0')
    {
        len++;
    }

    return (len);
}

/**
 * @brief Main function
 * 
 * @return int 
 */
int main(void)
{
    char str1[3][20] = {
        "Hello",
        "World",
        "C programming"
    };
    char *ptr1[3];
    char *str2[] = {
        "Here",
        "I come",
        "World"
    };
    int num_str1, num_str2, i;
    int len1, len2, len3, len4;

    for (i = 0; i < 3; i++)
    {
        ptr1[i] = str1[i];
    }

    num_str1 = sizeof(str1) / sizeof(str1[0]);
    num_str2 = sizeof(str2) / sizeof(str2[0]);

    /*for (i = 0; i < num_str1; i++)
        {
            printf("%s\n", str1[i]);
        }*/

    len1 = printStr(ptr1, num_str1);
    len2 = printStr(str2, num_str2);
    len3 = printSpecificStr(ptr1, 2);
    len4 = printSpecificStr(str2, 2);

    printf("The lengths printed by printStr() are: %d and %d.\n", len1, len2);
    printf("The lengths printed by printSpecificStr() are: %d and %d.\n", len3, len4);

    return (0);
}