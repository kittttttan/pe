#! /usr/bin/env python3

def is_lychrel(n):
    ss = str(n)[::-1]
    for i in range(50):
        n += int(ss)
        s = str(n)
        ss = s[::-1]
        if s == ss:
            return False
    return True

def pe55(limit=10000):
    """
    How many Lychrel numbers are there below ten-thousand?
    """
    return sum(1 for i in range(limit) if is_lychrel(i))

if __name__ == "__main__":
    print(pe55())
