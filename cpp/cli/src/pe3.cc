#include "../include/pe3.h"

#include <cstdlib>
#include <iostream>

int pe3(int argc, char **argv)
{
  using namespace std;

  uint64_t n = 600851475143ull;
  if (argc > 1) {
    char *end;
    n = strtoull(argv[1], &end, 10);
  }

  vector<uint32_t> vec = pe::pe3(n);

  if (vec.empty()) {
    cout << n << endl;
  } else {
    cout << n << " = ";
    bool is_first = true;
    for (uint32_t& v : vec) {
      if (is_first) {
        is_first = false;
        cout << v;
      } else {
        cout << " * " << v;
      }
    }
    cout << endl;
  }

  return 0;
}
