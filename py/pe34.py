#! /usr/bin/env python3

facts = (1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880)

def sdf(n):
    s = 0
    while n:
        d = n % 10
        s += facts[d]
        n //= 10
    return s

def pe34(limit=100000):
    """
    Find the sum of all numbers
    which are equal to the sum of the factorial of their digits.
    """
    # print([n for n in range(10, limit) if n == sdf(n)])
    return sum(n for n in range(145, limit) if n == sdf(n))

if __name__ == "__main__":
    print(pe34())
