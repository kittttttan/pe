#include "../include/pe1.h"

#include <cstdlib>
#include <cstring>
#include <iostream>

int pe1(int argc, char **argv)
{
  using namespace std;

  uint32_t n = 1000;
  bool is_loop = false;
  if (argc > 1) {
    if (strcmp(argv[1], "-l") == 0) {
      is_loop = true;
      if (argc > 2) {
        char *end;
        n = strtoul(argv[2], &end, 10);
      }
    } else {
      char *end;
      n = strtoul(argv[1], &end, 10);
    }
  }

  cout <<
    "n = " << n <<
    (is_loop ? " (with loop)" : "") << endl;
  cout <<
    (is_loop ? pe::with_loop(n) : pe::no_loop(n)) << endl;

  return 0;
}
