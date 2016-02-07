#!/usr/bin/env python
"""
Find the maximum sum travelling from the top of the triangle to the base.
"""

def pe18(fname="../../res/pe18.txt"):
    """
    >>> pe18()
    1074
    """
    with open(fname, 'r') as f:
        s = f.read()
    s = s.split('\n')
    size = len(s) - 1
    for i in range(size + 1):
        s[i] = s[i].split(' ')
    for i in range(size):
        si = s[size - i - 1]
        for j in range(len(si)):
            si[j] = int(si[j]) + \
                    max(int(s[size - i][j]), int(s[size - i][j + 1]))
    return(s[0][0])

if __name__ == "__main__":
    import doctest
    doctest.testmod()
