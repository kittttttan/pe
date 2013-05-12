#include <pe9.h>

#include <cstdlib>
#include <iostream>

using namespace std;

int pe9(int n)
{
  int l = (n >> 1) + 1;
  for (int x = 1; x < l; ++x) {
    for (int y = x; y < l; ++y) {
      int z = n - x - y;
      if (x * x + y * y == z * z) {
        return x * y * z;
      }
    }
  }

  return 1;
}

int main(int argc, char** argv)
{
  int n = 1000;

  if (argc > 1) {
    n = atoi(argv[1]);
  }

  cout << pe9(n) << endl;

  return 0;
}
