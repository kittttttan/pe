#! /usr/bin/env python3

from sys import argv

def pe6a(n=100):
    """
    What is the difference between the sum of the squares and
    the square of the sums?
    """
    s1 = sum([x for x in range(1, n + 1)])
    s2 = sum([x * x for x in range(1, n + 1)])
    return(s1 * s1 - s2)

def pe6(n=100):
    """
    s1 = n*(n+1)/2
    s2 = n*(n+1)*(2*n+1)/6
    s1*s1 - s2
        = n*(n+1)*(n*(n+1)/4 - (2*n+1)/6)
        = n*(n+1)*(3*n*(n+1) - 2*(2*n+1))/12
        = n*(n+1)*(3*n*n - n - 2)/12
        = n*(n+1)*(n-1)*(3*n+2)/12
    """
    return(n * (n + 1) * (n - 1) * (3 * n + 2) // 12)

def main():
    argc = len(argv)
    if argc > 1:
        try:
            n = int(argv[1])
        except ValueError:
            print("  python pe6.py [integer]")
            return
    else:
        n = 100

    print(pe6(n))

if __name__ == "__main__":
    main()
