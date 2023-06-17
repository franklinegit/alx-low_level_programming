#include "lists.h"

/**
 * delete_nodeint_at_index - a function that deletes the node at index
 * @head: pointer to pointer to list
 * @index: index
 * Return: 1 if it succeeded, -1 if it failed
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current = *head, *prev = *head;
	unsigned int i = 0;

	if (!*head)
		return (-1);
	if (index == 0)
	{
		*head = (*head)->next;
		free(prev);
		return (1);
	}
	while (i < index - 1)
	{
		if (!prev || !(prev->next))
			return (-1);
		prev = prev->next;
		i++;
	}
	current = prev->next;
	prev->next = current->next;
	free(current);
	return (1);
}
