#include "../include/divs.h"

#include <cstddef>
#include <cmath>

namespace pe {
  void get_divs(std::vector<uint32_t>* p, uint64_t n)
  {
    uint32_t limit = static_cast<uint32_t>(sqrt(n));
    while ((n & 1) == 0) {
      p->push_back(2);
      n >>= 1;
    }
    if (n == 1) {
      return;
    }

    uint32_t i = 3;
    while (i <= limit) {
      if (n % i == 0) {
        p->push_back(i);
        n /= i;
        if (n < i) {
          break;
        }
      } else {
        i += 2;
      }
    }
    if (n > 1) {
      p->push_back(static_cast<uint32_t>(n));
    }
  }

  uint32_t cnt_divs(uint32_t n)
  {
    if (!n) {
      return 0;
    }
    if (n == 1) {
      return 1;
    }
    if (n < 4) {
      return 2;
    }

    std::vector<uint32_t> p;
    get_divs(&p, n);
    size_t l = p.size();
    uint32_t t = 0;
    uint32_t c = 1;
    for (size_t i = 0; i < l; ++i) {
      if (i + 1 < l && p[i] == p[i + 1]) {
        ++t;
      } else {
        c *= t + 2;
        t = 0;
      }
    }

    return c;
  }
}