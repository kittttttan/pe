#include <prime.h>

#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>

#include <iostream>

using namespace std;

uint32_t sieve(vector<uint32_t>& p, uint32_t l) {
  if (l < 1) {
    return 0;
  }

  double times;
  if (l < 50) {
    times = 5.0;
  } else {
    times = log(l) + 2.0;
  }
  uint32_t limit = static_cast<int>(floor(l * times));

  bool *s = new bool[limit + 1];
  if (!s) {
    cerr << "failed malloc: " << __FILE__ << ":" << __LINE__ << endl;
    return 0;
  }

  uint32_t sq = static_cast<uint32_t>(floor(sqrt(limit)));
  s[0] = false;
  s[1] = false;
  for (uint32_t i = 2; i < limit + 1; ++i) {
    s[i] = true;
  }
  for (uint32_t i = 2; i < sq + 1; ++i) {
    for (uint32_t j = i * i; j < limit + 1; j += i) {
      s[j] = false;
    }
  }

  uint32_t j = 0;
  for (uint32_t i = 0; j < l; ++i) {
    if (s[i]) {
      p.push_back(i);
      ++j;
    }
  }

  delete [] s;
  return j;
}

uint32_t sieve_below(vector<uint32_t>& p, uint32_t limit) {
  bool *s = new bool[limit + 1];
  if (!s) {
    cerr << "failed malloc: " << __FILE__ << ":" << __LINE__ << endl;
    return 0;
  }

  uint32_t sq = static_cast<uint32_t>(floor(sqrt(limit)));
  s[0] = false;
  s[1] = false;
  for (uint32_t i = 2; i < limit + 1; ++i) {
    s[i] = true;
  }
  for (uint32_t i = 2; i < sq + 1; ++i) {
    for (uint32_t j = i * i; j < limit + 1; j += i) {
      s[j] = false;
    }
  }

  uint32_t j = 0;
  for (uint32_t i = 0; i < limit + 1; ++i) {
    if (s[i]) {
      p.push_back(i);
      ++j;
    }
  }

  delete [] s;
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
  srand(static_cast<uint32_t>(time(NULL)));
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
