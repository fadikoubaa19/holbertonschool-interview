#!/usr/bin/python
# -*- coding: utf-8 -*-

"""pascal triangle"""


def pascal_triangle(n):
    """calculate rows"""

    list = [[1]]
    for x in range(n - 1):
        list += [[1] + [list[-1][y] + list[-1][y + 1] for y in
                 range(len(list[-1]) - 1)] + [1]]
    return (list if n > 0 else [])
