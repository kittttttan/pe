#include "gtest/gtest.h"
#include "../include/pe17.h"

namespace {
  TEST(Pe17Test, Main) {
    EXPECT_EQ(21124, pe::pe17(1000));
  }
}