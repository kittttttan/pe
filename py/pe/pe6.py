#!/usr/bin/env python
"""
What is the difference between the sum of the squares and
the square of the sums?
"""

def pe6a(n=100):
    """
    sum

    >>> pe6a()
    25164150
    """
    s1 = sum(x for x in range(1, n + 1))
    s2 = sum(x * x for x in range(1, n + 1))
    return(s1 * s1 - s2)

def pe6(n=100):
    """
    s1 = n*(n+1)/2
    s2 = n*(n+1)*(2*n+1)/6
    s1*s1 - s2
        = n*(n+1)*(n*(n+1)/4 - (2*n+1)/6)
        = n*(n+1)*(3*n*(n+1) - 2*(2*n+1))/12
        = n*(n+1)*(3*n*n - n - 2)/12
        = n*(n+1)*(n-1)*(3*n+2)/12

    >>> pe6()
    25164150
    """
    return(n * (n + 1) * (n - 1) * (3 * n + 2) // 12)

if __name__ == "__main__":
    import doctest
    doctest.testmod()

    try:
        while True:
            s = input('> ')
            n = int(s)
            print(pe6(n))
    except (SyntaxError, EOFError, KeyboardInterrupt, NameError):
        pass
