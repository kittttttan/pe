#include "gtest/gtest.h"
#include "../include/pe2.h"

namespace {
  TEST(Pe2Test, Main) {
    EXPECT_EQ(4613732, pe::pe2(4000000));
  }
}