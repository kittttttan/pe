#include "../include/pe17.h"

#include <cstdlib>
#include <iostream>

int pe17(int argc, char **argv)
{
  using namespace std;

  uint32_t n = 1000;
  if (argc > 1) {
    char *end;
    n = strtoul(argv[1], &end, 10);
  }

  cout << "n = " << n << endl;
  cout << pe::pe17(n) << " letters" << endl;

  return 0;
}
