#include "lists.h"

/**
 * free_listint - a function that frees a list
 * @head: pointer to list
 */

void free_listint(listint_t *head)
{
	listint_t *temp;

	if (head == NULL)
		return;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
