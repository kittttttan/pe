#!/usr/bin/env python
"""
If p is the perimeter of a right angle triangle, {a, b, c},
which value, for p <= 1000, has the most solutions?
"""

def pe39(limit=1000):
    """
    >>> pe39()
    (840, 8)
    """
    # py = []
    ps = []
    for a in range(1, limit // 3):
        a2 = a * a
        for b in range(a, (limit - a) >> 1):
            cc = (a2 + b * b)**0.5
            c = int(cc)
            if cc == c:
                # py.append((a, b, c, a + b + c))
                ps.append(a + b + c)
    # print(py)
    ps.sort()
    lp = len(ps) - 1
    mp, ms = 0, 0
    cnt = 1
    for i in range(lp):
        if ps[i] == ps[i + 1]:
            cnt += 1
        else:
            if cnt > ms:
                mp, ms = ps[i], cnt
            cnt = 1
    return (mp, ms)

if __name__ == "__main__":
    import doctest
    doctest.testmod()

    try:
        while True:
            s = input('> ')
            n = int(s)
            print(pe39(n))
    except (SyntaxError, EOFError, KeyboardInterrupt, NameError):
        pass
