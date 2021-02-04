
#include "lists.h"

/**
 * find_listint_loop - checks a loop  in linked lsit
 * @head: linked list to check
 * Return: 0 if no loop, 1 if loop
 */
listint_t *find_listint_loop(listint_t *head)
{
    listint_t *fast, *slow;

    if (head == NULL)
        return (0);
    fast = slow = head;
    do
    {
        fast = fast->next;
        if (fast == NULL)
            return (NULL);
        fast = fast->next;
        if (fast == NULL)
            return (NULL);
        slow = slow->next;
    } while (fast != slow);

    fast = head;
    for (; fast != slow;)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return (fast);
}
