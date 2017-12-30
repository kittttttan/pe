package ktn.pe

import org.junit.Assert.*
import org.hamcrest.CoreMatchers.*

import org.junit.Test

class Pe2Test {

    @Test
    fun test() {
        val pe2 = Pe2()

        assertThat("0 2", pe2.pe2(0L), `is`(2L))
        assertThat("8 10", pe2.pe2(8L), `is`(10L))
    }

}
