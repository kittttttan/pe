#!/usr/bin/env python

from sys import argv
from pe import count_divisors

def pe12(sub=500):
    """
    What is the value of the first triangle number
    to have over five hundred divisors?
    """
    t = 1
    i = 2
    while 1:
        c = count_divisors(t)
        if c >= sub:
            break
        t += i
        i += 1
    return(t)

def main():
    argc = len(argv)
    if argc > 1:
        try:
            n = int(argv[1])
        except ValueError:
            print("  python pe12.py [integer]")
            return
    else:
        n = 500

    print(pe12(n))

if __name__ == "__main__":
    main()
