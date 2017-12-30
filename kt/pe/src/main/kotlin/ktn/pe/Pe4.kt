package ktn.pe

class Pe4 : Pe {
    private var digits = 3

    override val problemNumber: Int
        get() = 4

    /**
     *
     * @param n
     * @return
     */
    fun isPalindrome(n: Int): Boolean {
        val src = n.toString()
        val reversed = StringBuilder(src).reverse().toString()

        return src == reversed
    }

    /**
     *
     * @param digits
     * @return
     */
    fun pe4(digits: Int): Int {
        if (digits < 1) {
            return 0
        }
        if (digits > 12) {
            throw IllegalArgumentException("too large: " + digits)
        }

        val z = Math.pow(10.0, (digits - 1).toDouble()).toInt()
        val first = 9 * z + 1
        val last = 10 * z + 1
        var xy: Int
        var max = 0
        for (x in first until last) {
            for (y in x until last) {
                xy = x * y
                if (xy > max && isPalindrome(xy)) {
                    max = xy
                }
            }
        }

        return max
    }

    override fun setArgs(args: Array<String>) {
        if (args.isNotEmpty()) {
            digits = args[0].toInt()
        }
    }

    override fun solve() {
        System.out.println(PeUtils.format(this, pe4(digits)))
    }

    override fun run() {
        solve()
    }
}
