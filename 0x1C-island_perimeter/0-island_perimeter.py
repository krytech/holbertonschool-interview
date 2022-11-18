#!/usr/bin/python3
"""
Function that returns the perimeter of the island
described in grid.
"""


def island_perimeter(grid):
    """
    Returns the perimeter of the island described in grid
    """
    result = 0

    for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == 1:
                    result += 4
                    if i - 1 >= 0 and grid[i - 1][j] == 1:
                        result -= 2
                    if j - 1 >= 0 and grid[i][j - 1] == 1:
                        result -= 2

    return result
