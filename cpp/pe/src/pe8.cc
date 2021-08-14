#include "../include/pe8.h"

#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>

namespace pe {
  using namespace std;

  int pe8(const char* fname, int n)
  {
    vector<char> digits;
    digits.reserve(1000);

    ifstream ifs(fname, ifstream::in);
    if (!ifs) {
      cerr << "failed to open " << fname << endl;
      return -1;
    }
    char c = ifs.get();
    while (ifs.good()) {
      if ('0' <= c && c <= '9') { digits.push_back(c - '0'); }
      c = ifs.get();
    }
    ifs.close();
    
    int m = 0;
    const size_t size = digits.size();
    for (size_t i = 0; i < size - n + 1; ++i) {
      int t = 1;
      for (int j = 0; j < n; ++j) {
        t *= digits[i + j];
      }
      if (m < t) {
        m = t;
      }
    }

    return m;
  }
}