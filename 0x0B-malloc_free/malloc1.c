#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <string.h>

/**
 * main - Function that takes array of user input and calculates average
 * 
 * Return: 0 on success, otherwise, 1
*/
int main(void)
{
    int i = 0, sum = 0, no_of_ints;
    int *arr;
    double avg;

    /* Take number of integers to claculate their average */
    printf("Enter number of integers to calculate their average: ");
    scanf("%d", &no_of_ints);

    /* Dinamically allocate memory for array of integers and handle any errors */
    arr = (int *)malloc(sizeof(int) * no_of_ints);
    if (arr == NULL)
    {
        fprintf(stderr, "Error encountered. Unable to allocate memory: %s\n", strerror(errno));
        return (EXIT_FAILURE);
    }

    /* Take user input of array of integers and calculate sum */
    printf("Enter %d integers: \n", no_of_ints);
    for (i = 0; i < no_of_ints; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    /* Calculate the average and print the answer */
    avg = sum / no_of_ints;
    printf("The average value is: %f\n", avg);

    /* Free dinamically allocated memory */
    free(arr);

    return (EXIT_SUCCESS);
}