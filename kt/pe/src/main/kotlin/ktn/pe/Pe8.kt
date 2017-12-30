package ktn.pe

import java.io.BufferedReader
import java.io.File
import java.io.FileInputStream
import java.io.IOException
import java.io.InputStreamReader
import java.util.logging.Logger

class Pe8 : Pe {

    var fname = DEFAULT_FILENAME
    private var digits = 5

    override val problemNumber: Int
        get() = 8

    private fun loadFile(file: File): String {
        val buf = StringBuffer()
        try {
            FileInputStream(file).use({ fis ->
                InputStreamReader(fis, "UTF-8").use({ isr ->
                    BufferedReader(isr).use({ br ->
                        var line: String?
                        while (true) {
                            line = br.readLine()
                            if (line == null) { break; }
                            buf.append(line)
                        }
                    })
                })
            })
        } catch (e: IOException) {
            logger.severe(e.toString())
        }

        return buf.toString()
    }

    fun product(numbers: String, n: Int): Int {
        var m = 1
        var t: Int
        val length = numbers.length
        for (i in 0 until length - n + 1) {
            t = 1
            for (j in 0 until n) {
                t *= numbers[i + j] - '0'
            }
            if (m < t) {
                m = t
            }
        }

        return m
    }

    fun pe8(n: Int): Int {
        return pe8(fname, n)
    }

    @JvmOverloads
    fun pe8(fname: String = DEFAULT_FILENAME, n: Int = digits): Int {
        val file = File(fname)
        val numbers = loadFile(file)
        logger.fine(numbers)

        return product(numbers, n)
    }

    override fun setArgs(args: Array<String>) {
        if (args.isNotEmpty()) {
            digits = args[0].toInt()
        }
        if (args.size > 1) {
            fname = args[1]
        }
    }

    override fun solve() {
        System.out.println(PeUtils.format(this, pe8()))
    }

    override fun run() {
        solve()
    }

    companion object {
        private val logger = Logger.getLogger(Pe8::class.java.name)
        private const val DEFAULT_FILENAME = "../../res/pe8.txt"
    }

}
