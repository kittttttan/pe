package ktn.pe;

public class Pe9 implements Pe {
    private int limit = 1000;

    public int pe9(int limit) {
        int last = (limit >> 1) + 1;
        for (int x = 1; x < last; ++x) {
            int x2 = x * x;
            for (int y = x; y < last; ++y) {
                int z = limit - x - y;
                if (x2 + y * y == z * z) {
                    return x * y * z;
                }
            }
        }

        return 0;
    }

    @Override
    public void setArgs(String[] args) {
        if (args == null) {
            return;
        }

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
        System.out.println(PeUtils.format(this, pe9(limit)));
    }

    @Override
    public void run() {
        solve();
    }

    @Override
    public int getProblemNumber() {
        return 9;
    }

}
