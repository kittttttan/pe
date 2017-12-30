package ktn.pe

import org.junit.Assert.*
import org.hamcrest.CoreMatchers.*

import java.util.ArrayList

import org.junit.Test

class Pe3Test {

    @Test
    fun test() {
        val divisors = ArrayList<Long>()

        PeUtils.divisors(divisors, 0L)
        assertTrue("0 []", divisors.isEmpty())
        divisors.clear()

        PeUtils.divisors(divisors, 12L)
        assertThat<List<Long>>("12 [2,2,3]", divisors, hasItems(*arrayOf(2L, 2L, 3L)))
        divisors.clear()

        PeUtils.divisors(divisors, 97L)
        assertThat<List<Long>>("97 [97]", divisors, hasItems(*arrayOf(97L)))
        divisors.clear()
    }

}
