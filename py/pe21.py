#! /usr/bin/env python3

from sys import argv
from pe import spd
 
def pe21(limit):
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
    print(s, ami)

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

    pe21(n)

if __name__ == "__main__":
    main()
