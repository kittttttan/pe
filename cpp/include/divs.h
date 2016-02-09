#pragma once

#include <cstdint>
#include <vector>

/*!
    @brief get divisors
    @param[out] p divisors
    @param[in]  n max length
    @return length
*/
void get_divs(std::vector<uint32_t>* p, uint64_t n);

/*!
    @brief count divisors
    @param[in] n
    @return
*/
uint32_t cnt_divs(uint32_t n);
