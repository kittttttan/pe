#!/usr/bin/env python
"""
Solve project euler 58

Investigate the number of primes
that lie on the diagonals of the spiral grid.
"""

from utils import sieve

primes2 = sieve(30000)

def is_prime2(n):
    """
    Slow checking below n * n.
    """
    if n < 2:
        return False
    for p in primes2:
        if p * p > n:
            break
        if not n % p:
            return False
    return True

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
        ps += is_prime2(d + i) + is_prime2(d + 2*i) + is_prime2(d + 3*i)
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
