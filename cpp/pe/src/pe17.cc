#define _CRT_SECURE_NO_WARNINGS 1
#include "../include/pe17.h"

#include <iostream>

namespace pe {
  using namespace std;

  static uint32_t to20[] = {
    0, //
    3, //one
    3, //two
    5, //three
    4, //four
    4, //five
    3, //six
    5, //seven
    5, //eight
    4, //nine
    3, //ten
    6, //eleven
    6, //twelve
    8, //thirteen
    8, //fourteen
    7, //fifteen
    7, //sixteen
    9, //seventeen
    8, //eighteen
    8, //nineteen
  };

  static uint32_t ty[] = {
    6, //twenty
    6, //thirty
    5, //forty
    5, //fifty
    5, //sixty
    7, //seventy
    6, //eighty
    6, //ninety
  };

  static uint32_t spell1(uint32_t n) {
    if (n < 20) {
      return to20[n];
    }

    uint32_t a = n / 10;
    uint32_t b = n % 10;
    return ty[a - 2] + to20[b];
  }

  static uint32_t spell2(uint32_t n) {
    if (n < 100) {
      return spell1(n);
    }
    
    uint32_t h = n / 100;
    uint32_t d = spell1(n % 100);
    if (!d) {
      return to20[h] + 7; // hundred
    }
    return to20[h] + 10 + d; // hundredand
  }

  static uint32_t spell3(uint32_t n) {
    if (n < 1000) {
      return spell2(n);
    }

    uint32_t t = n / 1000;
    uint32_t h = spell2(n % 1000);
    if (!h) {
      return spell2(t) + 8; // thousand
    }
    return spell2(t) + 11 + h; // thousandand
  }

  uint32_t pe17(uint32_t n) {    
    if (n > 99999) {
      cerr << "too large.\n";
      return 0;
    }

    uint32_t s = 0;
    for (uint32_t i = 1; i < n + 1; ++i) {
      s += spell3(i);
    }

    return s;
  }
}