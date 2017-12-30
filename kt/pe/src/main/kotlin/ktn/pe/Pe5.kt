package ktn.pe

class Pe5 : Pe {
    private var to = 20

    override val problemNumber: Int
        get() = 5

    fun pe5(to: Int): Long {
        var mul = 1L

        if (to < 2) {
            return mul
        }
        mul = 2L
        val factors = mutableListOf<Int>()
        factors.add(2)

        var x: Int
        for (i in 3 until to + 1) {
            x = i
            for (factor in factors) {
                if (x % factor == 0) {
                    x /= factor
                }
                if (x < factor) {
                    break
                }
            }

            if (x > 1) {
                factors.add(x)
                mul *= x.toLong()
            }
        }

        return mul
    }

    override fun setArgs(args: Array<String>) {
        if (args.isNotEmpty()) {
            to = args[0].toInt(10)
        }
    }

    override fun solve() {
        System.out.println(PeUtils.format(this, pe5(to)))
    }

    override fun run() {
        solve()
    }

}
