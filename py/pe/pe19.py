#!/usr/bin/env python

from sys import argv
from datetime import date

def pe19(n=2000):
    """
    How many Sundays fell on the first of the month
    during the twentieth century?
    """
    s = 0
    for y in range(1901, n + 1):
        for m in range(1, 13):
            d = date(y, m, 1)
            if d.weekday() == 6:
                s += 1
    return s

def main():
    argc = len(argv)
    if argc > 1:
        try:
            n = int(argv[1])
        except ValueError:
            print("  python pe19.py [integer]")
            return
    else:
        n = 2000

    print("%d Sundays do (1901 to %d)" % (pe19(n), n))

if __name__ == "__main__":
    main()