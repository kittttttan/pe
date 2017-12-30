package ktn.pe

import org.junit.Assert.*
import org.hamcrest.CoreMatchers.*

import org.junit.Test

class Pe7Test {

    @Test
    fun test() {
        val pe7 = Pe7()

        assertThat("0 0", pe7.pe7(0), `is`(0))
        assertThat("1 2", pe7.pe7(1), `is`(2))
        assertThat("2 3", pe7.pe7(2), `is`(3))
        assertThat("3 5", pe7.pe7(3), `is`(5))
        assertThat("4 7", pe7.pe7(4), `is`(7))
        assertThat("5 11", pe7.pe7(5), `is`(11))
    }

}
