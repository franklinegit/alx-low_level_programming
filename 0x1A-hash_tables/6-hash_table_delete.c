#include "hash_tables.h"

/**
 * hash_table_delete - Function that deletes a hash table.
 * @ht: Pointer to  hash table.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *head = ht;
	hash_node_t *tmp, *ptr;
	unsigned long int i;

	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i] != NULL)
		{
			ptr = ht->array[i];
			while (ptr != NULL)
			{
				tmp = ptr->next;
				free(ptr->key);
				free(ptr->value);
				free(ptr);
				ptr = tmp;
			}
		}
	}
	free(head->array);
	free(head);
}
