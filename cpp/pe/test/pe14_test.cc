#include "gtest/gtest.h"
#include "../include/pe14.h"

namespace {
  TEST(Pe14Test, Main) {
    uint32_t index, cnt;
    pe::pe14(index, cnt, 500001, 1000000);

    EXPECT_EQ(837799, index);
    EXPECT_EQ(525, cnt);
  }
}