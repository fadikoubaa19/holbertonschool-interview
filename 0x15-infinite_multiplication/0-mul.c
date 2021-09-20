#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * pt - prints the error message
 *
 * Return: print error and the new line
 */
void pt(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(98);
}
/**
 * check - checks if all the characters are digits.
 * @arg: arg
 * Return: 0 or 1
 */
int check(char **arg)
{
	int i, j;

	for (i = 1; i <= 2; i++)
		for (j = 0; arg[i][j]; j++)
		{
			if (arg[i][j] < '0' || arg[i][j] > '9')
				return (0);
		}
	return (1);
}
/**
 * memory- initializes memory spaces with zero.
 * @m1: the first string.
 * @s: the sec string that's conc into the first one
 *
 * Return: return the conc string
 */
void *memory(unsigned int m1, unsigned int s)
{
	unsigned int i;
	char *fi;

	if (m1 == 0 || s == 0)
		return (NULL);

	fi = malloc(m1 * s);
	if (fi == NULL)
		return (NULL);

	for (i = 0; i < (m1 * s); i++)
		*(fi + i) = 0;

	return (fi);
}
/**
 * main- mul a & b
 * @argc: arg
 * @argv: arg
 * Return: c or pt.
 */

int main(int argc, char **argv)
{
	int i, j, carry, len, len_s1 = 0, len_s2 = 0;
	char *s1 = *(argv + 1), *s2 = *(argv + 2);
	int *a, *b, *c;

	if (argc != 3 || check(argv) != 1)
		pt();
	if (*s1 == '0' || *s2 == '0')
		_putchar('0');
	while (*(*(argv + 1) + len_s1))
		len_s1++;
	while (*(*(argv + 2) + len_s2))
		len_s2++;
	len = len_s1 + len_s2 + 1;
	a = (int *) malloc(len_s1 * sizeof(int));
	b = (int *) malloc(len_s2 * sizeof(int));
	c = memory(len, sizeof(int));
	if (a == NULL || b == NULL || c == NULL)
		pt();
	for (i = len_s1 - 1, j = 0; i >= 0; i--, j++)
		*(a + j) = *(s1 + i) - '0';
	for (i = len_s2 - 1, j = 0; i >= 0; i--, j++)
		*(b + j) = *(s2 + i) - '0';
	for (i = 0; i < len_s2; i++)
		for (j = 0; j < len_s1; j++)
			*(c + i + j) = *(c + i + j) + *(b + i) * *(a + j);
	for (i = 0; i < len_s1 + len_s2; i++)
	{
		carry = *(c + i) / 10, *(c + i) = *(c + i) % 10;
		*(c + i + 1) = *(c + i + 1) + carry; }
	for (i = len_s1 + len_s2; i >= 0; i--)
		if (*(c + i) > 0)
			break;
	for (; i >= 0; i--)
		_putchar(*(c + i) + '0');
	_putchar('\n');
	free(a), free(b), free(c);
	return (0);
}
