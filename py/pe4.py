#! /usr/bin/env python3

from sys import argv
from pe import is_palindrome
 
def pe4(n):
    """
    Find the largest palindrome made from the product of two 3-digit numbers.
    """
    first, last = 9*10**(n - 1) + 1, 10**n
    max = 0
    for x in range(first, last):
        for y in range(x, last):
            xy = x * y
            if xy > max and is_palindrome(xy):
                max = xy
    print(max)

def main():
    argc = len(argv)
    if argc > 1:
        try:
            n = int(argv[1])
        except ValueError:
            print("  python pe4.py [integer]")
            return
    else:
        n = 3
    
    pe4(n)

if __name__ == "__main__":
    main()
