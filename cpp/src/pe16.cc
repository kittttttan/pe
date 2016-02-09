#define _CRT_SECURE_NO_WARNINGS 1
#include <pe16.h>

#include <iostream>

using namespace std;

const size_t MAX_ORDER = 128;

/**
 * sum of digits for 2^n
 * @param[in] n power of 2
 */
void pe16(int n) {
  static int bits[MAX_ORDER] = {0};
  bits[0] = 1;
  int i;
  int m = n;
  int sum = 0;

  if (n > 0) {
    while (m--) {
      /* x2 */
      for (i = 0; i < MAX_ORDER; ++i) {
        bits[i] <<= 1;
      }
      
      /* ceil */
      for (i = 0; i < MAX_ORDER - 1; ++i) {
        while (bits[i] > 9999) {
          ++bits[i + 1];
          bits[i] -= 10000;
        }
      }

      /* check overflow */
      if (bits[MAX_ORDER - 1] > 9999) {
        cerr << "overflow\n";
        return;
      }
    }
  }
  
  i = MAX_ORDER;
  /* ignore following zeros */
  while (i--) {
    if (bits[i]) break;
  }

  /* print for debug */
  cout << "2 ^ " << n << " = ";
  cout << bits[i];
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

int pe16_main(void) {
  for (;;) {
    int n;
    cout << "> ";
    cin >> n;
    if (n < 1) {
      break;
    }
    pe16(n);
  }

  return 0;
}
