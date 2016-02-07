#!/usr/bin/env python
"""
Solve project euler 3

Find the largest prime factor of a composite number.
"""

from __future__ import print_function
from pe import get_divisors

def pe3(n=600851475143):
    """
    >>> pe3()
    [71, 839, 1471, 6857]
    """
    return get_divisors(n)

if __name__ == "__main__":
    import doctest
    doctest.testmod()

    try:
        while True:
            s = input('> ')
            n = int(s)
            print(pe3(n))
    except (SyntaxError, EOFError, KeyboardInterrupt, NameError):
        pass
