#define _CRT_SECURE_NO_WARNINGS 1
#include <pe22.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char DEFAULT_FILE_NAME[] = "pe22.txt";

static int compare(const void* a, const void* b) {
  return strcmp(*(const char**) a, *(const char**) b);
}

void pe22(const char* filepath) {
  // file open
  FILE *fp = fopen(filepath, "rb");
  if (!fp) {
    fprintf(stderr, "failed to open %s\n", filepath);
    return;
  }

  // count
  int c;
  size_t size = 0;
  size_t name_count = 1;
  while ((c = getc(fp)) != EOF) {
    if (c == ',') {
      ++size;
      ++name_count;
    } else if ('A' <= c && c <= 'Z') {
      ++size;
    }
  }
  //printf("%d %d\n", size, name_count);

  // read names
  char *text = (char*)malloc(size + 1);
  if (!text) {
    fprintf(stderr, "error\n");
    fclose(fp);
    return;
  }

  fseek(fp, 0, SEEK_SET);
  size_t i = 0;
  while ((c = getc(fp)) != EOF) {
    if ((c == ',') || ('A' <= c && c <= 'Z')) {
      text[i] = c;
      ++i;
    }
  }
  text[i] = '\0';

  // file close
  if (ferror(fp)) {
    fprintf(stderr, "file error.");
    clearerr(fp);
  }
  fclose(fp);

  // string array
  char *cp = text;
  char **names = (char**)malloc(name_count * sizeof(char*));
  for (i = 0; i < size; ++i) {
    if ((names[i] = strtok(cp, ",")) == NULL) {
      break;
    }
    cp = NULL;
  }

  // sort
  qsort(names, name_count, sizeof(const char *), compare);

  // calculate score
  unsigned long score = 0;
  for (i = 0; i < name_count; ++i) {
    size_t j = 0;
    int worth = 0;
    while ((c = names[i][j]) != '\0') {
      worth += c - 'A' + 1;
      ++j;
    }
    score += (i + 1) * worth;
    //printf("%s %d\n", names[i], worth);
  }

  printf("%lu\n", score);

  for (i = 0; i < name_count; ++i) {
    free(names[i]);
  }
  free(names);
}

int pe22_main(void) {
  pe22(DEFAULT_FILE_NAME);

  return 0;
}
