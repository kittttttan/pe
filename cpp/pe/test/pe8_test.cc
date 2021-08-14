#include "gtest/gtest.h"
#include "../include/pe8.h"

namespace {
  TEST(Pe8Test, Main) {
    EXPECT_EQ(40824, pe::pe8("../../res/pe8.txt", 5));
  }
}