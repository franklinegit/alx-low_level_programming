#include "lists.h"

/**
 * listint_len - a function that returns number of elements in a linked list
 * @h: pointer to list
 * Return: number of elements in a linked list
 */

size_t listint_len(const listint_t *h)
{
	size_t count = 0;
	const listint_t *ptr;

	ptr = h;
	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}
	return (count);
}
