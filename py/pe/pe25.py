#!/usr/bin/env python

from sys import argv

def pe25(digits=1000):
    """
    What is the first term in the Fibonacci sequence to contain 1000 digits?
    """
    a, b, n = 1, 0, 1
    while len(str(a)) < digits:
        a,b = a+b, a
        n += 1
    return (n, a)

def main():
    argc = len(argv)
    if argc > 1:
        try:
            n = int(argv[1])
        except ValueError:
            print("  python pe25.py [integer]")
            return
    else:
        n = 1000

    print(pe25(n))

if __name__ == "__main__":
    main()
