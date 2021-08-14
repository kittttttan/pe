#include "gtest/gtest.h"
#include "../include/pe4.h"

namespace {
  TEST(Pe4Test, Main) {
    uint32_t first;
    uint32_t last;
    EXPECT_EQ(906609, pe::pe4(3, first, last));
  }
}