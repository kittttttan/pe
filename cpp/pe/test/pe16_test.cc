#include "gtest/gtest.h"
#include "../include/pe16.h"

namespace {
  TEST(Pe16Test, Main) {
    EXPECT_EQ(1366, pe::pe16(1000));
  }
}