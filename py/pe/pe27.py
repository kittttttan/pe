#!/usr/bin/env python

from pe import is_prime

def pe27():
    """
    Find a quadratic formula that produces the maximum number of primes
    for consecutive values of n.

    f(n) = n2 + an + b, where |a| < 1000 and |b| < 1000
    """
    """
    f(0) >= 2    =>   b >= 2
    f(1) >= 2    =>   b >= 1 - a
    """
    m = (0, 0, 0)
    for a in range(-999, 1000):
        for b in range(max(2, 1 - a), 1000):
            n, cnt = 0, 0
            while 1:
                p = n * (n + a) + b
                if is_prime(p):
                    cnt += 1
                else:
                    break
                n += 1
            if cnt > m[2]:
                m = (a, b, cnt)
    return (m[0] * m[1], m)

if __name__ == "__main__":
    print(pe27())
