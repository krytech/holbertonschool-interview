#!/usr/bin/python3
"""
Calculates the fewest number of operations needed to result in
exactly 'n' 'H' characters in the file.
"""


def minOperations(n):
    """Returns an integer with the fewest number of possible operations"""
    if n <= 0 or type(n) != int:
        return 0
    total_ops = 0
    i = 2
    while i <= n:
        if n % i == 0:
            total_ops += i
            n /= i
        else:
            i += 1
    return total_ops
