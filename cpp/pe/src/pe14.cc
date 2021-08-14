#include "../include/pe14.h"

namespace pe {
  uint32_t count(uint32_t n)
  {
    uint32_t c = 1;
    while (n > 1) {
      if (n & 1) {
        n = 3 * n + 1;
      } else {
        n >>= 1;
      }
      ++c;
    }

    return c;
  }

  void pe14(uint32_t& index, uint32_t& cnt, uint32_t begin, uint32_t limit)
  {
    uint32_t m = 0;
    uint32_t mi = 0;
    if ((begin & 1) == 0) {
      uint32_t c = count(begin);
      if (m < c) {
        m = c;
        mi = begin;
      }
      ++begin;
    }

    for (uint32_t i = begin; i < limit; i += 2) {
      uint32_t c = count(i);
      if (m < c) {
        m = c;
        mi = i;
      }
    }

    index = mi;
    cnt = m;
  }
}