package unittest;

import static org.junit.Assert.*;
import static org.hamcrest.CoreMatchers.*;
import ktn.pe.Pe2;

import org.junit.Test;

public class Pe2Test {

    @Test
    public void test() {
        assertThat("0 2", Pe2.pe2(0L), is(2L));
        assertThat("8 10", Pe2.pe2(8L), is(10L));
    }

}
