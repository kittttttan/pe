#include "../include/pe9.h"

#include <cstdlib>
#include <iostream>

int pe9(int argc, char **argv)
{
  using namespace std;

  uint32_t n = 1000;
  if (argc > 1) {
    char *end;
    n = strtoul(argv[1], &end, 10);
  }

  cout << "n = " << n << endl;
  cout << pe::pe9(n) << endl;

  return 0;
}
