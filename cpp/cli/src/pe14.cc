#include "../include/pe14.h"

#include <iostream>

int pe14(int argc, char **argv)
{
  using namespace std;

  uint32_t index, cnt;
  pe::pe14(index, cnt, 500001, 1000000);
  cout << index << " produces " << cnt << " Collatz chain" << endl;

  return 0;
}
