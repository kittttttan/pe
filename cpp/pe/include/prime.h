#pragma once

#include <cstdint>
#include <vector>

namespace pe {
  /*!
    @brief get prime number list with sieve algorhythm
    @param[out] p Array for the list
    @param[in]  l Length of the list
    @return
  */
  uint32_t sieve(std::vector<uint32_t>& p, uint32_t l);

  /*!
    @brief get prime number list below limit
    @param[out] p
    @param[in]  limit
    @return
  */
  void sieve_below(std::vector<uint32_t>& p, uint32_t limit);

  /*!
    @brief mod_math_pow
    @param[in] base
    @param[in] power
    @param[in] mod
    @return [base]^[power] (mod [mod])
  */
  uint32_t mod_math_pow(uint32_t base, uint32_t power, uint32_t mod);

  /*!
    @brief Miller-Rabin primality test
    @param[in] n Target number
    @param[in] i Repeat times of the test
    @return 1 means prime
  */
  bool mrpt(uint32_t n, uint32_t i);
}