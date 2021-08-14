#include "../include/pe11.h"

#include <cstdlib>
#include <iostream>

int pe11(int argc, char **argv)
{
  using namespace std;

  char* fname = "../../res/pe11.txt";
  if (argc > 1) {
    fname = argv[1];
  }

  cout << "file = " << fname << endl;
  cout << pe::pe11(fname) << endl;

  return 0;
}
