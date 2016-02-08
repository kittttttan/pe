#define _CRT_SECURE_NO_WARNINGS 1
#include <gcd.h>
#include <pe5.h>

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

void pe5(uint32_t n) {
  uint32_t d = 1;
  for (uint32_t i = 2; i <= n; ++i) {
    d = lcm(d, i);
  }

  printf("%" PRIu32 " below %" PRIu32 "\n", d, n);
}

int pe5_main(void) {
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
      pe5(n);
    }
  }

  return 0;
}
