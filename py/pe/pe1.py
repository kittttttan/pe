#!/usr/bin/env python
"""
Solve project euler 1

Add all the natural numbers below one thousand
that are multiples of 3 or 5.
"""
from __future__ import division, print_function
#unicode_literals, absolute_import

def pe1a(limit=1000):
    """
    iter

    >>> pe1a()
    234168
    """
    return sum([x for x in range(1, limit + 1) if not x % 3 or not x % 5])

def pe1(n=1000):
    """
    sum(multiples of 3) + sum(multiples of 5) - sum(multiples of 15)

    >>> pe1()
    234168
    """
    s = 0

    if n > 2:
        n3 = n // 3
        n5 = n // 5
        n15 = n // 15
        s = (3 * n3 * (n3 + 1) + 5 * n5 * (n5 + 1) - 15 * n15 * (n15 + 1)) >> 1

    return s

if __name__ == "__main__":
    import doctest
    doctest.testmod()

    try:
        while True:
            s = input('> ')
            n = int(s)
            print(pe1(n))
    except (SyntaxError, EOFError, KeyboardInterrupt, NameError):
        pass
