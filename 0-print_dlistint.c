#include "lists.h"

size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *ptr;
	size_t count = 0;

	/**if (!h)
	{
		return(NULL);
	}
	*/
	ptr = h;
	while(ptr != NULL)
	{
		printf("%d \n", ptr->n);
		count++;
		ptr = ptr->next;
	}
	return(count);
}
