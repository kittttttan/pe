package ktn.lab;

/**
 * Sample for Runnable and synchronized
 */
public class Counter implements Runnable {
    private static int count = 0;

    private static synchronized void countUp() {
        System.out.println(++count);
    }

    @Override
    public void run() {
        for (int i = 0; i < 7; ++i) {
            countUp();
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
