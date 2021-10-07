#!/usr/bin/python3
"""
"""


def rain(walls):
    """Calculates how much water will be retained after it rains.
    """
    if walls is None or walls == []:
        return 0
    if len(walls) == 1:
        return 0

    a = len(walls)
    l_side = [0] * a

    r_side = [0] * a
    water = 0

    l_side[0] = walls[0]
    for x in range(1, a):
        l_side[x] = max(l_side[x - 1], walls[x])

    r_side[a - 1] = walls[a - 1]
    for x in range(a - 2, -1, -1):
        r_side[x] = max(r_side[x + 1], walls[x])

    for x in range(0, a):
        water += min(l_side[x], r_side[x]) - walls[x]

    return water
