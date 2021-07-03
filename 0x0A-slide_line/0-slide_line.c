#include "slide_line.h"

/**
 * swap - swaping btw two integers
 * @a: first pointer
 * @b: sec pointer
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * slide_left - slide an array to the left,
 * skip all zeros.
 * @line: The pointer.
 * @size: the size of array
 */
void slide_left(int *line, size_t size)
{
	size_t i, j = 0;

	for (i = 0; i < size && j < size; i++)
	{
		while (line[j] == 0 && j < size && j + 1 < size)
			j++;
		if (line[i] == 0)
			swap(&line[j], &line[i]);
		j++;
	}
}

/**
 * slide_right - swaping an array to the right,
 * skip all zeros
 * @line: the pointer.
 * @size: size of array
 */
void slide_right(int *line, size_t size)
{
	size_t i, j = size - 1;

	for (i = size - 1; (int) i >= 0 && (int) j >= 0; i--)
	{
		while (line[j] == 0 && (int) j > 0)
			j--;
		if (line[i] == 0)
			swap(&line[j], &line[i]);
		j--;
	}
}

/**
 * slide_line - merging and sliding all arrays
 * @line: the pointer
 * @size: size of array
 * @direction: function of slide left and right
 * Return: 1 mean success
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t i = 0;

	if (direction == SLIDE_LEFT)
	{
		slide_left(line, size);
		for (i = 0; i < size; i++)
		{
			if (line[i] == line[i + 1])
			{
				line[i] = line[i] + line[i + 1];
				line[i + 1] = 0;
			}
		}
		slide_left(line, size);
		return (1);
	} else if (direction == SLIDE_RIGHT)
	{
		slide_right(line, size);
		for (i = size - 1; (int) i >= 0; i--)
		{
			if (line[i] == line[i - 1])
			{
				line[i] = line[i] + line[i - 1];
				line[i - 1] = 0;
			}
		}
		slide_right(line, size);
		return (1);
	}
	return (0);
}
