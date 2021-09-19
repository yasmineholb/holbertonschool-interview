#!/usr/bin/python3
""" Prime Game """


def isWinner(x, nums):
    """ Prime game that returns the name
        of the player that won the most rounds """
    if not nums or x < 1:
        return None
    nm = max(nums)
    ply = [True for _ in range(max(nm + 1, 2))]
    for i in range(2, int(pow(nm, 0.5)) + 1):
        if not ply[i]:
            continue
        for j in range(i * i, nm + 1, i):
            ply[j] = False
    ply[0] = ply[1] = False
    c = 0
    for i in range(len(ply)):
        if ply[i]:
            c += 1
        ply[i] = c
    ply1 = 0
    for nm in nums:
        ply1 += ply[nm] % 2 == 1
    if ply1 * 2 == len(nums):
        return None
    if ply1 * 2 < len(nums):
        return "Ben"
    return "Maria"
