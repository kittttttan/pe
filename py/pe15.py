#! /usr/bin/env python3

from sys import argv
from pe import perm
from math import factorial

def pe15(m=20, n=20):
    """
    Starting in the top left corner in a 20 by 20 grid,
    how many routes are there to the bottom right corner?
    """

    #return factorial(m + n) // (factorial(m) * factorial(n))

    p = perm(m + n, m)
    f = factorial(n)
    #print("%d / %d = %d" % (p, f, p // f))
    return p // f

def main():
    argc = len(argv)
    if argc > 1:
        try:
            m = int(argv[1])
        except ValueError:
            print("  python pe15.py [integer [integer]]")
            return
    else:
        m = 20
    if argc > 2:
        try:
            n = int(argv[2])
        except ValueError:
            print("  python pe15.py [integer [integer]]")
            return
    else:
        n = 20

    print(pe15(m, n))

if __name__ == "__main__":
    main()
