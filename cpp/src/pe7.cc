#include <pe7.h>
#include <prime.h>

#include <cstdlib>
#include <iostream>
#include <list>

using namespace std;

uint32_t pe7(uint32_t n)
{
  if (n < 1) {
    return 0;
  }

  vector<uint32_t> ps;

  sieve(ps, n);
  if (ps.empty()) return 0;

  return ps.back();
}

int pe7_main()
{
  for (;;) {
    uint32_t n = 10001;
    cout << "> ";
    cin >> n;
    if (n < 1) {
      break;
    }
    cout << pe7(n) << endl;
  }

  return 0;
}
