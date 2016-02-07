#!/usr/bin/env python
"""
Find the sum of digits in 100!
"""

from utils import sod
from math import factorial

def pe20(n=100):
    """
    >>> pe20()
    648
    """
    return sod(factorial(n))

if __name__ == "__main__":
    import doctest
    doctest.testmod()

    try:
        while True:
            s = input('> ')
            n = int(s)
            print(pe20(n))
    except (SyntaxError, EOFError, KeyboardInterrupt, NameError):
        pass
