#!/usr/bin/env python
# -*- coding: utf-8 -*-

from utils import count_divisors, triangle_numbers

def pe12(sub=500):
    """
    What is the value of the first triangle number
    to have over five hundred divisors?

    >>> pe12()
    76576500
    """
    for t in triangle_numbers():
        c = count_divisors(t)
        if c >= sub:
            return(t)
    return -1

if __name__ == "__main__":
    import doctest
    doctest.testmod()

    try:
        while True:
            s = input('> ')
            n = int(s)
            print(pe12(n))
    except (SyntaxError, EOFError, KeyboardInterrupt, NameError):
        pass
