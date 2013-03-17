#! /usr/bin/env python3

from time import time
from math import log

def time_func(f):
    t = time()
    f()
    print("%ss" % (time() - t))

def get_prime(n):
    """
    Get nth prime.
    """
    if n < 1: return 0
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
    i,j = 0,0
    while True:
        if s[j]:
            i += 1
            if i >= n0: break
        j += 1
    return j

def sieve(n):
    """
    Get primes below n.
    """
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
    """
    return n in primes

def is_prime2(n):
    """
    Slow checking below n * n.
    """
    if n < 2: return False
    for p in primes2:
        if p * p > n: break
        if not n % p:
            return False
    return True

def get_divisors(n):
    """
    Get divisors.
    """
    p = []
    limit = int(n**0.5)
    while not n & 1:
        p.append(2)
        n >>= 1
    if n == 1: return p
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
    """
    p = get_divisors(n)
    pl = len(p)
    if pl == 1:
        return 2
    t = 0
    c = 1
    for i in range(pl):
        if i+1 < pl and p[i] == p[i + 1]:
            t += 1
        else:
            c *= t + 2
            t = 0
    return c

def count_distinct(n):
    """
    Count distinct divisors.
    """
    return len(set(get_divisors(n)))

def is_palindrome(n):
    s = str(n)
    if s == s[::-1]:
        return True
    return False

def fact(n):
    """factorial: n!"""
    f = 1
    while n > 1:
        f *= n
        n -= 1
    return f

def perm(n, m):
    """permutation: nPm"""
    f = 1
    for i in range(n - m + 1, n+1):
        f *= i
    return f

def comb(n, m):
    """combination: nCm"""
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
    """
    s = 0
    while n:
        s += (n % 10)**p
        n //= 10
    return s

def sod(n):
    """
    Sum of digits.
    """
    s = 0
    for i in str(n):
        s += int(i)
    return s

def spd(n):
    """
    Sum of proper divisors.
    """
    if not n > 2:
        return 1
    s = 1
    sq = n**0.5
    for i in range(2, int(sq)+1):
        if not n % i:
            s += i + n//i
    if sq == int(sq):
        s -= sq
    return s

def word_worth(sets):
    return sum(ord(letter) - ord('A') + 1 for letter in sets)

def list_num(l):
    s = 0
    for n in l:
        s = s * 10 + n
    return s
