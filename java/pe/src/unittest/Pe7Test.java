package unittest;

import static org.junit.Assert.*;
import static org.hamcrest.CoreMatchers.*;
import ktn.pe.Pe7;

import org.junit.Test;

public class Pe7Test {

    @Test
    public void test() {
        assertThat("0 0", Pe7.pe7(0), is(0));
        assertThat("1 2", Pe7.pe7(1), is(2));
        assertThat("2 3", Pe7.pe7(2), is(3));
        assertThat("3 5", Pe7.pe7(3), is(5));
        assertThat("4 7", Pe7.pe7(4), is(7));
        assertThat("5 11", Pe7.pe7(5), is(11));
    }

}
