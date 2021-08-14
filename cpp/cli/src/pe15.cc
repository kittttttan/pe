#include "../include/pe15.h"

#include <cstdlib>
#include <iostream>

int pe15(int argc, char **argv)
{
  using namespace std;

  uint32_t m = 20;
  uint32_t n = 20;
  if (argc > 1) {
    char *end;
    m = strtoul(argv[1], &end, 10);
    if (argc > 2) {
      n = strtoul(argv[2], &end, 10);
    }
  }

  cout << "m, n = " << m << ", " << n << endl;
  cout << pe::pe15(m, n) << endl;

  return 0;
}
