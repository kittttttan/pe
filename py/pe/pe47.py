#!/usr/bin/env python
"""
Find the first four consecutive integers
to have four distinct primes factors.
"""

from utils import count_distinct

def pe47(d=4):
    """
    >>> pe47()
    134043
    """
    i = 14
    while 1:
        rep = 0
        while count_distinct(i) == d:
            rep += 1
            i += 1
            if rep >= d:
                return i - d
        i += 1

if __name__ == "__main__":
    import doctest
    doctest.testmod()

    try:
        while True:
            s = input('> ')
            n = int(s)
            print(pe47(n))
    except (SyntaxError, EOFError, KeyboardInterrupt, NameError):
        pass
