#!/usr/bin/env python

def pe45():
    """
    After 40755, what is the next triangle number
    that is also pentagonal and hexagonal?
    T285 = P165 = H143 = 40755.
    """
    limit = 30000
    h = [n * ((n << 1) - 1) for n in range(144, limit)]
    p = set([n * (3 * n - 1) >> 1 for n in range(166, limit << 1)])
    t = set([n * (n + 1) >> 1 for n in range(286, limit << 1)])
    for i in range(limit - 144):
        n = h[i]
        if n in p and n in t:
            return (n, i)
    return None

if __name__ == "__main__":
    ans = pe45()
    if ans is None:
        print("Not Found")
    else:
        print(ans)
