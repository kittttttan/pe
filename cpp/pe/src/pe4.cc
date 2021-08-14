#include "../include/pe4.h"
#include "../include/palindrome.h"

#include <cmath>

namespace pe {
  uint32_t pe4(uint32_t n, uint32_t& first, uint32_t& last)
  {
    first = static_cast<uint32_t>(9 * pow(10, n - 1) + 1);
    last = static_cast<uint32_t>(pow(10, n));

    uint32_t m = 0;
    for (uint32_t x = first; x < last; ++x) {
      for (uint32_t y = x; y < last; ++y) {
        uint32_t xy = x * y;
        if (xy > m && is_palindrome(xy)) {
          m = xy;
        }
      }
    }

    return m;
  }
}