#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import division, print_function

def pe5(n=20):
    """
    What is the smallest number divisible by each of the numbers 1 to 20?

    >>> pe5()
    232792560
    """
    if n < 2:
        return 1
    p = 2
    m = [2]
    for x in range(3, n + 1):
        for y in m:
            if not x % y:
                x //= y
        if x > 1:
            m.append(x)
            p *= x
    return p

if __name__ == "__main__":
    import doctest
    doctest.testmod()

    try:
        while True:
            s = input('> ')
            n = int(s)
            print(pe5(n))
    except (SyntaxError, EOFError, KeyboardInterrupt, NameError):
        pass
