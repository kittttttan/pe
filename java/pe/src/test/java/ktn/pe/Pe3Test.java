package ktn.pe;

import static org.junit.Assert.*;
import static org.hamcrest.CoreMatchers.*;

import java.util.ArrayList;
import java.util.List;

import ktn.pe.util.PeUtils;

import org.junit.Test;

public class Pe3Test {

    @Test
    public void test() {
        List<Long> divisors = new ArrayList<>();

        PeUtils.divisors(divisors, 0L);
        assertTrue("0 []", divisors.isEmpty());
        divisors.clear();

        PeUtils.divisors(divisors, 12L);
        assertThat("12 [2,2,3]", divisors, hasItems(2L, 2L, 3L));
        divisors.clear();

        PeUtils.divisors(divisors, 97L);
        assertThat("97 [97]", divisors, hasItems(97L));
        divisors.clear();
    }

}
