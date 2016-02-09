#include <pe2.h>

#include <cstdlib>
#include <iostream>

uint32_t pe2(uint32_t n)
{
  uint32_t a = 1;
  uint32_t b = 1;
  uint32_t sum = 0;
  while (a < n) {
    if ((a & 1) == 0) {
      sum += a;
    }
    uint32_t t = a;
    a += b;
    b = t;
  }

  return sum;
}

int pe2_main()
{
  using namespace std;
  
  for (;;) {
    uint32_t n = 4000000;
    cout << "below: ";
    cin >> n;
    if (n < 1) {
      break;
    }
    cout << pe2(n) << endl;
  }

  return 0;
}
