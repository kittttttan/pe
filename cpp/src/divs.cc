#include <divs.h>
#include <cstddef>
#include <cmath>

using namespace std;

/*
 * get divisors
 * @param[out] p divisors
 * @param[in]  n max length
 * @return length
 */
void get_divs(vector<uint>* p, uint64 n)
{
  size_t i, limit;

  limit = static_cast<size_t>(sqrt(n));
  while ((n & 1) == 0) {
    p->push_back(2);
    n >>= 1;
  }
  if (n == 1) {
    return;
  }

  i = 3;
  while (i <= limit) {
    if (n % i == 0) {
      p->push_back(i);
      n /= i;
      if (n < i) {
        break;
      }
    } else {
      i += 2;
    }
  }
  if (n > 1) {
    p->push_back(n);
  }
}

/*
 * count divisors
 * @param[in] n
 * @return 
 */
uint cnt_divs(uint n)
{
  if (!n) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  if (n < 4) {
    return 2;
  }

  vector<uint> p;
  get_divs(&p, n);
  size_t l = p.size();
  uint t = 0;
  uint c = 1;
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
