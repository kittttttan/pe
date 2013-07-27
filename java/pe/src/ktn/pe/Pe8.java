package ktn.pe;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.logging.Logger;

public class Pe8 implements Pe {
    private static final Logger logger = Logger.getLogger(Pe8.class.getName());
    private static final String defaultFilename = "../res/pe8.txt";
    
    private String fname = defaultFilename;
    private int digits = 5;

    private String loadFile(File file) {
        if (file == null) {
            return null;
        }

        StringBuffer buf = new StringBuffer();
        try (FileInputStream fis = new FileInputStream(file);
                InputStreamReader isr = new InputStreamReader(fis, "UTF-8");
                BufferedReader br = new BufferedReader(isr)) {
            String line;
            while ((line = br.readLine()) != null) {
                buf.append(line);
            }
        } catch (IOException e) {
            logger.severe(e.toString());
        }

        return buf.toString();
    }

    public int product(String numbers, int n) {
        int m = 1;
        if (numbers == null) {
            return m;
        }

        int t;
        int length = numbers.length();
        for (int i = 0; i < length - n + 1; ++i) {
            t = 1;
            for (int j = 0; j < n; ++j) {
                t *= numbers.charAt(i + j) - '0';
            }
            if (m < t) {
                m = t;
            }
        }

        return m;
    }

    public int pe8() {
        return pe8(fname, digits);
    }
    
    public int pe8(int n) {
        return pe8(fname, n);
    }

    public int pe8(String fname, int n) {
        File file = new File(fname);
        String numbers = loadFile(file);
        logger.fine(numbers);

        return product(numbers, n);
    }

    @Override
    public void setArgs(String[] args) {
        if (args == null) {
            return;
        }

        if (args.length > 0) {
            try {
                digits = Integer.parseInt(args[0]);
            } catch (NumberFormatException e) {
                //
            }
        }
        if (args.length > 1) {
            fname = args[1];
        }
    }

    @Override
    public void solve() {
        System.out.println(PeUtils.format(this, pe8()));
    }

    @Override
    public void run() {
        solve();
    }

    @Override
    public int getProblemNumber() {
        return 8;
    }

    public String getFname() {
        return fname;
    }

    public void setFname(String fname) {
        this.fname = fname;
    }

    public int getDigits() {
        return digits;
    }

    public void setDigits(int digits) {
        this.digits = digits;
    }

}
