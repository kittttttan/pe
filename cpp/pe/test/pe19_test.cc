#include "gtest/gtest.h"
#include "../include/pe19.h"

namespace {
  TEST(Pe19Test, Main) {
    EXPECT_EQ(171, pe::pe19(2000));
  }
}