#include "lists.h"

/**
 * print_listint_safe - function that prints a linked list
 * @head: pointer to the head of the linked list
 * Return: the number of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *current = head, *prev = NULL;

	while (current)
	{
		printf("[%p] %d\n", (void *) current, current->n);
		count++;
		if (current < prev)
		{
			printf("-> [%p] %d\n", (void *) current->next, current->next->n);
			break;
		}
		prev = current;
		current = current->next;
	}
	if (count == 0)
		exit(98);
	return (count);
}
