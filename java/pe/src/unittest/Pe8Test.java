package unittest;

import static org.junit.Assert.*;
import static org.hamcrest.CoreMatchers.*;
import ktn.pe.Pe8;

import org.junit.Before;
import org.junit.Test;

public class Pe8Test {
    private Pe8 pe8 = new Pe8();

    @Before
    public void setUp() throws Exception {
        pe8.setFname("../../res/pe8.txt");
    }

    @Test
    public void test() {
        assertThat("0 1", pe8.pe8(0), is(1));
        assertThat("1 9", pe8.pe8(1), is(9));
    }

    @Test
    public void testProduct() {
        assertThat("0 1", pe8.product("", 0), is(1));
        assertThat("123456789 1 9", pe8.product("123456789", 1), is(9));
        assertThat("123456789 2 72", pe8.product("123456789", 2), is(72));
    }
}
