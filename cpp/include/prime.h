#pragma once

#include <cstdint>
#include <vector>

uint32_t sieve(std::vector<uint32_t>& p, uint32_t l);
uint32_t sieve_below(std::vector<uint32_t>& p, uint32_t limit);
uint32_t mod_math_pow(uint32_t base, uint32_t power, uint32_t mod);
bool mrpt(uint32_t n, uint32_t i);
