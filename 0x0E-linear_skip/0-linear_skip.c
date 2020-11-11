#include "search.h"

/**
 * linear_skip - search for value in skip list of integers
 * @list: pointer to head of skip list to search
 * @value: value to search for
 *
 * Return: pointer to first node where value is located, otherwise NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *curr, *node, *tmp;

	if (list == 0)
		return (NULL);
	curr = list;
	while (curr)
	{
		if (curr->express == NULL)
		{
			node = curr->express;
			for (tmp = list; tmp; tmp = tmp->next)
			{
				if (tmp->next == NULL)
				{
					printf("Value found between indexes [%lu] and [%lu]\n",
						   curr->index, tmp->index);
					break;
				}
			}
			break;
		}
		if (curr->express->n >= value)
		{
			node = curr->express;
			printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
			printf("Value found between indexes [%lu] and [%lu]\n",
				   curr->index, node->index);
			break;
		}
		curr = curr->express;
		printf("Value checked at index [%lu] = [%d]\n", curr->index, curr->n);
	}
	while (curr)
	{
		printf("Value checked at index [%lu] = [%d]\n", curr->index, curr->n);
		if (curr->n == value)
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}
