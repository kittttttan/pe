#define _CRT_SECURE_NO_WARNINGS 1
#if _DEBUG
#pragma comment(lib, "pe_d.lib")
#else
#pragma comment(lib, "pe.lib")
#endif

#include "runner.h"

#include <iostream>

using namespace std;

void pe(unsigned n) {
  switch (n) {
  case 1: pe1_main(); break;
  case 2: pe2_main(); break;
  case 3: pe3_main(); break;
  case 4: pe4_main(); break;
  case 5: pe5_main(); break;
  case 6: pe6_main(); break;
  case 7: pe7_main(); break;
  case 8: pe8_main(); break;
  case 9: pe9_main(); break;
  case 10: pe10_main(); break;
  case 11: pe11_main(); break;
  case 12: pe12_main(); break;
  case 13: pe13_main(); break;
  case 14: pe14_main(); break;
  case 15: pe15_main(); break;
  case 16: pe16_main(); break;
  case 17: pe17_main(); break;
  case 18: pe18_main(); break;
  case 19: pe19_main(); break;
  case 20: pe20_main(); break;
  case 21: pe21_main(); break;
  case 22: pe22_main(); break;
  default: cout << "Invalid problem number\n"; break;
  }
}

static void help() {
  printf("  pe [problem_number]\n");
}

int main(int argc, char** argv) {
  unsigned n;

  if (argc > 1) {
    string arg1(argv[1]);
    if (arg1 == "-h" || arg1 == "--help") {
      help();
      return 0;
    }

    n = atoi(arg1.c_str());
    pe(n);
    return 0;
  }

  while (1) {
    cout << "Problem: ";
    cin >> n;
    if (n < 1) {
      break;
    }
    pe(n);
  }

  return 0;
}
