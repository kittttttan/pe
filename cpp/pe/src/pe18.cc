#define _CRT_SECURE_NO_WARNINGS 1
#include "../include/pe18.h"

#include <cstdio>
#include <cstdlib>
#include <algorithm>

namespace pe {
  uint32_t pe18(const char* filepath) {
    static const int SIZE = 15;
    
    FILE *fp = fopen(filepath, "r");
    if (!fp) {
      fprintf(stderr, "failed to open %s\n", filepath);
      return 0;
    }
    
    // init array
    int **s = (int**)calloc(sizeof(int*), SIZE);
    for (size_t i = 0; i < SIZE; ++i) {
      s[i] = (int*)calloc(sizeof(int), i + 1);
    }
    
    // parse
    int c;
    int invalid = 0;
    int x = 0;
    int y = 0;
    int t = 0;
    while ((c = getc(fp)) != EOF) {
      if (c >= '0' && c <= '9') {
        t = 10 * t + c - '0';
      } else if (c == '\n') {
        s[y][x] = t;
        // printf("%02d\n", t);
        t = 0;
        ++y;
        x = 0;
        if (y >= SIZE) {
          invalid = 1;
          break;
        }
      } else {
        s[y][x] = t;
        // printf("%02d ", t);
        t = 0;
        ++x;
        if (x >= SIZE) {
          invalid = 1;
          break;
        }
      }
    }

    uint32_t sum = 0;
    if (invalid) {
      fprintf(stderr, "invalid file\n");
      fclose(fp);
    } else {
      s[y][x] = t;
      // printf("%02d\n", t);
    
      if (ferror(fp)) {
        fprintf(stderr, "file error.");
        clearerr(fp);
      }
      fclose(fp);
      
      // sum
      for (size_t i = 0; i < SIZE - 1; ++i) {
        for (size_t j = 0; j < SIZE - i - 1; ++j) {
          s[SIZE - 1 - i - 1][j] +=
              std::max(s[SIZE - 1 - i][j], s[SIZE - 1 - i][j + 1]);
        }
      }
      sum = s[0][0];
    }
    
    free(s[0]);
    free(s);

    return sum;
  }
}