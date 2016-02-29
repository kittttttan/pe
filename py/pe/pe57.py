#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Investigate the expansion of the continued fraction
for the square root of two.
"""

def pe57(limit=1000):
    """
    >>> pe57()
    153
    """
    n, d = 3, 2
    cnt = 0
    for a in range(limit + 1):
        # n, d = n + (d << 1), n + d
        nn = n
        n += d << 1
        d += nn
        if len(str(n)) > len(str(d)):
            cnt += 1
    return cnt

def calc(n):
    nd13 = n // 13
    return (nd13 << 1) + ((n - nd13 * 13) >> 3)

def pe57a(n=1000):
    """
    >>> pe57a()
    153
    """
    return calc(n)

if __name__ == "__main__":
    import doctest
    doctest.testmod()
