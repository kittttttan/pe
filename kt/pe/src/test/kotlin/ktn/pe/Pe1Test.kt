package ktn.pe

import org.junit.Assert.*
import org.hamcrest.CoreMatchers.*

import org.junit.Test

class Pe1Test {

    @Test
    fun test() {
        val pe1 = Pe1()
        assertThat("0 0", pe1.pe1(0), `is`(0))
        assertThat("1 0", pe1.pe1(1), `is`(0))
        assertThat("2 0", pe1.pe1(2), `is`(0))
        assertThat("3 3", pe1.pe1(3), `is`(3))
        assertThat("4 3", pe1.pe1(4), `is`(3))
        assertThat("5 8", pe1.pe1(5), `is`(8))
        assertThat("6 14", pe1.pe1(6), `is`(14))
    }

}
