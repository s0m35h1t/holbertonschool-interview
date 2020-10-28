#!/usr/bin/python3

import sys


def solve(row, col):
    svr = [[]]
    for q in range(row):
        svr = place_queen(q, col, svr)
    return svr


def place_queen(q, col, prev_solver):
    solver_queen = []
    for arr in prev_solver:
        for x in range(col):
            if is_safe(q, x, arr):
                solver_queen.append(arr + [x])
    return solver_queen


def is_safe(q, x, arr):
    if x in arr:
        return (False)
    else:
        return all(abs(arr[col] - x) != q - col
                   for col in range(q))


if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    if sys.argv[1].isdigit():
        queen = int(sys.argv[1])
    else:
        print("N must be a number")
        sys.exit(1)
    if queen < 4:
        print("N must be at least 4")
        sys.exit(1)

    solver = solve(queen, queen)
    for arr in solver:
        cl = []
        for q, x in enumerate(arr):
            cl.append([q, x])
        print(cl)
