#! /usr/bin/env python3
 
from sys import argv

def pe5(n):
    """
    What is the smallest number divisible by each of the numbers 1 to 20?
    """
    if n < 2:
        print(1)
        return
    p = 2
    m = [2]
    for x in range(3, n + 1):
        for y in m:
            if not x % y:
                x //= y
        if x > 1:
            m.append(x)
            p *= x
    print(p)

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
    
    pe5(n)

if __name__ == "__main__":
    main()
