#include "../include/pe8.h"

#include <cstdlib>
#include <iostream>

int pe8(int argc, char **argv)
{
  using namespace std;

  char* fname = "../../res/pe8.txt";
  uint32_t n = 5;
  if (argc > 1) {
    fname = argv[1];
    if (argc > 2) {
      char *end;
      n = strtoul(argv[2], &end, 10);
    }
  }

  cout << "file = " << fname << endl;
  cout << "n = " << n << endl;
  cout << pe::pe8(fname, n) << endl;

  return 0;
}
