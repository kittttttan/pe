package ktn.pe;

import ktn.pe.util.PeUtils;

import java.util.Arrays;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

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
        } else if ("-h".equals(args[0]) || "--help".equals(args[0])) {
            help();
        } else if ("-a".equals(args[0])) {
            solveAll();
        } else if ("-A".equals(args[0])) {
            int n = -1;
            if (args.length > 1) {
                n = Integer.parseInt(args[1]);
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
    private static void help() {
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
    private static String loadClassName(int n) {
        return Main.class.getPackage().getName() + ".Pe" + n;
    }

    /**
     * 
     * @param args
     *            commandline options
     * @return true means
     */
    private static boolean solve(String[] args) {
        try {
            int n = Integer.parseInt(args[0]);
            if (n < PROBLEM_MIN || n > PROBLEM_MAX) {
                return false;
            }

            ClassLoader loader = ClassLoader.getSystemClassLoader();
            Class<?> clazz = loader.loadClass(loadClassName(n));
            Pe pe = (Pe) clazz.newInstance();

            String[] shiftedArgs = Arrays.copyOfRange(args, 1, args.length);
            pe.setArgs(shiftedArgs);

            PeUtils.timeit(pe::solve);

            return true;
        } catch (NumberFormatException | ClassNotFoundException
                | InstantiationException | IllegalAccessException e) {
            System.err.println(e.toString());

            return false;
        }
    }

    private static void solveAll() {
        ClassLoader loader = ClassLoader.getSystemClassLoader();
        PeUtils.timeit(() -> {
            Class<?> clazz;
            Pe pe;
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
        });
    }

    private static void solveAllAsync(int n) {
        int threadCount = THREAD_COUNT;
        if (n > 0) { threadCount = n; }
        ExecutorService executor = Executors.newFixedThreadPool(threadCount);
        ClassLoader loader = ClassLoader.getSystemClassLoader();

        PeUtils.timeit(() -> {
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
        });
    }
}
