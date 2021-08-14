#include "gtest/gtest.h"
#include "../include/pe6.h"

namespace {
  TEST(Pe6Test, Main) {
    EXPECT_EQ(25164150, pe::pe6(100));
  }
}