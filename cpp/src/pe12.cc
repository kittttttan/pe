#include <pe12.h>
#include <divs.h>

#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

uint pe12(uint n)
{
  uint c;
  uint t = 1;
  uint i = 2;
  while ((c = cnt_divs(t)) < n) {
    t += i++;
  }

  return t;
}

int main(int argc, char** argv)
{
  uint n = 500;

  if (argc > 1) {
    n = strtoul(argv[1], nullptr, 0);
  }

  cout << pe12(n) << endl;

  return 0;
}
