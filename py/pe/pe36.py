#!/usr/bin/env python
"""
Find the sum of all numbers less than one million,
which are palindromic in base 10 and base 2.
"""

from utils import is_palindrome

def is_palindrome2(n):
    s = ''
    while n:
        s += str(n & 1)
        n >>= 1
    return s == s[::-1]

def pe36(limit=1000000):
    """
    >>> pe36()
    872187
    """
    return sum(i for i in range(1, limit, 2)
                if is_palindrome(i) and is_palindrome2(i))

if __name__ == "__main__":
    import doctest
    doctest.testmod()

    try:
        while True:
            s = input('> ')
            n = int(s)
            print(pe36(n))
    except (SyntaxError, EOFError, KeyboardInterrupt, NameError):
        pass
