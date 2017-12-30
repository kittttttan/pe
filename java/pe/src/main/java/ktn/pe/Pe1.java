package ktn.pe;

import ktn.pe.util.PeUtils;

public class Pe1 implements Pe {
    private int limit = 1000;

    /**
     * double sum of 0, 1, ..., limit
     * 
     * @param limit
     * @return
     */
    private int sumToX2(int limit) {
        return limit * (limit + 1);
    }

    /**
     * 
     * @param limit
     * @return
     */
    public int pe1(int limit) {
        int sum = 0;

        if (limit > 2) {
            sum = (3 * sumToX2(limit / 3) + 5 * sumToX2(limit / 5) - 15 * sumToX2(limit / 15)) >> 1;
        }

        return sum;
    }

    /**
     * 
     * @param limit
     * @return
     */
    public int pe1loop(int limit) {
        int sum = 0;

        for (int i = 3; i <= limit; ++i) {
            if (i % 3 == 0 || i % 5 == 0) {
                sum += i;
            }
        }

        return sum;
    }

    @Override
    public void setArgs(String[] args) {
        if (args.length > 0) {
            limit = Integer.parseInt(args[0]);
        }
    }

    @Override
    public void solve() {
        System.out.println(PeUtils.format(this, pe1(limit)));
    }

    @Override
    public void run() {
        solve();
    }

    @Override
    public int getProblemNumber() {
        return 1;
    }
}
