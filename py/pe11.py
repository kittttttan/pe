#! /usr/bin/env python3

from sys import argv

def pe11(fname, n):
    """
    What is the greatest product of four numbers
    on the same straight line in the 20 by 20 grid?
    """
    with open(fname, 'r') as f:
        grid = f.read()
    grid = grid.split('\n')
    m = 0
    size = len(grid)
    r = size - n
    for i in range(size):
        grid[i] = grid[i].split(' ')
        print(len(grid[i]))
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
    print(m)

def main():
    argc = len(argv)
    if argc > 1:
        fname = argv[1]
    else:
        fname = "pe11.txt"
    if argc > 2:
        n = int(argv[2])
    else:
        n = 4

    try:
        pe11(fname, n)
    except FileNotFoundError:
        print("""file not found: %s

  python pe11.py [filepath [integer]]""" % fname)

if __name__ == "__main__":
    main()
