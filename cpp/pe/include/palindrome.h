#pragma once

#include <cstdint>

namespace pe {
  /*!
    <pre>
    original    reverse  is_palindrome
        12345 != 54321        false
        1221 == 1221         true
    </pre>
    @param[in] n
    @return
  */
  bool is_palindrome(uint32_t n);
}
