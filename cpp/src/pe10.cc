#include <pe10.h>

#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

uint pe10(uint n)
{
  bool* s = new bool[n];
  s[0] = false;
  s[1] = false;
  for (uint i = 2; i <= n; ++i) {
    s[i] = true;
  }

  uint sq = static_cast<uint>(sqrt(n));
  for (uint i = 2; i < sq + 1; i++) {
    if (s[i]) {
      for (uint j = i * i; j <= n; j += i) {
        s[j] = false;
      }
    }
  }

  uint sum = 0;
  for (uint i = 0; i <= n; ++i) {
    if (s[i]) {
      sum += i;
    }
  }
  
  delete [] s;

  return sum;
}

int main(int argc, char** argv)
{
  uint n = 2000000;

  if (argc > 1) {
    n = strtoul(argv[1], nullptr, 0);
  }

  cout << pe10(n) << endl;

  return 0;
}
