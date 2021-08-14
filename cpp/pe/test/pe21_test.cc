#include "gtest/gtest.h"
#include "../include/pe21.h"

namespace {
  TEST(Pe21Test, Main) {
    EXPECT_EQ(31626, pe::pe21(10000));
  }
}