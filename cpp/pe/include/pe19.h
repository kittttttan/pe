#pragma once

#include <cstdint>

namespace pe {
  bool isLeapYear(uint32_t year);
  uint32_t daysOfMonth(uint32_t year, uint32_t month);
  uint32_t pe19(uint32_t n);
}