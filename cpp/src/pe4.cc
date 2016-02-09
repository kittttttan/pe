#include <pe4.h>
#include <palindrome.h>

#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

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

int pe4_main()
{  
  for (;;) {
    uint32_t n = 3;
    cout << "> ";
    cin >> n;
    if (n < 1) {
      break;
    }

    uint32_t first;
    uint32_t last;
    uint32_t max = pe4(n, first, last);
    cout << first << " <= x,y < " << last << endl;
    if (max) {
      cout << max << endl;
    }
    else {
      cout << "not found" << endl;
    }
  }

  return 0;
}
