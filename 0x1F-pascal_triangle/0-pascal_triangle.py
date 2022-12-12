#!/usr/bin/python3
""" Pascal's Triangle """


def pascal_triangle(n):
    """
    Returns a list of lists of integers representing the
    Pascal's triangle of n
    """
    list_p = []

    if n <= 0:
        return list_p

    list_p = [[1]]
    if n == 1:
        return list_p

    for row in range(1, n):
        left = -1
        right = 0
        listInt = []
        for column in range(row+1):
            integer = 0
            if left > -1:
                integer += list_p[row - 1][left]
            if right < row:
                integer += list_p[row - 1][right]
            left += 1
            right += 1
            listInt.append(integer)
        list_p.append(listInt)

    return list_p
