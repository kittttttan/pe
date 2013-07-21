package unittest;

import static org.junit.Assert.*;
import static org.hamcrest.CoreMatchers.*;
import ktn.pe.Pe4;

import org.junit.Test;

public class Pe4Test {
    @Test
    public void test() {
        assertThat("0 0", Pe4.pe4(0), is(0));
        assertThat("2 9009", Pe4.pe4(2), is(9009));
    }

    @Test
    public void palindromeTrueTest() {
        assertThat("0 true", Pe4.isPalindrome(0), is(true));
        assertThat("77 true", Pe4.isPalindrome(77), is(true));
        assertThat("12321 true", Pe4.isPalindrome(12321), is(true));
    }

    @Test
    public void palindromeFalseTest() {
        assertThat("-1 false", Pe4.isPalindrome(-1), is(false));
        assertThat("37 false", Pe4.isPalindrome(37), is(false));
        assertThat("12320 false", Pe4.isPalindrome(12320), is(false));
    }
}
