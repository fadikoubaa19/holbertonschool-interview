#!/usr/bin/python3
""" task 0"""


def rotate_2d_matrix(matrix):
    """
    --- Function that reverse a matrix
    90 degre -------------------------

    """
    index = 0
    while index < len(matrix[0]):
        for j in range(index, len(matrix[0])):
            aux = matrix[index][j]
            matrix[index][j] = matrix[j][index]
            matrix[j][index] = aux
        index += 1
    for j in range(len(matrix[0])):
        matrix[j].reverse()
