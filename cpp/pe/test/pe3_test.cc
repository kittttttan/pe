#include "gtest/gtest.h"
#include "../include/pe3.h"

namespace {
  using namespace std;

  TEST(Pe3Test, Main) {
    vector<uint32_t> e{71, 839, 1471, 6857};
    vector<uint32_t> v = pe::pe3(600851475143ull);
    EXPECT_EQ(e.size(), v.size());
    for (size_t i = 0; i < e.size(); i++) {
      EXPECT_EQ(e[i], v[i]);
    }
  }
}