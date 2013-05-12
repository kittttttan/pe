#include <pe11.h>

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

uint pe11(const char* fname)
{
  int i, j, k, n;
  int nums[20][20];

  i = j = 0;
  n = -1;
  ifstream ifs(fname, ifstream::in);
  char c = ifs.get();
  while (ifs.good()) {
    if (c >= '0' && c <= '9') {
      if (n == -1) {
        n = 10 * (c - '0');
      } else {
        n += c - '0';
        nums[i][j++] = n;
        n = -1;
        if (j > 19) {
          j = 0;
          ++i;
          if (i > 19) {
            break;
          }
        }
      }
    }
    c = ifs.get();
  }
  ifs.close();

  uint ud, lr, d0, d1, m = 0;
  for (i = 0; i < 20; ++i) {
    for (j = 0; j < 20; ++j) {
      ud = lr = d0 = d1 = 1;
      for (k = 0; k < 4; ++k) {
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

int main(int argc, char** argv)
{
  string fname = "../res/pe11.txt";

  if (argc > 1) {
    fname = argv[1];
  }

  cout << pe11(fname.c_str()) << endl;

  return 0;
}
