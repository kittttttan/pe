#! /usr/bin/env python3

from sys import argv

def pe13(fname="../res/pe13.txt"):
    """
    Work out the first ten digits of the sum of
    the following one-hundred 50-digit numbers.
    """
    with open(fname, 'r') as f:
        nums = f.read()
    nums = nums.split('\n')
    return(str(sum([int(num) for num in nums]))[0:10])

def main():
    argc = len(argv)
    if argc > 1:
        fname = argv[1]
    else:
        fname = "../res/pe13.txt"

    try:
        print(pe13(fname))
    except FileNotFoundError:
        print("""file not found: %s

  python pe13.py [filepath]""" % fname)

if __name__ == "__main__":
    main()
