#!/usr/bin/python3
""" task 0 """


def makeChange(coins, total):
    """function to determine the fewest number of coin"""

    nc = 0
    bg = 0
    if total <= 0:
        return 0

    coins = sorted(coins, reverse=True)

    for ele in coins:
        while bg + ele <= total:
            bg += ele
            nc = nc + 1
        if bg == total:
            return nc
    return -1
