package ktn.pe;

public interface Pe extends Runnable {
    int getProblemNumber();
    void setArgs(String[] args);
    void solve();
}
