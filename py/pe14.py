#! /usr/bin/env python3

from sys import argv

cache = {1:1}

def chain(n):
    if not cache.get(n, 0):
        if n & 1:
            cache[n] = 1 + chain(3 * n + 1)
        else:
            cache[n] = 1 + chain(n >> 1)
    return cache[n]

def pe14(limit):
    """
    Which starting number produces the longest Collatz chain?
    """
    m, mi = 0, 0
    for i in range(3, limit, 2):
        c = chain(i)
        if m < c:
            m, mi = c, i
    print(mi, m)

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
    
    pe14(n)

if __name__ == "__main__":
    main()
