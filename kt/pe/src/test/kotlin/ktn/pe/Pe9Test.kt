package ktn.pe

import org.junit.Assert.*
import org.hamcrest.CoreMatchers.*

import org.junit.Test

class Pe9Test {

    @Test
    fun test() {
        val pe9 = Pe9()

        assertThat("0 0", pe9.pe9(0), `is`(0))
        assertThat("12 60", pe9.pe9(12), `is`(60))
    }

}
