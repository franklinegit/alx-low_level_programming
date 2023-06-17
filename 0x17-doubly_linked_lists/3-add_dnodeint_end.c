#include "lists.h"

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *ptr = *head, *temp;

	temp = malloc(sizeof(dlistint_t));
	if (!temp)
		return(NULL);

	temp->n = n;
	temp->next = NULL;
	temp->prev = NULL;

	if (*head == NULL)
		*head = temp;
	else
	{
		while(ptr->next != NULL)
		{
			ptr = ptr->next;
		}

		ptr->next = temp;
		temp->prev = ptr;
	}
	return(temp);
}
