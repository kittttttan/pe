#!/usr/bin/env python

from itertools import permutations

from pe import is_prime2, list_num

def pe41():
    """
    What is the largest n-digit pandigital prime that exists?
    """
    for perm in permutations(range(7, 0, -1)):
        n = list_num(perm)
        if is_prime2(n):
            return n
    return -1

if __name__ == "__main__":
    ans = pe41()
    if ans < 0:
        print("Not Found")
    else:
        print(ans)
