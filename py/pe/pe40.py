#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Finding the nth digit of the fractional part of the irrational number.
"""

def digit_at(n):
    d = 1
    n -= 1
    while 1:
        """
        number of 1 digit numbers is 9
        number of 2 digit numbers is 90
        number of 3 digit numbers is 900
            ...
        number of d digit numbers is 9*10**(d-1)
        """
        ds = d * 9 * 10**(d - 1)
        if n > ds:
            n -= ds
        else:
            break
        d += 1
    num = n // d + 10**(d - 1)
    return int(str(num)[n % d])

def pe40():
    """
    >>> pe40()
    210
    """
    d = 1
    for i in range(7):
        d *= digit_at(10**i)
        # print(digit_at(10**i))
    return d

if __name__ == "__main__":
    import doctest
    doctest.testmod()
