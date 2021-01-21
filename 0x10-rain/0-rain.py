#!/usr/bin/python3
""" rain fn """


def rain(walls):
    """ Function that calculates how much
        water will be retained after it rains """
    if not walls:
        return 0
    if len(walls) <= 2:
        return 0
    rn = 0
    for r in range(1, len(walls) - 1):
        left = max(walls[:r])
        right = max(walls[r + 1:])
        minn = min(left, right)
        if walls[r] < minn:
            rn += minn - walls[r]
    return rn
