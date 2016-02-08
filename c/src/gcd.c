/*
 * gcd.c - Greatest Common Divisor, Least Common Multiple
 */
#include <gcd.h>

/*
 * Greatest Common Divisor
 * @param[in] a
 * @param[in] b
 * @return 
 */
uint32_t gcd(uint32_t a, uint32_t b) {
  if (b == 0) {
    return a;
  }
  for (;;) {
    uint32_t c = a % b;
    if (!c) { break; }
    a = b;
    b = c;
  }

  return b;
}

/*
 * Least Common Multiple
 * @param[in] a
 * @param[in] b
 * @return 
 */
uint32_t lcm(uint32_t a, uint32_t b) {
  uint32_t c = gcd(a, b);
  if (c == 0) {
    return 0;
  }
  
  return a * b / c;
}
