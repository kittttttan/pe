#include "../include/pe10.h"
#include "../include/prime.h"

#include <numeric>

namespace pe {
  uint64_t pe10(uint32_t n)
  {
    std::vector<uint32_t> v;
    pe::sieve_below(v, n);

    return std::accumulate(v.begin(), v.end(), 0ul);
  }
}