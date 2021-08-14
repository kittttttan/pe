#include "../include/pe11.h"

#include <fstream>

namespace pe {
  using namespace std;

  uint32_t pe11(const char* fname)
  {
    int nums[20][20];
    int i = 0;
    int j = 0;
    int n = -1;
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

    uint32_t m = 0;
    for (i = 0; i < 20; ++i) {
      for (j = 0; j < 20; ++j) {
        uint32_t ud = 1;
        uint32_t lr = 1;
        uint32_t d0 = 1;
        uint32_t d1 = 1;
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
}