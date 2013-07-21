package unittest;

import static org.junit.Assert.*;
import static org.hamcrest.CoreMatchers.*;
import ktn.pe.Pe1;

import org.junit.Test;

public class Pe1Test {

    @Test
    public void test() {
        assertThat("0 0", Pe1.pe1(0), is(0));
        assertThat("1 0", Pe1.pe1(1), is(0));
        assertThat("2 0", Pe1.pe1(2), is(0));
        assertThat("3 3", Pe1.pe1(3), is(3));
        assertThat("4 3", Pe1.pe1(4), is(3));
        assertThat("5 8", Pe1.pe1(5), is(8));
        assertThat("6 14", Pe1.pe1(6), is(14));
    }

}
