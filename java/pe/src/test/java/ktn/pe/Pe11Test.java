package ktn.pe;

import static org.hamcrest.CoreMatchers.is;
import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

public class Pe11Test {
    private final Pe11 pe11 = new Pe11();

    @Before
    public void setUp() {
        pe11.setFname("../../res/pe11.txt");
    }

    @Test
    public void test() {
        assertThat("70600674", pe11.pe11(), is(70600674));
    }

}
