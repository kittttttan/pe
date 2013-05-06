#! /usr/bin/env python3

from pe import pod

def pe30():
    """
    Find the sum of all the numbers that can be written as
    the sum of fifth powers of their digits.
    """
    return sum(n for n in range(11, 200000) if pod(n, 5) == n)

if __name__ == "__main__":
    print(pe30())
