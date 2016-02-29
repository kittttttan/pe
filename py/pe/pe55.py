#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
How many Lychrel numbers are there below ten-thousand?
"""

def is_lychrel(n):
    ss = str(n)[::-1]
    for i in range(50):
        n += int(ss)
        s = str(n)
        ss = s[::-1]
        if s == ss:
            return False
    return True

def pe55(limit=10000):
    """
    >>> pe55()
    249
    """
    return sum(1 for i in range(limit) if is_lychrel(i))

if __name__ == "__main__":
    import doctest
    doctest.testmod()

    try:
        while True:
            s = input('> ')
            n = int(s)
            print(pe55(n))
    except (SyntaxError, EOFError, KeyboardInterrupt, NameError):
        pass
