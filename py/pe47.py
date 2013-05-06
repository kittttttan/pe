#! /usr/bin/env python3

from pe import count_distinct

def pe47(d=4):
    """
    Find the first four consecutive integers
    to have four distinct primes factors.
    """
    i = 14
    while 1:
        rep = 0
        while count_distinct(i) == d:
            rep += 1
            i += 1
            if rep >= d:
                return i - d
        i += 1

if __name__ == "__main__":
    print(pe47())
