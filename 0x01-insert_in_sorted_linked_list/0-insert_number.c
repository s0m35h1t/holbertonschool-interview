#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * insert_node - inserts a node into a sorted singly linked list
 * @head: double pointer to head of linked list
 * @number: integer to insert into list
 * Return: address of new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new = malloc(sizeof(listint_t)), *i;

	if (!head || !new)
		return (NULL);

	new->next = NULL;
	new->n = number;
	if (!*head)
	{
		*head = new;
		return (new);
	}
	i = *head;
	if (i->n > number)
	{
		new->next = i;
		*head = new;
		return (new);
	}
	while (i->next != NULL && i->next->n < number)
		i = i->next;
	new->next = i->next;
	i->next = new;
	return (new);
}
