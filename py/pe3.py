#! /usr/bin/env python3
 
from sys import argv
from pe import get_divisors
 
def pe3(n):
    """
    Find the largest prime factor of a composite number.
    """
    print(get_divisors(n))

def main():
    argc = len(argv)
    if argc > 1:
        try:
            n = int(argv[1])
        except ValueError:
            print("  python pe3.py [integer]")
            return
    else:
        n = 600851475143
    
    pe3(n)

if __name__ == "__main__":
    main()
