package unittest;

import static org.junit.Assert.*;
import static org.hamcrest.CoreMatchers.*;
import ktn.pe.Pe8;

import org.junit.Test;

public class Pe8Test {

    @Test
    public void test() {
        String fname = "../../res/pe8.txt";

        assertThat("0 1", Pe8.pe8(fname, 0), is(1));
        assertThat("1 9", Pe8.pe8(fname, 1), is(9));
    }

    @Test
    public void testProduct() {
        assertThat("0 1", Pe8.product("", 0), is(1));
        assertThat("123456789 1 9", Pe8.product("123456789", 1), is(9));
        assertThat("123456789 2 72", Pe8.product("123456789", 2), is(72));
    }
}
