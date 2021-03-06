#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Find the sum of all pandigital numbers
with an unusual sub-string divisibility property.
"""

from itertools import permutations

from utils import list_num

def pe43():
    """
    >>> pe43()
    [1406357289, 1430952867, 1460357289, 4106357289, 4130952867, 4160357289]
    """
    # s = 0
    ps = []
    for perm in permutations(i for i in range(10) if i != 5):
        if perm[3] & 1: continue
        perm = list(perm)
        perm.insert(5, 5)
        if not list_num(perm[7:10]) % 17 and \
           not list_num(perm[6: 9]) % 13 and \
           not list_num(perm[5: 8]) % 11 and \
           not list_num(perm[4: 7]) %  7 and \
           not list_num(perm[3: 6]) %  5 and \
           not list_num(perm[2: 5]) %  3:
            # s += list_num(perm)
            ps.append(list_num(perm))
    # print(s)
    return ps

if __name__ == "__main__":
    import doctest
    doctest.testmod()
