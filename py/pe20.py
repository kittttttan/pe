#! /usr/bin/env python3
 
from sys import argv
from pe import fact, sod

def pe20(n):
    """
    Find the sum of digits in 100!
    """
    print("sum of digits in %d! is %d" % (n, sod(fact(n))))

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
    
    pe20(n)

if __name__ == "__main__":
    main()
