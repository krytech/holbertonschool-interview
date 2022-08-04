#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 * Return: a pointer on the first node where value is located, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	int left, right;
	skiplist_t *start;

	if (!list)
		return (NULL);

	while (list->next && list->n < value)
	{
		start = list;
		if (list->express)
		{
			list = list->express;
			printf("Value checked at index [%i] = [%d]\n", (int)list->index, list->n);
		}
		while (!list->express && list->next)
			list = list->next;
	}
	left = start->index;
	right = list->index;
	printf("Value found between indexes [%d] and [%d]\n", left, right);

	while (start && left <= right)
	{
		printf("Value checked at index [%d] = [%d]\n", left, start->n);
		if (start->n == value)
			return (start);
		left++;
		start = start->next;
	}
	return (NULL);
}
