package ktn.pe

import org.junit.Assert.*
import org.hamcrest.CoreMatchers.*

import org.junit.Before
import org.junit.Test

class Pe8Test {
    private val pe8 = Pe8()

    @Before
    @Throws(Exception::class)
    fun setUp() {
        pe8.fname = "../../res/pe8.txt"
    }

    @Test
    fun test() {
        assertThat("0 1", pe8.pe8(0), `is`(1))
        assertThat("1 9", pe8.pe8(1), `is`(9))
    }

    @Test
    fun testProduct() {
        assertThat("0 1", pe8.product("", 0), `is`(1))
        assertThat("123456789 1 9", pe8.product("123456789", 1), `is`(9))
        assertThat("123456789 2 72", pe8.product("123456789", 2), `is`(72))
    }
}
