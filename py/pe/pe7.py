#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Find the 10001st prime.
"""

from primes import Primes

primes = Primes()

def pe7(n=10001):
    """
    >>> pe7()
    104743
    """
    return(primes[n - 1])

if __name__ == "__main__":
    import doctest
    doctest.testmod()

    try:
        while True:
            s = input('> ')
            n = int(s)
            print(pe7(n))
    except (SyntaxError, EOFError, KeyboardInterrupt, NameError):
        pass
