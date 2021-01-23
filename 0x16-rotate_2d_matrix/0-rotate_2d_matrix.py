#!/usr/bin/python3
"""Rotate a matrix"""


def rotate_2d_matrix(matrix):
    """Rotate a matrix
    Args:
        Matrix nXn matrix to rotate
    Retruns:
        None
    """
    L = len(matrix[0])
    for i in range(L // 2):
        for j in range(i, L - i - 1):
            tmp = matrix[i][j]
            matrix[i][j] = matrix[L - 1 - j][i]
            matrix[L - 1 - j][i] = matrix[L - 1 - i][L - 1 - j]
            matrix[L - 1 - i][L - 1 - j] = matrix[j][L - 1 - i]
            matrix[j][L - 1 - i] = tmp
