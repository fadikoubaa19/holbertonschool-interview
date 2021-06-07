#!/usr/bin/python3


def canUnlockAll(boxes):
    """lockboxes"""
    if (boxes is None):
        return (True)
    if (type(boxes) is list):
        my_list = {}
        keys = []
        my_list[0] = True
        for i in range(1, len(boxes)):
            my_list[i] = False
        if (len(boxes) > 0):
            keys.append(boxes[0])
        for i in keys:
            for j in i:
                my_list[j] = True
                i.remove(j)
                if j < len(boxes):
                    keys.append(boxes[j])
        if False in my_list.values():
            return (False)
        else:
            return (True)
    else:
        return (False)
