#include "../include/pe18.h"

#include <cstdlib>
#include <iostream>

int pe18(int argc, char **argv)
{
  using namespace std;

  char* fname = "../../res/pe18.txt";
  if (argc > 1) {
    fname = argv[1];
  }

  cout << "file = " << fname << endl;
  cout << "max sum = " << pe::pe18(fname) << endl;

  return 0;
}
