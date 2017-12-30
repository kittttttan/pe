package ktn.pe

import java.util.logging.Logger

class Pe2 : Pe {

    private var limit: Long = 4000000

    override val problemNumber: Int
        get() = 2

    fun pe2(limit: Long): Long {
        var sum: Long = 2
        var a: Long = 1
        var b: Long = 2
        var t: Long

        while (b <= limit) {
            t = b
            b += a
            logger.fine(b.toString())
            a = t
            if (b and 1 == 0L) {
                sum += b
            }
        }

        return sum
    }

    override fun setArgs(args: Array<String>) {
        if (args.isNotEmpty()) {
            limit = args[0].toLong()
        }
    }

    override fun solve() {
        System.out.println(PeUtils.format(this, pe2(limit)))
    }

    override fun run() {
        solve()
    }

    companion object {
        private val logger = Logger.getLogger(Pe2::class.java.name)
    }
}
