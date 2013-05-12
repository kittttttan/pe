#include <pe14.h>

#include <iostream>

using namespace std;

uint count(uint n)
{
  uint c;

  c = 1;
  while (n > 1) {
    if (n & 1) {
      n = 3 * n + 1;
    } else {
      n >>= 1;
    }
    ++c;
  }

  return c;
}

void pe14(uint& index, uint& cnt, uint begin, uint limit)
{
  uint m, mi, c;

  m = mi = 0;
  if ((begin & 1) == 0) {
    c = count(begin);
    if (m < c) {
      m = c;
      mi = begin;
    }
    ++begin;
  }

  for (uint i = begin; i < limit; i += 2) {
    c = count(i);
    if (m < c) {
      m = c;
      mi = i;
    }
  }

  index = mi;
  cnt = m;
}

int main(int argc, char** argv)
{
  uint index, cnt;
  
  pe14(index, cnt, 500001, 1000000);
  cout << index << " produces " << cnt << " Collatz chain" << endl;

  return 0;
}
