#define _CRT_SECURE_NO_WARNINGS 1
#include <pe20.h>

#include <stdio.h>
#include <string.h>

enum { MAX_ORDER = 256 };

void pe20(int n) {
  static int bits[MAX_ORDER] = {0};
  bits[0] = 1;

  if (n > 1) {
    for (int j = 2; j <= n; ++j) {
      /* multiply */
      for (int i = 0; i < MAX_ORDER; ++i) {
        bits[i] *= j;
      }
      
      /* ceil */
      for (int i = 0; i < MAX_ORDER - 1; ++i) {
        bits[i + 1] += bits[i] / 10000;
        bits[i] %= 10000;
      }

      /* check overflow */
      if (bits[MAX_ORDER - 1] > 9999) {
        fprintf(stderr, "overflow\n");
        return;
      }
    }
  }
  
  int i = MAX_ORDER;
  /* ignore following zeros */
  while (i--) {
    if (bits[i]) break;
  }

  /* print for debug */
  printf("%d! = ", n);
  printf("%d", bits[i]);
  int sum = 0;
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
  printf("\n");
  
  printf("sum of digits = %d\n", sum);
}

int pe20_main(void) {
  int n;

  while (1) {
    printf("n!: ");
    if (scanf("%d", &n) != 1) {
      scanf("%*s");
      puts("Input Number.");
    } else {
      if (!n) {
        break;
      }
      pe20(n);
    }
  }

  return 0;
}
