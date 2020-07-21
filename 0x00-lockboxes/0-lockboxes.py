#!/usr/bin/python3
"""Lockboxes - Function that determines if all the boxes can be opened"""


def canUnlockAll(boxes):
    """check if all boxes can be opened
    Args:
        boxes (list): Boxes list
    Returns:
        (bool): True if all boxes can be opened otherwise False
    """
    checked = [False if i != 0 else True for i in range(len(boxes))]
    _s = [0]
    while len(_s):
        for box in boxes[_s.pop(0)]:
            if type(box) is int:
                if box >= 0 and box < len(boxes) and not checked[box]:
                    checked[box] = True
                    _s.append(box)
    return all(checked)
