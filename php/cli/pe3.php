<?php
require_once 'vendor/autoload.php';

use Pe\Pe3;

/**
 * @return void
 */
function help(): void
{
    echo 'php pe3.php number'."\n";
}

/**
 * @return void
 */
function main(): void
{
    $argv = $_SERVER['argv'];

    $arg1 = $argv[1] ?? null;
    if ($arg1 === '-h') {
        help();
        return;
    }

    $n = $argv[1] ?? 600851475143;
    if (!is_numeric($n)) {
        help();
        return;
    }

    $n = intval($n);
    $a = Pe3::calc($n);
    if (count($a) > 1) {
        echo "$n = ". implode(' * ', $a) ."\n";
    } else {
        echo "$n";
    }
}

main();
