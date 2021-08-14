#include "../include/pe16.h"

#include <cstdlib>
#include <iostream>

int pe16(int argc, char **argv)
{
  using namespace std;

  uint32_t n = 1000;
  if (argc > 1) {
    char *end;
    n = strtoul(argv[1], &end, 10);
  }

  cout << "n = " << n << endl;
  cout << "sum of digits = " << pe::pe16(n) << endl;

  return 0;
}
