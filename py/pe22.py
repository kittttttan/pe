#! /usr/bin/env python3

from sys import argv
from pe import word_worth
 
def pe22(fname):
    """
    What is the total of all the name scores in the file of first names?
    """
    with open(fname, 'r') as f:
        names_string = f.read()
    names = names_string.replace('"', '').split(',')
    names.sort()
    print(sum(word_worth(names[i]) * (i + 1) for i in range(len(names))))

def main():
    argc = len(argv)
    if argc > 1:
        fname = argv[1]
    else:
        fname = "pe22.txt"

    try:
        pe22(fname)
    except FileNotFoundError:
        print("""file not found: %s

  python pe22.py [filepath]""" % fname)

if __name__ == "__main__":
    main()
