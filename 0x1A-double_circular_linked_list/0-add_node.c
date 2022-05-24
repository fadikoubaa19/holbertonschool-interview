#include "list.h"
/**
 * add_node_end - new node in the end.
 * @list: modify the list
 * @str: copy a string into a new node
 *
 * Return: Null or fail
 */
List *add_node_end(List **list, char *str)
{
	List *node;

	node = malloc(sizeof(*node));
	if (!node)
		return ('\0');
	node->str = strdup(str);
	if (!node->str)
		return ('\0');

	if (!*list)
	{
		*list = node;
		(*list)->next = (*list)->prev = node;
	}
	else
	{
		node->prev = (*list)->prev, node->next = *list;
		(*list)->prev = (*list)->prev->next = node;
	}
	return (node);
}
/**
 * add_node_begin - Add a node in the begining
 * a double circular linked list
 * @list: modify the list
 * @str: copy a string into a new node
 *
 * Return: NULL or fail
 */
List *add_node_begin(List **list, char *str)
{
	List *node;

	node = malloc(sizeof(*node));
	if (!node)
		return ('\0');
	node->str = strdup(str);
	if (!node->str)
		return ('\0');

	if (!*list)
	{
		*list = node;
		(*list)->next = (*list)->prev = node;
	}
	else
	{
		node->prev = (*list)->prev, node->next = *list;
		(*list)->prev = (*list)->prev->next = node;
	}
	*list = node;
	return (node);
}

