#include <pe3.h>
#include <divs.h>

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
  uint64 n = 600851475143ULL;
  
  if (argc > 1) {
    n = strtoul(argv[1], nullptr, 0);
  }

  vector<uint> vec;

  get_divs(&vec, n);
  cout << n << endl;
  
  // max
  //if (vec.empty()) {
  //  cout << 1 << endl;
  //} else {
  //  cout << vec.back() << endl;
  //}
  
  // all
  for (uint& v: vec) {
    cout << v << endl;
  }

  return 0;
}
