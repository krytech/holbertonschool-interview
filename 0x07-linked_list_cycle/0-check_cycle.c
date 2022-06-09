#include "lists.h"

/**
 * check_cycle - checks if linkedlist has a cycle in it
 * @list: pointer to the LL
 * Return: 1 if there is a cycle, 0 if not
 */
int check_cycle(listint_t *list)
{
	listint_t *slow = list;
	listint_t *fast = list;

	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
			return (1);
	}
	return (0);
}
