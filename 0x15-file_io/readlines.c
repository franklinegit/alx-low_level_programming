#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void displayMenu(void);
int getIntInput(const char *prompt);
char* getStrInput(const char *prompt);
int countLines(FILE *file);
int countWordOccurance(FILE *file);
/**
 * @brief Displays menu
 * 
 */
void displayMenu(void)
{
    printf("\n");
    printf("====OPERATIONS MENU====\n");
	printf("1: Count lines in the file.\n");
    printf("2: Count occurances of a word.\n");
    printf("3: Exit the program.\n");
	printf("\n");
}

/**
 * @brief Get the Int Input object
 * 
 * @param prompt - Prompt for input
 * @return int 
 */
int getIntInput(const char *prompt)
{
	int input;
	do
	{
		printf("%s", prompt);
		if (scanf("%d", &input) != 1)
		{
			fprintf(stderr, "Wrong input type: %s.\n", strerror(errno));
			printf("Please enter an integer\n");
			printf("\n");
			while (getchar() != '\n');
		}
		else
		{
			while (getchar() != '\n');
			break;
		}
	} while (1);
	return (input);
}

/**
 * @brief Get the Str Input object
 * 
 * @param prompt String to prompt for input
 * @return char* 
 */
char* getStrInput(const char *prompt)
{
	char *str = (char *)malloc(sizeof(char) * 100);
	if (!str)
	{
		fprintf(stderr, "Memory not allocated: %s.\n", strerror(errno));
		printf("\n");
		exit (EXIT_FAILURE);
	}

	do
	{
		printf("%s", prompt);
		if (fgets(str, 100, stdin) != NULL)
		{
			str[strcspn(str, "\n")] = 0;
			break;
		}
		else
		{
			printf("Invalid string input. Try again.\n");
			printf("\n");
			while (getchar() != '\n');
		}
	} while (1);

	return (str);
}

/**
 * @brief Function that counts the number of lines in a file
 * 
 * @param file pointer to file
 * @return int 
 */
int countLines(FILE *file)
{
    int line_count = 0;
    char c;

    while ((c = fgetc(file)) != EOF)
    {
        if (c == '\n')
        {
            line_count++;
        }
    }
    rewind(file); /* Reset file pointer to beginning of the file */

    return (line_count);
}

/**
 * @brief Function that counts the number of word occurances in a file
 * 
 * @param file pointer to the file
 * @return int 
 */
int countWordOccurance(FILE *file)
{
    char *word;
    int word_count = 0;
    char line[300];

    word = getStrInput("Enter the word to search for in the file.\n");
    while (fgets(line, sizeof(line), file))
    {
        char *ptr = line;
        while ((ptr = strstr(ptr, word)) != NULL)
        {
            word_count++;
            ptr +=strlen(word);
        }
        
    }
    free(word);
    rewind(file); /* Reset file pointer to beginning of the file */

    return (word_count);
}

/**
 * @brief main function
 * 
 * @return int 
 */
int main(void)
{
    FILE *file;
    char *filename;

    filename = getStrInput("Enter the name of the file on which to perform operations.\n");
    file = fopen(filename, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Could not open the file %s. %s", filename, strerror(errno));
        printf("\n");
        free(filename);
        exit(EXIT_FAILURE);
    }

    do
    {
        int choice, line_count, word_count;

        displayMenu();

        choice = getIntInput("Enter choice of operation from the menu.\n");
        switch (choice)
        {
            case 1:
                line_count = countLines(file);
                printf("The number of lines counted are: %d.\n", line_count);
                printf("\n");
                break;
        
            case 2:
                word_count = countWordOccurance(file);
                printf("The word occurs in the file %s %d times.\n", filename, word_count);
                printf("\n");
                break;
        
            case 3:
                fclose(file);
                free(filename);
                printf("Exiting program....\n");
                printf("\n");
                exit(EXIT_SUCCESS);
                break;
        
            default:
                printf("Choice must be a number between 1 and 3\n");
                printf("Please try again.\n");
                printf("\n");
                break;
        }
    } while (1);
    

    return (EXIT_SUCCESS);
}