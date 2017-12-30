package ktn.pe

import org.hamcrest.CoreMatchers.`is`
import org.junit.Assert.*

import org.junit.Test

class Pe10Test {

    @Test
    fun test() {
        val pe10 = Pe10()

        assertThat("0 0", pe10.pe10(0), `is`(0L))
        assertThat("2 2", pe10.pe10(2), `is`(2L))
        assertThat("3 5", pe10.pe10(3), `is`(5L))
        assertThat("5 10", pe10.pe10(5), `is`(10L))
        assertThat("7 17", pe10.pe10(7), `is`(17L))
    }

}
