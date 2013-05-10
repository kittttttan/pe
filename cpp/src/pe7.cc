#include <pe7.h>
#include <prime.h>

#include <cstdlib>
#include <iostream>
#include <list>

using namespace std;

int pe7(int n)
{
  if (n < 1) {
    return 0;
  }

  vector<int> ps;

  sieve(ps, n);
  if (ps.empty()) return 0;

  return ps.back();
}

int main(int argc, char** argv)
{
  int n = 10001;

  if (argc > 1) {
    n = atoi(argv[1]);
  }

  cout << pe7(n) << endl;

  return 0;
}
