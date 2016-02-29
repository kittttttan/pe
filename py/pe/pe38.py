#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
What is the largest 1 to 9 pandigital
that can be formed by multiplying a fixed number by 1, 2, 3, ... ?
"""

def pand(n):
    p = ''
    i = 1
    while 1:
        p += str(i * n)
        if len(p) >= 9: break
        i += 1
    if '0' in p:
        return 0
    if len(p) == 9 == len(set(p)):
        return int(p)
    return 0

def pe38():
    """
    >>> pe38()
    932718654
    """
    m = 0
    for n in range(1, 10000):
        p = pand(n)
        if p > m:
            m = p
    return m

if __name__ == "__main__":
    import doctest
    doctest.testmod()
