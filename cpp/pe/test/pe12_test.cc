#include "gtest/gtest.h"
#include "../include/pe12.h"

namespace {
  TEST(Pe12Test, Main) {
    EXPECT_EQ(76576500, pe::pe12(500));
  }
}