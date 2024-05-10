#include "main.h"

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