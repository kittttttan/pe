package ktn.pe

class Pe1 : Pe {
    private var limit = 1000

    override val problemNumber: Int
        get() = 1

    /**
     * double sum of 0, 1, ..., limit
     *
     * @param limit
     * @return
     */
    private fun sumToX2(limit: Int): Int {
        return limit * (limit + 1)
    }

    /**
     *
     * @param limit
     * @return
     */
    fun pe1(limit: Int): Int {
        var sum = 0

        if (limit > 2) {
            sum = (3 * sumToX2(limit / 3)
                + 5 * sumToX2(limit / 5)
                - 15 * sumToX2(limit / 15)) shr 1
        }

        return sum
    }

    /**
     *
     * @param limit
     * @return
     */
    fun pe1loop(limit: Int): Int {
        return (3..limit)
                .filter { it % 3 == 0 || it % 5 == 0 }
                .sum()
    }

    override fun setArgs(args: Array<String>) {
        if (args.isNotEmpty()) {
            limit = args[0].toInt()
        }
    }

    override fun solve() {
        println(PeUtils.format(this, pe1(limit)))
    }

    override fun run() {
        solve()
    }
}
