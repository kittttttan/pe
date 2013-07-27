package ktn.pe;

import java.util.Arrays;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

import ktn.lab.Counter;

/**
 * 
 */
public class Main {
    private static final int PROBLEM_MIN = 1;
    private static final int PROBLEM_MAX = 12;
    private static final int THREAD_COUNT = 4;

    /**
     * @param args
     *            ProblemNumber options...
     */
    public static void main(String[] args) {
        if (args.length < 1) {
            help();
        } else if ("-t".equals(args[0])) {
            test();
        } else if ("-t2".equals(args[0])) {
            test2();
        } else if ("-h".equals(args[0]) || "--help".equals(args[0])) {
            help();
        } else if ("-a".equals(args[0])) {
            solveAll();
        } else if ("-A".equals(args[0])) {
            int n = -1;
            if (args.length > 1) {
                try {
                    n = Integer.parseInt(args[1]);
                } catch (NumberFormatException e) {
                    //
                }
            }
            solveAllAsync(n);
        } else {
            if (!solve(args)) {
                help();
            }
        }
    }

    /**
     * Show help
     */
    public static void help() {
        System.out.println("ProblemNumber options...");
        System.out.println("-a      all");
        System.out.println("-A [n]  all async with n threads");
        System.out.println("-h      help");
    }

    /**
     * 
     * @param n
     * @return
     */
    public static String loadClassName(int n) {
        return Main.class.getPackage().getName() + ".Pe" + n;
    }

    /**
     * 
     * @param args
     *            commandline options
     * @return true means
     */
    static boolean solve(String[] args) {
        boolean done = false;

        try {
            int n = Integer.parseInt(args[0]);
            if (n < PROBLEM_MIN || n > PROBLEM_MAX) {
                return done;
            }

            ClassLoader loader = ClassLoader.getSystemClassLoader();
            Class<?> clazz = loader.loadClass(loadClassName(n));
            Pe pe = (Pe) clazz.newInstance();

            String[] shiftedArgs = Arrays.copyOfRange(args, 1, args.length);
            pe.setArgs(shiftedArgs);

            long start = System.currentTimeMillis();

            pe.solve();

            long stop = System.currentTimeMillis();
            System.out.println((stop - start) + " ms");

            done = true;
        } catch (NumberFormatException | ClassNotFoundException
                | InstantiationException | IllegalAccessException e) {
            System.err.println(e.toString());
        }

        return done;
    }

    static void solveAll() {
        ClassLoader loader = ClassLoader.getSystemClassLoader();
        Class<?> clazz;
        Pe pe;
        long start = System.currentTimeMillis();
        try {
            for (int i = PROBLEM_MIN; i < PROBLEM_MAX + 1; ++i) {
                clazz = loader.loadClass(loadClassName(i));
                pe = (Pe) clazz.newInstance();
                pe.solve();
            }
        } catch (ClassNotFoundException | InstantiationException
                | IllegalAccessException e) {
            e.printStackTrace();
        }
        long stop = System.currentTimeMillis();
        System.out.println((stop - start) + " ms");
    }

    static void solveAllAsync(int n) {
        int threadCount = THREAD_COUNT;
        if (n > 0) { threadCount = n; }
        ExecutorService executor = Executors.newFixedThreadPool(threadCount);
        ClassLoader loader = ClassLoader.getSystemClassLoader();

        long start = System.currentTimeMillis();
        try {
            for (int i = PROBLEM_MIN; i < PROBLEM_MAX + 1; ++i) {
                Class<?> clazz = loader.loadClass(loadClassName(i));
                Pe pe = (Pe) clazz.newInstance();
                executor.execute(pe);
            }
        } catch (ClassNotFoundException | InstantiationException
                | IllegalAccessException e) {
            e.printStackTrace();
        }

        long awaitTime = 30 * 1000;
        try {
            executor.shutdown();

            if (!executor.awaitTermination(awaitTime, TimeUnit.MILLISECONDS)) {
                executor.shutdownNow();
            }
        } catch (InterruptedException e) {
            System.out.println("awaitTermination interrupted: " + e);
            executor.shutdownNow();
        }
        
        long stop = System.currentTimeMillis();
        System.out.println((stop - start) + " ms");
    }

    static void test() {
        ThreadGroup threadGroup = new ThreadGroup("counter");
        Thread[] threads = new Thread[7];
        for (int i = 0; i < 7; ++i) {
            Counter counter = new Counter();
            threads[i] = new Thread(threadGroup, counter);
            threads[i].start();
        }
    }

    static public void test2() {
        ExecutorService executor = Executors.newFixedThreadPool(THREAD_COUNT);
        for (int i = 0; i < 7; ++i) {
            Counter counter = new Counter();
            executor.execute(counter);
        }

        long awaitTime = 5 * 1000;
        try {
            executor.shutdown();

            if (!executor.awaitTermination(awaitTime, TimeUnit.MILLISECONDS)) {
                executor.shutdownNow();
            }
        } catch (InterruptedException e) {
            System.out.println("awaitTermination interrupted: " + e);
            executor.shutdownNow();
        }
    }
}
