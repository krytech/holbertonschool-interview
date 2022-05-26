#include "lists.h"

/**
* palindrome_check - compares the 1st and last node, then moves to middle
* @left: keeps track of left side of list
* @right: keeps track of nodes on right
* Return: 1 if it is a palindrome, 0 if not
*/
int palindrome_check(listint_t **left, listint_t *right)
{
	int result;

	/* empty list */
	if (right == NULL)
		return (1);

	/* checks values at left and right then 2nd node & 2nd to last, etc */
	result = palindrome_check(left, right->next) && (*left)->n == right->n;

	/* points left to next node */
	*left = (*left)->next;

	return (result);
}

/**
* is_palindrome - checks if the linked list is a palindrome
* @head: double pointer to head of list
* Return: 1 if it is a palindrome, 0 if not
*/
int is_palindrome(listint_t **head)
{
	listint_t *deref = *head;

	return (palindrome_check(&deref, deref));
}
