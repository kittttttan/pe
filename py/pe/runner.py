#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import absolute_import, print_function, unicode_literals
from __init__ import LAST
from timeit import timeit

def main():
    rep = 1
    try:
        while True:
            s = input('pe> ')
            if not s:
                break
            try:
                n = int(s)
                if n < 1 or n > LAST:
                    raise ValueError('Invalid value: {0}'.format(n))
            except:
                print('Invalid number: {0}'.format(s))
                continue
            t = timeit('print(pe{0}())'.format(n), setup='from pe{0} import pe{1}'.format(n, n), number=rep)
            print('{0}s at {1} times'.format(t, rep))
    except (SyntaxError, EOFError, KeyboardInterrupt, NameError):
        pass

if __name__ == "__main__":
    main()
