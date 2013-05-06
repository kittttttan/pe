#! /usr/bin/env python3

from pe import sieve

def pe50(below=1000000):
    """
    Which prime, below one-million,
    can be written as the sum of the most consecutive primes?
    """
    primes = sieve(below)
    ps = set(primes)
    pl = len(primes)
    m, ml = 0, 0
    for j in range(pl - 500):
        t, s, l = 0, 0, 0
        for i in range(j, pl):
            s += primes[i]
            if s >= below: break
            if s in ps:
                t, l = s, i - j
        if l > ml:
            m, ml = t, l
    return (m, ml)

if __name__ == "__main__":
    print(pe50())
