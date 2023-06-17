#include "lists.h"

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *temp;

	temp = malloc(sizeof(dlistint_t));
	if (!temp)
		return(NULL);
	temp->n = n;
	temp->prev = NULL;
	temp->next = *head;

	if (*head != NULL)
		(*head)->prev = temp;
	*head = temp;
	return(temp);
}
