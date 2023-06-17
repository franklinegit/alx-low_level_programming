#include "lists.h"

/**
 * get_nodeint_at_index - a function that returns the nth node of a list
 * @head: pointer to list
 * @index: index of node
 * Return: nth node or NULL if the node does not exist
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;
	listint_t *ptr;

	if (!head)
		return (NULL);
	ptr = head;
	for (i = 0; ptr && i < index; i++)
		ptr = ptr->next;
	if (!ptr)
		return (NULL);
	return (ptr);
}
