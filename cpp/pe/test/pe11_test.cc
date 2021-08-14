#include "gtest/gtest.h"
#include "../include/pe11.h"

namespace {
  TEST(Pe11Test, Main) {
    EXPECT_EQ(70600674, pe::pe11("../../res/pe11.txt"));
  }
}