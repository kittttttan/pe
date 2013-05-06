#! /usr/bin/env python3

from sys import argv

to20 = ['', 'one', 'two', 'three', 'four', 'five', 'six', 'seven',
        'eight', 'nine', 'ten', 'eleven', 'twelve', 'thirteen', 'fourteen',
        'fifteen', 'sixteen', 'seventeen', 'eighteen', 'nineteen']

ty = ['twenty', 'thirty', 'forty', 'fifty',
      'sixty', 'seventy', 'eighty', 'ninety']

def spell1(n):
    if n < 20:
        return to20[n]
    d = n // 10
    e = n % 10
    return ty[d-2] + to20[e]

def spell2(n):
    if n < 100:
        return spell1(n)
    h = n // 100
    d = n % 100
    d = spell1(d)
    if not d:
        return to20[h] + 'hundred'
    return to20[h] + 'hundredand' + d

def spell3(n):
    if n < 1000:
        return spell2(n)
    t = n // 1000
    h = n % 1000
    h = spell2(h)
    if not h:
        return spell2(t) + 'thousand'
    return spell2(t) + 'thousandand' + h

def pe17(n=1000):
    """
    How many letters would be needed
    to write all the numbers in words from 1 to 1000?
    """
    if n > 99999:
        raise ValueError("too large")
    return sum([len(spell3(i)) for i in range(1, n + 1)])

def main():
    argc = len(argv)
    if argc > 1:
        try:
            n = int(argv[1])
        except ValueError:
            print("  python pe17.py [integer]")
            return
    else:
        n = 1000

    print(pe17(n))

if __name__ == "__main__":
    main()
