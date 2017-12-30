package ktn.pe;

import ktn.pe.util.PeUtils;

import java.util.logging.Logger;

public class Pe2 implements Pe {
    private static final Logger logger = Logger.getLogger(Pe2.class.getName());
    
    private long limit = 4000000;

    public long pe2(long limit) {
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

    @Override
    public void setArgs(String[] args) {
        if (args.length > 0) {
            limit = Long.parseLong(args[0]);
        }
    }

    @Override
    public void solve() {
        System.out.println(PeUtils.format(this, pe2(limit)));
    }

    @Override
    public void run() {
        solve();
    }

    @Override
    public int getProblemNumber() {
        return 2;
    }
}
