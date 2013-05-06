package ktn.pe;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		int problemNumber = 0;
		
		if (args.length > 0) {
			try {
				problemNumber = Integer.parseInt(args[0]);
			} catch (NumberFormatException e) {
				e.printStackTrace();
			}
			
			solve(problemNumber);
		} else {
			while(true) {
				problemNumber = 0;
				System.out.print("Problem: ");
				BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
			    try {
					String str = input.readLine();
					if (!"".equals(str)) {
						problemNumber = Integer.parseInt(str);
					}
				} catch (NumberFormatException e) {
					e.printStackTrace();
				} catch (IOException e) {
					e.printStackTrace();
				}
			    
			    if (problemNumber < 1) { break; }
			    
			    solve(problemNumber);
			}
			
			System.out.println("Exit");
		}
	}

	/**
	 * 
	 * @param problemNumber
	 */
	public static void solve(int problemNumber) {
		switch (problemNumber) {
		case 1: Pe1.solve(); break;
		default: break;
		}
	}
}
