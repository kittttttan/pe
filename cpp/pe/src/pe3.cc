#include "../include/pe3.h"
#include "../include/divs.h"

namespace pe {
  std::vector<uint32_t> pe3(uint64_t n)
  {
    std::vector<uint32_t> vec;
    get_divs(&vec, n);

    return vec;
  }
}