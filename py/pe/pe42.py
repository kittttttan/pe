#!/usr/bin/env python
"""
How many triangle words does the list of common English words contain?
"""

from utils import word_worth

def pe42(fname="../../res/pe42.txt"):
    """
    >>> pe42()
    162
    """
    with open(fname, 'r') as f:
        words = f.read()
    words = words.replace('"', '').split(',')
    triangles = set(i * (i + 1) >> 1 for i in range(1, 100))
    # print([w for w in words if worth(w) in triangles])
    return sum([1 for w in words if word_worth(w) in triangles])

if __name__ == "__main__":
    import doctest
    doctest.testmod()
