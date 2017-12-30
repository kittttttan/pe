package ktn.pe

import org.hamcrest.CoreMatchers.`is`
import org.junit.Assert.*

import org.junit.Before
import org.junit.Test

class Pe11Test {
    private val pe11 = Pe11()

    @Before
    @Throws(Exception::class)
    fun setUp() {
        pe11.fname = "../../res/pe11.txt"
    }

    @Test
    fun test() {
        assertThat("70600674", pe11.pe11(), `is`(70600674))
    }

}
