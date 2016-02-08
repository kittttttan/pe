#define _CRT_SECURE_NO_WARNINGS 1
#include <pe4.h>
#include <palindrome.h>

#include <stdio.h>

void pe4(int first, int last) {
  int m = 0;
  for (int x = first; x < last; ++x) {
    for (int y = x; y < last; ++y) {
      int xy = x * y;
      if (xy > m && is_palindrome(xy)) {
        m = xy;
      }
    }
  }

  if (m) {
    printf("Max palindrome is %d for x * y (%d <= x,y < %d)\n", m, first, last);
  } else {
    printf("No palindromes are found for x * y (%d <= x,y < %d)\n", first, last);
  }
}

int pe4_main(void) {
  int m, n;

  while (1) {
    printf("min max: ");
    if (scanf("%d %d", &m, &n) != 2) {
      scanf("%*s");
      puts("Input 2 Numbers.");
    } else {
      if (!m && !n) {
        break;
      }
      pe4(m, n);
    }
  }

  return 0;
}
