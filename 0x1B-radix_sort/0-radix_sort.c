#include "sort.h"
/**
 * csorting - function of radix sort
 * @array: array
 * @buff: buffer
 * @size: the size of data
 * @lsd: Less significant digit
 */
void csorting(int *array, int **buff, int size, int lsd)
{
	int x, j, length = 10, num;
	int par[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int par2[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (x = 0; x < size; x++)
	{
		num = array[x];
		for (j = 0; j < lsd; j++)
			if (j > 0)
				num = num / 10;
		num = num % 10;
		buff[num][par[num]] = array[x];
		par[num] += 1;
	}

	for (x = 0, j = 0; x < length; x++)
	{
		while (par[x] > 0)
		{
			array[j] = buff[x][par2[x]];
			par2[x] += 1, par[x] -= 1;
			j++;
		}
	}

	print_array(array, size);
}
/**
 * csort - radix sort function
 * @array: array
 * @size: the size of data
 * @lsd: Less significant digit
 */
void csort(int *array, int size, int lsd)
{
	int par[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int x, j, num, len = 10, **buff;

	for (x = 0; x < size; x++)
	{
		num = array[x];
		for (j = 0; j < lsd; j++)
			if (j > 0)
				num = num / 10;
		num = num % 10;
		par[num] += 1;
	}

	if (par[0] == size)
		return;

	buff = malloc(sizeof(int *) * 10);
	if (!buff)
		return;

	for (x = 0; x < len; x++)
		if (par[x] != 0)
			buff[x] = malloc(sizeof(int) * par[x]);

	csorting(array, buff, size, lsd);

	csort(array, size, lsd + 1);

	for (x = 0; x < len; x++)
		if (par[x] > 0)
			free(buff[x]);
	free(buff);
}
/**
 * radix_sort - array sorts with radix
 * @array: array
 * @size: the size of data
 */
void radix_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	csort(array, size, 1);
}
