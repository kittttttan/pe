package ktn.pe;

import static org.junit.Assert.*;
import static org.hamcrest.CoreMatchers.*;

import org.junit.Test;

public class Pe4Test {
    private final Pe4 pe4 = new Pe4();
    
    @Test
    public void test() {
        assertThat("0 0", pe4.pe4(0), is(0));
        assertThat("2 9009", pe4.pe4(2), is(9009));
    }

    @Test
    public void palindromeTrueTest() {
        assertThat("0 true", pe4.isPalindrome(0), is(true));
        assertThat("77 true", pe4.isPalindrome(77), is(true));
        assertThat("12321 true", pe4.isPalindrome(12321), is(true));
    }

    @Test
    public void palindromeFalseTest() {
        assertThat("-1 false", pe4.isPalindrome(-1), is(false));
        assertThat("37 false", pe4.isPalindrome(37), is(false));
        assertThat("12320 false", pe4.isPalindrome(12320), is(false));
    }
}
