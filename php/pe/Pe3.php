<?php
/**
 * Solve project euler 3
 *
 * Find the largest prime factor of a composite number.
 */

namespace Pe;

class Pe3
{
    /**
     * @param int $n
     * @return int[]
     */
    public static function calc(int $n): array
    {
        return get_divisors($n);
    }
}
