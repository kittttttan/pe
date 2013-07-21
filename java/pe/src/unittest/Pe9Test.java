package unittest;

import static org.junit.Assert.*;
import static org.hamcrest.CoreMatchers.*;
import ktn.pe.Pe9;

import org.junit.Test;

public class Pe9Test {

    @Test
    public void test() {
        assertThat("0 0", Pe9.pe9(0), is(0));
        assertThat("12 60", Pe9.pe9(12), is(60));
    }

}
