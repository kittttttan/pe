package ktn.pe;

import static org.junit.Assert.*;
import static org.hamcrest.CoreMatchers.*;

import org.junit.Test;

public class Pe5Test {

    @Test
    public void test() {
        Pe5 pe5 = new Pe5();
        
        assertThat("1 1", pe5.pe5(1), is(1L));
        assertThat("2 2", pe5.pe5(2), is(2L));
        assertThat("3 6", pe5.pe5(3), is(6L));
        assertThat("4 12", pe5.pe5(4), is(12L));
        assertThat("5 60", pe5.pe5(5), is(60L));
        assertThat("6 60", pe5.pe5(6), is(60L));
        assertThat("7 420", pe5.pe5(7), is(420L));
        assertThat("8 840", pe5.pe5(8), is(840L));
        assertThat("9 2520", pe5.pe5(9), is(2520L));
        assertThat("10 2520", pe5.pe5(10), is(2520L));
    }

}
