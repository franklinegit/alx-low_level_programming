#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Structure for bank account */
typedef struct
{
    int accountNumber;
    char accounyName[50];
    double accountBalance;
}BankAccount;


/* Structure for bank */
typedef struct
{
    BankAccount *account;
    int numAccounts;
}Bank;

void initializeBank(Bank *myBank)
{
	myBank->account = NULL;
	myBank->numAccounts = 0;	
}

void displayMenu(void)
{
	printf("======BANKING SYSTEM MENU======\n");
	printf("Choose operation to execute\n");
	printf("1: Create an account\n");
	printf("2: Deposit cash\n");
	printf("3: Withdraw cash\n");
	printf("4: Transfer money\n");
	printf("5: Exit\n");
	printf("Enter your choice.\n");
}


/**
 * main - Entry point for initializing, creating, withdrawing, displaying, transfering
 * 
 * Return: EXIT_SUCCESS, EXIT_FAILURE
*/
int main(void)
{
	int choice;
	Bank myBank;

	initializeBank(&myBank);

	do
	{
		displayMenu();
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			/* Option to create bank account */
			createAccount(&myBank);
			break;
		
		case 2:
			deposit(&myBank);
			break;
		
		case 3:
			withdraw(&myBank);
			break;

		case 4:
			/* code */
			break;

		case 5:
			printf("Exiting...\n");

			return(EXIT_SUCCESS);
			break;

		default:
			printf("Invalid choice. Please pick 1, 2, 3 or 4\n");
			printf("\n");
			break;
		}

	} while (1);
	
	return(EXIT_SUCCESS);
}