#include "../include/pe5.h"

#include <numeric>

namespace pe {
  uint32_t pe5(uint32_t n)
  {
    uint32_t d = 1;
    for (uint32_t i = 2; i <= n; ++i) {
      d = std::lcm(d, i);
    }

    return d;
  }
}