#!/usr/bin/env python

from itertools import permutations

from utils import is_prime

def pe49(limit=10000):
    """
    Find arithmetic sequences, made of prime terms,
    whose four digits are permutations of each other.
    """
    for num in range(1111, limit):
        sn = str(num)
        if sn.find('0') >= 0: continue
        if is_prime(num):
            pp = {num : 1}
            for p in permutations(list(sn)):
                n = int(''.join(p))
                if is_prime(n):
                    pp[n] = 1
            primes = sorted(pp.keys())
            pl = len(primes)
            for a in range(pl):
                if primes[a] == 1487: continue
                for b in range(a+1, pl):
                    c = (primes[a] + primes[b]) >> 1
                    if c in pp:
                        return (primes[a], c, primes[b])
    return None

if __name__ == "__main__":
    ans = pe49()
    if ans is None:
        print("Not Found")
    else:
        print(ans)
