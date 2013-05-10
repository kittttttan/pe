#include <pe6.h>

#include <cstdlib>
#include <iostream>

using namespace std;

int pe6(int n)
{
  return n * (n + 1) * (n - 1) * (3 * n + 2) / 12;
}

int main(int argc, char** argv)
{
  int n = 100;

  if (argc > 1) {
    n = atoi(argv[1]);
  }

  cout << pe6(n) << endl;

  return 0;
}
