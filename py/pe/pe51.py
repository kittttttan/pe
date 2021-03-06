#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Find the smallest prime which, by changing the same part of the number,
can form eight different primes.
"""

from primes import sieve

primes = sieve(1000000)
primeset = set(primes)

def is_prime(n):
    return n in primeset

def get_char_index(s, n):
    index = []
    char = str(n)
    for i in range(len(s)):
        if s[i] == char:
            index.append(i)
    return index

def change(sp, n, index):
    sp = list(sp)
    for i in index:
        sp[i] = str(n + 1)
    return ''.join(sp)

def count_change(sp, n):
    cnt = 1
    index = get_char_index(sp, n)
    for i in range(n, 10):
        sp = change(sp, i, index)
        if is_prime(int(sp)):
            cnt += 1
    return cnt

def pe51():
    """
    >>> pe51()
    121313
    """
    for p in primes:
        sp = str(p)
        for i in range(3):
            if sp.count(str(i)) > 1:
                if count_change(sp, i) == 8:
                    return p
    return -1

if __name__ == "__main__":
    import doctest
    doctest.testmod()
