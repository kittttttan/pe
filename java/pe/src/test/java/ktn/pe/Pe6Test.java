package ktn.pe;

import static org.junit.Assert.*;
import static org.hamcrest.CoreMatchers.*;

import org.junit.Test;

public class Pe6Test {

    @Test
    public void test() {
        Pe6 pe6 = new Pe6();
        
        assertThat("0 0", pe6.pe6(0), is(0));
        assertThat("1 0", pe6.pe6(1), is(0));
        assertThat("2 4", pe6.pe6(2), is(4));
        assertThat("3 22", pe6.pe6(3), is(22));
    }

}
