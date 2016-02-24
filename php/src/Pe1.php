<?php
/**
 * Solve project euler 1
 *
 * Add all the natural numbers below one thousand
 * that are multiples of 3 or 5.
 */

$ROOT = dirname(__FILE__);
require_once $ROOT.'/iter.php';

class Pe1
{
    public static function sum(int $limit = 1000)
    {
        return sum_iterator(
            ite_filter(
                xrange(1, $limit + 1),
                function ($n) {
                    return $n % 3 == 0 || $n % 5 == 0;
                }
            )
        );
    }

    public static function calc(int $n = 1000)
    {
        $s = 0;

        if ($n > 2) {
            $n3 = floor($n / 3);
            $n5 = floor($n / 5);
            $n15 = floor($n / 15);
            $s = (3 * $n3 * ($n3 + 1) + 5 * $n5 * ($n5 + 1) - 15 * $n15 * ($n15 + 1)) >> 1;
        }

        return $s;
    }
}

/*
echo Pe1::sum();
echo "\n";
echo Pe1::calc();
*/
