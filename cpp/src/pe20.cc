#define _CRT_SECURE_NO_WARNINGS 1
#include <pe20.h>

#include <iostream>

using namespace std;

const size_t MAX_ORDER = 256;

void pe20(uint32_t n) {
  static uint32_t bits[MAX_ORDER] = {0};
  bits[0] = 1;

  uint32_t sum = 0;
  if (n > 1) {
    for (uint32_t j = 2; j <= n; ++j) {
      /* multiply */
      for (uint32_t i = 0; i < MAX_ORDER; ++i) {
        bits[i] *= j;
      }
      
      /* ceil */
      for (uint32_t i = 0; i < MAX_ORDER - 1; ++i) {
        bits[i + 1] += bits[i] / 10000;
        bits[i] %= 10000;
      }

      /* check overflow */
      if (bits[MAX_ORDER - 1] > 9999) {
        cerr << "overflow" << endl;
        return;
      }
    }
  }
  
  uint32_t i = MAX_ORDER;
  /* ignore following zeros */
  while (i--) {
    if (bits[i]) break;
  }

  /* print for debug */
  cout << n << "! = " << bits[i];
  do {
    sum += bits[i] % 10;
  } while (bits[i] /= 10);
  if (i > 0) {
    while (i--) {
      printf("%04d", bits[i]);
      
      do {
        sum += bits[i] % 10;
      } while (bits[i] /= 10);
    }
  }
  cout << endl;
  
  cout << "sum of digits = " << sum << endl;
}

int pe20_main(void) {
  for (;;) {
    uint32_t n;
    cout << "> ";
    cin >> n;
    if (n < 1) {
      break;
    }
    pe20(n);
  }

  return 0;
}
