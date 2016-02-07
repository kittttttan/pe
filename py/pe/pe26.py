#!/usr/bin/env python
"""
Find the value of d < 1000
for which 1/d contains the longest recurring cycle.
"""

def cycle(n):
    i = 1
    if not n & 1:
        return cycle(n >> 1)
    if not n % 5:
        return cycle(n // 5)
    while 1:
        if not (10**i - 1) % n:
            return i
        i += 1

def pe26(d=1000):
    """
    >>> pe26()
    (983, 982)
    """
    m, l = 0, 0
    for d in range(1, 1000):
        c = cycle(d)
        if c > m:
            m, l = d, c
    return (m, l)

if __name__ == "__main__":
    import doctest
    doctest.testmod()

    try:
        while True:
            s = input('> ')
            n = int(s)
            print(pe26(n))
    except (SyntaxError, EOFError, KeyboardInterrupt, NameError):
        pass
