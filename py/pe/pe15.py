#!/usr/bin/env python
"""
Starting in the top left corner in a 20 by 20 grid,
how many routes are there to the bottom right corner?
"""

from utils import perm
from math import factorial

def pe15(m=20, n=20):
    """
    >>> pe15()
    137846528820
    """

    # return factorial(m + n) // (factorial(m) * factorial(n))

    p = perm(m + n, m)
    f = factorial(n)
    # print("%d / %d = %d" % (p, f, p // f))
    return p // f

if __name__ == "__main__":
    import doctest
    doctest.testmod()

    try:
        while True:
            s = input('m> ')
            m = int(s)
            s = input('n> ')
            n = int(s)
            print(pe15(m, n))
    except (SyntaxError, EOFError, KeyboardInterrupt, NameError):
        pass
