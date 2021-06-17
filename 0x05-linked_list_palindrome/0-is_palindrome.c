#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * listint_len - print the element of all lists
 * @h:var
 * Return: return integer
 */
int listint_len(listint_t **h)
{
    int in;
    listint_t *current = *h;
    in = 0;
    while (current != NULL)
    {
        in++;
        current = current->next;
    }
    return (in);
}
/**
 * is_palindrome - prints the all element of a list
 * @head: The pointer
 * Return: return integer
 */
int is_palindrome(listint_t **head)
{
    int l = listint_len(head);
    int arr[4000];
    int j;
    listint_t *nd = *head;
    while (nd)
    {
        for (j = 0; j < l; j++)
        {
            arr[j] = nd->n;
            nd = nd->next;
        }
    }
    for (j = 0; j <= l / 2 && l != 0; j++)
    {
        if (arr[j] != arr[l - j - 1])
        {
            return (0);
        }
    }
    return (1);
}
