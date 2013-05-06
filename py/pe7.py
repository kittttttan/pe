#! /usr/bin/env python3

from sys import argv
from pe import get_prime

def pe7(n=10001):
    """
    Find the 10001st prime.
    """
    return(get_prime(n))

def main():
    argc = len(argv)
    if argc > 1:
        try:
            n = int(argv[1])
        except ValueError:
            print("  python pe7.py [integer]")
            return
    else:
        n = 10001

    print(pe7(n))

if __name__ == "__main__":
    main()
