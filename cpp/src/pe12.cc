#include <pe12.h>
#include <divs.h>

#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

uint32_t pe12(uint32_t n)
{
  uint32_t c;
  uint32_t t = 1;
  uint32_t i = 2;
  while ((c = cnt_divs(t)) < n) {
    t += i++;
  }

  return t;
}

int pe12_main()
{
  for (;;) {
    uint32_t n = 500;
    cout << "> ";
    cin >> n;
    if (n < 1) {
      break;
    }
    cout << pe12(n) << endl;
  }

  return 0;
}
