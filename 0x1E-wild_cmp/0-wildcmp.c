#include "holberton.h"
#include <stdio.h>

/**
 * wildcmp - compares two strings
 * @s1: string number 1
 * @s2: string number 2
 * Return: 1 or zero
 */
int wildcmp(char *s1, char *s2)
{
	if (*s2 == '*')
		return (wildcmp(s1, s2 + 1) || wildcmp(s1 + 1, s2));
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));
	return (0);
}
