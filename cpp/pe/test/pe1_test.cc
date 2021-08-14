#include "gtest/gtest.h"
#include "../include/pe1.h"

namespace {
  TEST(Pe1Test, Main) {
    EXPECT_EQ(234168, pe::with_loop(1000));
    EXPECT_EQ(234168, pe::no_loop(1000));
  }
}