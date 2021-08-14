#include "gtest/gtest.h"
#include "../include/pe13.h"

#include <string>

namespace {
  using namespace std;

  TEST(Pe13Test, Main) {
    vector<char> res;
    pe::pe13("../../res/pe13.txt", res);
    int k = res.size();
    int size = k < 10 ? k : 10;

    string s(res.end() - size, res.end());
    std::reverse(s.begin(), s.end());

    ASSERT_STREQ("5537376230", s.c_str());
  }
}