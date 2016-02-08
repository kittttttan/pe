#define _CRT_SECURE_NO_WARNINGS 1
#include <divs.h>
#include <pe3.h>

#include <inttypes.h>
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

enum { MAX_DIVS_CNT = 128u };

void pe3(uint32_t n) {
  uint32_t p[MAX_DIVS_CNT];
  size_t len = get_divs(p, n);
  if (len) {
    printf("Max prime factor of %" PRIu32 " is %" PRIu32 "\n",
        n, p[len - 1]);
  } else {
    printf("%" PRIu32 " has no prime factors\n", n);
  }
}

int pe3_main(void) {
  uint32_t n;

  while (1) {
    printf("Max prime factor of: ");
    if (scanf("%" PRIu32, &n) != 1) {
      scanf("%*s");
      puts("Input Number.");
    } else {
      if (!n) {
        break;
      }
      pe3(n);
    }
  }

  return 0;
}
