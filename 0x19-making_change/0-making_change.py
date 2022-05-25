#!/usr/bin/python3
""" task 0 """


def makeChange(coins, total):
    """function to determine the fewest number of coin"""

    cal = 0
    coins = sorted(coins, reverse=True)
    for ele in coins:
        if total or ele != 0:
            cal += total // ele
            total = total % ele
    if total == 0:
        return cal
    else:
        return -1
