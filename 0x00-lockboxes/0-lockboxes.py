#!/usr/bin/python3
""" boxes """


def canUnlockAll(boxes):
    """boxes"""
    s = {}
    vis = []
    i = 1
    for i, j in enumerate(boxes):
        s[i] = j
    return(check(vis, s, i))


def check(vis, s, i):
    """chech function"""
    inv = []
    if i not in vis:
        vis.append(i)
    for n in s[i]:
        if n not in vis:
            inv.append(n)
    for m in inv:
        check(vis, s, m)
    if len(inv) == 0:
        return(True)
    else:
        return(False)
