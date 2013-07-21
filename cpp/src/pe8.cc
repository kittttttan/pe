#include <pe8.h>

#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int pe8(const char* fname, int n)
{
  vector<char> digits;
  digits.reserve(1000);

  ifstream ifs(fname, ifstream::in);
  if (!ifs) {
    cerr << "failed to open " << fname << endl;
    return -1;
  }
  char c = ifs.get();
  while (ifs.good()) {
    if ('0' <= c && c <= '9') { digits.push_back(c - '0'); }
    c = ifs.get();
  }
  ifs.close();
  
  int t, j;
  int m = 0;
  const size_t size = digits.size();
  for (size_t i = 0; i < size - n + 1; ++i) {
    t = 1;
    for (j = 0; j < n; ++j) {
      t *= digits[i + j];
    }
    if (m < t) {
      m = t;
    }
  }

  return m;
}

int main(int argc, char** argv)
{
  string fname = "../../res/pe8.txt";
  int n = 5;

  if (argc > 1) {
    fname = argv[1];
  }
  if (argc > 2) {
    n = atoi(argv[2]);
  }
  cout << pe8(fname.c_str(), n) << endl;

  return 0;
}
