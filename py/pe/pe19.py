#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
How many Sundays fell on the first of the month
during the twentieth century?
"""

from datetime import date

def pe19(n=2000):
    """
    >>> pe19()
    171
    """
    s = 0
    for y in range(1901, n + 1):
        for m in range(1, 13):
            d = date(y, m, 1)
            if d.weekday() == 6:
                s += 1
    return s

if __name__ == "__main__":
    import doctest
    doctest.testmod()

    try:
        while True:
            s = input('> ')
            n = int(s)
            print(pe19(n))
    except (SyntaxError, EOFError, KeyboardInterrupt, NameError):
        pass
