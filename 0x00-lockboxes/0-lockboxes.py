#!/usr/bin/python3
'Lockboxes'


def canUnlockAll(boxes):
    """method that determines if all the boxes can be opened
    Arguments:
        list of lists(boxes)
    key number of keys
    Returns:
    return true if all boxes opened else it's false
    """
    if (len(boxes) < 1 or type(boxes) is not list):
        return False

    open_box = [0]
    i = 0
    while i < len(boxes):
        if i >= len(open_box):
            return False
        if boxes[open_box[i]] is not None:
            for key in boxes[open_box[i]]:
                if key not in open_box and key < len(boxes):
                    open_box.append(key)
        i += 1
    if len(open_box) == len(boxes):
        return True
    else:
        return False
