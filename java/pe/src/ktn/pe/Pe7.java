package ktn.pe;

import java.util.Arrays;

public class Pe7 implements Pe {
    private int index = 10001;

    public static int pe7(int n) {
        if (n < 1) {
            return 0;
        }

        double times = n < 50 ? 5.0 : Math.log(n) + 2.0;
        int limit = (int) (n * times);

        boolean[] s = new boolean[limit + 1];
        Arrays.fill(s, true);
        s[0] = false;
        s[1] = false;

        int sq = (int) Math.sqrt(limit);
        for (int i = 2; i < sq + 1; ++i) {
            for (int j = i * i; j < limit + 1; j += i) {
                s[j] = false;
            }
        }

        int prime = 0;
        for (int i = 0;;) {
            if (s[prime]) {
                ++i;
                if (i >= n) {
                    break;
                }
            }
            ++prime;
        }

        return prime;
    }

    @Override
    public void setArgs(String[] args) {
        if (args != null && args.length > 0) {
            try {
                index = Integer.parseInt(args[0]);
            } catch (NumberFormatException e) {
                //
            }
        }
    }

    @Override
    public void solve() {
        System.out.println(pe7(index));
    }

}
