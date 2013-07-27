package ktn.pe;

public interface Pe extends Runnable {
    public int getProblemNumber();
    public void setArgs(String[] args);

    public void solve();
}
