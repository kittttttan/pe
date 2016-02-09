#include <pe3.h>
#include <divs.h>

#include <cstdlib>
#include <iostream>

using namespace std;

int pe3_main()
{
  for (;;) {
    uint64_t n = 600851475143ULL;
    cout << "> ";
    cin >> n;
    if (n < 1) {
      break;
    }

    vector<uint32_t> vec;
    get_divs(&vec, n);
    cout << n << endl;

    // max
    //if (vec.empty()) {
    //  cout << 1 << endl;
    //} else {
    //  cout << vec.back() << endl;
    //}

    // all
    for (uint32_t& v : vec) {
      cout << v << endl;
    }
  }

  return 0;
}
