package ktn.pe

class Pe12 : Pe {
    private var _over = 500

    override val problemNumber: Int
        get() = 12

    fun pe12(over: Int = _over): Int {
        var t = 1
        var i = 2
        var count: Int
        while (true) {
            count = PeUtils.countDivisors(t.toLong())
            if (count >= over) {
                break
            }
            t += i
            ++i
        }

        return t
    }

    override fun run() {
        solve()
    }

    override fun setArgs(args: Array<String>) {
        if (args.isNotEmpty()) {
            _over = args[0].toInt()
        }
    }

    override fun solve() {
        System.out.println(PeUtils.format(this, pe12()))
    }

}
