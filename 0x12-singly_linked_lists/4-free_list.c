#include "lists.h"

/**
 * free_list - frees a linked list
 * @head: pointer to list_t list to be freed
 */
void free_list(list_t *head)
{
	list_t *ptr;

	while (head)
	{
		ptr = head->next;
		free(head->str);
		free(head);
		head = ptr;
	}
}
