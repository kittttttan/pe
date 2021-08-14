#include "../include/pe15.h"
#include "../include/divs.h"

#include <iostream>
#include <vector>

namespace pe {
  using namespace std;

  /*
  *  (m + n)! / (m! * n!)
  */
  uint64_t pe15(uint32_t m, uint32_t n)
  {
    if (m > 64) {
      cerr << "Too Large" << endl;
      return 0;
    }
    
    if (m < n) {
      auto t = m; m = n; n = t;
    }

    uint32_t* ps = new uint32_t[m];
    for (size_t i = 0; i < m; ++i) {
      ps[i] = i + n + 1;
    }

    vector< vector<uint32_t> > divs(n - 1, vector<uint32_t>(0));
    uint64_t num = 2;
    for (auto& vs : divs) {
      get_divs(&vs, num);
      ++num;
    }

    for (size_t i = 0; i < m; ++i) {
      for (size_t j = 0; j < n - 1; ++j) {
        const size_t size = divs[j].size();
        for (size_t k = 0; k < size; ++k) {
          if (divs[j][k] > 1 && ps[i] % divs[j][k] == 0) {
            ps[i] /= divs[j][k];
            divs[j][k] = 0;
            if (ps[i] < 2) {
              goto nextps;
            }
          }
        }
      }
  nextps:
  ; // dummy to avoid compile error
    }

    uint64_t a = 1;
    for (size_t i = 0; i < m; i++) {
      if (ps[i] > 1) {
        a *= ps[i];
      }
    }
    
    delete[] ps;

    return a;
  }
}