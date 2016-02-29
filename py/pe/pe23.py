#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Find the sum of all the positive integers
which cannot be written as the sum of two abundant numbers.
"""

from utils import spd

def pe23(limit=28123):
    """
    >>> pe23()
    4179871
    """
    s = 0
    abn = set()
    for n in range(1, limit):
        if spd(n) > n:
            abn.add(n)
        if not any((n - a in abn) for a in abn):
            s += n
    return s

if __name__ == "__main__":
    import doctest
    doctest.testmod()

    try:
        while True:
            s = input('> ')
            n = int(s)
            print(pe23(n))
    except (SyntaxError, EOFError, KeyboardInterrupt, NameError):
        pass
