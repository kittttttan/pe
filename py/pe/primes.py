#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import division
from math import log

class Primes:
    def __init__(self, limit=100000):
        primes = sieve(limit)
        self.max_prime = primes[-1]
        self.primes = primes
        self.prime_set = set(primes)

    def __getitem__(self, index):
        """
        >>> p = Primes(1001)
        >>> p[0]
        2

        >>> p[9]
        29
        """
        self.update(index)
        return self.primes[index]

    def __len__(self):
        """
        >>> p = Primes(10)
        >>> len(p)
        4
        """
        return len(self.primes)

    def update(self, index):
        pl = len(self.primes)
        m = self.max_prime
        while pl < index + 1:
            m += 2
            if self.is_prime(m):
                self.primes.append(m)
                pl += 1
        self.max_prime = self.primes[-1]
        self.prime_set = set(self.primes)
        return self

    def is_prime(self, n):
        """
        >>> p = Primes(1001)
        >>> p.is_prime(997)
        True

        >>> p.is_prime(1001)
        False
        """
        if n < self.max_prime:
            return n in self.prime_set
        for p in self.primes:
            if p * p > n:
                break
            if not n % p:
                return False
        return True

def sieve(n):
    """
    Get primes below n.

    >>> sieve(10)
    [2, 3, 5, 7]
    """
    if n < 2:
        return []
    s = [True] * (n + 1)
    s[0], s[1] = False, False
    sq = int(n ** 0.5)
    for i in range(2, sq + 1):
        if s[i]:
            m = n // i - i
            s[i * i : n + 1 : i] = [False] * (m + 1)
    return [i for i in range(n + 1) if s[i]]

if __name__ == "__main__":
    import doctest
    doctest.testmod()
