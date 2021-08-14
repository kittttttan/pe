#include "../include/pe1.h"
#include "../include/pe2.h"
#include "../include/pe3.h"
#include "../include/pe4.h"
#include "../include/pe5.h"
#include "../include/pe6.h"
#include "../include/pe7.h"
#include "../include/pe8.h"
#include "../include/pe9.h"
#include "../include/pe10.h"
#include "../include/pe11.h"
#include "../include/pe12.h"
#include "../include/pe13.h"
#include "../include/pe14.h"
#include "../include/pe15.h"
#include "../include/pe16.h"
#include "../include/pe17.h"
#include "../include/pe18.h"
#include "../include/pe19.h"
#include "../include/pe20.h"
#include "../include/pe21.h"
#include "../include/pe22.h"

#include <cstdlib>
#include <cstring>
#include <iostream>

int main(int argc, char **argv)
{
  using namespace std;

  if (argc < 2) {
    cout << "required problem number." << endl;
    return 0;
  }

  char *end;
  uint32_t n = strtoul(argv[1], &end, 10);
  cout << "problem " << n << endl;

  switch (n) {
    case 1: pe1(argc - 1, &argv[1]); break;
    case 2: pe2(argc - 1, &argv[1]); break;
    case 3: pe3(argc - 1, &argv[1]); break;
    case 4: pe4(argc - 1, &argv[1]); break;
    case 5: pe5(argc - 1, &argv[1]); break;
    case 6: pe6(argc - 1, &argv[1]); break;
    case 7: pe7(argc - 1, &argv[1]); break;
    case 8: pe8(argc - 1, &argv[1]); break;
    case 9: pe9(argc - 1, &argv[1]); break;
    case 10: pe10(argc - 1, &argv[1]); break;
    case 11: pe11(argc - 1, &argv[1]); break;
    case 12: pe12(argc - 1, &argv[1]); break;
    case 13: pe13(argc - 1, &argv[1]); break;
    case 14: pe14(argc - 1, &argv[1]); break;
    case 15: pe15(argc - 1, &argv[1]); break;
    case 16: pe16(argc - 1, &argv[1]); break;
    case 17: pe17(argc - 1, &argv[1]); break;
    case 18: pe18(argc - 1, &argv[1]); break;
    case 19: pe19(argc - 1, &argv[1]); break;
    case 20: pe20(argc - 1, &argv[1]); break;
    case 21: pe21(argc - 1, &argv[1]); break;
    case 22: pe22(argc - 1, &argv[1]); break;
    default:
      cout << "not implemented." << endl;
      break;
  }

  return 0;
}
