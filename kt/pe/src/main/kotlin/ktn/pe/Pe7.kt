package ktn.pe

import java.util.Arrays

class Pe7 : Pe {
    private var index = 10001

    override val problemNumber: Int
        get() = 7

    fun pe7(n: Int): Int {
        if (n < 1) {
            return 0
        }

        val times = if (n < 50) { 5.0 }
                    else { Math.log(n.toDouble()) + 2.0 }
        val limit = (n * times).toInt()

        val s = BooleanArray(limit + 1)
        Arrays.fill(s, true)
        s[0] = false
        s[1] = false

        val sq = Math.sqrt(limit.toDouble()).toInt()
        for (i in 2 until sq + 1) {
            var j = i * i
            while (j < limit + 1) {
                s[j] = false
                j += i
            }
        }

        var prime = 0
        var i = 0
        while (true) {
            if (s[prime]) {
                ++i
                if (i >= n) {
                    break
                }
            }
            ++prime
        }

        return prime
    }

    override fun setArgs(args: Array<String>) {
        if (args.isNotEmpty()) {
            index = args[0].toInt()
        }
    }

    override fun solve() {
        System.out.println(PeUtils.format(this, pe7(index)))
    }

    override fun run() {
        solve()
    }

}
