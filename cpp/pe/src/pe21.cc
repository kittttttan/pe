#define _CRT_SECURE_NO_WARNINGS 1
#include "../include/pe21.h"
#include "../include/spd.h"

#include <iostream>

namespace pe {
  using namespace std;

  static bool debug_on = false;

  uint32_t pe21(uint32_t n) {
    uint32_t sum = 0;
    
    for (uint32_t i = 2; i < n + 1; ++i) {
      uint32_t t = spd(i);
      if (i < t && i == spd(t)) {
        if (debug_on) {
          cout << "(" << i << ", " << t << ")" << endl;
        }
        sum += i + t;
      }
    }
    
    return sum;
  }
}