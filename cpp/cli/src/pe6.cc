#include "../include/pe6.h"

#include <cstdlib>
#include <iostream>

int pe6(int argc, char **argv)
{
  using namespace std;

  uint32_t n = 100;
  if (argc > 1) {
    char *end;
    n = strtoul(argv[1], &end, 10);
  }

  cout << "n = " << n << endl;
  cout << pe::pe6(n) << endl;

  return 0;
}
