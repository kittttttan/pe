#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
What is the largest n-digit pandigital prime that exists?
"""

from itertools import permutations

from utils import is_prime2, list_num

def pe41():
    """
    >>> pe41()
    7652413
    """
    for perm in permutations(range(7, 0, -1)):
        n = list_num(perm)
        if is_prime2(n):
            return n
    return -1

if __name__ == "__main__":
    import doctest
    doctest.testmod()
