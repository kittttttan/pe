#!/usr/bin/env python
"""
How many letters would be needed
to write all the numbers in words from 1 to 1000?
"""

_TO20 = ['', 'one', 'two', 'three', 'four', 'five', 'six', 'seven',
        'eight', 'nine', 'ten', 'eleven', 'twelve', 'thirteen', 'fourteen',
        'fifteen', 'sixteen', 'seventeen', 'eighteen', 'nineteen']

_TY = ['twenty', 'thirty', 'forty', 'fifty',
      'sixty', 'seventy', 'eighty', 'ninety']

def spell1(n):
    if n < 20:
        return _TO20[n]
    d = n // 10
    e = n % 10
    return _TY[d - 2] + _TO20[e]

def spell2(n):
    if n < 100:
        return spell1(n)
    h = n // 100
    d = spell1(n % 100)
    if not d:
        return _TO20[h] + 'hundred'
    return _TO20[h] + 'hundredand' + d

def spell3(n):
    if n < 1000:
        return spell2(n)
    t = n // 1000
    h = spell2(n % 1000)
    if not h:
        return spell2(t) + 'thousand'
    return spell2(t) + 'thousandand' + h

def pe17(n=1000):
    """
    >>> pe17()
    21124
    """
    if n > 99999:
        raise ValueError("too large")
    return sum(len(spell3(i)) for i in range(1, n + 1))

if __name__ == "__main__":
    import doctest
    doctest.testmod()

    try:
        while True:
            s = input('> ')
            n = int(s)
            print(pe17(n))
    except (SyntaxError, EOFError, KeyboardInterrupt, NameError):
        pass
