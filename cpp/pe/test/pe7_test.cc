#include "gtest/gtest.h"
#include "../include/pe7.h"

namespace {
  TEST(Pe7Test, Main) {
    EXPECT_EQ(104743, pe::pe7(10001));
  }
}