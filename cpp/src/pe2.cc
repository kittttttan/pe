#include <pe2.h>

#include <cstdlib>
#include <iostream>

uint pe2(uint n)
{
  uint a, b, t, sum;

  a = b = 1;
  sum = 0;
  while (a < n) {
    if ((a & 1) == 0) {
      sum += a;
    }
    t = a;
    a += b;
    b = t;
  }

  return sum;
}

int main(int argc, char** argv)
{
  using namespace std;
  
  uint n = 4000000;

  if (argc > 1) {
    n = strtoul(argv[1], nullptr, 0);
  }
  
  cout << pe2(n) << endl;

  return 0;
}
