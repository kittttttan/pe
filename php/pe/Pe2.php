<?php
/**
 * Solve project euler 2
 *
 * By considering the terms in the Fibonacci sequence
 * whose values do not exceed four million,
 * find the sum of the even-valued terms.
 */

namespace Pe;

class Pe2
{
    /**
     * @param int $limit
     * @return int
     */
    public static function calc(int $limit): int
    {
        [$a, $b, $s] = [1, 2, 2];

        while ($b <= $limit) {
            [$a, $b] = [$b, $a + $b];
            if (($b & 1) === 0) {
                $s += $b;
            }
        }

        return $s;
    }
}
