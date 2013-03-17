#! /usr/bin/env python3

from sys import argv

def pe13(fname):
    """
    Work out the first ten digits of the sum of
    the following one-hundred 50-digit numbers.
    """
    with open(fname, 'r') as f:
        nums = f.read()
    nums = nums.split('\n')
    nums = [int(num) for num in nums]
    print(str(sum(nums))[0:10])

def main():
    argc = len(argv)
    if argc > 1:
        fname = argv[1]
    else:
        fname = "pe13.txt"

    try:
        pe13(fname)
    except FileNotFoundError:
        print("""file not found: %s

  python pe13.py [filepath]""" % fname)

if __name__ == "__main__":
    main()
