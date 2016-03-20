#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
What is the largest n-digit pandigital prime that exists?
"""

from itertools import permutations

from primes import Primes
from utils import list_num

def pe41():
    """
    >>> pe41()
    7652413
    """
    primes = Primes(1000000)
    for perm in permutations(range(7, 0, -1)):
        n = list_num(perm)
        if primes.is_prime(n):
            return n
    return -1

if __name__ == "__main__":
    import doctest
    doctest.testmod()
