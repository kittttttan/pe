#pragma once

#include <stddef.h>
#include <stdint.h>

/*!
    @brief get divisors
    @param[out] p divisors
    @param[in]  n max length
    @return length
*/
size_t get_divs(uint32_t *p, uint32_t n);

/*!
    @brief count divisors
    @param[in] n
    @return
*/
uint32_t cnt_divs(uint32_t n);
