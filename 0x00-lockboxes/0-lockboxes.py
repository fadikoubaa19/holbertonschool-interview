#!/usr/bin/python3


def canUnlockAll(boxes):
    """
    lockboxes function
    """

    ln = len(boxes)
    bx = boxes[0]
    bloc1 = [False] + [True] * (ln - 1)
    for i in bx:
        if ((i < ln) and (bloc1[i] is True)):
            bloc1[i] = False
            bx.extend(boxes[i])
    return not any(bloc1)
