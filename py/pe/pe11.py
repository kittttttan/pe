#!/usr/bin/env python
"""
What is the greatest product of four numbers
on the same straight line in the 20 by 20 grid?
"""

def pe11(fname="../res/pe11.txt", n=4):
    """
    >>> pe11('../../res/pe11.txt')
    70600674
    """
    with open(fname, 'r') as f:
        grid = f.read()
    grid = grid.split('\n')
    m = 0
    size = len(grid)
    r = size - n
    for i in range(size):
        grid[i] = grid[i].split(' ')
        #print(len(grid[i]))
    for x in range(size):
        for y in range(size):
            ud = lr = d0 = d1 = 1
            for i in range(n):
                lr *= int(grid[x+i][y]) if x < r else 0
                ud *= int(grid[x][y+i]) if y < r else 0
                d0 *= int(grid[x+i][y+i]) if x < r and y < r else 0
                d1 *= int(grid[x+i][y+n-i]) if x < r and y < r else 0
            if m < ud: m = ud
            if m < lr: m = lr
            if m < d0: m = d0
            if m < d1: m = d1
    return(m)

if __name__ == "__main__":
    import doctest
    doctest.testmod()

    try:
        while True:
            s = input('> ')
            n = int(s)
            print(pe11('../../res/pe11.txt', n=n))
    except (SyntaxError, EOFError, KeyboardInterrupt, NameError):
        pass
