#!/usr/bin/env python
"""
Solve project euler 2

By considering the terms in the Fibonacci sequence
whose values do not exceed four million,
find the sum of the even-valued terms.
"""

from __future__ import print_function

def pe2(limit=4000000):
    """
    Sum of the even-valued Fibonacci sequence

    >>> pe2()
    4613732
    """
    a, b, s = 1, 2, 2
    while b <= limit:
        a, b = b, a + b
        if not b & 1:
            s += b
    return s

if __name__ == "__main__":
    import doctest
    doctest.testmod()

    try:
        while True:
            s = input('> ')
            n = int(s)
            print(pe2(n))
    except (SyntaxError, EOFError, KeyboardInterrupt, NameError):
        pass
