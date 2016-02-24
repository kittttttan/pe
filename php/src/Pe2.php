<?php
/**
 * Solve project euler 2
 *
 * By considering the terms in the Fibonacci sequence
 * whose values do not exceed four million,
 * find the sum of the even-valued terms.
 */

class Pe2
{
    public static function calc(int $limit = 4000000)
    {
        list($a, $b, $s) = array(1, 2, 2);
        while ($b <= $limit) {
            list($a, $b) = array($b, $a + $b);
            if (($b & 1) == 0) {
                $s += $b;
            }
        }

        return $s;
    }
}
