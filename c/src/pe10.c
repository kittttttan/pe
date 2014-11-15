#define _CRT_SECURE_NO_WARNINGS 1
#include <pe10.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

void pe10(unsigned n) {
  int *s;
  unsigned i, j, sq;
  unsigned long sum = 0;

  assert(n > 0);
  s = (int*)malloc(sizeof(int) * n);
  if (!s) {
    fprintf(stderr, "%s:%d: failed malloc.\n", __FILE__, __LINE__);
    return;
  }

  s[0] = 0;
  s[1] = 0;
  for (i = 2; i <= n; ++i) {
    s[i] = 1;
  }

  sq = (unsigned)sqrt(n);
  for (i = 2; i < sq + 1; i++) {
    if (s[i]) {
      for (j = i * i; j <= n; j += i) {
        s[j] = 0;
      }
    }
  }

  for (i = 0; i <= n; i++) {
    if (s[i]) {
      sum += i;
    }
  }
  free(s);

  printf("%lu below %u\n", sum, n);
}

int pe10_main(void) {
  unsigned n;

  while (1) {
    printf("below: ");
    if (scanf("%u", &n) != 1) {
      scanf("%*s");
      puts("Input Number.");
    } else {
      if (!n) {
        break;
      }
      pe10(n);
    }
  }

  return 0;
}
