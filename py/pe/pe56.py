#!/usr/bin/env python

def pe56(alimit=100, blimit=100):
    """
    Considering natural numbers of the form, ab,
    finding the maximum digital sum.
    """
    m = 0
    for a in range(11, alimit):
        for b in range(11, blimit):
            s = sum(int(digit) for digit in str(a**b))
            if s > m:
                m, ma, mb = s, a, b
    return (m, ma, mb)

if __name__ == "__main__":
    print(pe56())
