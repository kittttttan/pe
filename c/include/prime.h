#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*!
    @brief get prime number list with sieve algorhythm
    @param[out] p Array for the list
    @param[in]  l Length of the list
    @return
*/
size_t sieve(uint32_t *p, size_t l);

/*!
    @brief get prime number list below limit
    @param[out] p
    @param[in]  limit
    @return length
*/
size_t sieve_below(uint32_t *p, uint32_t limit);

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
    @return true means prime
*/
bool mrpt(uint32_t n, uint32_t i);
