#!/usr/bin/env python
"""
Calculate the sum of all the primes below two million.
"""

def pe10(n=2000000):
    """
    >>> pe10()
    142913828922
    """
    s = [True] * (n + 1)
    s[0], s[1] = False, False
    sq = int(n**0.5)
    for i in range(2, sq + 1):
        if s[i]:
            m = n // i - i
            s[i * i : n + 1 : i] = [False] * (m + 1)
    return(sum(i for i in range(n + 1) if s[i]))

if __name__ == "__main__":
    import doctest
    doctest.testmod()

    try:
        while True:
            s = input('> ')
            n = int(s)
            print(pe10(n))
    except SyntaxError:
        pass
