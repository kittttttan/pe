#define _CRT_SECURE_NO_WARNINGS 1
#include <pe21.h>
#include <spd.h>

#include <iostream>

using namespace std;

static bool debug_on = false;

void pe21(uint32_t n) {
  uint32_t sum = 0;
  
  for (uint32_t i = 2; i < n + 1; ++i) {
    uint32_t t = spd(i);
    if (i < t && i == spd(t)) {
      if (debug_on) {
        cout << "(" << i << ", " << t << ")" << endl;
      }
      sum += i + t;
    }
  }
  
  cout << sum << endl;
}

int pe21_main(void) {
  for (;;) {
    uint32_t n;
    cout << "> ";
    cin >> n;
    if (n < 1) {
      break;
    }
    pe21(n);
  }

  return 0;
}
