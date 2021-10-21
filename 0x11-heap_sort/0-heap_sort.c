#include "sort.h"
/**
 * heap_modify - done for holbertonschool
 * @array: var
 * @size: var
 * @n: var
 * @i: int
 * Return: zero or noth
 */
void heap_modify(int *array, int n, int i, size_t size)
{
	int largest, left, right;
	int xio;

	largest = i;
	left = 2 * i + 1;
	right = 2 * i + 2;
	if (left < n && array[left] > array[largest])
		largest = left;

	if (right < n && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		xio = array[largest];
		array[largest] = array[i];
		array[i] = xio;
		print_array(array, size);
		heap_modify(array, n, largest, size);
	}
}


/**
 * heap_sort - for holbertonschool
 * @array: var
 * @size: var
 * Return: zero or noth
 */
void heap_sort(int *array, size_t size)
{
	register int i;
	int xio;

	if (!array || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		heap_modify(array, size, i, size);

	for (i = size - 1; i >= 0; i--)
	{
		xio = array[i];
		array[i] = array[0];
		array[0] = xio;
		if (i != 0)
			print_array(array, size);
		heap_modify(array, i, 0, size);
	}
}
