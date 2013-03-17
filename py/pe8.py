#! /usr/bin/env python3

from sys import argv

def pe8(fname, n):
    """
    Discover the largest product of five consecutive digits
    in the 1000-digit number.
    """
    with open(fname, 'r') as f:
        s = f.read()
    s = s.replace('\n', '')
    ls = len(s)
    if ls < n:
        raise ValueError
    m = 0
    for x in range(ls - n):
        t = 1
        for y in range(n):
            t *= int(s[x + y])
        if m < t:
            m = t
    print(m)

def main():
    argc = len(argv)
    if argc > 1:
        fname = argv[1]
    else:
        fname = "pe8.txt"
    if argc > 2:
        n = int(argv[2])
    else:
        n = 5

    try:
        pe8(fname, n)
    except FileNotFoundError:
        print("""file not found: %s

  python pe8.py [filepath [digits]]""" % fname)

if __name__ == "__main__":
    main()
