#include <stdio.h>

void odd();
void even();
int n = 1;

/**
 * @brief  Adds 1 to odd number and prints it
 * 
 */
void odd()
{
    if (n <= 10)
    {
        printf("%d ", n + 1);
        n++;
        even();
    }
    return;
}

/**
 * @brief Subtracts 1 from even number and prints it
 * 
 */
void even()
{
    if (n <= 10)
    {
        printf("%d ", n-1);
        n++;
        odd();
    }
    return;
}

/**
 * @brief Main function
 * 
 * @return int 
 */
int main(void)
{
    printf("Program that adds 1 to odd numbers and subtracts 1 from even.\n");
    printf("\n");
    odd();
    printf("\n");

    return (0);
}