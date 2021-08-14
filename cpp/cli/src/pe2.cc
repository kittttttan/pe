#include "../include/pe2.h"

#include <cstdlib>
#include <iostream>

int pe2(int argc, char **argv)
{
  using namespace std;

  uint32_t n = 4000000;
  if (argc > 1) {
    char *end;
    n = strtoul(argv[1], &end, 10);
  }

  cout << "n = " << n << endl;
  cout << pe::pe2(n) << endl;

  return 0;
}
