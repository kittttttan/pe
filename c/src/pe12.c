#define _CRT_SECURE_NO_WARNINGS 1
#include <pe12.h>
#include <divs.h>

#include <inttypes.h>
#include <math.h>
#include <stdio.h>

void pe12(uint32_t n) {
  uint32_t i, c, t;

  t = 1;
  i = 2;
  while ((c = cnt_divs(t)) < n) {
    t += i++;
  }

  printf("%" PRIu32 "\n", t);
}

int pe12_main(void) {
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
      pe12(n);
    }
  }

  return 0;
}
