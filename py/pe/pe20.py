#!/usr/bin/env python

from sys import argv
from pe import sod
from math import factorial

def pe20(n=100):
    """
    Find the sum of digits in 100!
    """
    return sod(factorial(n))

def main():
    argc = len(argv)
    if argc > 1:
        try:
            n = int(argv[1])
        except ValueError:
            print("  python pe20.py [integer]")
            return
    else:
        n = 100

    print("sum of digits in %d! is %d" % (n, pe20(n)))

if __name__ == "__main__":
    main()
