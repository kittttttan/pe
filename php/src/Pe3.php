<?php
/**
 * Solve project euler 3
 *
 * Find the largest prime factor of a composite number.
 */

$ROOT = dirname(__FILE__);
require_once $ROOT.'/utils.php';

class Pe3
{
    public static function calc(int $n = 600851475143)
    {
        return get_divisors($n);
    }
}
