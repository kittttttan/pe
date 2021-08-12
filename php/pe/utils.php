<?php

namespace Pe;

/**
 * @param int $n
 * @return int[]
 */
function get_divisors(int $n): array
{
    $p = [];
    if ($n < 2) {
        return $p;
    }

    $limit = (int)floor(sqrt($n));

    while (($n & 1) === 0) {
        $p[] = 2;
        $n >>= 1;
    }
    if ($n === 1) {
        return $p;
    }

    $i = 3;
    while ($i <= $limit) {
        if (($n % $i) === 0) {
            $p[] = $i;
            $n = intdiv($n, $i);
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

/**
 * @param int $start
 * @param int $limit
 * @param int $step
 * @return \Iterator
 */
function xrange(int $start, int $limit, int $step = 1): \Iterator
{
    if ($start < $limit) {
        if ($step <= 0) {
            throw new \LogicException('Step must be +ve');
        }

        for ($i = $start; $i <= $limit; $i += $step) {
            yield $i;
        }
        return;
    }

    if ($step >= 0) {
        throw new \LogicException('Step must be -ve');
    }

    for ($i = $start; $i >= $limit; $i += $step) {
        yield $i;
    }
}

/**
 * @param \Iterator $it
 * @param callable $fn
 * @return \Iterator
 */
function ite_filter(\Iterator $it, callable $fn): \Iterator
{
    foreach ($it as $cur) {
        if ($fn($cur)) {
            yield $cur;
        }
    }
}

/**
 * @param \Iterator $it
 * @return int
 */
function sum_iterator(\Iterator $it): int
{
    $sum = 0;
    foreach ($it as $i) {
        $sum += $i;
    }

    return $sum;
}
