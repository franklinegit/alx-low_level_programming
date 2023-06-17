#include "lists.h"

/**
 * reverse_listint - a function that reverses a list
 * @head: pointer to head
 * Return: pointer to first node
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL, *next = NULL;

	while (*head)
	{
		next = (*head)->next;
		(*head)->next = prev;
		prev = *head;
		*head = next;
	}
	*head = prev;
	return (*head);
}
