package ktn.pe;

import ktn.pe.util.PeUtils;

public class Pe4 implements Pe {
    private int digits = 3;

    /**
     * 
     * @param n
     * @return
     */
    public boolean isPalindrome(int n) {
        String src = String.valueOf(n);
        String reversed = new StringBuilder(src).reverse().toString();

        return src.equals(reversed);
    }

    /**
     * 
     * @param digits
     * @return
     */
    public int pe4(int digits) {
        if (digits < 1) {
            return 0;
        }
        if (digits > 12) {
            throw new IllegalArgumentException("too large: " + digits);
        }

        int z = (int) Math.pow(10, digits - 1);
        int first = 9 * z + 1;
        int last = 10 * z + 1;
        int xy;
        int max = 0;
        for (int x = first; x < last; ++x) {
            for (int y = x; y < last; ++y) {
                xy = x * y;
                if (xy > max && isPalindrome(xy)) {
                    max = xy;
                }
            }
        }

        return max;
    }

    @Override
    public void setArgs(String[] args) {
        if (args.length > 0) {
            digits = Integer.parseInt(args[0]);
        }
    }

    @Override
    public void solve() {
        System.out.println(PeUtils.format(this, pe4(digits)));
    }

    @Override
    public void run() {
        solve();
    }

    @Override
    public int getProblemNumber() {
        return 4;
    }
}
