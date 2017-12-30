package ktn.pe

class Pe6 : Pe {
    private var n = 100

    override val problemNumber: Int
        get() = 6

    /**
     * (n(n+1)/2)^2 - n(n+1)(2n+1)/6
     *
     * @param n
     * @return
     */
    fun pe6(n: Int): Int {
        return n * (n + 1) * (n - 1) * (3 * n + 2) / 12
    }

    override fun setArgs(args: Array<String>) {
        if (args.isNotEmpty()) {
            n = args[0].toInt()
        }
    }

    override fun solve() {
        System.out.println(PeUtils.format(this, pe6(n)))
    }

    override fun run() {
        solve()
    }

}
