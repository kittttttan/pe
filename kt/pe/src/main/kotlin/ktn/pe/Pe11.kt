package ktn.pe

import java.io.BufferedReader
import java.io.File
import java.io.FileInputStream
import java.io.IOException
import java.io.InputStreamReader

class Pe11 : Pe {
    private val width = 20
    private val height = 20

    var fname = DEFAULT_FILENAME

    override val problemNumber: Int
        get() = 11

    private fun loadFile(nums: Array<IntArray>, file: File?) {
        if (file == null) {
            return
        }

        try {
            FileInputStream(file).use({ fis ->
                InputStreamReader(fis, "UTF-8").use({ isr ->
                    BufferedReader(isr).use({ br ->
                        var w = 0
                        var h = 0
                        var n = 0
                        var ch: Int
                        while (true) {
                            ch = br.read()
                            if ('0'.toInt() <= ch && ch <= '9'.toInt()) {
                                n = 10 * n + (ch - '0'.toInt())
                            } else if (n > 0) {
                                nums[h][w] = n
                                n = 0
                                ++w
                                if (w >= width) {
                                    w = 0
                                    ++h
                                    if (h >= height) {
                                        break
                                    }
                                }
                            }
                            if (ch < 0) {
                                break
                            }
                        }
                    })
                })
            })
        } catch (e: IOException) {
            e.printStackTrace()
        }

    }

    @JvmOverloads
    fun pe11(fname: String = DEFAULT_FILENAME): Int {
        val nums = Array(height) { IntArray(width) }
        val file = File(fname)
        loadFile(nums, file)

        var m = 0
        var ud: Int
        var lr: Int
        var d0: Int
        var d1: Int
        for (i in 0..19) {
            for (j in 0..19) {
                d1 = 1
                d0 = d1
                lr = d0
                ud = lr
                for (k in 0..3) {
                    if (i < 16) {
                        lr *= nums[i + k][j]
                    } else {
                        lr = 0
                    }
                    if (j < 16) {
                        ud *= nums[i][j + k]
                    } else {
                        ud = 0
                    }
                    if (i < 16 && j < 16) {
                        d0 *= nums[i + k][j + k]
                        d1 *= nums[i + k][j + 4 - k]
                    } else {
                        d1 = 0
                        d0 = d1
                    }
                }
                if (m < ud) {
                    m = ud
                }
                if (m < lr) {
                    m = lr
                }
                if (m < d0) {
                    m = d0
                }
                if (m < d1) {
                    m = d1
                }
            }
        }

        return m
    }

    override fun run() {
        solve()
    }

    override fun setArgs(args: Array<String>) {
        if (args.isNotEmpty()) {
            fname = args[0]
        }
    }

    override fun solve() {
        System.out.println(PeUtils.format(this, pe11()))
    }

    companion object {
        private const val DEFAULT_FILENAME = "../../res/pe11.txt"
    }

}
