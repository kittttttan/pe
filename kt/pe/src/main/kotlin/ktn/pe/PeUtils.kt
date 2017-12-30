package ktn.pe

class PeUtils {
    companion object {
        fun <T> format(pe: Pe, result: T): String {
            return String.format("%3d: ", pe.problemNumber) + result
        }

        fun <T> format(pe: Pe, result: List<T>): String {
            val s = String.format("%3d:", pe.problemNumber)
            val buf = StringBuffer(s)
            for (r in result) {
                buf.append(' ')
                buf.append(r.toString())
            }
            return buf.toString()
        }

        fun countDivisors(n: Long): Int {
            val divisors = mutableListOf<Long>()
            divisors(divisors, n)
            val pl = divisors.size
            if (pl == 1) {
                return 2
            }

            var t = 0
            var c = 1
            for (i in 0 until pl) {
                if (i + 1 < pl && divisors[i] == divisors[i + 1]) {
                    t += 1
                } else {
                    c *= t + 2
                    t = 0
                }
            }

            return c
        }

        fun divisors(divisors: MutableList<Long>, n: Long) {
            var nAbs = n
            if (nAbs == 0L) {
                return
            }
            if (nAbs < 0) {
                nAbs = -n
                divisors.add(-1L)
            }

            while (nAbs and 1 == 0L) {
                divisors.add(2L)
                nAbs = nAbs shr 1
            }

            var limit = Math.sqrt(nAbs.toDouble()).toLong()
            if (limit < 3L) {
                limit = 3L
            }

            var i = 3L
            while (i <= limit) {
                if (nAbs % i == 0L) {
                    divisors.add(i)
                    nAbs /= i
                    if (nAbs < i) {
                        break
                    }
                } else {
                    i += 2
                }
            }
            if (nAbs > 1) {
                divisors.add(nAbs)
            }
        }
    }
}
