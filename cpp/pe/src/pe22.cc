#define _CRT_SECURE_NO_WARNINGS 1
#include "../include/pe22.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>

namespace pe {
  using namespace std;

  static const char DEFAULT_FILE_NAME[] = "pe22.txt";

  static int compare(const void* a, const void* b) {
    return strcmp(*(const char**) a, *(const char**) b);
  }

  uint32_t pe22(const char* filepath) {
    // file open
    FILE *fp = fopen(filepath, "rb");
    if (!fp) {
      cerr << "failed to open " << filepath << endl;
      return 0;
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
    // cout << size << " " << name_count << endl;

    // read names
    char *text = (char*)malloc(size + 1);
    if (!text) {
      cerr << "error" << endl;
      fclose(fp);
      return 0;
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
      cerr << "file error." << endl;
      clearerr(fp);
    }
    fclose(fp);
    
    // string array
    char *cp = text;
    char **names = (char**)calloc(sizeof(char*), name_count + 1);
    for (i = 0; i < size; ++i) {
      if ((names[i] = strtok(cp, ",")) == NULL) {
        break;
      }
      cp = NULL;
    }
    free(text);
    
    // sort
    qsort(names, name_count, sizeof(const char *), compare);
    
    // calculate score
    uint32_t score = 0;
    for (i = 0; i < name_count; ++i) {
      size_t j = 0;
      int worth = 0;
      while ((c = names[i][j]) != '\0') {
        worth += c - 'A' + 1;
        ++j;
      }
      score += (i + 1) * worth;
    }
    
    free(names);
    
    return score;
  }
}