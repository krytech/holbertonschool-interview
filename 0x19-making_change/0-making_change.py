#!/usr/bin/python3
"""
Given a pile of coins of different values, determine the fewest
number of coins needed to meet a given amount total.
"""


def makeChange(coins, total):
    """ Returns the fewest number of coins needed to meet total.
    """
    ph_value = 0
    coins.sort(reverse=True)

    if total < 0:
        return 0

    for coin in coins:
        if total % coin <= total:
            ph_value += total // coin
            total = total % coin

    return ph_value if total == 0 else -1
