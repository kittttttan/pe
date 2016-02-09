#include <pe5.h>
#include <gcd.h>

#include <cstdlib>
#include <iostream>

using namespace std;

uint32_t pe5(uint32_t n)
{
  uint32_t d = 1;
  for (uint32_t i = 2; i <= n; ++i) {
    d = lcm(d, i);
  }

  return d;
}

int pe5_main()
{
  for (;;) {
    uint32_t n = 20;
    cout << "> ";
    cin >> n;
    if (n < 1) {
      break;
    }
    cout << pe5(n) << endl;
  }

  return 0;
}
