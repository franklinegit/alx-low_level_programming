#include "lists.h"

/**
 * pop_listint - a function that deletes the head node
 * @head: pointer to pointer to list
 * Return: returns the head nodes data (n) or 0
 */

int pop_listint(listint_t **head)
{
	int data;
	listint_t *temp = *head;

	if (!*head)
		return (0);
	data = (*head)->n;
	*head = (*head)->next;
	free(temp);
	temp = NULL;
	return (data);
}
