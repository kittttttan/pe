#include "gtest/gtest.h"
#include "../include/pe5.h"

namespace {
  TEST(Pe5Test, Main) {
    EXPECT_EQ(232792560, pe::pe5(20));
  }
}