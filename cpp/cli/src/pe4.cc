#include "../include/pe4.h"

#include <cstdlib>
#include <iostream>

int pe4(int argc, char **argv)
{
  using namespace std;

  uint32_t n = 3;
  if (argc > 1) {
    char *end;
    n = strtoul(argv[1], &end, 10);
  }

  uint32_t first;
  uint32_t last;
  uint32_t max = pe::pe4(n, first, last);

  cout << "n = " << n << endl;
  cout << first << " <= x,y < " << last << endl;
  if (max) {
    cout << max << endl;
  }
  else {
    cout << "not found" << endl;
  }

  return 0;
}
