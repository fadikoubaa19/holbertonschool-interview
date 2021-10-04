#include "lists.h"
/**
*  find_listint_loop  - singly linked list
* @head: integer
* Return: listint_t
**/
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *a, *i;

	if (!head || !(head->next))
		return ('\0');

	a = head->next;
	i = head->next->next;

	while (i && i->next)
	{
		if (a == i)
			break;
		a = a->next;
		i = i->next->next;
	}

	if (a != i)
		return ('\0');

	a = head;
	while (a != i)
	{
		a = a->next;
		i = i->next;
	}

	return (a);
}
