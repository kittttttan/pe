#! /usr/bin/env python3

from sys import argv

def pe24(n=999999):
    """
    What is the millionth lexicographic permutation of the digits
    0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
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
    print(''.join(res))

def main():
    argc = len(argv)
    if argc > 1:
        try:
            n = int(argv[1])
        except ValueError:
            print("  python pe24.py [integer]")
            return
    else:
        n = 999999

    print(pe24(n))

if __name__ == "__main__":
    main()
