#include "../include/pe22.h"

#include <cstdlib>
#include <iostream>

int pe22(int argc, char **argv)
{
  using namespace std;

  char* fname = "../../res/pe22.txt";
  if (argc > 1) {
    fname = argv[1];
  }
  const char* file = fname;

  cout << "file = " << file << endl;
  cout << "sum of digits = " << pe::pe22(file) << endl;

  return 0;
}
