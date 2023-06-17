#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: pointer to pointer to list
 * @idx: index of the list where the new node should be added
 * @n: input data
 * Return: address of the new node, or NULL if it failed
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *ptr, *temp;
	unsigned int i = 0;

	if (!head)
		return (NULL);
	if (idx == 0)
	{
		temp = malloc(sizeof(listint_t));
		if (!temp)
			return (NULL);
		temp->n = n;
		temp->next = *head;
		*head = temp;
		return (temp);
	}
	ptr = *head;
	while (ptr && i < (idx - 1))
	{
		ptr = ptr->next;
		i++;
	}
	if (!ptr || !ptr->next)
		return (NULL);
	temp = malloc(sizeof(listint_t));
	if (!temp)
		return (NULL);
	temp->n = n;
	temp->next = ptr->next;
	ptr->next = temp;
	return (temp);
}
