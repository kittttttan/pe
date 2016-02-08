#define _CRT_SECURE_NO_WARNINGS 1
#include <pe15.h>
#include <divs.h>

#include <inttypes.h>
#include <stdio.h>

typedef struct _DivsData {
  size_t len;
  uint32_t divs[32];
} DivsData;

enum {
  MAX_M = 64u,
  MAX_N = 64u
};

/*
 *  (m + n)! / (m! * n!)
 */
void pe15(uint32_t m, uint32_t n) {
  if (m > MAX_M || n > MAX_N) {
    printf("Too Large: max numbers are (%u, %u).\n", MAX_M, MAX_N);
    return;
  }
  if (m < n) {
    uint32_t i = m; m = n; n = i;
  }

  uint32_t ps[MAX_M];
  for (uint32_t i = 0; i < m; i++) {
    ps[i] = i + n + 1;
  }

  DivsData dd[MAX_N];
  for (size_t i = 0; i < n - 1; i++) {
    dd[i].len = get_divs(dd[i].divs, i + 2);
  }

  for (size_t i = 0; i < m; ++i) {
    for (size_t j = 0; j < n - 1; ++j) {
      for (size_t k = 0; k < dd[j].len; ++k) {
        if (dd[j].divs[k] > 1 && ps[i] % dd[j].divs[k] == 0) {
          ps[i] /= dd[j].divs[k];
          dd[j].divs[k] = 0;
          if (ps[i] < 2) {
            goto nextps;
          }
        }
      }
    }
nextps:
; // dummy to avoid compile error
  }

  uint64_t a = 1;
  for (size_t i = 0; i < m; i++) {
    if (ps[i] > 1) {
      a *= ps[i];
    }
  }

  printf("(%" PRIu32 " + %" PRIu32 ")! / (%" PRIu32 "! * %" PRIu32 "!) = %" PRIu64 "\n",
          m, n, m, n, a);
}

int pe15_main(void) {
  uint32_t m, n;

  while (1) {
    printf("m n: ");
    if (scanf("%" PRIu32 " %" PRIu32, &m, &n) != 2) {
      scanf("%*s");
      puts("Input Number.");
    } else {
      if (!m && !n) {
        break;
      }
      pe15(m, n);
    }
  }

  return 0;
}
