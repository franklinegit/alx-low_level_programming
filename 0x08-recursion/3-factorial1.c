#include "main.h"

/**
 * @brief factorial1 - function that returns the factorial of a number
 * 
 * @param n: number whose factorial is to be returned
 * @return int 
 */
int factorial1(int n)
{
    if (n < 0)
        /* Base case: When input is negative */
        return (-1);
    if (n == 0)
        /* Base case: When n == 0 */
        return (1);
    return (n * factorial1(n -1));
}