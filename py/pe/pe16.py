#!/usr/bin/env python
"""
What is the sum of the digits of the number 2**1000?
"""

from utils import sod

def pe16(n=1000):
    """
    >>> pe16()
    1366
    """
    return sod(2**n)

if __name__ == "__main__":
    import doctest
    doctest.testmod()

    try:
        while True:
            s = input('> ')
            n = int(s)
            print(pe16(n))
    except (SyntaxError, EOFError, KeyboardInterrupt, NameError):
        pass
