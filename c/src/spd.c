#include <spd.h>

#include <math.h>

/*
 * Sum of proper divisors
 * @param[in] n
 * @return
 */
uint32_t spd(uint32_t n) {
  uint32_t sum = 1;
  if (n < 2) {
    return sum;
  }

  uint32_t isq = (uint32_t)floor(sqrt(n));
  for (uint32_t i = 2; i < isq; ++i) {
    if (n % i == 0) {
      sum += i + n / i;
    }
  }

  if (n == isq * isq) {
    sum += isq;
  }

  return sum;
}
