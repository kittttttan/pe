#! /usr/bin/env python3

from pe import spd
from sys import argv

def pe23(limit=28123):
    """
    Find the sum of all the positive integers
    which cannot be written as the sum of two abundant numbers.
    """
    s = 0
    abn = set()
    for n in range(1, limit):
        if spd(n) > n:
            abn.add(n)
        if not any((n - a in abn) for a in abn):
            s += n
    return s

def main():
    argc = len(argv)
    if argc > 1:
        try:
            n = int(argv[1])
        except ValueError:
            print("  python pe23.py [integer]")
            return
    else:
        n = 28123

    print(pe23(n))

if __name__ == "__main__":
    main()
