#include "../include/pe13.h"

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>

int pe13(int argc, char **argv)
{
  using namespace std;

  char* fname = "../../res/pe13.txt";
  if (argc > 1) {
    fname = argv[1];
  }
  const char* file = fname;

  vector<char> res;
  pe::pe13(file, res);
  int k = res.size();
  int size = k < 10 ? k : 10;

  string s(res.end() - size, res.end());
  std::reverse(s.begin(), s.end());

  cout << "file = " << file << endl;
  cout << s << endl;

  return 0;
}
