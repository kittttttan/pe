#!/usr/bin/env python
"""
Discover the largest product of five consecutive digits
in the 1000-digit number.
"""

def pe8(fname="../res/pe8.txt", n=5):
    """
    Discover the largest product of five consecutive digits
    in the 1000-digit number.

    >>> pe8('../../res/pe8.txt')
    40824
    """
    with open(fname, 'r') as f:
        s = f.read()
    s = s.replace('\n', '')
    ls = len(s)
    if ls < n:
        raise ValueError
    m = 0
    for x in range(ls - n + 1):
        t = 1
        for y in range(n):
            t *= int(s[x + y])
        if m < t:
            m = t
    return(m)

if __name__ == "__main__":
    import doctest
    doctest.testmod()

    try:
        while True:
            s = input('> ')
            n = int(s)
            print(pe8('../../res/pe8.txt', n=n))
    except (SyntaxError, EOFError, KeyboardInterrupt, NameError):
        pass
