<?php

/**
 * Solve project euler 1
 *
 * Add all the natural numbers below one thousand
 * that are multiples of 3 or 5.
 */

namespace Pe;

class Pe1
{
    /**
     * @param int $limit
     * @return int
     */
    public static function with_loop(int $limit): int
    {
        return array_sum(
            array_filter(
                range(1, $limit),
                function ($n) {
                    return $n % 3 == 0 || $n % 5 == 0;
                }
            )
        );
    }

    /**
     * @param int $n
     * @return int
     */
    public static function no_loop(int $n): int
    {
        $s = 0;

        if ($n > 2) {
            $n3 = intdiv($n, 3);
            $n5 = intdiv($n, 5);
            $n15 = intdiv($n, 15);
            $s = (3 * $n3 * ($n3 + 1) + 5 * $n5 * ($n5 + 1) - 15 * $n15 * ($n15 + 1)) >> 1;
        }

        return $s;
    }
}
