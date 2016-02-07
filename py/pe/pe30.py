#!/usr/bin/env python
"""
Find the sum of all the numbers that can be written as
the sum of fifth powers of their digits.
"""
from utils import pod

def pe30():
    """
    >>> pe30()
    443839
    """
    return sum(n for n in range(11, 200000) if pod(n, 5) == n)

if __name__ == "__main__":
    import doctest
    doctest.testmod()
