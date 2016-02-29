#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
How many values of C(n,r), for 1 <= n <= 100, exceed one-million?
"""

from utils import comb

def pe53(limit=100):
    """
    >>> pe53()
    4075
    """
    cnt = 0
    for n in range(1, limit+1, 2):
        for r in range(1, (n >> 1) + 1):
            c = comb(n, r)
            if c > 1000000:
                cnt += 2
    for n in range(2, limit+1, 2):
        for r in range(1, (n >> 1) + 1):
            c = comb(n, r)
            if c > 1000000:
                if r == n >> 1:
                    cnt += 1
                else:
                    cnt += 2
    return cnt

if __name__ == "__main__":
    import doctest
    doctest.testmod()

    try:
        while True:
            s = input('> ')
            n = int(s)
            print(pe53(n))
    except (SyntaxError, EOFError, KeyboardInterrupt, NameError):
        pass
