#include <divs.h>

#include <cmath>

/*
 * get divisors
 * @param[out] p divisors
 * @param[in]  n max length
 * @return length
 */
void get_divs(std::vector<uint>& p, uint64 n)
{
  size_t i, limit;

  limit = (size_t)sqrt(n);
  while ((n & 1) == 0) {
    p.push_back(2);
    n >>= 1;
  }
  if (n == 1) {
    return;
  }

  i = 3;
  while (i <= limit) {
    if (n % i == 0) {
      p.push_back(i);
      n /= i;
      if (n < i) {
        break;
      }
    } else {
      i += 2;
    }
  }
  if (n > 1) {
    p.push_back(n);
  }
}

