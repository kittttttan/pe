#include <pe5.h>
#include <gcd.h>

#include <cstdlib>
#include <iostream>

using namespace std;

uint pe5(uint n)
{
  uint i, d = 1;

  for (i = 2; i <= n; ++i) {
    d = lcm(d, i);
  }

  return d;
}

int main(int argc, char** argv)
{
  uint n = 20;

  if (argc > 1) {
    n = strtoul(argv[1], nullptr, 0);
  }

  cout << pe5(n) << endl;

  return 0;
}
