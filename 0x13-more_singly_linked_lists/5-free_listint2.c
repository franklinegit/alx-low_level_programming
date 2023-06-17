#include "lists.h"

/**
 * free_listint2 - a function that frees a list and sets the head to NULL
 * @head: pointer to pointer of list
 */

void free_listint2(listint_t **head)
{
	listint_t *temp;

	if (!head)
		return;
	while (*head)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
	*head = NULL;
}
