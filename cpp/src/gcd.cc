/*
 * gcd.c - Greatest Common Divisor, Least Common Multiple
 */
#include <gcd.h>

#include <cassert>

/*
 * Greatest Common Divisor
 * @param[in] a
 * @param[in] b
 * @return 
 */
uint gcd(uint a, uint b)
{
  uint c;

  assert(b != 0);
  for (;;) {
    c = a % b;
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
uint lcm(uint a, uint b)
{
  uint c;

  c = gcd(a, b);
  
  assert(c != 0);
  return a * b / c;
}
