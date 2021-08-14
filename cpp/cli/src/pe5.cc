#include "../include/pe5.h"

#include <cstdlib>
#include <iostream>

int pe5(int argc, char **argv)
{
  using namespace std;

  uint32_t n = 20;
  if (argc > 1) {
    char *end;
    n = strtoul(argv[1], &end, 10);
  }

  cout << "n = " << n << endl;
  cout << pe::pe5(n) << endl;

  return 0;
}
