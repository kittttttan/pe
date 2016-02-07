#!/usr/bin/env python
"""
Solve project euler 4

Find the largest palindrome made from the product of two 3-digit numbers.
"""

from utils import is_palindrome

def pe4(n=3):
    """
    >>> pe4()
    906609
    """
    first, last = 9*10**(n - 1) + 1, 10**n
    mx = 0
    for x in range(first, last):
        for y in range(x, last):
            xy = x * y
            if xy > mx and is_palindrome(xy):
                mx = xy
    return mx

if __name__ == "__main__":
    import doctest
    doctest.testmod()

    try:
        while True:
            s = input('> ')
            n = int(s)
            print(pe4(n))
    except (SyntaxError, EOFError, KeyboardInterrupt, NameError):
        pass
