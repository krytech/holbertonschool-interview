#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - inserts a node into a sorted linked list
 * @head: head of the sorted linked list
 * @number: number to insert into the list
 * Return: the address of the new node, otherwise NULL if failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node, *tmp, *ph;

	if (!head)
		return (NULL);

	/* malloc a new node and set the value */
	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);
	new_node->n = number;

	/* insert at begining */
	if ((!*head) || number < (*head)->n)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	/* placeholder node, go through the list */
	tmp = *head;
	while (tmp->next != NULL && tmp->next->n < number)
		tmp = tmp->next;
	if (tmp->next == NULL) /* if last position in the list */
	{
		tmp->next = new_node;
		new_node->next = NULL;
		return (new_node);
	}
	ph = tmp->next;
	tmp->next = new_node;
	new_node->next = ph;

	return (new_node);
}
