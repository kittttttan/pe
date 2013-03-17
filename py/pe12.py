#! /usr/bin/env python3

from sys import argv
from pe import count_divisors

def pe12(sub):
    """
    What is the value of the first triangle number
    to have over five hundred divisors?
    """
    t = 1
    i = 2
    while True:
        c = count_divisors(t)
        if c >= sub:
            break
        t += i
        i += 1
    print(t)

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
    
    pe12(n)

if __name__ == "__main__":
    main()
