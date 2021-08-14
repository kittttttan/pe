#include "../include/pe7.h"

#include <cstdlib>
#include <iostream>

int pe7(int argc, char **argv)
{
  using namespace std;

  uint32_t n = 10001;
  if (argc > 1) {
    char *end;
    n = strtoul(argv[1], &end, 10);
  }

  cout << "n = " << n << endl;
  cout << pe::pe7(n) << endl;

  return 0;
}
