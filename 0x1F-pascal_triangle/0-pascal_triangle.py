#!/usr/bin/python3
""" triangle fn """

def pascal_triangle(n):
    """ Function that returns a list of lists
        of integers representing the Pascal’s
        triangle of n """
    s = []
    if n == 1:
        return [1]
    else:
        for i in range(n):
            p = [1]
            if s:
                last = s[-1]
                p.extend([sum(pair) for pair in zip(last, last[1:])])
                p.append(1)
            s.append(p)
    return(s)
                                                

