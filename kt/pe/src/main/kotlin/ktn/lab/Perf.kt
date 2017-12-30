package ktn.lab

import java.math.BigInteger

object Perf {
    internal fun fib(n: Int): BigInteger {
        var a = BigInteger.ONE
        var b = BigInteger.ZERO
        var c: BigInteger

        for (i in 1 until n) {
            c = a
            a = a.add(b)
            b = c
        }

        return a
    }
}
