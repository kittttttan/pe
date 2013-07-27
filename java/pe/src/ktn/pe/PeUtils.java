package ktn.pe;

import java.util.ArrayList;
import java.util.List;

public class PeUtils {
    private PeUtils() {

    }

    public static <T> String format(Pe pe, T result) {
        return String.format("%3d: ", pe.getProblemNumber()) + result;
    }

    public static <T> String format(Pe pe, List<T> result) {
        String s = String.format("%3d:", pe.getProblemNumber());
        StringBuffer buf = new StringBuffer(s);
        for (T r : result) {
            buf.append(' ');
            buf.append(r.toString());
        }
        return buf.toString();
    }

    public static int countDivisors(long n) {
        List<Long> divisors = new ArrayList<Long>();
        divisors(divisors, n);
        int pl = divisors.size();
        if (pl == 1) {
            return 2;
        }
        
        int t = 0;
        int c = 1;
        for (int i = 0; i < pl; ++i) {
            if (i + 1 < pl && divisors.get(i) == divisors.get(i + 1)) {
                t += 1;
            } else {
                c *= t + 2;
                t = 0;
            }
        }
        
        return c;
    }

    public static void divisors(List<Long> divisors, long n) {
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
}
