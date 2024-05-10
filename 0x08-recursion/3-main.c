#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    int r;

    r = factorial1(1);
    printf("%d\n", r);
    r = factorial1(5);
    printf("%d\n", r);
    r = factorial1(10);
    printf("%d\n", r);
    r = factorial1(-1024);
    printf("%d\n", r);
    return (0);
}
