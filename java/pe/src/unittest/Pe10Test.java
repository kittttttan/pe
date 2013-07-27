package unittest;

import static org.hamcrest.CoreMatchers.is;
import static org.junit.Assert.*;
import ktn.pe.Pe10;

import org.junit.Test;

public class Pe10Test {

    @Test
    public void test() {
        Pe10 pe10 = new Pe10();
        
        assertThat("0 0", pe10.pe10(0), is(0L));
        assertThat("2 2", pe10.pe10(2), is(2L));
        assertThat("3 5", pe10.pe10(3), is(5L));
        assertThat("5 10", pe10.pe10(5), is(10L));
        assertThat("7 17", pe10.pe10(7), is(17L));
    }

}
