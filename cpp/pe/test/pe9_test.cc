#include "gtest/gtest.h"
#include "../include/pe9.h"

namespace {
  TEST(Pe9Test, Main) {
    EXPECT_EQ(31875000, pe::pe9(1000));
  }
}