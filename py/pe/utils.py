#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import division, unicode_literals
from math import log

def get_prime(n):
    """
    Get nth prime.

    >>> get_prime(1)
    2

    >>> get_prime(10)
    29
    """
    if n < 1:
        return 0
    if n < 50:
        times = 5
    else:
        times = log(n) + 2
    n0 = n
    n = int(n * times)

    s = [True] * (n + 1)
    s[0], s[1] = False, False
    sq = int(n**0.5)
    for i in range(2, sq + 1):
        if s[i]:
            m = n//i - i
            s[i * i : n + 1 : i] = [False] * (m + 1)
    i, j = 0, 0
    while 1:
        if s[j]:
            i += 1
            if i >= n0:
                break
        j += 1
    return j

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
    sq = int(n**0.5)
    for i in range(2, sq + 1):
        if s[i]:
            m = n//i - i
            s[i * i : n+1 : i] = [False] * (m+1)
    return [i for i in range(n+1) if s[i]]

primes = set(sieve(100000))
primes2 = sieve(2766)

def is_prime(n):
    """
    Fast checking below n.

    >>> is_prime(997)
    True

    >>> is_prime(1001)
    False
    """
    return n in primes

def is_prime2(n):
    """
    Slow checking below n * n.

    >>> is_prime2(97)
    True
    """
    if n < 2:
        return False
    for p in primes2:
        if p * p > n:
            break
        if not n % p:
            return False
    return True

def get_divisors(n):
    """
    Get divisors.

    >>> get_divisors(180)
    [2, 2, 3, 3, 5]
    """
    p = []
    limit = int(n**0.5)
    while not n & 1:
        p.append(2)
        n >>= 1
    if n == 1:
        return p
    i = 3
    while i <= limit:
        if not n % i:
            p.append(i)
            n //= i
            if n < i:
                break
        else:
            i += 2
    if n > 1:
        p.append(n)
    return p

def count_divisors(n):
    """
    Count divisors.

    >>> count_divisors(18) # 18 can be divided by 1,2,3,6,9,18
    6
    """
    p = get_divisors(n)
    pl = len(p)
    if pl == 1:
        return 2
    t = 0
    c = 1
    for i in range(pl):
        if i + 1 < pl and p[i] == p[i + 1]:
            t += 1
        else:
            c *= t + 2
            t = 0
    return c

def count_distinct(n):
    """
    Count distinct divisors.

    >>> count_distinct(180) # 180 = (2*2)*(3*3)*5
    3
    """
    return len(set(get_divisors(n)))

def is_palindrome(n):
    """

    >>> is_palindrome(12321)
    True

    >>> is_palindrome(99)
    True

    >>> is_palindrome(0)
    True
    """
    s = str(n)
    return s == s[::-1]

def perm(n, m):
    """
    permutation: nPm

    >>> perm(5, 2) # 5*4
    20
    """
    f = 1
    for i in range(n - m + 1, n + 1):
        f *= i
    return f

def comb(n, m):
    """
    combination: nCm

    >>> comb(5, 2) # 5*4 // (2*1)
    10
    """
    c = d = 1
    if n >= m >= 0:
        while m > 0:
            c *= n
            d *= m
            n -= 1
            m -= 1
    return c//d

def pod(n, p):
    """
    Sum of pth powers of n's digits.

    >>> pod(123, 2) # 1**2 + 2**2 + 3**2
    14
    """
    s = 0
    while n:
        s += (n % 10)**p
        n //= 10
    return s

def sod(n):
    """
    Sum of digits.

    >>> sod(123) # 1 + 2 + 3
    6
    """
    s = 0
    while n:
        s += n % 10
        n //= 10
    return s

def spd(n):
    """
    Sum of proper divisors.

    >>> spd(6) # 6 can be divided by 1,2,3 excluding 6
    6

    >>> spd(9) # 1,3
    4
    """
    if not n > 2:
        return 1
    s = 1
    sq = n**0.5
    isq = int(sq)
    for i in range(2, isq + 1):
        if not n % i:
            s += i + n//i
    if sq == isq:
        s -= isq
    return s

def word_worth(sets):
    """

    >>> word_worth('ABC')
    6
    """
    return sum(ord(letter) - ord('A') + 1 for letter in sets)

def list_num(l):
    """
    list to number

    >>> list_num([1,2,3,4,5,6,7,8,9])
    123456789

    >>> list_num(i for i in range(9, 0, -1))
    987654321
    """
    s = 0
    for n in l:
        s = s * 10 + n
    return s

if __name__ == "__main__":
    import doctest
    doctest.testmod()
