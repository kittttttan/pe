#!/usr/bin/env python
"""
What is the total of all the name scores in the file of first names?
"""

from utils import word_worth

def pe22(fname="../../res/pe22.txt"):
    """
    >>> pe22()
    871198282
    """
    with open(fname, 'r') as f:
        names_string = f.read()
    names = names_string.replace('"', '').split(',')
    names.sort()
    return sum(word_worth(names[i]) * (i + 1) for i in range(len(names)))

if __name__ == "__main__":
    import doctest
    doctest.testmod()
