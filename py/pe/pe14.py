#!/usr/bin/env python
"""
Which starting number produces the longest Collatz chain?
"""

_cache = {1:1}

def _chain(n):
    if not _cache.get(n, 0):
        if n & 1:
            _cache[n] = 1 + _chain(3 * n + 1)
        else:
            _cache[n] = 1 + _chain(n >> 1)
    return _cache[n]

def _chain_count(n):
    c = 1
    while n > 1:
        if n & 1:
            n = 3 * n + 1
        else:
            n >>= 1
        c += 1
    return c

def pe14(limit=1000000):
    """
    >>> pe14()
    (837799, 525)
    """
    m, mi = 0, 0
    for i in range(3, limit, 2):
        c = _chain(i)
        if m < c:
            m, mi = c, i
    return(mi, m)

if __name__ == "__main__":
    import doctest
    doctest.testmod()

    try:
        while True:
            s = input('> ')
            n = int(s)
            print(pe14(n))
    except (SyntaxError, EOFError, KeyboardInterrupt, NameError):
        pass
