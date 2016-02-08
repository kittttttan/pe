#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

size_t sieve(uint32_t *p, size_t l);
size_t sieve_below(uint32_t *p, uint32_t limit);
uint32_t mod_math_pow(uint32_t base, uint32_t power, uint32_t mod);
bool mrpt(uint32_t n, uint32_t i);
