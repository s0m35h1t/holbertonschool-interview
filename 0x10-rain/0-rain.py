#!/usr/bin/python3
"""
Rain
"""


def rain(walls):
    """calculate how much water will be
    retained after rain
    Args:
        walls is a list of non-negative integers.
    Retruns:
        Integer indicating total amount of rainwater retained
        Or 0.
    """
    if len(walls) == 0:
        return 0

    water, l = 0, len(walls)
    for n in range(l):
        left = walls[n]
        for i in range(n):
            left = max(left, walls[i])
        right = walls[n]
        for i in range(n + 1, l):
            right = max(right, walls[i])

        water = water + min(left, right) - walls[n]

    return water
