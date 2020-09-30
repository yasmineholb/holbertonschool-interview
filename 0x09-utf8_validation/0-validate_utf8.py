#!/usr/bin/python3
"""validUTF8"""


def validUTF8(data):
    """ Function that determines if a given data
        set represents a valid UTF-8 encoding"""
    bin1 = 1 << 6
    nb = 0
    for dt in data:
        bin2 = 1 << 7
        if nb == 0:
            while dt & bin2:
                nb += 1
                bin2 = bin2 >> 1
            if nb == 0:
                continue
            """ if (nb >= 4) or (nb == 1) """
            if (nb > 4) or (nb == 1):
                return False
        else:
            if not (dt & bin2 and not (dt & bin1)):
                return False
        nb -= 1
    return nb == 0
