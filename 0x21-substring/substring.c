#include "substring.h"


/**
* find_substring - find the substrings
* @s: string
* @words: words
* @nb_words: number of words
* @n: var
* Return: null or the array
*/

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int s1, s2, x, i = 0, j;
	int *obj, *exist;

	if (!s)
		return ('\0');

	*n = 0;
	s1 = strlen(s);
	s2 = strlen(words[0]);

	exist = malloc(nb_words * sizeof(int));
	obj = malloc(s1 * sizeof(int));

	while (i <= s1 - nb_words * s2)
	{
		for (x = 0; x < nb_words; x++)
			exist[x] = 0;
		for (x = 0; x < nb_words; x++)
		{

			for (j = 0; j < nb_words; j++)
			{
				if (exist[j] == 0 && strncmp(s + i + x * s2, words[j], s2) == 0)
				{

					exist[j] = 1;

					break;
				}
			}
			if (j == nb_words)
				break;
		}
		if (x == nb_words)
			obj[(*n)++] = i;
		i++;
	}

	free(exist);
	return (obj);
}
