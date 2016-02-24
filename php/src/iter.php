<?php

function xrange(int $start, int $limit, int $step = 1)
{
    if ($start < $limit) {
        if ($step <= 0) {
            throw new LogicException('Step must be +ve');
        }

        for ($i = $start; $i <= $limit; $i += $step) {
            yield $i;
        }
        return;
    }

    if ($step >= 0) {
        throw new LogicException('Step must be -ve');
    }

    for ($i = $start; $i >= $limit; $i += $step) {
        yield $i;
    }
}

function ite_filter(\Iterator $it, callable $func)
{
    foreach ($it as $cur) {
        if ($func($cur)) {
            yield $cur;
        }
    }
}

function sum_iterator(\Iterator $it)
{
    $sum = 0;
    foreach ($it as $i) {
        $sum += $i;
    }

    return $sum;
}
