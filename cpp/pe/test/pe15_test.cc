#include "gtest/gtest.h"
#include "../include/pe15.h"

namespace {
  TEST(Pe15Test, Main) {
    EXPECT_EQ(137846528820, pe::pe15(20, 20));
  }
}