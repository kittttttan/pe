#! /usr/bin/env python3

from pe import is_palindrome

def is_palindrome2(n):
    s = ''
    while n:
        s += str(n & 1)
        n >>= 1
    return s == s[::-1]

def pe36(limit=1000000):
    """
    Find the sum of all numbers less than one million,
    which are palindromic in base 10 and base 2.
    """
    return sum([i for i in range(1, limit, 2)
                if is_palindrome(i) and is_palindrome2(i)])

if __name__ == "__main__":
    print(pe36())
