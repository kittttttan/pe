#include <spd.h>

#include <cmath>

/*
 * Sum of proper divisors
 * @param[in] n
 * @return
 */
int spd(int n)
{
  int sum = 1;  
  if (n < 2) return sum;
  
  int isq = static_cast<int>(floor(sqrt(n)));
  for (int i = 2; i < isq; ++i) {
    if (n % i == 0) {
      sum += i + n / i;
    }
  }
  
  if (n == isq * isq) {
    sum += isq;
  }

  return sum;
}
