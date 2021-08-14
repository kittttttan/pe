#include "../include/pe6.h"

namespace pe {
  int pe6(int n)
  {
    return n * (n + 1) * (n - 1) * (3 * n + 2) / 12;
  }
}