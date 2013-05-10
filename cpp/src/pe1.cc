#include <pe1.h>

#include <cstdlib>
#include <iostream>

static inline uint SUM_X2(unsigned long n)
{
  return n * (n + 1);
}

uint pe1(uint n)
{
  uint sum = 0;

  if (n > 2) {
    sum = (3 * SUM_X2(n / 3) + 5 * SUM_X2(n / 5) - 15 * SUM_X2(n / 15)) >> 1;
  }

  return sum;
}

uint pe1_loop(uint n)
{
  uint i, sum = 0;
  if (n > 2) {
    for (i = 3; i < n + 1; ++i) {
      if (i % 3 == 0 || i % 5 == 0) {
        sum += i;
      }
    }
  }

  return sum;
}

int main(int argc, char** argv)
{
  using namespace std;
  
  uint n = 1000;

  if (argc > 1) {
    n = atoi(argv[1]);
  }
  
  cout << pe1(n) << endl;

  return 0;
}
