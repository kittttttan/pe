package ktn.pe

interface Pe : Runnable {
    val problemNumber: Int

    fun setArgs(args: Array<String>)
    fun solve()
}
