#!/usr/bin/env python

from sys import argv

def pe28(d=1001):
    """
    What is the sum of both diagonals in a 1001 by 1001 spiral?
    21 22 23 24 25 ..
    20  7  8  9 10 
    19  6  1  2 11 
    18  5  4  3 12
    17 16 15 14 13
    """
    n = (d - 1) >> 1
    """
    ld = [(2*i+1)**2 + 4*(i + 1) for i in range(n)]
    rd = [(2*i+1)**2 + 2*(i + 1) for i in range(n)]
    ru = [(2*i+3)**2 for i in range(n)]
    lu = [(2*i+3)**2 - 2*(i + 1) for i in range(n)]
    return 1 + sum(ld) + sum(rd) + sum(ru) + sum(lu)
    """
    return 1 + sum(i * ((i << 4) + 36) + 24 for i in range(n))

def main():
    argc = len(argv)
    if argc > 1:
        try:
            n = int(argv[1])
        except ValueError:
            print("  python pe28.py [integer]")
            return
    else:
        n = 1001

    print(pe28(n))

if __name__ == "__main__":
    main()
