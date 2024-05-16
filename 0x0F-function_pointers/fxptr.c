#include <stdio.h>
#include <stdlib.h>

/* Callback implementation */
/* Array in main; Filtered for even and odd by fxs */
/* Filter Functions create new filtered arrays and print sum */

typedef void (*filterArray)(int[], int);

void filterEven(int arr[], int size);
void filterOdd(int arr[], int size);
void processArray(int arr[], int size, filterArray callback);



void processArray(int arr[], int size, filterArray callback)
{
	printf("Processing array.\n");
	printf("\n");
	callback(arr, size);
}

void filterEven(int arr[], int size)
{
	int i = 0;
	int count = 0, sum = 0;

	printf("Filtering even numbers in the array.\n");
	printf("\n");
	for (i = 0; i < size; i++)
	{
		if (arr[i] % 2 == 0)
		{
			count++;
			sum += arr[i];
		}
	}

	printf("The count of even numbers in the array is %d.\n", count);

	int* even_array = (int*)malloc(sizeof(int) * count);
	int index = 0;

	for (i = 0; i < size; i++)
	{
		if (arr[i] % 2 == 0)
		{
			even_array[index++] = arr[i];
		}
	}

	printf("The even numbers in the array are:\n ");
	printf("[");
	for (i = 0; i < count; i++)
	{
		printf("%d ", even_array[i]);
	}
	printf("]\n");
	printf("The sum of the even numbers is: %d", sum);
	printf("\n");

	free(even_array);

}

void filterOdd(int arr[], int size)
{
	int i = 0;
	int count = 0, sum = 0;

	printf("Filtering odd numbers in the array.\n");
	printf("\n");
	for (i = 0; i < size; i++)
	{
		if (arr[i] % 2 != 0)
		{
			count++;
			sum += arr[i];
		}
	}

	printf("The count of even numbers in the array is %d.\n", count);

	int* odd_array = (int*)malloc(sizeof(int) * count);
	int index = 0;

	for (i = 0; i < size; i++)
	{
		if (arr[i] % 2 != 0)
		{
			odd_array[index++] = arr[i];
		}
	}

	printf("The odd numbers in the array are:\n ");
	printf("[");
	for (i = 0; i < count; i++)
	{
		printf("%d ", odd_array[i]);
	}
	printf("]\n");
	printf("The sum of the odd numbers is: %d", sum);
	printf("\n");

	free(odd_array);

}

int main(void)
{
	int arr[] = {1, 23, 90, 67, 27, 56, 91, 53, 62, 8, 4, 44, 86};
	int size = sizeof(arr) / sizeof(arr[0]);
	filterArray evens = filterEven;
	filterArray odds = filterOdd;

	processArray(arr, size, evens);
	processArray(arr, size, odds);

	return (0);
}