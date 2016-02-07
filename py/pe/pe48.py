#!/usr/bin/env python

def pe48(limit=1000):
    """
    Find the last ten digits of 1**1 + 2**2 + ... + 1000**1000.
    """
    s = 0
    for i in range(1, limit+1):
        s += i**i
    return s % (10**10)

if __name__ == "__main__":
    print(pe48())
