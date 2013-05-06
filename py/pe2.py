#! /usr/bin/env python3

from sys import argv

def pe2(limit=4000000):
    """
    By considering the terms in the Fibonacci sequence
    whose values do not exceed four million,
    find the sum of the even-valued terms.
    """
    a,b,s = 1,2,2
    while b <= limit:
        a, b = b, a + b
        if not b & 1:
            s += b
    return s

def main():
    argc = len(argv)
    if argc > 1:
        try:
            n = int(argv[1])
        except ValueError:
            print("  python pe2.py [integer]")
            return
    else:
        n = 4000000

    print(pe2(n))

if __name__ == "__main__":
    main()
