package unittest;

import static org.junit.Assert.*;
import static org.hamcrest.CoreMatchers.*;
import ktn.pe.Pe1;

import org.junit.Test;

public class Pe1Test {

	@Test
	public void test() {
		assertThat(Pe1.pe1(0), is(0));
		assertThat(Pe1.pe1(1), is(0));
		assertThat(Pe1.pe1(2), is(0));
		assertThat(Pe1.pe1(3), is(3));
		assertThat(Pe1.pe1(4), is(3));
		assertThat(Pe1.pe1(5), is(8));
		assertThat(Pe1.pe1(6), is(14));
	}

}
