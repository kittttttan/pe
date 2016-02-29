#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Work out the first ten digits of the sum of
the following one-hundred 50-digit numbers.
"""

def pe13(fname="../../res/pe13.txt"):
    """
    >>> pe13()
    '5537376230'
    """
    with open(fname, 'r') as f:
        nums = f.read()
    nums = nums.split('\n')
    return(str(sum([int(num) for num in nums]))[:10])

if __name__ == "__main__":
    import doctest
    doctest.testmod()
