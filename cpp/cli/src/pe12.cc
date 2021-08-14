#include "../include/pe12.h"

#include <cstdlib>
#include <iostream>

int pe12(int argc, char **argv)
{
  using namespace std;

  uint32_t n = 500;
  if (argc > 1) {
    char *end;
    n = strtoul(argv[1], &end, 10);
  }

  cout << "n = " << n << endl;
  cout << pe::pe12(n) << endl;

  return 0;
}
