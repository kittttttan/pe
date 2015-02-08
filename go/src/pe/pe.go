/*
    Package pe implements functions to solve problems of Project Euler.
*/
package pe

import (
    "math"
)

func Divisors(n uint64) []uint64 {
    ps := []uint64{}
    limit := uint64(math.Sqrt(float64(n)))
    for (n & 1) == 0 {
        ps = append(ps, 2)
        n >>= 1
    }
    if n == 1 {
        return ps
    }

    var i uint64 = 3
    for i <= limit {
        if (n % i) == 0 {
            ps = append(ps, i)
            n /= i
            if n < i {
                break
            }
        } else {
            i += 2
        }
    }
    if n > 1 {
        ps = append(ps, n)
    }

    return ps
}