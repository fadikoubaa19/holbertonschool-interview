#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * insert_node -  inserts a number into a sorted singly linked list.
 * @head: pointer
 * @number: var
 * Return: 0
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *in1, *temp;
	listint_t *new_list;

	in1 = temp = *head;
	if (head == NULL)
		return (NULL);
	new_list = malloc(sizeof(listint_t));
	if (new_list == NULL)
		return (NULL);
	new_list->next = NULL;
	new_list->n = number;
	if (!*head)
	{
		new_list->next = NULL;
		*head = new_list;
		return (new_list);
	}
	if ((*head)->n >= new_list->n)
	{
		new_list->next = *head;
		*head = new_list;
		return (new_list);
	}
	while (temp && temp->n < number)
	{
		in1 = temp;
		temp = temp->next;
	}
	new_list->next = temp;
	in1->next = new_list;
	return (new_list);
}
