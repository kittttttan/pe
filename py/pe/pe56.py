#!/usr/bin/env python
"""
Considering natural numbers of the form, ab,
finding the maximum digital sum.
"""

def pe56(alimit=100, blimit=100):
    """
    >>> pe56()
    (972, 99, 95)
    """
    m = 0
    for a in range(11, alimit):
        for b in range(11, blimit):
            s = sum(int(digit) for digit in str(a**b))
            if s > m:
                m, ma, mb = s, a, b
    return (m, ma, mb)

if __name__ == "__main__":
    import doctest
    doctest.testmod()

    try:
        while True:
            s = input('a> ')
            a = int(s)
            s = input('b> ')
            b = int(s)
            print(pe56(a, b))
    except (SyntaxError, EOFError, KeyboardInterrupt, NameError):
        pass
