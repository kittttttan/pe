#!/usr/bin/env python

from sys import argv

def cycle(n):
    i = 1
    if not n & 1:
        return cycle(n >> 1)
    if not n % 5:
        return cycle(n // 5)
    while 1:
        if not (10**i - 1) % n:
            return i
        i += 1

def pe26(d=1000):
    """
    Find the value of d < 1000
    for which 1/d contains the longest recurring cycle.
    """
    m, l = 0, 0
    for d in range(1, 1000):
        c = cycle(d)
        if c > m:
            m, l = d, c
    return (m, l)

def main():
    argc = len(argv)
    if argc > 1:
        try:
            n = int(argv[1])
        except ValueError:
            print("  python pe26.py [integer]")
            return
    else:
        n = 1000

    print(pe26(n))

if __name__ == "__main__":
    main()
