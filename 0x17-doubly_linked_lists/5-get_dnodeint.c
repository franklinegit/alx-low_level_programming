#include "lists.h"

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i = 0, count = 0;

	dlistint_t *ptr = head;

	if (!head)
		return(NULL);
	while(ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}
	if (index >= count)
		return(NULL);
	/**else if (index == 0)
		return(head);
		*/
	/**else
	{
		while(i < index)
		{
			ptr = ptr->next;
			i++;
		}
		return(ptr);
	}
	*/
	ptr = head;
	for (i = 0; i < index; i++)
    	{
		ptr = ptr->next;
	}
	return ptr;
}
