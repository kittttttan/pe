#include "gtest/gtest.h"
#include "../include/pe18.h"

namespace {
  TEST(Pe18Test, Main) {
    EXPECT_EQ(1074, pe::pe18("../../res/pe18.txt"));
  }
}