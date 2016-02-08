#define _CRT_SECURE_NO_WARNINGS 1
#include <pe19.h>

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

enum {
  SUN,
  MON,
  TUE,
  WED,
  THU,
  FRI,
  SAT
};

bool isLeapYear(uint32_t year) {
  return (year & 3) == 0 && (year % 100 || (year % 400) == 0);
}

uint32_t daysOfMonth(uint32_t year, uint32_t month) {
  switch (month) {
    case 2:
      return isLeapYear(year) ? 29 : 28;
    case 4:
    case 6:
    case 9:
    case 11:
      return 30;
  }
  
  return 31;
}

void pe19(uint32_t n) {
  uint32_t sum = 0;
  uint32_t dow = TUE;  // 1901-01-01 is Tuesday
  for (uint32_t year = 1901; year <= n; ++year) {
    for (uint32_t month = 1; month <= 12; ++month) {
      dow += daysOfMonth(year, month);
      dow %= 7;
      if (dow == SUN) {
        ++sum;
      }
    }
  }
  
  printf("%" PRIu32 " (1901 to %" PRIu32 ")\n", sum, n);
}

int pe19_main(void) {
  uint32_t n;

  while (1) {
    printf("1901 to: ");
    
    if (scanf("%" PRIu32, &n) != 1) {
      scanf("%*s");
      puts("Input Number.");
    } else {
      if (n < 1) {
        break;
      }
      pe19(n);
    }
  }

  return 0;
}
