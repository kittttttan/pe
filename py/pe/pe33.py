#!/usr/bin/env python
"""
Discover all the fractions with an unorthodox cancelling method.
"""

from fractions import Fraction

def is_curious(n, d):
    if n >= d:
        return False
    f = Fraction(n, d)
    n_digits = [int(digit) for digit in str(n)]
    d_digits = [int(digit) for digit in str(d)]

    if n_digits[1] == d_digits[0] and \
            d_digits[1] and Fraction(n_digits[0], d_digits[1]) == f:
        return True
    return False

def pe33():
    """
    >>> pe33()
    100
    """
    fractions = ((x, y) for x in range(10, 100) for y in range(10, 100))
    m = 1
    for f in (Fraction(*f) for f in fractions if is_curious(*f)):
        m *= f
    return m.denominator

if __name__ == "__main__":
    import doctest
    doctest.testmod()
