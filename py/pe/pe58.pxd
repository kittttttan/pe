cimport cython

cdef list primes2

@cython.locals(p = cython.long)
cdef bint is_prime2(long n)

@cython.locals(l = cython.long, ps = cython.long, d = cython.long, ds = cython.long)
cdef long pe58(double p=*)

cdef main()
