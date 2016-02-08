#define _CRT_SECURE_NO_WARNINGS 1
#include <pe2.h>

#include <inttypes.h>
#include <stdio.h>

void pe2(uint32_t n) {
  uint32_t a = 1;
  uint32_t b = 1;
  uint32_t sum = 0;
  while (a < n) {
    if ((a & 1) == 0) {
      sum += a;
    }
    uint32_t t = a;
    a += b;
    b = t;
  }

  printf("%" PRIu32 " below %" PRIu32 "\n", sum, n);
}

int pe2_main(void) {
  uint32_t n;

  while (1) {
    printf("below: ");
    if (scanf("%" PRIu32, &n) != 1) {
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
