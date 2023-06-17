#include "lists.h"

/**
 * sum_listint - a function that returns the sum of all the data (n) of a list
 * @head: pointer to list
 * Return: sum of data or 0 if the list is empty
 */

int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *ptr;

	if (!head)
		return (0);
	ptr = head;
	while (ptr)
	{
		sum += ptr->n;
		ptr = ptr->next;
	}
	return (sum);
}
