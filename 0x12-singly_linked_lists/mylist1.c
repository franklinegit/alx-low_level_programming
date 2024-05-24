#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/* struct for list */
typedef struct list_s
{
    char *str;
    unsigned int len;
    struct list_s *next;
}list_t;

/* PROTOTYPES FOR FUNCTION POINTERS */
typedef int (*GetInteger)(const char *);
typedef char* (*GetString)(const char *);

/*Function Prototypes */
void displayMenu(void);
int getIntInput(const char *prompt);
char* getStrInput(const char *prompt);
list_t* createNode(GetString getStr);
void prependNode(list_t **head, GetString getStr);
void appendNode(list_t **head, GetString getStr);
void insertNode(list_t **head, GetString getStr, GetInteger getInt);
void printList(list_t *head);
void freeList(list_t **head);
int getListLen(list_t *head);


/**
 * @brief Displays menu
 * 
 */
void displayMenu(void)
{
    printf("====MENU====\n");
    printf("1: Prepend node to the list.\n");
    printf("2: Append node to the list.\n");
    printf("3: Add node at specific location.\n");
	printf("4: Print the list.\n");
    printf("5: Exit\n");
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
 * @brief Create a new Node
 * 
 * @param getStr pointer to function that reads string from stdin
 * @return list_t* : new node
 */
list_t* createNode(GetString getStr)
{
    printf("Creating a new node...\n");

    list_t *new_node = (list_t*)malloc(sizeof(list_t));

    if (new_node == NULL)
    {
        fprintf(stderr, "Error. Could not allocate memory for the node. %s.\n", strerror(errno));
        printf("\n");
        exit(EXIT_FAILURE);
    }

    new_node->str = getStr("Enter the string.\n");
    new_node->len = strlen(new_node->str);
    new_node->next = NULL;
    printf("\n\n");
    return (new_node);
}

/**
 * @brief Function that prepends node to a list
 * 
 * @param head pointer to first node of list
 * @param getStr pointer to function that gets string input from stdin
 */
void prependNode(list_t **head, GetString getStr)
{
    list_t *new_node;

    new_node = createNode(getStr);
    printf("Adding node at the beginning of the list.\n");
    if (*head == NULL)
    {
        printf("List is empty.\nAdding node to the empty list.\n\n\n");
        *head = new_node;
        return;
    }
    else
    {
        printf("Prepending node to an existing list...\n");
        new_node->next = *head;
        *head = new_node;
        printf("Done.\n\n\n");
    }
}

/**
 * @brief function that appends node to a list
 * 
 * @param head pointer to first node on the list
 * @param getStr pointer to function that reads string from stdin
 */
void appendNode(list_t **head, GetString getStr)
{
    list_t *new_node;
    list_t *temp;

    new_node = createNode(getStr);
    printf("Adding node to the list.\n");
    if (*head == NULL)
    {
        printf("List is empty.\nAdding node to the empty list.\n\n\n");
        *head = new_node;
        return;
    }
    else
    {
        printf("Appending node to an existing list...\n");
        temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        printf("Done.\n\n\n");
    }
}

/**
 * @brief Function that inserts node at a specified position
 * 
 * @param head pointer to first node on list
 * @param getStr pointer to function that reads string from stdin
 * @param getInt pointer to function that reads integer from stdin
 */
void insertNode(list_t **head, GetString getStr, GetInteger getInt)
{
    int len = getListLen(*head);
    int position;

    do
    {
        position = getInt("Enter the position where to insert node.\n");
        if (position < 0 || position > len)
        {
            printf("Invlid position. Position must be between 0 and %d.\n\n", len);
        }
        else
            break;
    } while (1);

    if (position == 0)
    {
        prependNode(head, getStr);
        return;
    }

    list_t *newNode = createNode(getStr);
    list_t *temp = *head;
    for (int i = 1; i < position && temp->next != NULL; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

/**
 * @brief function that prints list
 * 
 * @param head pointer to first node on list
 */
void printList(list_t *head)
{
    const list_t *temp = head;
    while (temp != NULL)
    {
        printf("[%u] %s -> ", temp->len, temp->str);
        temp = temp->next;
    }
    printf("NULL\n");
}

/**
 * @brief function that frees list
 * 
 * @param head pointer to first node on list
 */
void freeList(list_t **head)
{
    list_t *temp;
    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp->str);
        free(temp);
    }
}

/**
 * @brief Get the List Length
 * 
 * @param head pointer to the first node
 * @return int : length of the list
 */
int getListLen(list_t *head)
{
    int len = 0;

    while (head != NULL)
    {
        len++;
        head = head->next;
    }
    
    return (len);
}

int main(void)
{
    GetString getStr = getStrInput;
    GetInteger getInt = getIntInput;
    list_t *head = NULL;

    while (1)
    {
        displayMenu();

        int choice = getIntInput("Enter choice of operation from the menu.\n");

        switch (choice)
        {
            case 1:
                prependNode(&head, getStr);
                break;
            
            case 2:
                appendNode(&head, getStr);
                break;
            
            case 3:
                insertNode(&head, getStr, getInt);
                break;
            
            case 4:
                printList(head);
                break;
            
            case 5:
                freeList(&head);
                printf("Exiting program...\n");
                printf("\n");
                return (EXIT_SUCCESS);
                break;
            
            default:
                printf("Choice must be a number between 1 and 5\n");
				printf("Please try again.\n");
				printf("\n");
                break;
        }
    }
    
    return (EXIT_SUCCESS);
}