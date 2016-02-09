#include <prime.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>

size_t sieve(uint32_t *p, size_t l) {
  if (l < 1) {
    return 0;
  }

  double times;
  if (l < 50) {
    times = 5.0;
  } else {
    times = log(l) + 2.0;
  }
  size_t limit = (size_t)floor(l * times);

  bool *s = (bool*)malloc(sizeof(bool) * (limit + 1));
  if (!s) {
    fprintf(stderr, "failed malloc: %s@%d\n", __FILE__, __LINE__);
    return 0;
  }

  size_t sq = (size_t)floor(sqrt(limit));
  s[0] = 0;
  s[1] = 0;
  for (size_t i = 2; i < limit + 1; ++i) {
    s[i] = 1;
  }
  for (size_t i = 2; i < sq + 1; ++i) {
    for (size_t j = i * i; j < limit + 1; j += i) {
      s[j] = 0;
    }
  }

  size_t j = 0;
  for (size_t i = 0; j < l; ++i) {
    if (s[i]) {
      p[j++] = i;
    }
  }

  free(s);
  return j;
}

size_t sieve_below(uint32_t *p, uint32_t limit) {
  bool *s = (bool*)malloc(sizeof(bool) * (limit + 1));
  if (!s) {
    fprintf(stderr, "failed malloc: %s@%d\n", __FILE__, __LINE__);
    return 0;
  }

  size_t sq = (size_t)floor(sqrt(limit));
  s[0] = 0;
  s[1] = 0;
  for (size_t i = 2; i < limit + 1; ++i) {
    s[i] = 1;
  }
  for (size_t i = 2; i < sq + 1; ++i) {
    for (size_t j = i * i; j < limit + 1; j += i) {
      s[j] = 0;
    }
  }

  size_t j = 0;
  for (size_t i = 0; i < limit + 1; ++i) {
    if (s[i]) {
      p[j++] = i;
    }
  }

  free(s);
  return j;
}

uint32_t mod_math_pow(uint32_t base, uint32_t power, uint32_t mod) {
  uint32_t result = 1;

  while (power > 0) {
    if (power & 1) {
      result = result * base % mod;
    }
    base = base * base % mod;
    power >>= 1;
  }

  return result;
}

bool mrpt(uint32_t n, uint32_t i) {
  if (n == 2) {
    return true;
  }
  
  assert(n <= 0xfffffff);
  if (n < 2 || (n & 1) == 0) {
    return false;
  }

  uint32_t d = n - 1;
  srand((uint32_t)time(NULL));
  while ((d & 1) == 0) {
    d >>= 1;
  }

  while (i--) {
    uint32_t a = rand() % (n - 1) + 1;
    uint32_t t = d;
    uint32_t y = mod_math_pow(a, t, n);
    while (t != n - 1 && y != 1 && y != n - 1) {
      y = y * y % n;
      t <<= 1;
    }
    if (y != n - 1 && (t & 1) == 0) {
      return false;
    }
  }

  return true;
}
