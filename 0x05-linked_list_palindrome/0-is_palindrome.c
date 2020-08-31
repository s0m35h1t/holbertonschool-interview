#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * rec_palindrome - Recursive function that fetch  list nodes
 * @head: double pointer of the  head node
 * @tail: double pointer of the tail node
 * Return: 1 if is a palindrome, otherwise 0
 */
int rec_palindrome(listint_t **head, listint_t *tail)
{
	if (tail == NULL)
		return (1);

	if (rec_palindrome(head, tail->next) && (*head)->n == tail->n)
	{
		*head = (*head)->next;
		return (1);
	}
    return (0);
}

/**
 * is_palindrome - Check linked list is a palindrome Or not
 * @head: double pointer of head node
 * Return: 1 if is a palindrome 0 otherwise
 */

int is_palindrome(listint_t **head)
{
	if (head == NULL && *head == NULL)
		return (1);
    return (rec_palindrome(head, *head));
}
