#include <palindrome.h>

/*
 * original    reverse  is_palindrome
 *    12345 != 54321          0
 *     1221 == 1221           1
 * @param[in] n
 * @return 
 */
bool is_palindrome(uint32_t n) {
  uint32_t ds[10];
  uint32_t i = 0;
  uint32_t j = 0;
  while (n) {
    ds[i++] = n % 10;
    n /= 10;
  }

  while (i > j) {
    if (ds[--i] != ds[j++]) {
      return false;
    }
  }

  return true;
}
