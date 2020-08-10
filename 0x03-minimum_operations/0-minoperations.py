#!/usr/bin/python3
"""
function file
"""


def minOperations(n):
    """ min op """
    summ = 0
    it = 2
    while n > 1:
        if n % it == 0:
            summ += it
            n /= it
            while n % it == 0:
                summ += it
                n /= it
        it += 1
    return summ
