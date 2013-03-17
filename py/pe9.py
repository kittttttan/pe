#! /usr/bin/env python3

from sys import argv

def pe9(limit):
    """
    Find the only Pythagorean triplet, {a, b, c}, for which a + b + c = 1000.
    """
    l2 = (limit >> 1) + 1
    # list = []
    for x in range(1, l2):
        for y in range(x, l2):
            z = limit - x - y
            if x * x + y * y == z * z:
                print(x * y * z)
                # list.append((x, y, z))
                return
    # return list

def main():
    argc = len(argv)
    if argc > 1:
        try:
            n = int(argv[1])
        except ValueError:
            print("  python pe9.py [integer]")
            return
    else:
        n = 1000
    
    pe9(n)

if __name__ == "__main__":
    main()
