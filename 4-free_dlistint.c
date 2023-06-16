#include "lists.h"

void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp = head;

	while(temp != NULL)
	{
		temp = temp->next;
		free(head);
		head = temp;
	}
}
