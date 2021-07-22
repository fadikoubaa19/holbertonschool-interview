#!/usr/bin/python3
"""nqueens function """

import sys


if len(sys.argv) != 2:
    print("Usage: nqueens N")
    exit(1)
try:
    board = int(sys.argv[1])
except ValueError:
    print("N must be a number")
    exit(1)
if board < 4:
    print("N must be at least 4")
    exit(1)


def chest(board, place1, solders):
    """function of nqueens"""
    for x in range(board):
        col = 0
        for quen in solders:
            if x == quen[1]:
                col = 1
                break
            if place1 - x == quen[0] - quen[1]:
                col = 1
                break
            if x - quen[1] == quen[0] - place1:
                col = 1
                break
        if col == 0:
            solders.append([place1, x])
            if place1 != board - 1:
                chest(board, place1 + 1, solders)
            else:
                print(solders)
            del solders[-1]


chest(board, 0, [])
