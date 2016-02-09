#include <pe6.h>

#include <cstdlib>
#include <iostream>

using namespace std;

int pe6(int n)
{
  return n * (n + 1) * (n - 1) * (3 * n + 2) / 12;
}

int pe6_main()
{
  for (;;) {
    int n = 100;
    cout << "> ";
    cin >> n;
    if (n < 1) {
      break;
    }
    cout << pe6(n) << endl;
  }

  return 0;
}
