#include <divs.h>

#include <math.h>

enum { MAX_DIVS_CNT = 256u };

/*
 * get divisors
 * @param[out] p divisors
 * @param[in]  n max length
 * @return length
 */
size_t get_divs(uint32_t *p, uint32_t n) {
  size_t len = 0;
  size_t limit = (size_t)sqrt(n);
  while ((n & 1) == 0) {
    p[len++] = 2;
    n >>= 1;
  }
  if (n == 1) {
    return len;
  }

  size_t i = 3;
  while (i <= limit) {
    if (n % i == 0) {
      p[len++] = i;
      n /= i;
      if (n < i) {
        break;
      }
    } else {
      i += 2;
    }
  }
  if (n > 1) {
    p[len++] = n;
  }

  return len;
}

/*
 * count divisors
 * @param[in] n
 * @return 
 */
uint32_t cnt_divs(uint32_t n) {
  if (!n) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  if (n < 4) {
    return 2;
  }

  uint32_t p[MAX_DIVS_CNT];
  uint32_t t = 0;
  uint32_t c = 1;
  size_t l = get_divs(p, n);
  for (size_t i = 0; i < l; ++i) {
    if (i + 1 < l && p[i] == p[i + 1]) {
      ++t;
    } else {
      c *= t + 2;
      t = 0;
    }
  }

  return c;
}
