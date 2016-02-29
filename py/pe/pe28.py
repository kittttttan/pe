#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
What is the sum of both diagonals in a 1001 by 1001 spiral?
21 22 23 24 25 ..
20  7  8  9 10 
19  6  1  2 11 
18  5  4  3 12
17 16 15 14 13
"""

def pe28(d=1001):
    """
    >>> pe28()
    669171001
    """
    n = (d - 1) >> 1
    """
    ld = [(2*i+1)**2 + 4*(i + 1) for i in range(n)]
    rd = [(2*i+1)**2 + 2*(i + 1) for i in range(n)]
    ru = [(2*i+3)**2 for i in range(n)]
    lu = [(2*i+3)**2 - 2*(i + 1) for i in range(n)]
    return 1 + sum(ld) + sum(rd) + sum(ru) + sum(lu)
    """
    return 1 + sum(i * ((i << 4) + 36) + 24 for i in range(n))

if __name__ == "__main__":
    import doctest
    doctest.testmod()

    try:
        while True:
            s = input('> ')
            n = int(s)
            print(pe28(n))
    except (SyntaxError, EOFError, KeyboardInterrupt, NameError):
        pass
