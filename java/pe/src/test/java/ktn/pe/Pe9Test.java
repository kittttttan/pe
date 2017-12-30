package ktn.pe;

import static org.junit.Assert.*;
import static org.hamcrest.CoreMatchers.*;

import org.junit.Test;

public class Pe9Test {

    @Test
    public void test() {
        Pe9 pe9 = new Pe9();
        
        assertThat("0 0", pe9.pe9(0), is(0));
        assertThat("12 60", pe9.pe9(12), is(60));
    }

}
