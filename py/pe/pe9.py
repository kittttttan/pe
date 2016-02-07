#!/usr/bin/env python
"""
Find the only Pythagorean triplet, {a, b, c}, for which a + b + c = 1000.
"""


def pe9(limit=1000):
    """
    Find the only Pythagorean triplet, {a, b, c}, for which a + b + c = 1000.

    >>> pe9()
    31875000
    """
    l2 = (limit >> 1) + 1
    # list = []
    for x in range(1, l2):
        for y in range(x, l2):
            z = limit - x - y
            if x * x + y * y == z * z:
                # list.append((x, y, z))
                return(x * y * z)
    # return list

if __name__ == "__main__":
    import doctest
    doctest.testmod()

    try:
        while True:
            s = input('> ')
            n = int(s)
            print(pe9(n))
    except (SyntaxError, EOFError, KeyboardInterrupt, NameError):
        pass
