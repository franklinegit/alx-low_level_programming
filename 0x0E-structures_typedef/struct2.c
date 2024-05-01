#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

/* Struct for dynamic array */
/* array - array of integers */
/* num_occupied - Number of slots in the array already occupied */
/* capacity - total capacity of the array */
typedef struct {
    int *array;
    int num_occupied;
    int capacity;
} dynamicArray;

/* Function prototypes */
void initArray(dynamicArray *arr, int numElem);
void displayMenu(void);
void freeMem(dynamicArray *arr);
void addElem(dynamicArray *arr);
void printArray(dynamicArray *arr);
int getIntInput(const char *prompt);

/**
 * initArray - Function that initializes the integer array
 * @arr
*/
void initArray(dynamicArray *arr, int numElem) {
    arr->array = (int *)malloc(sizeof(int) * numElem);
    if (arr->array == NULL) {
        fprintf(stderr, "Error. Could not allocate memory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    arr->num_occupied = 0;
    arr->capacity = numElem;

    printf("Memory successfully allocated for the integer array\n");
    printf("Array capacity and slots occupied successfully initialized\n\n");
}

void displayMenu(void) {
    printf("======CHOICE OF OPERATION MENU======\n");
    printf("1: Add element to array.\n");
    printf("2: Print array.\n");
    printf("3: Exit.\n");
}

void freeMem(dynamicArray *arr) {
    free(arr->array);
    free(arr);

    printf("Memory freed successfully\n\n");
}

void addElem(dynamicArray *arr) {
    int elem = getIntInput("Enter the element to add:");

    /* Check if allocated memory is full and allocate more if needed */
    if (arr->num_occupied == arr->capacity) {
        arr->capacity *= 2; /* Increase size of memory to allocate */
        /* Reallocate memory to accommodate new element */
        arr->array = (int *)realloc(arr->array, arr->capacity * sizeof(int));
        if (arr->array == NULL) {
            fprintf(stderr, "Error. Could not allocate memory: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
        printf("Memory reallocated successfully.\n\n");
    }
    /* Add element while incrementing number of slots occupied */
    arr->array[arr->num_occupied++] = elem;
    printf("Element (%d) added successfully.\n\n", elem);
}

void printArray(dynamicArray *arr) {
    printf("Printing array elements.\n");
    if (arr->num_occupied == 0) {
        printf("Array empty. No elements to print.\n");
    } else {
        for (int i = 0; i < arr->num_occupied; i++) {
            printf("%d ", arr->array[i]);
        }
        printf("\n");
    }
}

/**
 * getIntInput - Function to get integer input from the user
 * @prompt: The prompt to display to the user
 * Returns: The integer inputted by the user
 */
int getIntInput(const char *prompt) {
    int input;
    do {
        printf("%s\n", prompt);
        if (scanf("%d", &input) != 1) {
            fprintf(stderr, "Invalid input type. Please enter an integer.\n");
            while (getchar() != '\n'); // Clear input buffer
            printf("Please try again.\n\n");
        } else {
            break;
        }
    } while (1);
    return input;
}

int main(void) {
    int numElem, choice;
    dynamicArray *arr;

    numElem = getIntInput("Enter number of integers to be stored in the array:");

    /* Initialize dynamic array */
    arr = (dynamicArray *)malloc(sizeof(dynamicArray));
    if (arr == NULL) {
        fprintf(stderr, "Error. Could not allocate memory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    initArray(arr, numElem);

    do {
        displayMenu();
        choice = getIntInput("Enter your choice:");

        switch (choice) {
            case 1:
                /* Add element to array */
                addElem(arr);
                break;
            case 2:
                /* Print contents of array */
                printArray(arr);
                break;
            case 3:
                /* Exit the loop/program */
                printf("Exiting...\n");
                freeMem(arr);
                return EXIT_SUCCESS;
            default:
                fprintf(stderr, "Invalid choice. Please enter a number between 1 and 3.\n\n");
        }
    } while (1);

    return EXIT_SUCCESS;
}