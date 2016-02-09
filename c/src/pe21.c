#define _CRT_SECURE_NO_WARNINGS 1
#include <pe21.h>
#include <spd.h>

#include <inttypes.h>
#include <stdio.h>
#include <string.h>

static int debug_on = 0;

void pe21(uint32_t n) {
  uint32_t sum = 0;

  for (uint32_t i = 2; i < n + 1; ++i) {
    uint32_t t = spd(i);
    if (i < t && i == spd(t)) {
      if (debug_on) {
        printf("(%" PRIu32 ", %" PRIu32 ")\n", i, t);
      }
      sum += i + t;
    }
  }

  printf("%" PRIu32 "\n", sum);
}

int pe21_main(void) {
  uint32_t n;

  while (1) {
    puts("below: ");
    if (scanf("%" PRIu32, &n) != 1) {
      scanf("%*s");
      puts("Input Number.");
    } else {
      if (!n) {
        break;
      }
      pe21(n);
    }
  }

  return 0;
}
