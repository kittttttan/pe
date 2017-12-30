package ktn.pe;

import ktn.pe.util.PeUtils;

import java.util.ArrayList;
import java.util.List;

public class Pe3 implements Pe {
    private long n;

    public Pe3() {
        super();

        n = 600851475143L;
    }

    @Override
    public void setArgs(String[] args) {
        if (args.length > 0) {
            n = Long.parseLong(args[0]);
        }
    }

    @Override
    public void solve() {
        List<Long> divisors = new ArrayList<>();
        PeUtils.divisors(divisors, n);
        System.out.println(PeUtils.format(this, divisors));
    }

    @Override
    public void run() {
        solve();
    }

    @Override
    public int getProblemNumber() {
        return 3;
    }
}
