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

void initArray(DynamicArray *arr, int no_of_elmts);
void addElem(DynamicArray *arr, int element);
void freeArray(DynamicArray *arr);

/**
 * main - Entry function for initializing, element addition, printing, quiting, and freeing
 * 
 * Return: EXIT_SUCCESS, EXIT_FAILURE
*/

int main(void)
{
    int no_of_elmts, choice, element;
    DynamicArray *arr;

    /* Take user input on size of array */
    printf("Enter no of elements to be stored in array: \n");
    scanf("%d", &no_of_elmts);

    /* Initialize the array */
    arr = (DynamicArray *)malloc(sizeof(DynamicArray));
    if (arr == NULL)
    {
        fprintf(stderr, "Error. Could not allocate memory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    initArray(arr, no_of_elmts);

    /* Take user input to choose what operation to do, and perform operation*/
    do
    {
        printf("Choose what to do\n");
        printf("1. Add element to array.\n");
        printf("2. Print array elemts\n");
        printf("3. Quit\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the element to add to the array\n");
                scanf("%d", &element);
				addElemt(arr, element);
                break;
        
            case 2:
                printf("\n");
                break;
            
            case 3:
                freeArray(arr);
                break;

            default:
                printf("Invalid choice. Please pick 1, 2 or 3\n");
                printf("\n");
                break;
        }
    } while (1);
    

    /* Free allocated memory */


    return (EXIT_SUCCESS);
}

/* Function for Initializing array */
void initArray(DynamicArray *arr, int no_of_elmts)
{
    arr->array = (int *)malloc(no_of_elmts * sizeof(int));
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
void addElem(DynamicArray *arr, int element)
{
	if (arr->size == arr->capacity)
	{
        printf("Not sufficient space in allocated memory\n");
        printf("Reallocating memory to accomodate new element......\n");
		arr->capacity *= 2;
		arr->array = (int *)realloc(arr->array, arr->capacity * sizeof(int));
		if (arr->array == NULL)
		{
			fprintf(stderr, "Error. Could not reallocate memory: %s\n", strerror(errno));
        	exit(EXIT_FAILURE);
			
		}
	}
	arr->array[arr->size++] = element;
    printf("Element successfully added.\n");
    printf("\n");
}


/* Function to print array elemts */


/* Function to free memory */
void freeArray(DynamicArray *arr)
{
    printf("Exiting...\n");

    free(arr->array);
    free(arr);

    printf("Successfully freed the memory\n");
    printf("\n");
}