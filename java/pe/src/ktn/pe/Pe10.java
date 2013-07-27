package ktn.pe;

import java.util.Arrays;

public class Pe10 implements Pe {
    private int limit = 2000000;

    public long pe10() {
        return pe10(limit);
    }
    
    public long pe10(int n) {
        if (n < 2) { return 0; }
        
        boolean[] primes = new boolean[n + 1];
        Arrays.fill(primes, true);
        primes[0] = false;
        primes[1] = false;
        
        int sq = (int)Math.sqrt(n);
        for (int i = 2; i < sq + 1; ++i) {
            if (primes[i]) {
                for (int j = i * i; j < n + 1; j += i) {
                    primes[j] = false;
                }
            }
        }
        
        long sum = 0;
        for (int i = 0; i < n + 1; ++i) {
            if (primes[i]) {
                sum += i;
            }
        }
        
        return sum;
    }
    
    @Override
    public void run() {
        solve();
    }

    @Override
    public int getProblemNumber() {
        return 10;
    }

    @Override
    public void setArgs(String[] args) {
        if (args == null) { return; }
        if (args.length > 0) {
            try {
                limit = Integer.parseInt(args[0]);
            } catch (NumberFormatException e) {
                //
            }
        }
    }

    @Override
    public void solve() {
        System.out.println(PeUtils.format(this, pe10()));
    }

}
