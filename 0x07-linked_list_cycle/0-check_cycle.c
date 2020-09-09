
#include "lists.h"

int check_cycle(listint_t *list)
{
	listint_t *loop_1, *loop_2;

	if (!list || list->next == NULL)
		return (0);

	loop_1 = list->next;
	loop_2 = list->next->next;

	while (loop_1 && loop_2 && loop_2->next)
	{
		if (loop_1 == loop_2->next)
			return (1);
		loop_1 = loop_1->next;
		loop_2 = loop_2->next->next;
	}
	return (0);
}
