#!/usr/bin/env python
"""
Find the last ten digits of 1**1 + 2**2 + ... + 1000**1000.
"""

def pe48(limit=1000):
    """
    >>> pe48()
    9110846700
    """
    s = 0
    for i in range(1, limit+1):
        s += i**i
    return s % (10**10)

if __name__ == "__main__":
    import doctest
    doctest.testmod()

    try:
        while True:
            s = input('> ')
            n = int(s)
            print(pe48(n))
    except (SyntaxError, EOFError, KeyboardInterrupt, NameError):
        pass
