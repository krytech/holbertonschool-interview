#include "sandpiles.h"
#include <stdio.h>

/**
 * stable_check - checks if the grid is stable, <4
 * @grid: 3x3 grid
 * Return: 1 if stable, 0 if not
 */
int stable_check(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				return (0);
			}
		}
	}
	return (1);
}

/**
 * print_grid - prints the 3x3 grid
 * @grid: 3x3 grid
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * sandpiles_sum - calculates the addition of two 3x3 grids
 * @grid1: first 3x3 grid
 * @grid2: second 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	int grid_tmp[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}
	while (!stable_check(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					grid_tmp[i][j] -= 4;
					if (i > 0)
						grid_tmp[i - 1][j] += 1;
					if (i < 2)
						grid_tmp[i + 1][j] += 1;
					if (j > 0)
						grid_tmp[i][j - 1] += 1;
					if (j < 2)
						grid_tmp[i][j + 1] += 1;
				}
			}
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
			{
				grid1[i][j] += grid_tmp[i][j];
				grid_tmp[i][j] = 0;
			}
	}
}
