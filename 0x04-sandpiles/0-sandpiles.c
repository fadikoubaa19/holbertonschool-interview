#include <stdio.h>
#include <stdlib.h>
#include "sandpiles.h"

/**
 * alt_print_grid - function to print the grid for holbertonschool
 * @grid1: grid 1
 */
void alt_print_grid(int grid1[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid1[i][j]);
		}
		printf("\n");
	}
}

/**
 * sandpiles_sum - sum of 2 sandpiles
 * @grid1: grid 2
 * @grid2: grid 2
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	add_grids(grid1, grid2);
	if (!is_stable(grid1))
		alt_print_grid(grid1);
	while (!is_stable(grid1))
	{
		topple(grid1);
		if (!is_stable(grid1))
			alt_print_grid(grid1);
	}
}

/**
 * is_stable - check if cell biger then 3
 * @grid1:grid1
 * Return: return 1
 */
int is_stable(int grid1[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * add_grids - adds grids
 * @grid1: grid1
 * @grid2: grid2
 */
void add_grids(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] = grid1[i][j] + grid2[i][j];
	}
}

/**
 * topple - remove cell
 * @grid1: grid
 */
void topple(int grid1[3][3])
{
	int grains[3][3];
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grains[i][j] = 0;
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{

				if ((i - 1 >= 0) && (i - 1 < 3))
					grains[i - 1][j]++;

				if ((i + 1 >= 0) && (i + 1 < 3))
					grains[i + 1][j]++;

				if ((j - 1 >= 0) && (j - 1 < 3))
					grains[i][j - 1]++;

				if ((j + 1 >= 0) && (j + 1 < 3))
					grains[i][j + 1]++;
				grid1[i][j] -= 4;
			}
		}
	}
	add_grids(grid1, grains);
}
