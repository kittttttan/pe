package ktn.pe;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Pe1 {
	/**
	 * double sum of 0, 1, ..., limit
	 * @param limit
	 * @return
	 */
	private static int sumToX2(int limit) {
		return limit * (limit + 1);
	}
	
	/**
	 * 
	 * @param limit
	 * @return
	 */
	public static int pe1(int limit) {
		int sum = 0;
		
		if (limit > 2) {
			sum = (3 * sumToX2(limit / 3) + 5 * sumToX2(limit / 5)
					- 15 * sumToX2(limit / 15)) >> 1;
		}
		
		return sum;
	}
	
	/**
	 * 
	 * @param limit
	 * @return
	 */
	public static int pe1loop(int limit) {
		int sum = 0;
		
		for (int i = 3; i <= limit; ++i) {
			if (i % 3 == 0 || i % 5 == 0) {
				sum += i;
			}
		}
		
		return sum;
	}
	
	public static void solve() {
		while(true) {
			int n = 1000;
			
			System.out.print("below: ");
			BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		    try {
				String str = input.readLine();
				if ("".equals(str)) { break; }
				n = Integer.parseInt(str);
			} catch (NumberFormatException e) {
				e.printStackTrace(); break;
			} catch (IOException e) {
				e.printStackTrace(); break;
			}
		    
		    System.out.println(pe1(n));
		}
	}
}
