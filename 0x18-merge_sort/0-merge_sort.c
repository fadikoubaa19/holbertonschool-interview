#include "sort.h"

/**
 * merges - this task is done for holbertonschool
 * @array: array of table
 * @under:var
 * @begin: var
 * @mid: var
 * @end: var
 * Return: zero
 */
void merges(int *array, int *under, int begin, int mid, int end)
{
	int a, b, i;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + begin, mid - begin);
	printf("[right]: ");
	print_array(array + mid, end - mid);

	for (a = begin, b = mid, i = 0; a < mid && b < end; i++)
		if (array[a] < array[b])
			under[i] = array[a++];
		else
			under[i] = array[b++];
	while (a < mid)
		under[i++] = array[a++];
	while (b < end)
		under[i++] = array[b++];
	for (a = begin, i = 0; a < end; a++)
		array[a] = under[i++];

	printf("[Done]: ");
	print_array(array + begin, end - begin);
}

/**
 * trees - split the table
 * @array: array of the table
 * @under: var
 * @begin: var
 * @end: var
 * Return: zero
 */
void trees(int begin, int end, int *array, int *under)
{
	int mid, sizes;

	sizes = end - begin + 1;
	if (sizes > 2)
	{
		mid = (end - begin) / 2 + begin;
		trees(begin, mid, array, under);
		trees(mid, end, array, under);
		merges(array, under, begin, mid, end);
	};
}

/**
 * merge_sort - function for holbertonschool
 * @array: array of table
 * @size: var
 * Return: zero
 */
void merge_sort(int *array, size_t size)
{
	int *under;

	if (size < 2 || array == NULL)
		return;
	under = malloc(sizeof(int) * size);
	trees(0, size, array, under);
	free(under);
}
