#! /usr/bin/env python3

from sys import argv

def pe18(fname):
    """
    Find the maximum sum travelling from the top of the triangle to the base.
    """
    with open(fname, 'r') as f:
        s = f.read()
    s = s.split('\n')
    size = len(s) - 1
    for i in range(size + 1):
        s[i] = s[i].split(' ')
    for i in range(size):
        si = s[size - i - 1]
        for j in range(len(si)):
            si[j] = int(si[j]) + \
                    max(int(s[size - i][j]), int(s[size - i][j + 1]))
    print(s[0][0])

def main():
    argc = len(argv)
    if argc > 1:
        fname = argv[1]
    else:
        fname = "pe18.txt"

    try:
        pe18(fname)
    except FileNotFoundError:
        print("""file not found: %s

  python pe18.py [filepath]""" % fname)

if __name__ == "__main__":
    main()
