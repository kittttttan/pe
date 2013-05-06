#! /usr/bin/env python3

from sys import argv

def pe5(n=20):
    """
    What is the smallest number divisible by each of the numbers 1 to 20?
    """
    if n < 2:
        return 1
    p = 2
    m = [2]
    for x in range(3, n + 1):
        for y in m:
            if not x % y:
                x //= y
        if x > 1:
            m.append(x)
            p *= x
    return p

def main():
    argc = len(argv)
    if argc > 1:
        try:
            n = int(argv[1])
        except ValueError:
            print("  python pe5.py [integer]")
            return
    else:
        n = 20

    print(pe5(n))

if __name__ == "__main__":
    main()
