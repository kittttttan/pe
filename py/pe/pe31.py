#!/usr/bin/env python
"""
How many different ways can L2 be made using any number of coins?
"""

def pe31(target=200):
    """
    >>> pe31()
    
    """
    coins = [1, 2, 5, 10, 20, 50, 100, 200]
    ways = [1] + [0] * target
    for coin in coins:
        for i in range(coin, target + 1):
            ways[i] += ways[i - coin]
    return ways[target]

if __name__ == "__main__":
    import doctest
    doctest.testmod()

    try:
        while True:
            s = input('> ')
            n = int(s)
            print(pe31(n))
    except (SyntaxError, EOFError, KeyboardInterrupt, NameError):
        pass
