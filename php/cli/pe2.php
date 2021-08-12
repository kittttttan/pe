<?php
require_once 'vendor/autoload.php';

use Pe\Pe2;

/**
 * @return void
 */
function help(): void
{
    echo 'php pe2.php number'."\n";
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

    $n = $argv[1] ?? 4000000;
    if (!is_numeric($n)) {
        help();
        return;
    }

    $n = intval($n);
    $a = Pe2::calc($n);
    echo "n = $n\n";
    echo $a;
}

main();
