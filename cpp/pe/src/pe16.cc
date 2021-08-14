#define _CRT_SECURE_NO_WARNINGS 1
#include "../include/pe16.h"

#include <iostream>

namespace pe {
  using namespace std;

  const size_t MAX_ORDER = 128;

  /**
  * sum of digits for 2^n
  * @param[in] n power of 2
  */
  uint32_t pe16(uint32_t n) {
    static uint32_t bits[MAX_ORDER] = {0};
    bits[0] = 1;
    uint32_t i;
    uint32_t m = n;
    uint32_t sum = 0;

    if (n > 0) {
      while (m--) {
        /* x2 */
        for (i = 0; i < MAX_ORDER; ++i) {
          bits[i] <<= 1;
        }
        
        /* ceil */
        for (i = 0; i < MAX_ORDER - 1; ++i) {
          while (bits[i] > 9999) {
            ++bits[i + 1];
            bits[i] -= 10000;
          }
        }

        /* check overflow */
        if (bits[MAX_ORDER - 1] > 9999) {
          cerr << "overflow\n";
          return 0;
        }
      }
    }
    
    i = MAX_ORDER;
    /* ignore following zeros */
    while (i--) {
      if (bits[i]) break;
    }

    // cout << "2 ^ " << n << " = ";
    // cout << bits[i];
    do {
      sum += bits[i] % 10;
    } while (bits[i] /= 10);
    if (i > 0) {
      while (i--) {
        // printf("%04d", bits[i]);

        do {
          sum += bits[i] % 10;
        } while (bits[i] /= 10);
      }
    }
    // cout << endl;

    return sum;
  }
}