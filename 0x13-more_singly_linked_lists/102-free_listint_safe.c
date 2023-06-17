#include "lists.h"

/**
 * free_listint_safe - a function that prints a linked list
 * @h: pointer to node head
 * Return: number of node
 */

size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	int i;
	listint_t *ptr;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		i = *h - (*h)->next;
		if (i > 0)
		{
			ptr = (*h)->next;
			free(*h);
			*h = ptr;
			count++;
		}
		else
		{
			free(*h);
			*h = NULL;
			count++;
			break;
		}
	}
	*h = NULL;
	return (count);
}
