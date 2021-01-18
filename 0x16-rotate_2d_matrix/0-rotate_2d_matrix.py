#!/usr/bin/python3
""" Function for rotation """


def rotate_2d_matrix(matrix):
    """ Function that rotates a matrix
        90 degrees clockwise """
    N = len(matrix[0])
    for i in range(N // 2):
        for j in range(i, N - i - 1):
            temp = matrix[i][j]
            matrix[i][j] = matrix[N - 1 - j][i]
            matrix[N - 1 - j][i] = matrix[N - 1 - i][N - 1 - j]
            matrix[N - 1 - i][N - 1 - j] = matrix[j][N - 1 - i]
            matrix[j][N - 1 - i] = temp


def printMat(matrix):
    """ Function that prints the matrix """
    N = len(matrix[0])
    for i in range(N):
        for j in range(N):
            print(matrix[i][j], end=" ")
        print()
