package ktn.pe

class Pe3 : Pe {
    private var n: Long = 0

    override val problemNumber: Int
        get() = 3

    init {
        n = 600851475143L
    }

    override fun setArgs(args: Array<String>) {
        if (args.isNotEmpty()) {
            n = args[0].toLong()
        }
    }

    override fun solve() {
        val divisors = mutableListOf<Long>()
        PeUtils.divisors(divisors, n)
        System.out.println(PeUtils.format(this, divisors))
    }

    override fun run() {
        solve()
    }
}
