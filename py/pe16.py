#! /usr/bin/env python3

from sys import argv
from pe import sod

def pe16(n):
    """
    What is the sum of the digits of the number 2**1000?
    """
    print("sum of the digits of 2**%d is %d" % (n, sod(2**n)))

def main():
    argc = len(argv)
    if argc > 1:
        try:
            n = int(argv[1])
        except ValueError:
            print("  python pe16.py [integer]")
            return
    else:
        n = 1000
    
    pe16(n)

if __name__ == "__main__":
    main()