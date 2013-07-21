package unittest;

import static org.junit.Assert.*;
import static org.hamcrest.CoreMatchers.*;

import java.util.ArrayList;
import java.util.List;

import ktn.pe.Pe3;

import org.junit.Test;

public class Pe3Test {

    @Test
    public void test() {
        List<Long> divisors = new ArrayList<Long>();

        Pe3.pe3(divisors, 0L);
        assertTrue("0 []", divisors.isEmpty());
        divisors.clear();

        Pe3.pe3(divisors, 12L);
        assertThat("12 [2,2,3]", divisors, hasItems(new Long[] { 2L, 2L, 3L }));
        divisors.clear();

        Pe3.pe3(divisors, 97L);
        assertThat("97 [97]", divisors, hasItems(new Long[] { 97L }));
        divisors.clear();
    }

}
