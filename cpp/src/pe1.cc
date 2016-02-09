#include <pe1.h>

#include <cstdlib>
#include <iostream>

static inline uint32_t SUM_X2(uint32_t n)
{
  return n * (n + 1);
}

uint32_t pe1(uint32_t n)
{
  uint32_t sum = 0;

  if (n > 2) {
    sum = (3 * SUM_X2(n / 3) + 5 * SUM_X2(n / 5) - 15 * SUM_X2(n / 15)) >> 1;
  }

  return sum;
}

uint32_t pe1_loop(uint32_t n)
{
  uint32_t sum = 0;
  if (n > 2) {
    for (uint32_t i = 3; i < n + 1; ++i) {
      if (i % 3 == 0 || i % 5 == 0) {
        sum += i;
      }
    }
  }

  return sum;
}

int pe1_main()
{
  using namespace std;

  for (;;) {
    uint32_t n = 1000;
    cout << "below: ";
    cin >> n;
    if (n < 1) {
      break;
    }
    cout << pe1(n) << endl;
  }

  return 0;
}
