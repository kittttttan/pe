#! /usr/bin/env python3

def pe1a(limit=1000):
    """
    Add all the natural numbers below one thousand
    that are multiples of 3 or 5.
    """
    return sum([x for x in range(1, limit + 1) if not x % 3 or not x % 5])

def pe1(n=1000):
    sum = 0

    if n > 2:
        n3 = n // 3
        n5 = n // 5
        n15 = n // 15
        sum = (3 * n3 * (n3 + 1) + 5 * n5 * (n5 + 1) - 15 * n15 * (n15 + 1)) >> 1

    return sum

def main():
    from sys import argv
    
    argc = len(argv)
    if argc > 1:
        try:
            n = int(argv[1])
        except ValueError:
            print("  python pe1.py [integer]")
            return
    else:
        n = 1000

    print(pe1(n))

if __name__ == "__main__":
    main()
