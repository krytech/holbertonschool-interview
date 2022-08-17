#!/usr/bin/python3
"""
Calculates how many square units of water will be retained after it rains
given the height of walls.
"""


def rain(walls):
    """
    Calculates how many units of water will be caught based on wall height.
    """
    water_total = 0

    for i in range(1, len(walls) - 1):

        left = walls[i]
        # Find max height on left
        for j in range(i):
            left = max(left, walls[j])

        right = walls[i]
        # Find max heigh on right
        for j in range(i + 1, len(walls)):
            right = max(right, walls[j])

        water_total += min(left, right) - walls[i]

    return water_total
