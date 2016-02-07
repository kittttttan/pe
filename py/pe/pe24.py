#!/usr/bin/env python
"""
What is the millionth lexicographic permutation of the digits
0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
"""

def pe24(n=999999):
    """
    >>> pe24()
    '2783915460'
    """
    nums = [i for i in range(10)]
    b, t = [], 1
    for j in range(1, 10):
        t *= j
        b.append(t)
    res = []
    for k in range(9, 0, -1):
        res.append(str(nums.pop(n // b[k - 1])))
        n %= b[k - 1]
    res.append(str(nums[0]))
    return ''.join(res)

if __name__ == "__main__":
    import doctest
    doctest.testmod()

    try:
        while True:
            s = input('> ')
            n = int(s)
            print(pe24(n))
    except (SyntaxError, EOFError, KeyboardInterrupt, NameError):
        pass
