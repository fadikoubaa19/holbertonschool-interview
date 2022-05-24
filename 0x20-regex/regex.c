#include <stdio.h>
#include <string.h>

#include "regex.h"

/**
 * regex_match - checking patt
 * @str: string
 * @pattern: compared pattern
 * Return: 1 or zero
 */
int regex_match(char const *str, char const *pattern)
{
		int s1 = '\0', s2 = '\0';

	if (!str || !pattern)
		return (0);

	s1 = *str && (*str == *pattern || *pattern == '.');
	s2 = *(pattern + 1) == '*';

	if (!*str && !s2)
		return (*pattern ? 0 : 1);
	if (s1 && s2)
		return (regex_match(str + 1, pattern) || regex_match(str, pattern + 2));
	else if (s1 && !s2)
		return (regex_match(str + 1, pattern + 1));
	else if (s2)
		return (regex_match(str, pattern + 2));

	return (0);
}
