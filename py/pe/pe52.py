#!/usr/bin/env python
"""
Find the smallest positive integer,
x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits in some order.
"""

def sd(n):
    digit = set(list(str(n)))
    for m in range(2, 7):
        if set(list(str(n * m))) != digit:
            return False
    return True

def pe52():
    """
    >>> pe52()
    142857
    """
    res = -1
    for i in range(100008, 200000, 9):
        if sd(i):
            res = i
            break
    return res

if __name__ == "__main__":
    import doctest
    doctest.testmod()
