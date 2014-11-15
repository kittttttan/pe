#define _CRT_SECURE_NO_WARNINGS 1

#include <pe1.h>
#include <stdio.h>

#define SUM_X2(n) ((n) * ((n) + 1))

void pe1(unsigned long n) {
  unsigned long sum = 0;

  if (n > 2) {
    sum = (3 * SUM_X2(n / 3) + 5 * SUM_X2(n / 5) - 15 * SUM_X2(n / 15)) >> 1;
  }

  printf("%lu below %lu\n", sum, n);
}

void pe1_loop(unsigned long n) {
  unsigned long i, sum = 0;
  if (n > 2) {
    for (i = 3; i < n + 1; ++i) {
      if (i % 3 == 0 || i % 5 == 0) {
        sum += i;
      }
    }
  }

  printf("%lu below %lu\n", sum, n);
}

int pe1_main(void) {
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
      pe1(n);
    }
  }

  return 0;
}
