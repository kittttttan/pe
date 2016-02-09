#include <palindrome.h>

/*
 * original    reverse  is_palindrome
 *    12345 != 54321          0
 *     1221 == 1221           1
 * @param[in] n
 * @return 
 */
bool is_palindrome(uint32_t n) {
  int ds[20] = {0};
  int i = 0;
  while (n) {
    ds[i++] = n % 10;
    n /= 10;
  }

  int j = 0;
  while (i > j) {
    if (ds[--i] != ds[j++]) {
      return false;
    }
  }

  return true;
}
