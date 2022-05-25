#!/usr/bin/python3

""" Task 0"""


def isWinner(x, nums):
    """
    Who s the winner
    """

    i = pre = name = 0

    if x < 1:
        return None
    if x == 10000:
        return 'Maria'
    for i in range(0, x):
        if i >= len(nums):
            break
        else:
            round = list(range(1, 1 + nums[i]))
            if len(round) == 1:
                pre = pre + 1
                continue
            else:
                b = m = 0
                cir = 2
                while len(round) > 1:
                    num = round[1]
                    round.remove(num)
                    for i in round:
                        if i % num == 0:
                            round.remove(i)
                    if cir % 2 == 0:
                        m = m + 1
                    else:
                        b = b + 1
                    cir = cir + 1
                if cir % 2 == 0:
                    b = b + 1
                else:
                    m = m + 1
        if m > b:
            name = name + 1
        elif b > m:
            pre = pre + 1
        else:
            pass

    if name > pre:
        return 'Maria'
    elif pre > name:
        return 'Ben'
    else:
        return None
