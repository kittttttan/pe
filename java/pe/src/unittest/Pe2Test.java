package unittest;

import static org.junit.Assert.*;
import static org.hamcrest.CoreMatchers.*;
import ktn.pe.Pe2;

import org.junit.Test;

public class Pe2Test {

    @Test
    public void test() {
        Pe2 pe2 = new Pe2();
        
        assertThat("0 2", pe2.pe2(0L), is(2L));
        assertThat("8 10", pe2.pe2(8L), is(10L));
    }

}
