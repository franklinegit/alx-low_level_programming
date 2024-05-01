#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

/* Struct for dynamic array */
/* array - array of integers */
/* num_occupied - Number of slots in the array already occupied */
/* capcity - total capacity of the array */
typedef struct
{
	int *array;
	int num_occupied;
	int capacity;    
}dynamicArray;

/**
 * initArray - Function that initializes the integer array
 * @arr
*/
void initArray(dynamicArray *arr, int numElem)
{
	arr->array = (int *)malloc(sizeof(int) * numElem);
	if (arr->array == NULL)
    {
        fprintf(stderr, "Error. Could not allocate memory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
	arr->num_occupied = 0;
	arr->capacity = numElem;

	printf("Memory successfully allocated for the integer array\n");
	printf("Array capacity and slots occupied successfully initialized\n");
	printf("\n");
}

void displayMenu(void)
{
	printf("======CHOICE OF OPERATION MENU======\n");
	printf("1: Add element to array.\n");
	printf("2: Print array.\n");
	printf("3: Exit.\n");
}

void freeMem(dynamicArray *arr)
{
	free(arr->array);
	free(arr);

	printf("Memory freed successfully\n");
	printf("\n");
}

void addElem(dynamicArray *arr)
{
	int elem;

	do
	{
		printf("You have chosen to add an element to the array\n");
		printf("Enter the element to add: \n");

		if (scanf("%d", &elem) != 1)
		{
			fprintf(stderr, "Invalid input type. Please enter an integer,\n");
			while(getchar() != '\n');
			printf("Please try again.\n");
		}
		else
		{
			break;
		}

	} while (1);
	
	/* Check if allocated memory is full and allocate more if needded */
	if (arr->num_occupied == arr->capacity)
	{
		arr->capacity *= 2; /* Increase size of memory to allocate */
		/* Reallocate memory to accomodate new element */
		arr->array = (int *)realloc(arr->array, arr->capacity * sizeof(int));
		if (arr->array == NULL)
    	{
        	fprintf(stderr, "Error. Could not allocate memory: %s\n", strerror(errno));
        	exit(EXIT_FAILURE);
    	}
		printf("Memory reallocated successfully.\n");
		printf("\n");
	}
	/* Add element while incrementing number of slots occupied */
	arr->array[arr->num_occupied++] = elem;
	printf("Element (%d) added successfully.\n", elem);
	printf("\n");
}

void printArray(dynamicArray *arr)
{
	int i;

	printf("Printing array elements.\n");
	if (arr->num_occupied == 0)
	{
		printf("Array empty. No elements to print.\n");
	}
	else
	{
		for (i = 0; i < arr->num_occupied; i++)
		{
			printf("%d ", arr->array[i]);
		}
		printf("\n");
	}
}

/**
 * main - Entry point to initialize, add elemnt, display, and free/exit
 * 
 * Return: EXIT_SUCCESS, EXIT_FAILURE
*/
int main(void)
{
	int numElem, choice, elem;
	dynamicArray *arr;

	/* Prompt user for number of integers to be stored in the array */
	do
	{
		printf("Enter number of integers to be stored in  the array.\n");
		/* Validate user input type */
		if (scanf("%d", &numElem) != 1)
		{
			fprintf(stderr, "Error. Incorrect value type entered: %s\n", strerror(errno));
			printf("\n");

			/* Clear input buffer */
			while (getchar() != '\n');

			printf("Please try again.\n");
			printf("\n");
		}
		else
		{
			break;
		}

	} while (1);
	
	/* Initialize dynamic array */
	arr = (dynamicArray *)malloc(sizeof(dynamicArray));
	if (arr == NULL)
    {
        fprintf(stderr, "Error. Could not allocate memory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

	initArray(arr, numElem);

	do
	{
		displayMenu();

		do
		{
			printf("Enter your choice: \n");
			/* Validate user input */
			if (scanf("%d", &choice) != 1)
			{
				fprintf(stderr, "Error. Incorrect value type entered: %s\n", strerror(errno));
				printf("\n");

				/* Clear input buffer */
				while (getchar() != '\n');

				printf("Please try again.\n");
				printf("\n");
			}

			else
			{
				if (choice < 1 || choice > 3)
				{
					fprintf(stderr, "Invalid choice. Please enter an integer ranging from 1 to 3.\n");
					printf("Please try again.\n");
					printf("\n");
				}

				else
				{
					break; /* Exit the loop if the input is valid */
				}
			}

		} while (1);
		

		switch (choice)
		{
		case 1:
			/* Add element to array */
			addElem(arr);
			break;
		
		case 2:
			/* Print contents of array */
			printArray(arr);
			break;

		case 3:
			/* Exit the loop/ program */
			printf("Exiting...\n");
			freeMem(arr);
			return(EXIT_SUCCESS);
			break;

		default:
			break;
		}
	} while (1);
	

	return(EXIT_SUCCESS);
}