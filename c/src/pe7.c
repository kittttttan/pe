#define _CRT_SECURE_NO_WARNINGS 1
#include <pe7.h>
#include <prime.h>

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

size_t pe7(size_t n) {
  if (n < 1) {
    return 0;
  }

  uint32_t *ps = (uint32_t*)calloc(sizeof(uint32_t), n);
  if (!ps) {
    fprintf(stderr, "%s:%d: failed malloc\n", __FILE__, __LINE__);
    return 0;
  }

  size_t res = sieve(ps, n);
  if (res) {
    printf("%zuth prime is %" PRIu32 "\n", n, ps[n - 1]);
  }
  free(ps);

  return res;
}

int pe7_main(void) {
  int n;
  
  while (1) {
    printf("prime index of: ");
    if (scanf("%zu", &n) != 1) {
      scanf("%*s");
      puts("Input Number.");
    } else {
      if (!n) {
        break;
      }
      pe7(n);
    }
  }

  return 0;
}
