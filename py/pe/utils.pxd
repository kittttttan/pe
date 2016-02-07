cimport cython

@cython.locals(times = cython.double, n0 = cython.long, sq = cython.long, s = list, m = cython.long, i = cython.long, j = cython.long)
cdef long get_prime(long n)

@cython.locals(sq = cython.long, m = cython.long, i = cython.long)
cdef list sieve(long n)

cdef bint is_prime(long n)

@cython.locals(p = cython.long)
cdef bint is_prime2(long n)

@cython.locals(p = cython.long, limit = cython.long, i = cython.long)
cdef list get_divisors(long n)

@cython.locals(pl = cython.long, t = cython.long, c = cython.long, i = cython.long)
cdef long count_divisors(long n)

cdef long count_distinct(long n)

@cython.locals(s = cython.bytes)
cdef bint is_palindrome(long n)

@cython.locals(f = cython.long, i = cython.long)
cdef long perm(long n, long m)

@cython.locals(c = cython.long, d = cython.long)
cdef long comb(long n, long m)

@cython.locals(s = cython.longlong)
cdef long long pod(long n, long p)

@cython.locals(s = cython.long)
cdef long sod(long n)

@cython.locals(s = cython.long, sq = cython.double, isq = cython.long, i = cython.long)
cdef long spd(long n)

cdef long word_worth(bytes sets)

@cython.locals(s = cython.long)
cdef long list_num(list l)
