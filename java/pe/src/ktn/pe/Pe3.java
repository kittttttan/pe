package ktn.pe;

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
