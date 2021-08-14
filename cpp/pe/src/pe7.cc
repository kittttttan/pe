#include "../include/pe7.h"
#include "../include/prime.h"

namespace pe {
  uint32_t pe7(uint32_t n)
  {
    if (n < 1) {
      return 0;
    }

    std::vector<uint32_t> ps;

    sieve(ps, n);
    if (ps.empty()) return 0;

    return ps.back();
  }
}