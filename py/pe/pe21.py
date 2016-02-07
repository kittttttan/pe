#!/usr/bin/env python
"""
Evaluate the sum of all amicable pairs under 10000.
"""

from utils import spd

def pe21(limit=10000):
    """
    >>> pe21()
    (31626, [(220, 284), (1184, 1210), (2620, 2924), (5020, 5564), (6232, 6368)])
    """
    ami = []
    s = 0
    for i in range(2, limit + 1):
        t = spd(i)
        if i < t and i == spd(t):
            s += i + t
            ami.append((i, t))
    return (s, ami)

if __name__ == "__main__":
    import doctest
    doctest.testmod()

    try:
        while True:
            s = input('> ')
            n = int(s)
            print(pe21(n))
    except (SyntaxError, EOFError, KeyboardInterrupt, NameError):
        pass
