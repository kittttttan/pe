#include <pe10.h>

#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

uint32_t pe10(uint32_t n)
{
  bool* s = new bool[n];
  s[0] = false;
  s[1] = false;
  for (uint32_t i = 2; i <= n; ++i) {
    s[i] = true;
  }

  uint32_t sq = static_cast<uint32_t>(sqrt(n));
  for (uint32_t i = 2; i < sq + 1; i++) {
    if (s[i]) {
      for (uint32_t j = i * i; j <= n; j += i) {
        s[j] = false;
      }
    }
  }

  uint32_t sum = 0;
  for (uint32_t i = 0; i <= n; ++i) {
    if (s[i]) {
      sum += i;
    }
  }
  
  delete [] s;

  return sum;
}

int pe10_main()
{
  for (;;) {
    uint32_t n = 2000000;
    cout << "> ";
    cin >> n;
    if (n < 1) {
      break;
    }
    cout << pe10(n) << endl;
  }

  return 0;
}
