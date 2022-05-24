#!/usr/bin/python3

"""task 0"""


def island_perimeter(grid):
    """island_perimeter"""

    env = 0
    for x in range(len(grid)):
        for y in range(len(grid[x])):
            if grid[x][y] == 1:
                if y + 1 < len(grid[0]) and grid[x][y + 1] == 0:
                    env = env + 1
                if y == len(grid[0]) - 1:
                    env = env + 1
                if grid[x][y - 1] == 0 and y > 0:
                    env = env + 1
                if y == 0:
                    env = env + 1
                if grid[x - 1][y] == 0 and x > 0:
                    env = env + 1
                if x == 0:
                    env = env + 1
                if x + 1 < len(grid) and grid[x + 1][y] == 0:
                    env = env + 1
                if x == len(grid) - 1:
                    env += 1
    return env
