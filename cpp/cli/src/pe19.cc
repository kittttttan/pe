#include "../include/pe19.h"

#include <cstdlib>
#include <iostream>

int pe19(int argc, char **argv)
{
  using namespace std;

  uint32_t n = 2000;
  if (argc > 1) {
    char *end;
    n = strtoul(argv[1], &end, 10);
  }

  cout << "n = " << n << endl;
  cout << pe::pe19(n) << endl;

  return 0;
}
