#!/usr/bin/python3
"""calculates the fewest number of operations needed
to result in exactly n H characters in the file."""


def minOperations(n):
    """Calculate fewest nbr of opertions needed to result in n H chars
    Args:
        n (int): number of Chars
    Returns:
        (int): fewest nbr of opertions
    """
    if n <= 1:
        return 0
    for i in range(2, n + 1):
        if n % i == 0:
            return minOperations(n // i) + i
