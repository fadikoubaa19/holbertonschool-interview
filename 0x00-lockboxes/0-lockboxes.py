#!/usr/bin/python3


def canUnlockAll(boxes):
    """lockboxes"""
    if boxes[0] == [] or not isinstance(boxes, list):
        return False

    opens = [0]
    for index, box in enumerate(boxes):
        for k in box:
            if k not in opens and k in range(0, len(boxes)) and k != index:
                opens.append(k)
    return len(opens) == len(boxes)
