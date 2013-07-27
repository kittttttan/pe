package ktn.pe;

public class Pe12 implements Pe {
    private int over = 500;

    public int pe12() {
        return pe12(over);
    }

    public int pe12(int over) {
        int t = 1;
        int i = 2;
        int count;
        while (true) {
            count = PeUtils.countDivisors(t);
            if (count >= over) {
                break;
            }
            t += i;
            ++i;
        }
        
        return t;
    }
    
    @Override
    public void run() {
        solve();
    }

    @Override
    public int getProblemNumber() {
        return 12;
    }

    @Override
    public void setArgs(String[] args) {
        if (args == null) { return; }
        if (args.length > 0) {
            try {
                over = Integer.parseInt(args[0]);
            } catch (NumberFormatException e) {
                //
            }
        }
    }

    @Override
    public void solve() {
        System.out.println(PeUtils.format(this, pe12()));
    }

}
