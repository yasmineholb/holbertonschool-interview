#!/usr/bin/python3
""" nqueens """
import sys


com = sys.argv[1]
if len(sys.argv) != 2:
    print("Usage: nqueens N")
if type(int(com)) is not int:
    print("N must be a number")
    exit(1)
if int(sys.argv[1]) < 4:
    print("N must be at least 4")
    exit(1)
p = []
for i in range(int(com)):
    p1 = []
    for j in range(int(com)):
        p1.append(0)
    p.append(p1)
print(p)
    
def isSafe(board, row, col):
    """ men geeks for geeks"""
    for i in range(col): 
        if board[row][i] == 1: 
            return False
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)): 
        if board[i][j] == 1: 
            return False
    for i, j in zip(range(row, N, 1), range(col, -1, -1)): 
        if board[i][j] == 1: 
            return False
    return True

