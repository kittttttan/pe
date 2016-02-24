<?php

function get_divisors(int $n)
{
    $p = array();
    $limit = floor(sqrt($n));
    while (($n & 1) == 0) {
        $p[] = 2;
        $n >>= 1;
    }
    if ($n == 1) {
        return $p;
    }
    $i = 3;
    while ($i <= $limit) {
        if (($n % $i) == 0) {
            $p[] = $i;
            $n = floor($n / $i);
            if ($n < $i) {
                break;
            }
            continue;
        }

        $i += 2;
    }
    if ($n > 1) {
        $p[] = $n;
    }

    return $p;
}
