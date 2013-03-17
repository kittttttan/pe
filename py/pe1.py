#! /usr/bin/env python3

from sys import argv
 
def pe1a(limit):
    """
    Add all the natural numbers below one thousand
    that are multiples of 3 or 5.
    """
    print(sum([x for x in range(1, limit + 1) if not x % 3 or not x % 5]))

def pe1(n):
    sum = 0
    
    if n > 2:
        n3 = n // 3
        n5 = n // 5
        n15 = n // 15
        sum = (3 * n3 * (n3 + 1) + 5 * n5 * (n5 + 1) - 15 * n15 * (n15 + 1)) >> 1

    print(sum)

def main():
    argc = len(argv)
    if argc > 1:
        try:
            n = int(argv[1])
        except ValueError:
            print("  python pe1.py [integer]")
            return
    else:
        n = 1000

    pe1(n)

if __name__ == "__main__":
    main()
