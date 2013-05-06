#! /usr/bin/env python3

from sys import argv

from pe import word_worth

def pe42(fname="../res/pe42.txt"):
    """
    How many triangle words does the list of common English words contain?
    """
    with open(fname, 'r') as f:
        words = f.read()
    words = words.replace('"', '').split(',')
    triangles = set(i * (i + 1) >> 1 for i in range(1, 100))
    # print([w for w in words if worth(w) in triangles])
    return sum([1 for w in words if word_worth(w) in triangles])

def main():
    argc = len(argv)
    if argc > 1:
        fname = argv[1]
    else:
        fname = "../res/pe42.txt"

    try:
        print(pe42(fname))
    except FileNotFoundError:
        print("""file not found: %s

  python pe42.py [filepath]""" % fname)

if __name__ == "__main__":
    main()
