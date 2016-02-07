#!/usr/bin/env python

from sys import argv
from utils import spd

def pe21(limit=10000):
    """
    Evaluate the sum of all amicable pairs under 10000.
    """
    ami = []
    s = 0
    for i in range(2, limit + 1):
        t = spd(i)
        if i < t and i == spd(t):
            s += i + t
            ami.append((i, t))
    return (s, ami)

def main():
    argc = len(argv)
    if argc > 1:
        try:
            n = int(argv[1])
        except ValueError:
            print("  python pe21.py [integer]")
            return
    else:
        n = 10000

    print(pe21(n))

if __name__ == "__main__":
    main()
