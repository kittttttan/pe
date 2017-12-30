package ktn.pe

class Pe9 : Pe {
    private var limit = 1000

    override val problemNumber: Int
        get() = 9

    fun pe9(limit: Int): Int {
        val last = (limit shr 1) + 1
        for (x in 1 until last) {
            val x2 = x * x
            for (y in x until last) {
                val z = limit - x - y
                if (x2 + y * y == z * z) {
                    return x * y * z
                }
            }
        }

        return 0
    }

    override fun setArgs(args: Array<String>) {
        if (args.isNotEmpty()) {
            limit = args[0].toInt()
        }
    }

    override fun solve() {
        System.out.println(PeUtils.format(this, pe9(limit)))
    }

    override fun run() {
        solve()
    }

}
