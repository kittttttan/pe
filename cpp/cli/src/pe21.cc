#include "../include/pe21.h"

#include <cstdlib>
#include <iostream>

int pe21(int argc, char **argv)
{
  using namespace std;

  uint32_t n = 100;
  if (argc > 1) {
    char *end;
    n = strtoul(argv[1], &end, 10);
  }

  cout << "n = " << n << endl;
  cout << "sum of digits = " << pe::pe21(n) << endl;

  return 0;
}
