package ktn.pe;

import java.util.logging.Logger;

public class Pe2 implements Pe {
    private static final Logger logger = Logger.getLogger(Pe2.class.getName());
    private long limit = 4000000;

    public static long pe2(long limit) {
        long sum = 2;
        long a = 1;
        long b = 2;
        long t;

        while (b <= limit) {
            t = b;
            b += a;
            logger.fine(String.valueOf(b));
            a = t;
            if ((b & 1) == 0) {
                sum += b;
            }
        }

        return sum;
    }

    public static void solve(long n) {
        System.out.println(pe2(n));
    }

    @Override
    public void setArgs(String[] args) {
        if (args != null && args.length > 0) {
            try {
                limit = Long.parseLong(args[0]);
            } catch (NumberFormatException e) {
                //
            }
        }
    }

    @Override
    public void solve() {
        solve(limit);
    }
}
