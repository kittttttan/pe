#include <pe15.h>

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 *  (m + n)! / (m! * n!)
 */
uint64 pe15(int m, int n)
{
  if (m > 64) {
    cerr << "Too Large" << endl;
    return 0;
  }
  
  int i;
  if (m < n) {
    i = m; m = n; n = i;
  }

  int* ps = new int[m];
  for (i = 0; i < m; ++i) {
    ps[i] = i + n + 1;
  }

  vector< vector<uint> > divs(n - 1, vector<uint>(0));
  uint64 num = 2;
  for (vector<uint>& vs : divs) {
    get_divs(&vs, num);
    ++num;
  }

  int j, k;
  for (i = 0; i < m; ++i) {
    for (j = 0; j < n - 1; ++j) {
      const int size = divs[j].size();
      for (k = 0; k < size; ++k) {
        if (divs[j][k] > 1 && ps[i] % divs[j][k] == 0) {
          ps[i] /= divs[j][k];
          divs[j][k] = 0;
          if (ps[i] < 2) {
            goto nextps;
          }
        }
      }
    }
nextps:
; // dummy to avoid compile error
  }

  uint64 a = 1;
  for (i = 0; i < m; i++) {
    if (ps[i] > 1) {
      a *= ps[i];
    }
  }
  
  delete[] ps;

  return a;
}

int main(int argc, char** argv)
{
  int m = 20;
  int n = 20;

  if (argc > 1) {
    m = atoi(argv[1]);
  }
  if (argc > 2) {
    n = atoi(argv[2]);
  }

  cout << pe15(m, n) << endl;

  return 0;
}
