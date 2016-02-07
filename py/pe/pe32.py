#!/usr/bin/env python

from itertools import permutations

def pan(a, b):
    """
    1 through 9 pandigital products.
    """
    ab = a * b
    t = str(a) + str(b) + str(ab)
    if '0' in t:
        return 0
    if len(t) == 9 == len(set(t)):
        return ab
    return 0

def pe32():
    """
    Find the sum of all numbers that can be written as pandigital products.
    """
    """
    a * bcde = fghi
    ab * cde = fghi
    """
    return sum(set(pan(a, b) for a in range(3, 50) for b in range(123, 1988)))

def num(l):
    s = 0
    for n in l:
        s = s * 10 + n
    return s

def pe32b():
    product = {}
    for perm in permutations(range(1, 10)):
        for cross in range(1, 4): 
            for eq in range(cross + 1, 6):
                a = num(perm[0:cross])
                b = num(perm[cross:eq])
                c = num(perm[eq:9])
                if a * b == c:
                    product[c] = 1
    return sum(p for p in product)

if __name__ == "__main__":
    print(pe32())
