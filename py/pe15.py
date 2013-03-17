#! /usr/bin/env python3

from sys import argv
from pe import perm, fact

def pe15(m, n):
    """
    Starting in the top left corner in a 20 by 20 grid,
    how many routes are there to the bottom right corner?
    """
    
    #return fact(m + n) // (fact(m) * fact(n))

    p = perm(m + n, m)
    f = fact(n)
    print("%d / %d = %d" % (p, f, p // f))

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
    
    pe15(m, n)

if __name__ == "__main__":
    main()
