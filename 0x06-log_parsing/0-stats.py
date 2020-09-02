#!/usr/bin/python3
""" log parsing proj """
import sys
g = 0
file_s = 0
s = ["200", "301", "400", "401", "403", "404", "405", "500"]
zros = [0, 0, 0, 0, 0, 0, 0, 0]
try:
    for l in sys.stdin:
        g += 1
        linesp = l.split(" ")
        if len(linesp) > 2:
            file_s += int(linesp[-1])
            status = linesp[-2]
        if status in s:
            j = s.index(status)
            zros[j] += 1
        if (g % 10 == 0):
            print("size = {}".format(file_s))
            for z in range(len(s)):
                if zros[z] > 0:
                    print("{}: {}".format(s[z], zros[z]))
except KeyboardInterrupt:
    pass
finally:
    for z in range(len(s)):
        if zros[z] > 0:
            print("{}: {}".format(s[z], zros[z]))
