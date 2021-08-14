#include "gtest/gtest.h"
#include "../include/pe22.h"

namespace {
  TEST(Pe22Test, Main) {
    EXPECT_EQ(871198282, pe::pe22("../../res/pe22.txt"));
  }
}