#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void displayMenu(void);
int getIntInput(const char *prompt);
char* getStrInput(const char *prompt);
void revString( char *string);
int printInts(void);
int printRevStr(void);

/**
 * @brief Displays menu
 * 
 */
void displayMenu(void)
{
    printf("====MENU====\n");
    printf("1: I want to see 1 to 20\n");
	printf("2: Reverse a string\n");
    printf("3: Exit\n");
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
 * @brief Function that prints a sequence of integers
 * 
 * @return int 
 */
int printInts(void)
{
	int printed = 0;
	int i = 0;
	int start = getIntInput("Enter the start of the sequence.\n");
	int end = getIntInput("Enter the end point of the sequence.\n");

	if (start == end)
	{
		printf("The end point must not equal the start: Please enter other figures.\n");
		printf("\n");
	}
	else if (start < end)
	{
		for (i = start; i < end; i++)
		{
			printf("%d ", i);
			printed++;
		}
		printf("%d\n", end);
		printed++;
	}
	else
	{
		for (i = start; i > end; i--)
		{
			printf("%d ", i);
			printed++;
		}
		printf("%d\n", end);
		printed++;
	}

	printf("%d numbers printed.\n", printed);
	printf("\n");
	return (printed);
}

/**
 * @brief Function that reverses a string
 * 
 * @param string  String to be reversed
 */
void revString( char *string)
{
	char temp;
	int start = 0;
	int end = (strlen(string)) - 1;

	while (start < end)
	{
		temp = string[start];
		string[start] = string[end];
		string[end] = temp;

		start++;
		end--;
	}
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
 * @brief Function that prints string character by character
 * 
 * @param str pointer to string to be printed
 * @return int 
 */
int printStr(char *str)
{
	int len = 0, i =0;

	while (str[i] != '\0')
	{
		putchar(str[i]);
		len++;
		i++;
	}
	printf("\n");
	return (len);
}

/**
 * @brief Function that prints a reversed string
 * 
 * @return int 
 */
int printRevStr(void)
{
	int printed = 0;
	char *str = getStrInput("Enter string to be reversed.\n");

	if (str == NULL) 
	{ 
		// Handle case where string input fails
		printf("Returning to the main menu.\n");
		return printed;
    }


	revString(str);
	printed += printStr(str);

	free(str);

	return (printed);
}

int main(void)
{
	do
	{
		displayMenu();

		int choice = getIntInput("Enter your choice from the menu: \n");

		switch (choice)
		{
			case 1:
				printInts();
				break;

			case 2:
				printRevStr();
				break;
			
			case 3:
				printf("Exiting program...\n");
				printf("\n");
				return (EXIT_SUCCESS);
				break;
			
			default:
				printf("Choice must be a number between 1 and 3\n");
				printf("Please try again.\n");
				printf("\n");
				break;
		}
	}while (1);

    return (EXIT_SUCCESS);
}