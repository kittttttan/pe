#define _CRT_SECURE_NO_WARNINGS 1
#include <pe2.h>
#include <stdio.h>

void pe2(unsigned long n) {
  unsigned long a, b, t, sum;

  a = b = 1;
  sum = 0;
  while (a < n) {
    if ((a & 1) == 0) {
      sum += a;
    }
    t = a;
    a += b;
    b = t;
  }

  printf("%lu below %lu\n", sum, n);
}

int pe2_main(void) {
  unsigned long n;

  while (1) {
    printf("below: ");
    if (scanf("%lu", &n) != 1) {
      scanf("%*s");
      puts("Input Number.");
    } else {
      if (!n) {
        break;
      }
      pe2(n);
    }
  }

  return 0;
}
