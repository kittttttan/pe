#include <pe13.h>

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void pe13(const char* fname, vector<char>& res)
{
  int nums[5000];

  ifstream ifs(fname, ifstream::in);
  char c = ifs.get();
  int i = 0;
  while (ifs.good()) {
    if (c >= '0' && c <= '9') {
      nums[i++] = c - '0';
    }

    c = ifs.get();
  }
  ifs.close();

  int j, sum = 0;
  for (i = 49; i >= 0; --i) {
    for (j = 0; j < 5000; j += 50) {
      sum += nums[i + j];
    }
    res.push_back(sum % 10);
    sum /= 10;
  }

  while (sum) {
    res.push_back(sum % 10);
    sum /= 10;
  }
}

int pe13_main()
{
  string fname = "../res/pe13.txt";
  vector<char> res;
  res.reserve(128);

  pe13(fname.c_str(), res);

  int k = res.size();
  int last = k < 10 ? k : 10;
  for (int i = 0; i < last; ++i) {
    cout << static_cast<int>(res[--k]);
  }
  cout << endl;

  return 0;
}
