package ktn.lab;

import java.math.BigInteger;

public class Perf {
    static BigInteger fib(int n) {
        BigInteger a = BigInteger.ONE;
        BigInteger b = BigInteger.ZERO;
        BigInteger c;

        for (int i = 1; i < n; ++i) {
            c = a;
            a = a.add(b);
            b = c;
        }

        return a;
    }
}
