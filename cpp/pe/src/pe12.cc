#include "../include/pe12.h"
#include "../include/divs.h"

namespace pe {
  uint32_t pe12(uint32_t n)
  {
    uint32_t c;
    uint32_t t = 1;
    uint32_t i = 2;
    while ((c = cnt_divs(t)) < n) {
      t += i++;
    }

    return t;
  }
}