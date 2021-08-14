#include "../include/pe2.h"

namespace pe {
  uint32_t pe2(uint32_t n)
  {
    uint32_t a = 1;
    uint32_t b = 1;
    uint32_t sum = 0;
    while (a < n) {
      if ((a & 1) == 0) {
        sum += a;
      }
      uint32_t t = a;
      a += b;
      b = t;
    }

    return sum;
  }
}
