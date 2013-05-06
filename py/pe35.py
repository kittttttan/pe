#! /usr/bin/env python3

from pe import sieve

def pe35(limit=1000000):
    """
    How many circular primes are there below one million?
    """
    ps = set(sieve(limit))
    s = 0
    # circ = []
    for p in ps:
        pl = len(str(p))
        for i in range(1, pl):
            t = 10**i
            pp = (p % t) * 10**(pl - i) + p // t
            if pp not in ps: break
        else:
            s += 1
            # circ.append(p)
    return s
    # print(circ)

if __name__ == "__main__":
    print(pe35())
