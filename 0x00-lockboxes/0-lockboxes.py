#!/usr/bin/python3
"""Function to determine if all boxes can be opened"""


def canUnlockAll(boxes):
    """Returns True if all boxes can be opened, otherwise False"""
    test = {}
    i = 0

    for box in boxes:
        if len(box) == 0 or i == 0:
            test[i] = -1
        for key in box:
            if key < len(boxes) and key != i:
                test[key] = key
        if len(test) == len(boxes):
            return True
        i += 1
    return False
