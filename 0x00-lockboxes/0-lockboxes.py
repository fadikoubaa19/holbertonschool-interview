#!/usr/bin/python3


def canUnlockAll(boxes):
    """
    lockboxes function
    """

    n = len(boxes)
    bx = boxes[0]
    bloc1 = [False] + [True] * (n - 1)
    for i in bx:
        if ((i < n) and (bloc1[i] is True)):
            bloc1[i] = False
            bx.extend(boxes[i])
    return not any(bloc1)
