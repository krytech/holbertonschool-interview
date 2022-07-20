#!/usr/bin/python3
""" N queens puzzle
"""
import sys


def is_NQueen(cell: list) -> bool:
    """ True if N queen, false if not.
    """
    row_num = len(cell) - 1
    diff = 0
    for i in range(0, row_num):
        diff = cell[i] - cell[row_num]
        if diff < 0:
            diff *= -1
        if diff == 0 or diff == row_num - i:
            return False
    return True


def solve_NQeens(dimension: int, row: int, cell: list, outcome: list):
    """ Return result of N queens recusrivley.
    """
    if row == dimension:
        print(outcome)
    else:
        for col in range(0, dimension):
            cell.append(col)
            outcome.append([row, col])
            if (is_NQueen(cell)):
                solve_NQeens(dimension, row + 1, cell, outcome)
            cell.pop()
            outcome.pop()


if len(sys.argv) != 2:
    print("Usage: nqueens N")
    exit(1)
try:
    N = int(sys.argv[1])
except BaseException:
    print("N must be a number")
    exit(1)

if N < 4:
    print("N must be at least 4")
    exit(1)
else:
    outcome = []
    cell = 0
    solve_NQeens(int(N), cell, [], outcome)
