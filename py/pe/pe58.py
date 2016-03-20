#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Solve project euler 58

Investigate the number of primes
that lie on the diagonals of the spiral grid.
"""

from primes import Primes

primes = Primes(30000)

def pe58(p=0.1):
    """
    >>> pe58()
    26241
    """
    l = 7
    ps = 8
    d = 49
    ds = 13
    while ps > p * ds:
        l += 2
        i = l - 1
        ps += primes.is_prime(d + i) + primes.is_prime(d + 2*i) + primes.is_prime(d + 3*i)
        d += i << 2
        ds += 4
    return l

if __name__ == "__main__":
    import doctest
    doctest.testmod()

    try:
        while True:
            s = input('> ')
            n = float(s)
            print(pe58(n))
    except (SyntaxError, EOFError, KeyboardInterrupt, NameError):
        pass
