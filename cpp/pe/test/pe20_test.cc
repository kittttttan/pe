#include "gtest/gtest.h"
#include "../include/pe20.h"

namespace {
  TEST(Pe20Test, Main) {
    EXPECT_EQ(648, pe::pe20(100));
  }
}