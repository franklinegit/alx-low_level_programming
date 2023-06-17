#include "lists.h"

/**
 * find_listint_loop - a function that finds the loop in a linked list
 * @head: pointer to list
 * Return: address of the node where the loop starts, or NULL if no loop
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *ptr = head, *tmp = head;

	if (!head)
		return (NULL);
	while (tmp && tmp->next && ptr)
	{
		tmp = tmp->next->next;
		ptr = ptr->next;
		if (tmp == ptr)
		{
			ptr = head;
			while (ptr != tmp)
			{
				ptr = ptr->next;
				tmp = tmp->next;
			}
			return (tmp);
		}
	}
	return (NULL);
}
