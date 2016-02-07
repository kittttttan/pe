#!/usr/bin/env python

from sys import argv

cache = {1:1}

def chain(n):
    if not cache.get(n, 0):
        if n & 1:
            cache[n] = 1 + chain(3 * n + 1)
        else:
            cache[n] = 1 + chain(n >> 1)
    return cache[n]

def chain_count(n):
    c = 1
    while n > 1:
        if n & 1:
            n = 3 * n + 1
        else:
            n >>= 1
        c += 1
    return c

def pe14(limit=1000000):
    """
    Which starting number produces the longest Collatz chain?
    """
    m, mi = 0, 0
    for i in range(3, limit, 2):
        c = chain(i)
        if m < c:
            m, mi = c, i
    return(mi, m)

def main():
    argc = len(argv)
    if argc > 1:
        try:
            n = int(argv[1])
        except ValueError:
            print("  python pe14.py [integer]")
            return
    else:
        n = 1000000

    print(pe14(n))

if __name__ == "__main__":
    main()
