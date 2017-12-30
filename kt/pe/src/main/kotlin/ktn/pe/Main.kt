package ktn.pe

import java.util.Arrays
import java.util.concurrent.Executors
import java.util.concurrent.TimeUnit

/**
 *
 */
object Main {
    private const val PROBLEM_MIN = 1
    private const val PROBLEM_MAX = 12
    private const val THREAD_COUNT = 4

    /**
     * @param args
     * problemNumber options...
     */
    @JvmStatic
    fun main(args: Array<String>) {
        if (args.isEmpty()) {
            help()
        } else if ("-h" == args[0] || "--help" == args[0]) {
            help()
        } else if ("-a" == args[0]) {
            solveAll()
        } else if ("-A" == args[0]) {
            var n = -1
            if (args.size > 1) {
                n = args[1].toInt()
            }
            solveAllAsync(n)
        } else {
            if (!solve(args)) {
                help()
            }
        }
    }

    /**
     * Show help
     */
    private fun help() {
        println("problemNumber options...")
        println("-a      all")
        println("-A [n]  all async with n threads")
        println("-h      help")
    }

    /**
     *
     * @param n
     * @return
     */
    private fun loadClassName(n: Int): String {
        return Main::class.java.`package`.name + ".Pe" + n
    }

    /**
     *
     * @param args
     * commandline options
     * @return true means
     */
    internal fun solve(args: Array<String>): Boolean {
        var done = false

        try {
            val n = args[0].toInt()
            if (n < PROBLEM_MIN || n > PROBLEM_MAX) {
                return done
            }

            val loader = ClassLoader.getSystemClassLoader()
            val clazz = loader.loadClass(loadClassName(n))
            val pe = clazz.newInstance() as Pe

            val shiftedArgs = Arrays.copyOfRange(args, 1, args.size)
            pe.setArgs(shiftedArgs)

            val start = System.currentTimeMillis()

            pe.solve()

            val stop = System.currentTimeMillis()
            println((stop - start).toString() + " ms")

            done = true
        } catch (e: NumberFormatException) {
            System.err.println(e.toString())
        } catch (e: ClassNotFoundException) {
            System.err.println(e.toString())
        } catch (e: InstantiationException) {
            System.err.println(e.toString())
        } catch (e: IllegalAccessException) {
            System.err.println(e.toString())
        }

        return done
    }

    private fun solveAll() {
        val loader = ClassLoader.getSystemClassLoader()
        var clazz: Class<*>
        var pe: Pe
        val start = System.currentTimeMillis()
        try {
            for (i in PROBLEM_MIN until PROBLEM_MAX + 1) {
                clazz = loader.loadClass(loadClassName(i))
                pe = clazz.newInstance() as Pe
                pe.solve()
            }
        } catch (e: ClassNotFoundException) {
            e.printStackTrace()
        } catch (e: InstantiationException) {
            e.printStackTrace()
        } catch (e: IllegalAccessException) {
            e.printStackTrace()
        }

        val stop = System.currentTimeMillis()
        println((stop - start).toString() + " ms")
    }

    private fun solveAllAsync(n: Int) {
        var threadCount = THREAD_COUNT
        if (n > 0) {
            threadCount = n
        }
        val executor = Executors.newFixedThreadPool(threadCount)
        val loader = ClassLoader.getSystemClassLoader()

        val start = System.currentTimeMillis()
        try {
            (PROBLEM_MIN until PROBLEM_MAX + 1)
                    .map { loader.loadClass(loadClassName(it)) }
                    .map { it.getDeclaredConstructor().newInstance() as Pe }
                    .forEach { executor.execute(it) }
        } catch (e: ClassNotFoundException) {
            e.printStackTrace()
        } catch (e: InstantiationException) {
            e.printStackTrace()
        } catch (e: IllegalAccessException) {
            e.printStackTrace()
        }

        val awaitTime = (30 * 1000).toLong()
        try {
            executor.shutdown()

            if (!executor.awaitTermination(awaitTime, TimeUnit.MILLISECONDS)) {
                executor.shutdownNow()
            }
        } catch (e: InterruptedException) {
            println("awaitTermination interrupted: " + e)
            executor.shutdownNow()
        }

        val stop = System.currentTimeMillis()
        println((stop - start).toString() + " ms")
    }
}
