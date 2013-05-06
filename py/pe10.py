#! /usr/bin/env python3

from sys import argv

def pe10(n=2000000):
    """
    Calculate the sum of all the primes below two million.
    """
    s = [True] * (n + 1)
    s[0], s[1] = False, False
    sq = int(n**0.5)
    for i in range(2, sq + 1):
        if s[i]:
            m = n // i - i
            s[i * i : n + 1 : i] = [False] * (m + 1)
    return(sum(i for i in range(n + 1) if s[i]))

def main():
    argc = len(argv)
    if argc > 1:
        try:
            n = int(argv[1])
        except ValueError:
            print("  python pe10.py [integer]")
            return
    else:
        n = 2000000

    print(pe10(n))

if __name__ == "__main__":
    main()
