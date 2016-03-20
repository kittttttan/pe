cimport cython

@cython.locals(sq = cython.long, m = cython.long, i = cython.long)
cdef list sieve(long n)
