package ktn.pe;

public class Pe6 implements Pe {
    private int n = 100;

    /**
     * (n(n+1)/2)^2 - n(n+1)(2n+1)/6
     * 
     * @param n
     * @return
     */
    public int pe6(int n) {
        return n * (n + 1) * (n - 1) * (3 * n + 2) / 12;
    }

    @Override
    public void setArgs(String[] args) {
        if (args != null && args.length > 0) {
            try {
                n = Integer.parseInt(args[0]);
            } catch (NumberFormatException e) {
                //
            }
        }
    }

    @Override
    public void solve() {
        System.out.println(PeUtils.format(this, pe6(n)));
    }

    @Override
    public void run() {
        solve();
    }

    @Override
    public int getProblemNumber() {
        return 6;
    }

}
