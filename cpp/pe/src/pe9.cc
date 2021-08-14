#include "../include/pe9.h"

namespace pe {
  uint32_t pe9(uint32_t n)
  {
    uint32_t l = (n >> 1) + 1;
    for (uint32_t x = 1; x < l; ++x) {
      for (uint32_t y = x; y < l; ++y) {
        uint32_t z = n - x - y;
        if (x * x + y * y == z * z) {
          return x * y * z;
        }
      }
    }

    return 1;
  }
}