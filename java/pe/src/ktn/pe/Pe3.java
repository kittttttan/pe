package ktn.pe;

import java.util.ArrayList;
import java.util.List;

public class Pe3 implements Pe {
    private long n;

    public Pe3() {
        super();

        n = 600851475143L;
    }

    public static void pe3(List<Long> divisors, long n) {
        if (n == 0) {
            return;
        }
        if (n < 0) {
            n = -n;
            divisors.add(-1L);
        }

        while ((n & 1) == 0) {
            divisors.add(2L);
            n >>= 1;
        }

        long limit = (long) Math.sqrt(n);
        if (limit < 3L) {
            limit = 3L;
        }

        long i = 3L;
        while (i <= limit) {
            if ((n % i) == 0) {
                divisors.add(i);
                n /= i;
                if (n < i) {
                    break;
                }
            } else {
                i += 2;
            }
        }
        if (n > 1) {
            divisors.add(n);
        }
    }

    @Override
    public void setArgs(String[] args) {
        if (args != null && args.length > 0) {
            try {
                n = Long.parseLong(args[0]);
            } catch (NumberFormatException e) {
                //
            }
        }
    }

    @Override
    public void solve() {
        List<Long> divisors = new ArrayList<Long>();
        pe3(divisors, n);
        for (long div : divisors) {
            System.out.print(div + " ");
        }
        System.out.println("");
    }
}
