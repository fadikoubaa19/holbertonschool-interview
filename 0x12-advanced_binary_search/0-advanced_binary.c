#include "search_algos.h"
/**
 * search - for holbertonschool
 * @array: var
 * @left: var
 * @right: var
 * @value: the value
 * Return: -1
 */
int search(int *array, size_t left, size_t right, int value)
{
	int midlle;
	size_t i;

	midlle = ((right - left) / 2) + left;

	printf("Searching in array: ");

	for (i = left; i <= right; i++)
	{
		if (i < right)
			printf("%i, ", array[i]);
		else
			printf("%i\n", array[i]);
	}

	if (array[midlle] == value && array[midlle - 1] != value)
		return (midlle);

	if (left == right)
		return (-1);

	if (array[midlle] >= value)
		return (search(array, left, midlle, value));

	if (array[midlle] < value)
		return (search(array, midlle + 1, right, value));

	return (-1);
}
/**
 * advanced_binary - for holbertonschool
 * @array: var
 * @size: var
 * @value: var
 * Return: -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t l = 0;
	size_t r = size - 1;

	if (array == NULL)
		return (-1);

	return (search(array, l, r, value));
}
