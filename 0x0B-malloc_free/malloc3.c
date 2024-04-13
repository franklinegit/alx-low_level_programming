#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <string.h>

/* Structure for array */
typedef struct
{
    int *array;
    int size;
    int capacity;
}DynamicArray;


/**
 * main - Entry function for initializing, element addition, printing, quiting, and freeing
 * 
 * Return: EXIT_SUCCESS, EXIT_FAILURE
*/

int main(void)
{
    int no_of_elmts;
    DynamicArray *arr;

    /* Take user input on size of array */
    printf("Enter no of elements to be stored in array: \n");
    scanf("%d", &no_of_elmts);

    /* Initialize the array */
    initArray(arr, no_of_elmts);

    /* Take user input to choose what operation to do, and perform operation*/


    /* Free allocated memory */


    return (EXIT_SUCCESS);
}

/* Function for Initializing array */
void initArray(DynamicArray *arr, int no_of_elmts)
{
    arr->array = (DynamicArray *)malloc(no_of_elmts * sizeof(int));
    if (arr->array == NULL)
    {
        fprintf(stderr, "Error. Could not allocate memory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    arr->size = 0;
    arr->capacity = no_of_elmts;

    printf("Memory successfully allocated\n");
    printf("\n");
}

/* Function to add element */


/* Function to print array elemts */


/* Function to free memory */