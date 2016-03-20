#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Find arithmetic sequences, made of prime terms,
whose four digits are permutations of each other.
"""

from itertools import permutations

from primes import Primes

def pe49(limit=10000):
    """
    >>> pe49()
    (2969, 6299, 9629)
    """
    pr = Primes()
    for num in range(1111, limit):
        sn = str(num)
        if sn.find('0') >= 0: continue
        if pr.is_prime(num):
            pp = {num : 1}
            for p in permutations(list(sn)):
                n = int(''.join(p))
                if pr.is_prime(n):
                    pp[n] = 1
            primes = sorted(pp.keys())
            pl = len(primes)
            for a in range(pl):
                if primes[a] == 1487: continue
                for b in range(a+1, pl):
                    c = (primes[a] + primes[b]) >> 1
                    if c in pp:
                        return (primes[a], c, primes[b])
    return None

if __name__ == "__main__":
    import doctest
    doctest.testmod()

    try:
        while True:
            s = input('> ')
            n = int(s)
            print(pe49(n))
    except (SyntaxError, EOFError, KeyboardInterrupt, NameError):
        pass
