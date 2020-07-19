#!/usr/bin/python3
""" boxes """


def tests(boxes):
    """ function """
    cles = []
    b = 1
    if boxes == [[]]:
        return b
    elif boxes == []:
        return 0
    elif boxes[0] == [] or boxes[0] == [0]:
        return 0
    else:
        for i in range(len(boxes)):
            for j in range(len(boxes[i])):
                cles.append(boxes[i][j])
        cles = set(cles)
        if 0 in cles:
            cles.pop()
        cles = list(cles)
        if max(cles) > len(boxes)-1:
            b = 0
        if len(cles) < len(boxes)-1:
            b = 0
        return(b)


def canUnlockAll(boxes):
    """ function"""
    s = {}
    vis = []
    i = 1
    b = tests(boxes)
    if b == 0:
        return False
    else:
        for i, j in enumerate(boxes):
            s[i] = j
    return(check(vis, s, i))


def check(vis, s, i):
    """function """
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
