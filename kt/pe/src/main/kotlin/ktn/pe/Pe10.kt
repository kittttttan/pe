package ktn.pe

import java.util.Arrays

class Pe10 : Pe {
    private var limit = 2000000

    override val problemNumber: Int
        get() = 10

    fun pe10(n: Int = limit): Long {
        if (n < 2) {
            return 0
        }

        val primes = BooleanArray(n + 1)
        Arrays.fill(primes, true)
        primes[0] = false
        primes[1] = false

        val sq = Math.sqrt(n.toDouble()).toInt()
        for (i in 2 until sq + 1) {
            if (primes[i]) {
                var j = i * i
                while (j < n + 1) {
                    primes[j] = false
                    j += i
                }
            }
        }

        return (0 until n + 1)
                .filter { primes[it] }
                .map { it.toLong() }
                .sum()
    }

    override fun run() {
        solve()
    }

    override fun setArgs(args: Array<String>) {
        if (args.isNotEmpty()) {
            limit = args[0].toInt()
        }
    }

    override fun solve() {
        System.out.println(PeUtils.format(this, pe10()))
    }

}
