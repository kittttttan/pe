#include <pe1.h>

#include <stdio.h>

void pe1(unsigned long n) {
  unsigned long n3, n5, n15, sum = 0;

  if (n > 2) {
    n3 = (n - 1) / 3;
    n5 = (n - 1) / 5;
    n15 = (n - 1) / 15;
    sum = (3 * n3 * (n3 + 1) + 5 * n5 * (n5 + 1)
        - 15 * n15 * (n15 + 1)) >> 1;
  }

  printf("%lu below %lu\n", sum, n);
}

void pe1_loop(unsigned long n) {
  unsigned long i, sum = 0;
  if (n > 2) {
    for (i = 3; i < n; ++i) {
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
