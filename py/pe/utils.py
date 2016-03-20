#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import division, unicode_literals

def get_divisors(n):
    """
    Get divisors.

    >>> [i for i in get_divisors(180)]
    [2, 2, 3, 3, 5]
    """
    limit = int(n**0.5)
    while not n & 1:
        yield 2
        n >>= 1
    if n == 1:
        return
    i = 3
    while i <= limit:
        if not n % i:
            yield i
            n //= i
            if n < i:
                break
        else:
            i += 2
    if n > 1:
        yield n

def count_divisors(n):
    """
    Count divisors.

    >>> count_divisors(18) # 18 can be divided by 1,2,3,6,9,18
    6
    """
    p = [i for i in get_divisors(n)]
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

import sys
if sys.version_info < (3, 0, 0):
    def triangle_numbers():
        """
        >>> import itertools
        >>> [i for i in itertools.islice(triangle_numbers(), 5)]
        [1, 3, 6, 10, 15]
        """
        t = 1
        i = 2
        while True:
            yield t
            t += i
            i += 1
else:
    import itertools
    def triangle_numbers():
        """
        >>> import itertools
        >>> [i for i in itertools.islice(triangle_numbers(), 5)]
        [1, 3, 6, 10, 15]
        """
        return itertools.accumulate(itertools.count(1))

if __name__ == "__main__":
    import doctest
    doctest.testmod()
