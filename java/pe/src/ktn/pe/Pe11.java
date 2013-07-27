package ktn.pe;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

public class Pe11 implements Pe {
    private static final String defaultFilename = "../res/pe11.txt";
    private int width = 20;
    private int height = 20;

    private String fname = defaultFilename;

    private void loadFile(int[][] nums, File file) {
        if (file == null) {
            return;
        }

        try (FileInputStream fis = new FileInputStream(file);
                InputStreamReader isr = new InputStreamReader(fis, "UTF-8");
                BufferedReader br = new BufferedReader(isr)) {
            int w = 0;
            int h = 0;
            int n = 0;
            int ch;
            while (true) {
                ch = br.read();
                if ('0' <= ch && ch <= '9') {
                    n = 10 * n + (ch - '0');
                } else if (n > 0) {
                    nums[h][w] = n;
                    n = 0;
                    ++w;
                    if (w >= width) {
                        w = 0;
                        ++h;
                        if (h >= height) {
                            break;
                        }
                    }                    
                }
                if (ch < 0) { break; }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public int pe11() {
        return pe11(fname);
    }

    public int pe11(String fname) {
        int nums[][] = new int[height][width];
        File file = new File(fname);
        loadFile(nums, file);

        int m = 0;
        int ud, lr, d0, d1;
        for (int i = 0; i < 20; ++i) {
            for (int j = 0; j < 20; ++j) {
                ud = lr = d0 = d1 = 1;
                for (int k = 0; k < 4; ++k) {
                    if (i < 16) {
                        lr *= nums[i + k][j];
                    } else {
                        lr = 0;
                    }
                    if (j < 16) {
                        ud *= nums[i][j + k];
                    } else {
                        ud = 0;
                    }
                    if (i < 16 && j < 16) {
                        d0 *= nums[i + k][j + k];
                        d1 *= nums[i + k][j + 4 - k];
                    } else {
                        d0 = d1 = 0;
                    }
                }
                if (m < ud) {
                    m = ud;
                }
                if (m < lr) {
                    m = lr;
                }
                if (m < d0) {
                    m = d0;
                }
                if (m < d1) {
                    m = d1;
                }
            }
        }

        return m;
    }

    @Override
    public void run() {
        solve();
    }

    @Override
    public int getProblemNumber() {
        return 11;
    }

    @Override
    public void setArgs(String[] args) {
        if (args == null) {
            return;
        }

        if (args.length > 0) {
            fname = args[0];
        }
    }

    @Override
    public void solve() {
        System.out.println(PeUtils.format(this, pe11()));
    }

    public String getFname() {
        return fname;
    }

    public void setFname(String fname) {
        this.fname = fname;
    }

}
