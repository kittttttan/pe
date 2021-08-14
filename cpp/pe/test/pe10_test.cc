#include "gtest/gtest.h"
#include "../include/pe10.h"

namespace {
  TEST(Pe10Test, Main) {
    EXPECT_EQ(142913828922ul, pe::pe10(2000000));
  }
}