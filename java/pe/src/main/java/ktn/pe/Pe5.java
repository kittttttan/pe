package ktn.pe;

import ktn.pe.util.PeUtils;

import java.util.List;
import java.util.ArrayList;

public class Pe5 implements Pe {
    private int to = 20;

    public long pe5(int to) {
        long mul = 1L;

        if (to < 2) {
            return mul;
        }
        mul = 2L;
        List<Integer> factors = new ArrayList<>();
        factors.add(2);

        int x;
        for (int i = 3; i < to + 1; ++i) {
            x = i;
            for (int factor : factors) {
                if ((x % factor) == 0) {
                    x /= factor;
                }
                if (x < factor) {
                    break;
                }
            }

            if (x > 1) {
                factors.add(x);
                mul *= x;
            }
        }

        return mul;
    }

    @Override
    public void setArgs(String[] args) {
        if (args.length > 0) {
            to = Integer.parseInt(args[0]);
        }
    }

    @Override
    public void solve() {
        System.out.println(PeUtils.format(this, pe5(to)));
    }

    @Override
    public void run() {
        solve();
    }

    @Override
    public int getProblemNumber() {
        return 5;
    }

}
