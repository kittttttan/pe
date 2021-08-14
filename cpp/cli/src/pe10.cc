#include "../include/pe10.h"

#include <cstdlib>
#include <iostream>

int pe10(int argc, char **argv)
{
  using namespace std;

  uint32_t n = 2000000;
  if (argc > 1) {
    char *end;
    n = strtoul(argv[1], &end, 10);
  }

  cout << "n = " << n << endl;
  cout << pe::pe10(n) << endl;

  return 0;
}
