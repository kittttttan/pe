#!/usr/bin/env python

from utils import is_prime

sq = [i * i << 1 for i in range(100)]

def is_goldbach(n):
    res = False
    for i in range(100):
        t = n - sq[i]
        if t < 2: break
        if is_prime(t):
            res = True
            break
    return res

def pe46():
    """
    What is the smallest odd composite
    that cannot be written as the sum of a prime and twice a square?
    """
    limit = 10000
    res = False
    for i in range(35, limit, 2):
        if not is_goldbach(i):
            res = i
            break
    return res

if __name__ == "__main__":
    print(pe46())
