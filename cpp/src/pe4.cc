#include <pe4.h>
#include <palindrome.h>

#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

int pe4(int n, int& first, int& last)
{
  int m, x, y, xy;
  first = 9 * pow(10, n - 1) + 1;
  last = pow(10, n);

  m = 0;
  for (x = first; x < last; ++x) {
    for (y = x; y < last; ++y) {
      xy = x * y;
      if (xy > m && is_palindrome(xy)) {
        m = xy;
      }
    }
  }

  return m;
}

int main(int argc, char** argv)
{
  int n = 3;
  int first;
  int last;
  
  if (argc > 1) {
    n = atoi(argv[1]);
  }

  int max = pe4(n, first, last);
  cout << first << " <= x,y < " << last << endl;
  if (max) {
    cout << max << endl;
  } else {
    cout << "not found" << endl;
  }

  return 0;
}
