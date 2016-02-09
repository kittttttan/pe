#define _CRT_SECURE_NO_WARNINGS 1
#include <pe8.h>

#include <stdio.h>

enum { DIGITS_LENGTH = 1000u };

void pe8(int n) {
  static const char* FILENAME = "pe8.txt";

  FILE *fp = fopen(FILENAME, "r");
  if (!fp) {
    fprintf(stderr, "%s:%d: Can't open %s\n", __FILE__, __LINE__, FILENAME);
    return;
  }

  int i = 0;
  int c;
  int digits[DIGITS_LENGTH];
  while ((c = getc(fp)) != EOF) {
    if (c >= '0' && c <= '9') {
      if (i >= DIGITS_LENGTH) {
        fprintf(stderr, "%s:%d: too many numbers.\n", __FILE__, __LINE__);
        break;
      }
      digits[i++] = c - '0';
    }
  }

  if (ferror(fp)) {
    fprintf(stderr, "file error.");
    clearerr(fp);
  }
  fclose(fp);

  int m = 0;
  if (n > 0 && n < 1000) {
    for (i = 0; i < 1000 - n + 1; ++i) {
      int t = 1;
      for (int j = 0; j < n; ++j) {
        t *= digits[i + j];
      }
      if (m < t) {
        m = t;
      }
    }
  }

  printf("%d (n = %d)\n", m, n);
}

int pe8_main(void) {
  int n;

  while (1) {
    printf("digits: ");
    if (scanf("%d", &n) != 1) {
      scanf("%*s");
      puts("Input Number.");
    } else {
      if (!n) {
        break;
      }
      pe8(n);
    }
  }

  return 0;
}
