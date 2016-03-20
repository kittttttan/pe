#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Find the sum of all eleven primes
that are both truncatable from left to right and right to left.
"""

from primes import sieve

def pe37():
    """
    >>> pe37()
    [23, 37, 53, 73, 313, 317, 373, 797, 3137, 3797, 739397]
    """
    s = 0
    p0 = sieve(1000000)
    p = set(p0)
    p0 = set(p0[5:])
    t = []
    tl = 0
    for i in p0:
        i1 = i2 = str(i)
        f = True
        i1 = i1[:-1]
        while i1:
            if int(i1) in p:
                i1 = i1[:-1]
            else:
                f = False
                break
        if not f:
            continue
        i2 = i2[1:]
        while i2:
            if int(i2) in p:
                i2 = i2[1:]
            else:
                f = False
                break
        if f:
            t.append(i)
            # s += i
            tl += 1
            if tl >= 11:
                break
    return t
    # print(s)

if __name__ == "__main__":
    import doctest
    doctest.testmod()
