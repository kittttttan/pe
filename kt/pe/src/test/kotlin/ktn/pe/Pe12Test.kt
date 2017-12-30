package ktn.pe

import org.hamcrest.CoreMatchers.`is`
import org.junit.Assert.*

import org.junit.Test

class Pe12Test {

    @Test
    fun test() {
        val pe12 = Pe12()

        assertThat("0 1", pe12.pe12(0), `is`(1))
        assertThat("3 6", pe12.pe12(3), `is`(6))
        assertThat("5 28", pe12.pe12(5), `is`(28))
        assertThat("7 36", pe12.pe12(7), `is`(36))
    }

}
